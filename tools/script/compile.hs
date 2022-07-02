#!/usr/bin/runhaskell

import System.FilePath
import Text.Regex.Posix
import System.FilePath

main :: IO ()

main = do
  let pro = "cgraph"
  let dir = "."
  let inc = joinPath [dir, "include"]
  let src = joinPath [dir, "src"]
  let tst = joinPath [dir, "tests"]
  let lib = joinPath [dir, "lib"]

  let cc = "cc"
  let _cflags = "-std=c89 -Wall -pedantic -fPIC"
  let csflags = "-shared"

  let mode = "debug"
  let cflags = if mode == "debug" then _cflags ++ " -g -DDEBUG" else (if mode == "release" then _cflags ++ " -static -O2" else _cflags)
  let ar = "ar"
  let arflags = "-rcs"
  print cflags