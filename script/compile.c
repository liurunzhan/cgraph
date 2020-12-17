#!/usr/bin/tcc -run

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define STRING_MAX 4096

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
  strcpy(CFLAGS, "-pedantic -Wall -fPIC -std=c89");

  char *mode = "debug";
  if (mode == "debug")
  { strcat(CFLAGS, " -g -DDEBUG"); }
  else if (mode == "release")
  { strcat(CFLAGS, " -static -O2"); }
  
  char *AR = "ar";
  char *ARFLAGS = "-rcs";
  DIR *dptr;
  struct dirent *eptr;
  if(NULL == (dptr = opendir(SRC)))
  {
    fprintf(stderr, "read directory %s error!\n", SRC);
    exit(-1);
  }
  
  while(NULL != (eptr = readdir(dptr)))
  {
    printf("%s\n", eptr->d_name);
  }
  closedir(dptr);

  if(argc == 1)
  {
    
  }
  else if(0 == strcmp("test", argv[1]))
  {

  }
  else if(0 == strcmp("clean", argv[1]))
  {
    
  }
  else if(0 == strcmp("distclean", argv[1]))
  {
    
  }
  else if(0 == strcmp("help", argv[1]))
  {
    fprintf(stdout, "%s    <target>\n", argv[0]);
    fprintf(stdout, "<target>: \n");
    fprintf(stdout, "                    compile cgraph\n");
    fprintf(stdout, "          test      test cgraph\n");
    fprintf(stdout, "          clean     clean all the generated files\n");
    fprintf(stdout, "          distclean clean all the generated files and directories\n");
    fprintf(stdout, "          help      commands to this program\n");
  }
  else
  {
    fprintf(stdout, "%s is an unsupported command\n", argv[1]);
    fprintf(stdout, "use \"%s help\" to know all supported commands\n", argv[0]);
  }
  
  return 0;
}