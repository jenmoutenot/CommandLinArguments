#include "stdio.h"

// This is my code
// Jen Moutenot
// CS366


const int BUF_SIZE = 512;

int main(int argc, char *argv[])
{
  for(argv++; *argv != NULL; )
  {
    char command[BUF_SIZE];
    printf("\nfile %s: command:", *argv);
    fgets(command, BUF_SIZE, stdin);

    switch (*command)
    {
      case 'c': cat(*argv); break;
...
    }
  }

  return 0;
}
