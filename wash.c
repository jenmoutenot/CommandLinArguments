#include "stdio.h"
#include "stdlib.h"

// This is my code
// Jen Moutenot
// CS366


const int BUF_SIZE = 512;
/*
void rename(const char *old, const char *new)
{
  gets_s(*old);
  printf("Enter new name for file: ");
  gets_s(*new);
  if (rename(*old, *new) == 0 )
  {
    printf("%s has been renamed %s.\n", *old, *new);
  }
   else 
  {
    printf("Error\n");
  }
}
*/
void cat(char *file)
{
  FILE *fp; //initialize file we are manipulating
  fp = fopen(file, "r"); //fp is the file pointer
  char c;  
  c = fgetc(fp);  
  while( c != EOF) //end of file
  {
     printf("%c", c); //printing the contents of the file
     c = fgetc(fp); 
  }
}



int main(int argc, char *argv[])
{
  if(argc <= 1) 
  {
    printf("Enter in the files\n");
    exit(-1); 
  }
  printf("\nEnter in one of the following commands:\n");
  printf(" ’c’ cat, list the current file to /dev/tty\n");
  printf(" ’d’ duplicate the current file (duplicate)\n");
  printf(" ’r’ rename the current file\n");
  printf(" ’u’ unlink the current file\n");
  printf(" ’t’ truncate the current file\n");
  printf(" ’a’ append the current file to another file\n");
  printf(" ’l’ last, display the last 100 bytes of the current file\n");
  printf(" ’m’ mode, change the current file’s access permissions\n");
  printf(" ’x’ change the current file’s access time to the current time \n");
  printf(" ’n’ next, goto the next file \n");
  printf(" ’q’ quit\n");
  
  for(argv++; *argv != NULL; )   //incrementing argv(the array of files) to go to the next file
  {
    char command[BUF_SIZE];
    printf("\nfile %s: command:", *argv);
    fgets(command, BUF_SIZE, stdin);

    switch (*command)
    {
      case 'c': cat(*argv); break;
      /*case 'd': duplicate(*argv); break;
      case 'r': rename(*argv); break;
      case 'u': unlink(*argv); break;
      case 't': truncate(*argv); break;
      case 'a': append(*argv); break;
      case 'l': last(*argv); break;
      case 'm': mode(*argv); break;
      case 'x': time(*argv); break; */
      case 'n': argv++; break; 		//incrementing to the next file
      case 'q': return 0; break; 
    }
  }  

  return 1; //returning off of 'n' to quit
  
}
