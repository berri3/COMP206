/*
 * producer.c
 *
 *  Created on: Dec 4, 2017
 *      Author: VictorVuong
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void producer() {

	FILE *MYDATA;

	char c;
	char checkTurn;
	FILE *TURN;
	FILE *DATA;

	//get data from mydata.txt
	if ((MYDATA = fopen("mydata.txt", "at")) == NULL) {
		exit();
	}

	while (!feof(MYDATA)) {
		c = fgetc(MYDATA);

		do {

			while ((TURN = fopen("TURN.txt", "r+")) == NULL); //do nothing

			checkTurn = fgetc(TURN);

			if (checkTurn == '0') {
				while ((DATA = fopen("DATA.txt", "w+")) == NULL);
				fputc(c, DATA);
				fputc('1', TURN);
			}

			fclose(TURN);
			fclose(DATA);

		} while (checkTurn != '0');

	}

}
