#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "sys/types.h"
#include "sys/stat.h"

// This is my code
// Jen Moutenot
// CS366

const int BUF_SIZE = 512;

/* purpose:
 * input:
 * returns:
*/
void mode(char *file)
{
  char mode[] = "0777";
  char buf[100] = "/home/hello.t";
  int i;
  i = strtol(mode, 0, 8);
  if (chmod(buf,i) < 0(
  {
    fprintf(stderr, "%s: error in chmod(%s, %s) - %d (%s)\n", argv[0], buf, mode, errno, strerror(errno));
    exit(1);
  }
  
}

/* purpose:
 * input:
 * returns:
*/
void append(char *file) 
{
  char c;
  char dest[BUF_SIZE];
  printf("Enter file you would like to append to: \n");
  scanf("%s", dest);
  FILE *fp1 = fopen(file, "r");
  FILE *fp2 = fopen(dest, "a");
  while ((c = getc(fp1))!= EOF)
  {
    putc(c, fp2);
  }  
}
/* purpose:
 * input:
 * returns:
*/
void duplicate(char *file)
{
  char c;
  char dest[BUF_SIZE];
  
  printf("Enter destination name: \n");
  scanf("%s", dest);
  FILE *fp1 = fopen(file, "r");
  FILE *fp2 = fopen(dest, "w");
  while ((c = getc(fp1))!= EOF)
  {
    putc(c, fp2);
  }
}

/* purpose:
 * input:
 * returns:
*/
void rename_file(char *file_old)
{
  char file_new[BUF_SIZE]; //technically a pointer
  
  printf("Enter new name for file: \n");
  scanf("%s", file_new);
  if (rename(file_old, file_new) == 0 ) //file_old is still a pointer, was not dereferenced
  {
    printf("%s has been renamed %s.\n", file_old, file_new); //passing through strings
  }
    else 
  {
    printf("Error\n");
  }
}

/* purpose:
 * input:
 * returns:
*/
void cat(char *file)
{
  FILE *fp; //initialize file we are manipulating
  fp = fopen(file, "r"); //fp is the file pointer
  char c;  
  c = fgetc(fp);  
  while(c != EOF) //end of file
  {
     printf("%c", c); //printing the contents of the file
     c = fgetc(fp); 
  }
}

/* purpose:
 * input:
 * returns:
*/

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
      case 'd': duplicate(*argv); break;
      case 'r': rename_file(*argv); break;
      case 'u': unlink(*argv); break;
      case 't': truncate(*argv, 0); break;
      case 'a': append(*argv); break;
   /*  
      case 'l': last(*argv); break;
   */
      case 'm': mode(*argv); break;
   /*
      case 'x': time(*argv); break;
    */
      case 'n': argv++; break; 		//incrementing to the next file
      case 'q': return 0; break; 
    }
  }  

  return 1; //returning off of 'n' to quit
  
}
