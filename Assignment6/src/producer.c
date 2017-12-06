/*
 * producer.c
 *
 *  Created on: Dec 4, 2017
 *      Author: VictorVuong
 */

#include <stdio.h>
#include <stdlib.h>


void producer() {

	//variables
	char c;
	char checkTurn;
	FILE *MYDATA;
	FILE *TURN;
	FILE *DATA;

	//get data from mydata.txt
	if ((MYDATA = fopen("mydata.txt", "at")) == NULL) {
		printf("Producer could not open data file.\n");
		exit(1);
	}

	while (!feof(MYDATA)) {
		printf("Producing. Aw yeah.\n");
		c = fgetc(MYDATA);

		do {

			while ((TURN = fopen("TURN.txt", "r+")) == NULL); //do nothing
			checkTurn = fgetc(TURN);

		} while (checkTurn != '0');

		//polling and waiting to be able to open the data file
		while ((DATA = fopen("DATA.txt", "w+")) == NULL);

		//put the character in the file, close it.
		fputc(c, DATA);
		fclose(TURN);

		//put give the turn to the consumer, and close the file.
		fputc('1', TURN);
		fclose(DATA);
	}

}
