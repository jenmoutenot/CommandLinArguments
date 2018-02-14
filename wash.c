#include "stdio.h"
// This is my code
// Jen Moutenot
// CS366

/* push.c */

#include <stdio.h>

const int BUF_SIZE = 512;

int main(int argc, char *argv[])
{
  for(argv++; *argv != NULL; )
  {
    char command[BUF_SIZE];
    printf("\nfor the file ``%s'': please enter a command command: ", *argv);
    fgets(command, BUF_SIZE, stdin);
    printf("File name is %s and the command you entered starts with a %c\n", *argv, *command);
    argv++;
  }

  return 0;
}

