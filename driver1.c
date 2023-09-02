/*
 * File: driver1.c
 * YOUR NAME ... YOU NEED TO IMPLEMENT THE main() + additional functions if needed
 *
 * ....
 */

#include <stdio.h>
#include <stdlib.h>
#include "mylinkedlist.h"

/*
 * Function: ReadLine
 * Usage: s = ReadLine();
 * ---------------------
 * ReadLine reads a line of text from standard input and returns
 * the line as a string.  The newline '\n' character that terminates
 * the input is not stored as part of the string.
 */
char *ReadLine(void);

int main(int argc, char *arvg[])
{
  // YOU NEED TO IMPLEMENT THIS driver1.c USING FUNCTIONS FROM mylinkedlist.h
  // But before that, implement your ReadLine() function, and test it as shown below.
  // IF NEEDED, YOU CAN ALSO IMLEMENT YOUR OWN FUNCTIONS HERE

  char *name;

  printf("Enter a name to test your ReadLine function  : ");
  name = ReadLine();
  printf("User entered : %s \n", name);
  free(name);

  return 0;
}

/*
 * IMPLEMENTATION of ReadLine();
 * Function: ReadLine
 * Usage: s = ReadLine();
 * ---------------------
 * ReadLine reads a line of text from standard input and returns
 * the line as a string.  The newline '\n' character that terminates
 * the input is not stored as part of the string.
 *
 * In contrast to standard I/O functions (e.g., scanf with "%s", fgets)
 * that can read strings into a given static size buffer, ReadLine function
 * should read the given input line of characters terminated by a newline
 * character ('\n') into a dynamically allocated and resized buffer based on
 * the length of the given input line.
 *
 * When implementing this function you can use standard I/O functions.
 * We just want you to make sure you allocate enough space for the entered data.
 * So don't simply allocate 100 or 1000 bytes every time.
 * If the given input has 5 characters, you need to allocate space for 6 characters.
 */

char *ReadLine()
{
  // A SIMPLE WAY TO IMPLEMENT JUST TO TEST FOR NOW, BUT THIS IS NOT WHAT WE WANT!!!
  // char *buff = malloc(100);
  // scanf("%s", buff);
  // return buff;

  /* Hint: initially dynamically allocate an array of char with size 10. */
  char *buff = malloc(10);
  /* If you see '\n' char before reading 10th character, you are done. And you know the
   * exact length of the input string */

  int initialSize = 10;
  for (int i = 0; i < initialSize; i++)
  {
    char c = getchar();
    if(c != '\n'){
      buff[i] = c;
    } else {
      buff[i] = '\0';
      if (i < initialSize){
        realloc(buff, i);
      }
      return buff;
    }
  }
  
  /*
   * So, accordingly allocate enough space and copy the
   * data into new char array, insert '\0' instead of '\n' */



  /* and free the original array.
   *
   * Then return the new string.
   *
   * However, if you DO NOT see '\n' char after 10th character,
   *
   * resize your original array and double its size
   *
   * and continue reading data character by character as in the first step...
   *
   * Also please check for possible errors (e.g., no memory etc.) and appropriately handle
   * them. For example, if malloc returns NULL, free partially allocated space and return
   * NULL from this function. The program calling this function may take other actions,
   * e.g., stop the program!
   */

  // YOU NEED TO DELETE ABOVE 3 LINES, and IMPLEMENT THIS as described above

  return buff; // if there is any error!
}
