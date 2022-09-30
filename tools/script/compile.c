//!/usr/bin/env -S tcc -run

#if defined(__linux__) || defined(__unix__) || defined(__CYGWIN__)
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#elif (defined(_WIN32) || defined(_WIN64))
#include <io.h>
#include <windows.h>
#else
#error Unsupported Platform
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_MAX (1024)
#define CMD_MAX (81960)
#define FILE_NUM (100)
#define CSTR_END '\0'
#define TRUE (1)
#define FALSE (0)

extern char **environ;

int judge_platform_is_windows(void);

int judge_platform_is_windows(void) {
  char **env = environ;
  const char *path = "PATH";
  int is_windows = FALSE;
  for (; NULL != *env; env++) {
    char *senv = *env, *tpath = (char *)path;
    for (; CSTR_END != *tpath; tpath++, senv++) {
      if (*tpath != *senv) {
        break;
      }
    }
    if (CSTR_END == *tpath) {
      char *senv = *env;
      for (; CSTR_END != *senv; senv++) {
        if ('\\' == *senv) {
          is_windows = TRUE;
          break;
        } else if ('/' == *senv) {
          is_windows = FALSE;
          break;
        }
      }
    }
  }

  return is_windows;
}

int main(int argc, char *argv[]) {
  const int is_windows = judge_platform_is_windows();
  const char *PRO = "cgraph";
  const char *_DIR = ".";
  char INC[STRING_MAX], SRC[STRING_MAX], SRC_TYPE[STRING_MAX], TST[STRING_MAX],
      LIB[STRING_MAX];
  char LIBSHARED[STRING_MAX], LIBSTATIC[STRING_MAX], TSTFILE[STRING_MAX],
      TSTTARGET[STRING_MAX];

  char PATH_SEP = '\0';
  if (TRUE == is_windows) {
    fprintf(stdout, "compile %s in windows platform!\n", PRO);
    PATH_SEP = '\\';
  } else {
    fprintf(stdout, "compile %s in unix-like platform!\n", PRO);
    PATH_SEP = '/';
  }
  sprintf(INC, "%s%c%s", _DIR, PATH_SEP, "include");
  sprintf(SRC, "%s%c%s", _DIR, PATH_SEP, "src");
  sprintf(SRC_TYPE, "%s%c%s", SRC, PATH_SEP, "type");
  sprintf(TST, "%s%c%s", _DIR, PATH_SEP, "tests");
  sprintf(LIB, "%s%c%s", _DIR, PATH_SEP, "lib");
  sprintf(LIBSHARED, "%s%clib%s.so", LIB, PATH_SEP, PRO);
  sprintf(LIBSTATIC, "%s%clib%s.a", LIB, PATH_SEP, PRO);
  sprintf(TSTFILE, "%s%c%s.c", TST, PATH_SEP, PRO);
  sprintf(TSTTARGET, "%s%c%s", TST, PATH_SEP, PRO);

  char CFLAGS[STRING_MAX];
  char *CC = "cc";
  char *CSFLAGS = "-shared";
  strcpy(CFLAGS, "-std=c89 -Wall -pedantic -fPIC");

  char *mode = "debug";
  if (mode == "debug") {
    strcat(CFLAGS, " -g -DDEBUG");
  } else if (mode == "release") {
    strcat(CFLAGS, " -static -O2");
  }

  char *AR = "ar";
  char *ARFLAGS = "-rcs";

  char CFILES[STRING_MAX][FILE_NUM], OBJ[STRING_MAX];
  DIR *dptr;
  struct dirent *eptr;
  int i = 0, j;
  if (NULL == (dptr = opendir(SRC))) {
    fprintf(stderr, "read directory %s error!\n", SRC);
    exit(-1);
  }
  while (NULL != (eptr = readdir(dptr))) {
    char *file = eptr->d_name;
    for (; CSTR_END != *file; file++) {
    }
    if (('c' == *(--file)) && ('.' == *(--file))) {
      sprintf(CFILES[i++], "%s/%s", SRC, eptr->d_name);
    }
  }
  closedir(dptr);

  char CMD[CMD_MAX], BUFFER[CMD_MAX];
  if (argc == 1) {
    mkdir(LIB, S_IRWXU);
    sprintf(BUFFER, "%s %s -I%s", CC, CFLAGS, INC);
    for (j = 0; j < i; j++) {
      char *tCFILE = CFILES[j], *tOBJ = OBJ;
      for (; CSTR_END != *tCFILE; tCFILE++, tOBJ++) {
        *tOBJ = *tCFILE;
      }
      *tOBJ = CSTR_END;
      *(--tOBJ) = 'o';
      sprintf(CMD, "%s -c %s -o %s\n", BUFFER, CFILES[j], OBJ);
      fprintf(stdout, CMD);
      system(CMD);
    }
    fprintf(stdout, "compile %s\n", LIBSHARED);
    // ${CC} ${CSFLAGS} -o ${LIBSHARED} ${SRC}/*.o
    fprintf(stdout, "compile %s\n", LIBSTATIC);
    // ${AR} ${ARFLAGS} ${LIBSTATIC} ${SRC}/*.o
  } else if (0 == strcmp("test", argv[1])) {

  } else if (0 == strcmp("clean", argv[1])) {
    // sprintf(BUFFER, "%s %s", RM, RMFLAGS);
    for (j = 0; j < i; j++) {
      char *tCFILE = CFILES[j], *tOBJ = OBJ;
      for (; CSTR_END != *tCFILE; tCFILE++, tOBJ++) {
        *tOBJ = *tCFILE;
      }
      *tOBJ = CSTR_END;
      *(--tOBJ) = 'o';
      fprintf(stdout, "clean %s\n", OBJ);
      remove(OBJ);
    }
    fprintf(stdout, "clean %s\n", LIBSTATIC);
    remove(LIBSTATIC);
    fprintf(stdout, "clean %s\n", LIBSHARED);
    remove(LIBSHARED);
    fprintf(stdout, "clean %s\n", TSTTARGET);
    remove(TSTTARGET);
  } else if (0 == strcmp("distclean", argv[1])) {
    // sprintf(BUFFER, "%s %s", RMDIR, RMDIRFLAGS);
    for (j = 0; j < i; j++) {
      char *tCFILE = CFILES[j], *tOBJ = OBJ;
      for (; CSTR_END != *tCFILE; tCFILE++, tOBJ++) {
        *tOBJ = *tCFILE;
      }
      *tOBJ = CSTR_END;
      *(--tOBJ) = 'o';
      fprintf(stdout, "clean %s\n", OBJ);
      remove(OBJ);
    }
    fprintf(stdout, "clean %s\n", LIBSTATIC);
    remove(LIBSTATIC);
    fprintf(stdout, "clean %s\n", LIBSHARED);
    remove(LIBSHARED);
    fprintf(stdout, "clean %s", LIB);
    rmdir(LIB);
    fprintf(stdout, "clean %s\n", TSTTARGET);
    remove(TSTTARGET);
  } else if (0 == strcmp("help", argv[1])) {
    fprintf(stdout, "%s    <target>\n", argv[0]);
    fprintf(stdout, "<target>: \n");
    fprintf(stdout, "                    compile cgraph\n");
    fprintf(stdout, "          test      test cgraph\n");
    fprintf(stdout, "          clean     clean all the generated files\n");
    fprintf(stdout, "          distclean clean all the generated files and "
                    "directories\n");
    fprintf(stdout, "          help      commands to this program\n");
  } else {
    fprintf(stdout, "%s is an unsupported command\n", argv[1]);
    fprintf(stdout, "use \"%s help\" to know all supported commands\n",
            argv[0]);
  }

  return 0;
}
