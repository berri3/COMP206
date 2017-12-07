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

		//check if it is our turn
		if(turn != '1'){
			fclose(turnFile);
			continue;
		}
		
		//fclose(turnFile);

		
		dataFile = fopen("DATA.txt", "rt");
	
		dataChar = fgetc(dataFile);
		
		//check if it is our custom end of file character
		if (dataChar == '~') {
			fclose(dataFile);
			fclose(turnFile);
			break;	//terminate if it is
		}
		//print characters on the screen
		else if (dataChar > 0) {
			printf("%c", dataChar);
		}
				
	
		//set the turn to 0 to let the producer do its job
		while ((turnFile = fopen("TURN.txt", "wt")) == NULL);
		fputc('0', turnFile);


		//close the files
		fclose(turnFile);
		fclose(dataFile);


	}

}

