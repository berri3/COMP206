/*
 * Consumer.c
 *
 *  Created on: Dec 4, 2017
 *      Author: ChunMing
 */



#include <stdio.h>
#include <stdlib.h>

void consumer() {

	//declare variables
	FILE* dataFile;
	FILE* turnFile;
	char turn;
	char dataChar;

	while (1) {

		//try until able to open
		while ((turnFile = fopen("TURN.txt", "rt")) == NULL);	//do nothing
		turn = fgetc(turnFile);
		fclose(turnFile);
		//check if it is our turn
		if(turn != '1'){
			continue;
		}
		
		//time to get the data from the producer
		dataFile = fopen("DATA.txt", "rt");
		dataChar = fgetc(dataFile);
		fclose(dataFile);

		//check if it is our custom end of file character
		if (dataChar == '\0') {
			break;	//terminate if it is
		}
		//print characters on the screen
		else if (dataChar > 0) { //make sure we only print good characters
			printf("%c", dataChar);
		}

		//set the turn to 0 to let the producer do its job
		while ((turnFile = fopen("TURN.txt", "wt")) == NULL);
		fputc('0', turnFile);
		fclose(turnFile);
	}
}

