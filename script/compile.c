#!/usr/bin/tcc - run

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_MAX 1024
#define CMD_MAX    81960
#define FILE_NUM   100
#define STRING_END '\0'

extern char **environ;

int main(int argc, char *argv[])
{
    char *PRO = "cgraph";
    char *_DIR = ".";
    char INC[STRING_MAX], SRC[STRING_MAX], TST[STRING_MAX], LIB[STRING_MAX];

    sprintf(INC, "%s/%s", _DIR, "include");
    sprintf(SRC, "%s/%s", _DIR, "src");
    sprintf(TST, "%s/%s", _DIR, "test");
    sprintf(LIB, "%s/%s", _DIR, "lib");

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

    // build and clean directories and files
    char *MKDIR = "mkdir";
    char *RM = "rm";
    char *RMFLAGS = "-rf";

    char *RMDIR = "rm";
    char *RMDIRFLAGS = "-rf";

    char *AR = "ar";
    char *ARFLAGS = "-rcs";

    char **env = environ;
    char *path = "PATH";
    for (; NULL != *env; env++) {
        char *senv = *env, *tpath = path;
        for (; STRING_END != *tpath; tpath++, senv++) {
            if (*tpath != *senv) {
                break;
            }
        }
        if (STRING_END == *tpath) {
            fprintf(stdout, "%s\n", *env);
        }
    }

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
        for (; STRING_END != *file; file++) {
        }
        if (('c' == *(--file)) && ('.' == *(--file))) {
            sprintf(CFILES[i++], "%s/%s", SRC, eptr->d_name);
        }
    }
    closedir(dptr);

    char CMD[CMD_MAX], BUFFER[CMD_MAX];
    if (argc == 1) {
        sprintf(BUFFER, "%s %s -I%s", CC, CFLAGS, INC);
        for (j = 0; j < i; j++) {
            char *tCFILE = CFILES[j], *tOBJ = OBJ;
            for (; STRING_END != *tCFILE; tCFILE++, tOBJ++) {
                *tOBJ = *tCFILE;
            }
            *tOBJ = STRING_END;
            *(--tOBJ) = 'o';
            sprintf(CMD, "%s -c %s -o %s\n", BUFFER, CFILES[j], OBJ);
            fprintf(stdout, CMD);
            sysetem(CMD);
        }
        // fprintf(stdout, "compile %s\n", LIBSHARED);
        // ${CC} ${CSFLAGS} -o ${LIBSHARED} ${SRC}/*.o
        // fprintf(stdout, "compile %s\n", LIBSTATIC);
        // ${AR} ${ARFLAGS} ${LIBSTATIC} ${SRC}/*.o
    } else if (0 == strcmp("test", argv[1])) {

    } else if (0 == strcmp("clean", argv[1])) {
        sprintf(BUFFER, "%s %s", RM, RMFLAGS);
        for (j = 0; j < i; j++) {
            char *tCFILE = CFILES[j], *tOBJ = OBJ;
            for (; STRING_END != *tCFILE; tCFILE++, tOBJ++) {
                *tOBJ = *tCFILE;
            }
            *tOBJ = STRING_END;
            *(--tOBJ) = 'o';
            sprintf(CMD, "%s %s\n", BUFFER, OBJ);
            fprintf(stdout, "clean %s\n", OBJ);
            system(CMD);
        }
    } else if (0 == strcmp("distclean", argv[1])) {
        sprintf(BUFFER, "%s %s", RMDIR, RMDIRFLAGS);
        for (j = 0; j < i; j++) {
            char *tCFILE = CFILES[j], *tOBJ = OBJ;
            for (; STRING_END != *tCFILE; tCFILE++, tOBJ++) {
                *tOBJ = *tCFILE;
            }
            *tOBJ = STRING_END;
            *(--tOBJ) = 'o';
            sprintf(CMD, "%s %s\n", BUFFER, OBJ);
            fprintf(stdout, "clean %s\n", OBJ);
            system(CMD);
        }
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