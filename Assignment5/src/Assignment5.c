/*
 ============================================================================
 Name        : Assignment5
 Author      : Chun Ming Liang
 Student ID	 : 260744492
 Description : Stores all user input in stack implemented using linked-list, pops and prints everything
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//constant
#define ARRAY_LENGTH 1000

//global variable
extern struct NODE *head;

//function prototypes

int main(void){

	//initializing variables
	char inputNumber[ARRAY_LENGTH];
	int number;

	//initialize a new list
	newList();

	//getting user input
	//do-while loop to check if the entered number is positive
	do {

		//print prompt for number
		printf("Please enter a number: ");
		fflush(stdout);

		//waits for user input; store it in temporary inputNumber variable
		fgets(inputNumber, (ARRAY_LENGTH - 1), stdin);

		//convert the inputNumber into an integer, store it in the appropriate variable
		number = atoi(inputNumber);

		//store the number in a stack, implemented using a linked list
		addNode(number);

	} while (number > 0); //NOTE: assuming 0 is not considered a positive integers, as per assignment instructions

	//do-while loop is done since user entered a negative number

	//print all the elements in the linked-list (i.e. pop all the elements in the stack)
	prettyPrint();

	return 0;
}
