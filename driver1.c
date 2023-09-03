/*
 * File: driver1.c
 * YOUR NAME ... YOU NEED TO IMPLEMENT THE main() + additional functions if needed
 *
 * ....
 */

#include <stdio.h>
#include <stdlib.h>
#include "mylinkedlist.h"

void printNumberOfStudents(linked_list_T *list);
void createStudent(linked_list_T *list);
void removeStudent(linked_list_T *list);
// this prints the student it's given
void printStudent(student_cell_T *student);
// this one asks you which student to print from the list
void printStudentFromList(linked_list_T *list);
void printAllStudents(linked_list_T *list);
void printGPAs(linked_list_T *list);

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

  // char *name;

  // printf("Enter a name to test your ReadLine function  : ");
  // name = ReadLine();
  // printf("User entered : %s \n", name);
  // free(name);
  int userInput;
  linked_list_T *list = NewLinkedList();
  Enlist(list, NewStudentCell(1, 1, "one"));
  Enlist(list, NewStudentCell(2, 2, "two"));
  Enlist(list, NewStudentCell(3, 3, "three"));
  Enlist(list, NewStudentCell(4, 4, "four"));
  Enlist(list, NewStudentCell(5, 5, "five"));

  printf("\n1 - Create a new student cell with given id, gpa, name info, and add (Enlist) it to the end of the linked list. \
\n2 - Remove (Delist) the first student from linked list and print his/her id, gpa, name info\
\n3 - Print the number of students in the linked list (Length)\
\n4 - Print (id, gpa, name) of a student at a specific index (head of the list is defined as index 0)\
\n5 - Print the list of all students in the linked list. Print (id, gpa, name) of every student\
\n6 - Print the min, average, max GPAs in the linked list\
\n7 - Remove the student with highest GPA and print his/her info (if there are ties, just take the first one you found)\
\n8 - Exit\n");
  while (1)
  {
    printf("---------------------\n");
    printf("Choose from 1-8:\n");
    char *userInputStr = ReadLine();
    sscanf(userInputStr, "%i", &userInput);
    // userInput = 1;

    if (userInput == 1)
    {
      createStudent(list);
    }
    if (userInput == 2)
    {
      removeStudent(list);
    }
    if (userInput == 3)
    {
      printNumberOfStudents(list);
    }
    if (userInput == 4)
    {
      printStudentFromList(list);
    }
    if (userInput == 5)
    {
      printAllStudents(list);
    }
    if (userInput == 6)
    {
      printGPAs(list);
    }
    if (userInput == 7)
    {
      // removeHighestGPA(list);
    }

    if (userInput == 8)
    {
      return 0;
    }
  }

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

  // YOU NEED TO DELETE ABOVE 3 LINES, and IMPLEMENT THIS as described above

  /* Hint: initially dynamically allocate an array of char with size 10. */
  char *buff = malloc(10);
  if (buff == NULL)
  {
    free(buff);
    return NULL;
  }

  int initialSize = 10;
  for (int i = 0; i <= initialSize; i++)
  {
    char c = getchar();

    if (c != '\n')
    {
      // printf("%i, \n", i);
      /* However, if you DO NOT see '\n' char after 10th character*/
      if (i == initialSize)
      {
        /* resize your original array and double its size*/
        initialSize = initialSize * 2;
        // printf("double buffer size realloc: dooubling to %i\n", initialSize);
        realloc(buff, initialSize);
        if (buff == NULL)
        {
          free(buff);
          return NULL;
        }
      }
      /* and continue reading data character by character as in the first step...*/
      buff[i] = c;
    }
    else
    {
      /* If you see '\n' char before reading 10th character, you are done. And you know the
       * exact length of the input string */
      buff[i] = '\0';

      /*
       * So, accordingly allocate enough space and copy the
       * data into new char array, insert '\0' instead of '\n' */
      if (i < initialSize)
      {
        // printf("reduce size realloc: reducing size to: %i\n", i);
        realloc(buff, i);
        if (buff == NULL)
        {
          free(buff);
          return NULL;
        }
      }
      /* and free the original array.
       *
       * Then return the new string.
       */
      return buff;
    }
  }

  /*
   * Also please check for possible errors (e.g., no memory etc.) and appropriately handle
   * them. For example, if malloc returns NULL, free partially allocated space and return
   * NULL from this function. The program calling this function may take other actions,
   * e.g., stop the program!
   */

  return buff; // if there is any error!
}

void printNumberOfStudents(linked_list_T *list)
{
  printf("you have %i students on the list\n", LinkedListLength(list));
}

void createStudent(linked_list_T *list)
{

  printf("Enter new student's name\n");
  char *name = ReadLine();
  printf("Enter new student's gpa\n");
  char *gpa = ReadLine();
  printf("Enter new student's id\n");
  char *id = ReadLine();

  int idInt;
  sscanf(id, "%i", &idInt);
  double gpaDouble;
  sscanf(gpa, "%lf", &gpaDouble);

  printf("creating new student:\n");
  printf("%s/%i/%.1lf\n", name, idInt, gpaDouble);

  Enlist(list, NewStudentCell(idInt, gpaDouble, name));
}

void removeStudent(linked_list_T *list)
{
  if (LinkedListIsEmpty(list))
  {
    printf("List is empty, nothing to remove!\n");
  }
  else
  {
    printf("Removing latest student entry\n");
    student_cell_T *removed = Delist(list);
    printStudent(removed);
    free(removed);
  }
}

void printStudent(student_cell_T *student)
{
  printf("%s/%i/%.1lf\n", student->name, student->id, student->gpa);
}

void printStudentFromList(linked_list_T *list)
{
  printf("Enter student's index\n");
  char *indexStr = ReadLine();

  int index;
  sscanf(indexStr, "%i", &index);

  printf("Finding student with index: %i\n", index);

  student_cell_T *student = GetLinkedListElement(list, index);
  printStudent(student);
}

void printAllStudents(linked_list_T *list)
{
  printf("Printing all students\n");
  int length = LinkedListLength(list);
  for (int i = 1; i <= length; i++)
  {
    printStudent(GetLinkedListElement(list, i));
  }
}

void printGPAs(linked_list_T *list)
{
  printf("Getting min, max, and avg GPA\n");
  double min = 4, max = 0, avg = 0;
  int length = LinkedListLength(list);
  for (int i = 1; i <= length; i++)
  {
    // is new max?
    int gpa = GetLinkedListElement(list, i)->gpa;
    if (gpa > max)
    {
      max = gpa;
    }
    // is new min?
    if (gpa < min)
    {
      min = gpa;
    }
    // add to average count
    avg = avg + gpa;
  }
  avg = avg / length;

  printf("Minimum GPA: %.1lf\n", min);
  printf("Maximum GPA: %.1lf\n", max);
  printf("Average GPA: %.1lf\n", avg);
}