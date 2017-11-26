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
#include "list.h"

//constant
#define ARRAY_LENGTH 1000

//global variable
extern struct NODE *head;

int main(void){

	//initializing variables
	char inputNumber[ARRAY_LENGTH];
	int number;

	//initialize a new list
	newList();

	//getting user input
	while(1){

		//print prompt for number
		printf("Please enter a number: ");
		fflush(stdout);

		//waits for user input; store it in temporary inputNumber variable
		fgets(inputNumber, (ARRAY_LENGTH - 1), stdin);

		//convert the inputNumber into an integer, store it in the appropriate variable
		if(!(number = atoi(inputNumber))){
			//if atoi failed or user entered zero (which is still not a valid number)
			printf("You entered '0' or a not-so-legit 'number'. Please try again kthxbye.\n");
			continue; //asked for valid input again
		}
		else if(number < 0){ //user entered a negative number
			printf("You have entered a negative number. Let's print out all the numbers!\n");
			//gtfo
			break;
		}

		//store the number in a stack, implemented using a linked list
		if(!addNode(number)){ //if malloc failed
			printf("uh oh no more memory :(\n");
			exit(1); //byebye
		}

	}//NOTE: assuming 0 is not considered a positive integers, as per assignment instructions

	//do-while loop is done since user entered a negative number

	//print all the elements in the linked-list (i.e. pop all the elements in the stack)
	prettyPrint();

	return 0;
}
