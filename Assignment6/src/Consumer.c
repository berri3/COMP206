/*
 * Consumer.c
 *
 *  Created on: Dec 4, 2017
 *      Author: ChunMing
 */

#include <stdio.h>
#include <stdlib.h>

void consumer() {

	//variables
	FILE* dataFile;
	FILE* turnFile;
	char turn;
	char dataChar;

	while (1) {
		printf("Consuming. Aw yeah.\n");
		do {
			//wait for access to the turn file
			while ((turnFile = fopen("TURN.txt", "r+")));

			//yay, now we have access! Let's check if it is actually our turn:
			turn = fgetc(turnFile);


		} while (!turn); //while it is the producer's turn... try again next time

		//now we're sure it's our turn. We can try to read from the data file

		//open the data file, wait till we have access:
		while ((dataFile = fopen("DATA.txt", "rt")));
		//now we can get the (supposedly) only character in the file
		dataChar = fgetc(dataFile);

		//close the data file
		fclose(dataFile);

		//gotta display this character on the screen
		putchar(dataChar);

		//change the turn number in the turn file to the producer's turn (0)
		putc('0', turnFile);

		//close the turn file
		fclose(turnFile);


	}

}
