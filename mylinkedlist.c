/*
 * File: mylinkedlist.c
 * Zoe Rodriguez ...
 * YOU NEED TO IMPLEMENT THE FUNCTIONS  here
 * ....
 */

#include <stdio.h>
#include <stdlib.h>
#include "mylinkedlist.h"

int countNodesRecursive(student_cell_T *student, int length);
student_cell_T *getNodesRecursive(student_cell_T *student, int index, int desiredIndex);

/*
 * Function: NewStudentCell
 * Usage: student_cell_T *element;
 *        element = NewStudentCell(int id, double gpa, char *name);
 * --------------------------
 * This function allocates space for a student cell and intilize its fileds
 */
student_cell_T *NewStudentCell(int id, double gpa, char *name)
{
  student_cell_T *element;

  element = (student_cell_T *)malloc(sizeof(student_cell_T));
  if (!element)
  {
    fprintf(stderr, "NewStudentCell cannot allocate memory\n");
    return NULL;
  }
  element->id = id;
  element->gpa = gpa;
  element->name = name;

  return element;
}

/*
 * Function: NewLinkedList
 * Usage: linked_list_T *list;
 *        list = NewLinkedList();
 * --------------------------
 * This function allocates and returns an empty linked list.
 */
linked_list_T *NewLinkedList(void)
{
  linked_list_T *list;

  list = (linked_list_T *)malloc(sizeof(linked_list_T));
  if (!list)
  {
    fprintf(stderr, "NewLinkedList cannot allocate memory\n");
    return NULL;
  }

  list->head = NULL;
  list->tail = NULL;

  return list;
}

/*
 * Function: FreeLinkedList
 * Usage: FreeLinkedList(list);
 * ------------------------
 * This function frees the storage associated with list.
 */
void FreeLinkedList(linked_list_T *list)
{
  int length = LinkedListLength(list);
  for (int i = 1; i <= length; i++)
  {
    free(GetLinkedListElement(list, i));
  }
  free(list);
}

/*
 * Function: Enlist
 * Usage: Enlist(list, element);
 * -------------------------------
 * This function adds a student cell pointed by element to the end of the list.
 */
void Enlist(linked_list_T *list, student_cell_T *element)
{
  // get the first person from the list
  // store it in the new node as their next
  if (!LinkedListIsEmpty(list))
  {
    element->next = list->head;
  }
  // modify list to point to new first node
  list->head = element;
}

/*
 * Function: Delist
 * Usage: element = Delist(list);
 * --------------------------------
 * This function removes the student cell at the head of the list
 * and returns its address to the caller (client).  If the list is empty, Delist
 * prints an Error with an appropriate message and returns NULL.
 */
student_cell_T *Delist(linked_list_T *list)
{
  student_cell_T *element = list->head;
  // from the line, get the original head
  // get that first person's next
  // set that "first person's next" to the head of the list object
  list->head = element->next;
  // return the original head
  return element;
}

/*
 * Functions: LinkedListIsEmpty, LinkedListIsFull
 * Usage: if (LinkedListIsEmpty(list)) . . .
 *        if (LinkedListIsFull(list)) . . .
 * -------------------------------------
 * These functions test whether the list is empty or full.
 */
int LinkedListIsEmpty(linked_list_T *list)
{
  // if the list object has no tail (or no head, really),
  // it must be empty
  if (list->head == NULL)
  {
    return 1;
  }

  return 0;
}

int LinkedListIsFull(linked_list_T *list)
{
  // if the list has a tail or a head?
  if (list->head != NULL)
  {
    return 1;
  }

  return 0;
}

/*
 * Function: LinkedListLength
 * Usage: n = LinkedListLength(list);
 * ------------------------------
 * This function returns the number of elements in the list.
 */
int LinkedListLength(linked_list_T *list)
{
  if (LinkedListIsEmpty(list))
  {
    return 0;
  }

  int initial = 1;
  // recursively traverse each node's next, adding 1 every time you recurse
  // when you run into a node that equals the tail (or that node has no next)
  // break recursion

  return countNodesRecursive(list->head, initial);
}

/*
 * Function: GetLinkedListElement
 * Usage: element = GetLinkedListElement(list, index);
 * -----------------------------------------------
 * This function returns the element at the specified index in the
 * list, where the head of the list is defined as index 0. For
 * example, calling GetLinkedListElement(list, 0) returns the initial
 * element from the list without removing it.  If the caller tries
 * to select an element that is out of range, GetLinkedListElement prints
 * Error and returns NULL.  Note: This function is not a fundamental list operation
 * and is instead provided mainly to facilitate debugging.
 */
student_cell_T *GetLinkedListElement(linked_list_T *list, int index)
{
  int target = 1;
  // recursively traverse each node's next, adding 1 every time you recurse
  // when you run into a node, and how many nodes you've traversed equals the index,
  // break recursion
  return getNodesRecursive(list->head, target, index);
}

/* OTHER FUNCTIONS YOU WOULD NEED....
 * EXPORT THEM HERE, BUT IMPLMENT THEM in mylinkedlist.c
 */

int countNodesRecursive(student_cell_T *student, int length)
{
  if (student->next == NULL)
  {
    return length;
  }

  return countNodesRecursive(student->next, length + 1);
}

student_cell_T *getNodesRecursive(student_cell_T *student, int index, int desiredIndex)
{

  if (index == desiredIndex)
  {
    return student;
  }

  return getNodesRecursive(student->next, index + 1, desiredIndex);
}

void removeAtIndex(linked_list_T *list, int index)
{
  student_cell_T *before = GetLinkedListElement(list, index - 1);
  student_cell_T *student = GetLinkedListElement(list, index);
  student_cell_T *after = GetLinkedListElement(list, index + 1);
  before->next = after;

  printf("%s/%i/%.1lf\n", student->name, student->id, student->gpa);
}