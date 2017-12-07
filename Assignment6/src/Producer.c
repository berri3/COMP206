/*
 * producer.c
 *
 *  Created on: Dec 4, 2017
 *      Author: VictorVuong
 */

#include <stdio.h>
#include <stdlib.h>


void producer() {

	//variable declarations
	char c;			//char for the character that we get from the file
	char checkTurn;		//char to check if it is our turn
	FILE *MYDATA;		//file pointer to mydata
	FILE *TURN;		//file pointer to the turn file
	FILE *DATA;		//file pointer to the shared data
	
	//open mydata file and check if there is any error
	if ((MYDATA = fopen("mydata.txt", "rt")) == NULL) {
		printf("Producer could not open data file.\n");
		exit(1);
	}
	
	//do the job until end of mydata file
	while(!feof(MYDATA)) {
		
		//try to open the turn file until you are able to
		while ((TURN = fopen("TURN.txt", "rt")) == NULL); //do nothing
		
		//checking if it is the producer's turn
		checkTurn = fgetc(TURN);
		fclose(TURN);
		if(checkTurn != '0') {
			continue; //skip the rest of the while loop
		}
		
		//get on character from mydata file
		c = fgetc(MYDATA);
		
		//try until able to open and put the char in the file
		DATA = fopen("DATA.txt", "wt");
		fputc(c, DATA);
		fclose(DATA);
		
		//update the turn to let the consumer a chance to do its job
		while ((TURN = fopen("TURN.txt", "wt")) == NULL); //do nothing
		fputc('1', TURN);
		fclose(TURN);
	}

	//no more reading from original data file: close it
	fclose(MYDATA);

	//when job is done, add a ~ to let the consumer know that it is the end of file
	while((DATA = fopen("DATA.txt", "wt")) == NULL);
	fputc('\0', DATA);
	fclose(DATA);

	//update the turn back to the consumer's number
	while((TURN = fopen("TURN.txt", "wt")) == NULL);
	fputc('1', TURN);
	fclose(TURN);
	
}

