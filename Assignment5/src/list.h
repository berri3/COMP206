/*
 * list.h
 *
 *  Created on: Nov 20, 2017
 *      Author: Chun Ming Liang
 */

#ifndef LIST_H_
#define LIST_H_

//defining a stack using a linked list, as a struct
struct NODE {
	int number; //since the stack can only contain operators.
	struct NODE *pointerNext;
};

//function prototypes
void newList();
int addNode(int value);
void prettyPrint();
int pop();

#endif /* LIST_H_ */
