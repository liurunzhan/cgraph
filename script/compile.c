#!/usr/bin/tcc -run

#include <stdio.h>
#include <string.h>

#define STRING_MAX 2048

int main(int argc, char *argv[])
{
  char *PRO = "cgraph";
  char *DIR = ".";
  char INC[STRING_MAX], SRC[STRING_MAX], TST[STRING_MAX], LIB[STRING_MAX];
  char CFLAGS[STRING_MAX];
  
  char *CC = "cc";
  char *CSFLAGS = "-shared";

  char *mode = "debug";
  strcpy(CFLAGS, "-pedantic -Wall -fPIC -std=c89");
  if (mode == "debug")
  { strcat(CFLAGS, " -g -DDEBUG"); }
  else if (mode == "release")
  { strcat(CFLAGS, " -static -O2"); }
  
  char *AR = "ar";
  char *ARFLAGS = "-rcs";

  if(argc == 1)
  {

  }
  else if(strcmp("test", argv[1]))
  {

  }
  else if(strcmp("clean", argv[1]))
  {
    
  }
  else if(strcmp("distclean", argv[1]))
  {
    
  }
  else if(strcmp("help", argv[1]))
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