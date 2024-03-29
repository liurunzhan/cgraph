#!/usr/bin/env gorun

// Date : 2022-07-01
// A script to compile Library cgraph in Unix-like and Windows Platforms
// gets source files iteratively from Directory src

package main

import (
  "fmt"
  "io/ioutil"
  "os"
  "os/exec"
  "regexp"
  "path"
  "runtime"
  "strings"
)

func getsubdirs(path, dirs) {
  dirs, _ := ioutil.ReadDir(entry)
  for _, item := range dirs {
    matched, _ := regexp.MatchString(`^(?!\.)`, item.Name())
    if matched {
      if item.IsDir() {
        append(dirs, item)
        getsubdirs(item, dirs)
      }
    }
  }
}

func main() {
  var PRO string = "cgraph"
  var DIR string = "."
  var INC string = path.Join(DIR, "include")
  var SRC string = path.Join(DIR, "src")
  var SRC_TYPE string = os.path.join(SRC, "type")
  var TST string = path.Join(DIR, "tests")
  var LIB string = path.Join(DIR, "lib")

  var CC string = "cc"
  var CFLAGS []string = strings.Split("-std=c89 -Wall -pedantic -fPIC", " ")
  var CSFLAGS string = "-shared"

  var MODE string = "debug"
  if MODE == "debug" {
    CFLAGS = append(CFLAGS, "-g", "-DDEBUG")
  } else if MODE == "release" {
    CFLAGS = append(CFLAGS, "-static", "-O2")
  }

  var AR string = "ar"
  var ARFLAGS string = "-rcs"

  // source files
  // get all subdirectories
  var SRCS []string
  getsubdirs(SRC, SRCS)

  // get all source files from subdirectories
  var CFILES []string
  for _, dir := range SRCS {
    items, _ := ioutil.ReadDir(dir)
    for _, item := range items {
      if item.IsFile() {
        matched, _ := regexp.MatchString(`^(?!\.).*?\.c$`, item.Name())
        if matched {
          CFILES = append(CFILES, path.Join(dir, item.Name()))
        }
      }
    }
  }

  var LIBSHARED string 
  var LIBSTATIC string 
  var TSTFILE string 
  var TSTTARGET string
  
  if runtime.GOOS == "windows" {
    LIBSHARED = path.Join(LIB, "lib" + PRO + ".dll")
    LIBSTATIC = path.Join(LIB, "lib" + PRO + ".lib")
    TSTFILE   = path.Join(TST, PRO + ".c")
    TSTTARGET = path.Join(TST, PRO + ".exe")
  } else {
    LIBSHARED = path.Join(LIB, "lib" + PRO + ".so")
    LIBSTATIC = path.Join(LIB, "lib" + PRO + ".a")
    TSTFILE   = path.Join(TST, PRO + ".c")
    TSTTARGET = path.Join(TST, PRO)
  }

  var args []string = os.Args
  if len(args) == 1 {
    if _, err := os.Stat(LIB); os.IsNotExist(err) {
      os.MkdirAll(LIB, 0777)
    }
    var OFILES []string
    for _, file := range CFILES {
      var obj string = regexp.MustCompile(`\.c$`).ReplaceAllString(file, ".o")
      var dep string = regexp.MustCompile(`\.c$`).ReplaceAllString(file, ".d")
      fmt.Printf("compile %s to %s\n", file, obj)
      ARGS := append(CFLAGS, "-I"+INC, "-c", file, "-o", obj, "-MD", "-MF", dep)
      cmd := exec.Command(CC, ARGS...)
      cmd.Run()
      OFILES = append(OFILES, obj)
    }
    fmt.Printf("compile %s\n", LIBSHARED)
    ARGS0 := []string{CSFLAGS, "-o", LIBSHARED}
    ARGS0 = append(ARGS0, OFILES...)
    cmd0 := exec.Command(CC, ARGS0...)
    cmd0.Run()
    fmt.Printf("compile %s\n", LIBSTATIC)
    ARGS1 := []string{ARFLAGS, LIBSTATIC}
    ARGS1 = append(ARGS1, OFILES...)
    cmd1 := exec.Command(AR, ARGS1...)
    cmd1.Run()
  } else if args[1] == "test" {
    fmt.Printf("compile %s to \n", TSTFILE, TSTTARGET)
    ARGS0 := append(CFLAGS, "-I"+INC, "-o", TSTTARGET, TSTFILE, "-L"+LIB, "-static", "-l"+PRO, "-lm")
    cmd0 := exec.Command(CC, ARGS0...)
    cmd0.Run()
    fmt.Printf("test %s with %s/elements.csv", TSTTARGET, TST)
    cmd1 := exec.Command(TSTTARGET, TST, "/elements.csv")
    cmd1.Run()
  } else if args[1] == "clean" {
    for _, file := range CFILES {
      var obj string = regexp.MustCompile(`\.c$`).ReplaceAllString(file, ".o")
      fmt.Printf("clean %s\n", obj)
      os.Remove(obj)
      var dep string = regexp.MustCompile(`\.c$`).ReplaceAllString(file, ".d")
      fmt.Printf("clean %s\n", dep)
      os.Remove(dep)
    }
    fmt.Printf("clean %s\n", LIBSHARED)
    os.Remove(LIBSHARED)
    fmt.Printf("clean %s\n", LIBSTATIC)
    os.Remove(LIBSTATIC)
    fmt.Printf("clean %s\n", TSTTARGET)
    os.Remove(TSTTARGET)
  } else if args[1] == "distclean" {
    for _, file := range CFILES {
      var obj string = regexp.MustCompile(`\.c$`).ReplaceAllString(file, ".o")
      fmt.Printf("clean %s\n", obj)
      os.Remove(obj)
      var dep string = regexp.MustCompile(`\.c$`).ReplaceAllString(file, ".d")
      fmt.Printf("clean %s\n", dep)
      os.Remove(dep)
    }
    fmt.Printf("clean %s\n", LIBSHARED)
    os.Remove(LIBSHARED)
    fmt.Printf("clean %s\n", LIBSTATIC)
    os.Remove(LIBSTATIC)
    fmt.Printf("clean %s\n", LIB)
    os.RemoveAll(LIB)
    fmt.Printf("clean %s\n", TSTTARGET)
    os.Remove(TSTTARGET)
  } else if args[1] == "help" {
    fmt.Printf("%s    <target>\n", args[0])
    fmt.Printf("<target>: \n")
    fmt.Printf("                    compile cgraph\n")
    fmt.Printf("          test      test cgraph\n")
    fmt.Printf("          clean     clean all the generated files\n")
    fmt.Printf("          distclean clean all the generated files and directories\n")
    fmt.Printf("          help      commands to this program\n")
  } else {
    fmt.Printf("%s is an unsupported command\n", args[1])
    fmt.Printf("use \"%s help\" to know all supported commands\n", args[0])
  }
}
