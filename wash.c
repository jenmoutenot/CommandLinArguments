#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "sys/types.h"
#include "sys/stat.h"
#include "utime.h"
#include "sys/time.h"

// This is my code
// Jen Moutenot
// CS366

const int BUF_SIZE = 512;

/* purpose: to change the current file's access mode
 * input: the current file
 * returns: nothing
*/
void mode(char *file)
{ 
  printf("Enter access mode: \n"); //can read write...etc
  int new_mode;  
  scanf("%d", &new_mode);  // scanning the user's input
  chmod(file, new_mode);   // change access mode for user
}

/* purpose: to display the last 100 bytes of the current file
 * input: the current file
 * returns: outputs last 100 bytes
*/
void last(char *file)
{
  char c;
  FILE *fp = fopen(file, "r");
  if ( file == NULL)
    perror("fopen");
    return -1;
  if (fseek(file, -TAIL_LENGTH, SEEK_END) < 0  && fseek(file, 0, SEEK_SET) < 0)
    perror("fseek");
    fclose(file);
    return -1;
  if (fopen("dev/tty", "w")
    perror("dev/tty")
    return -1;
  else 
  {
    fseek(fp, SEEK_END - 100, SEEK_END);  //sets the file position to the given offset
    c = fgetc(fp);
    while (c != EOF)
    { 
      printf("%c \n", c);
      c = fgetc(fp);
    }
  }
  fclose(file);
}

/* purpose: to change the file's access time to the current time
 * input: the current file
 * returns: outputs new access time (current time)
*/
void time(char *file)
{
  int n_time;
  struct utimbuf ubuf; //creating struct to hold the access time
  printf("Enter new access time: ");
  scanf("%d", &n_time);
  ubuf.actime = n_time;  //actual time
  ubuf.modtime = n_time; // mofified time
  utime(file, &ubuf);  //utilizing utime function to change access, mod times
  
}

/* purpose: to append the current file to another file
 * input: the current file
 * returns: nothing
*/
void append(char *file) 
{
  char c;
  char dest[BUF_SIZE]; 
  printf("Enter file destination you would like to append to: \n");
  scanf("%s", dest); //scanning the user's input
  FILE *fp1 = fopen(file, "r"); //reading the current file
  FILE *fp2 = fopen(dest, "a"); //appending into the destination
  if (file == NULL)
    perror("Can't open the file");
  if (dest == NULL)
    perror("Can't open the file");
  while ((c = getc(fp1))!= EOF)
  {
    putc(c, fp2);
  }
  fclose(fp1);
  fclose(fp2);  
}
/* purpose: to duplicate the current file, which creates a copy of the file
 * input: the current file
 * returns: nothing
*/
void duplicate(char *file)
{
  char c;
  char dest[BUF_SIZE];
  
  printf("Enter destination name: \n");
  scanf("%s", dest); //scanning the user's input
  FILE *fp1 = fopen(file, "r");  //reading the current file
  FILE *fp2 = fopen(dest, "w");  //writing the copy into the file destination
  if (file == NULL)
    perror("Can't open the file");
  if (dest == NULL)
    perror("Can't open the file");
  while ((c = getc(fp1))!= EOF)  // copy the contents until you get to eof
  {
    putc(c, fp2); //put the contents inside the new file
  }
  fclose(fp1);
  fclose(fp2);
}

/* purpose: to rename the current file
 * input: the current file
 * returns: nothing
*/
void rename_file(char *file_old)
{
  printf("Enter new name for file: \n");
  char file_new[BUF_SIZE]; //technically a pointer
  scanf("%s", file_new);  //scanning the user's input
  if (rename(file_old, file_new) == 0 ) //file_old is still a pointer
  {
    printf("%s has been renamed %s.\n", file_old, file_new); //passing through strings
  }
    else 
  {
    perror("Error\n");
  }
}

/* purpose: to list the current file contents to /dev/tty
 * input: the current file
 * returns: the contents of the file
*/
void cat(char *file)
{
  FILE *fp; //initialize file we are manipulating
  fp = fopen(file, "r"); //fp is the file pointer
  if (file == NULL)
    perror("Can't open the file");
  char c;  
  c = fgetc(fp);  
  while(c != EOF) //end of file
  {
     printf("%c", c); //printing the contents of the file
     c = fgetc(fp); 
  }
  fclose(fp);
}

/* purpose: to clean up and organize Mr. Krabs' files using the program wash
 * input: an array of files
 * returns: the file name, and asks for a command
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
  
  for(argv++; *argv != NULL; )   //incrementing argv(the array of files)
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
      case 't': truncate(*argv, 0); break;  //truncating, making the contents 0
      case 'a': append(*argv); break;
      case 'l': last(*argv); break;
      case 'm': mode(*argv); break;
      case 'x': time(*argv); break;
      case 'n': argv++; break;         //incrementing to the next file
      case 'q': return 0; break;       // quitting the program by returning 0
    }
  }  
  return 1; //returning off of 'n' to quit
}
