/*
 * list.c
 *
 *  Created on: Nov 20, 2017
 *      Author: Chun Ming
 */

//includes
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

//defining boolean
#define TRUE 1
#define FALSE 0

//private global linked-list pointer
//i.e. the top of the stack
struct NODE* head;

//simply initializes the global pointer of the beginning of the linked list to NULL
void newList() {
	head = NULL;
}

int addNode(int value) {
	//allocate new node
	struct NODE *newNode = (struct NODE*) malloc(sizeof(struct NODE));
	if (newNode == NULL) { //if the malloc failed for some reason
		return FALSE;
	}
	//puts the current address of the top of the stack into pnext.
	newNode->pointerNext = head;
	//assign the operator passed as argument
	//in the function call to the operator member of the struct.
	newNode->number = value;
	head = newNode; //changes address of the top of the stack to the address of the new node.
	return TRUE;
}

//calls the pop function to pop the element at the top of the stack
//then prints that element to STDIN
void prettyPrint() {
	int aNumber;

	while ((aNumber = pop())) { //while there is stuff left in the linked list
		//print that integer
		printf("%d\n", aNumber);
	}
	printf("That's it! All the integers, if any, are all printed!\n");
}

//pops the top element of the stack, implemented using a linked-list
//returns the value popped for success and 0 in case of failure
//(since technically no number less than 1 is stored in the list
int pop() {
	if (head) { //if the address of the top of stack does not point to NULL.
		//assigns address of the current top of the stack to value.
		struct NODE *headPointer = head;
		//value takes the current number of the top of the stack.
		int value = head->number;
		//the top of the stack gets reassigned the address of the following node.
		head = headPointer->pointerNext;
		free(headPointer); //remove node from memory
		return value; //returns the value
	} else
		//empty stack
		return 0;
}
