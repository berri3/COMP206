

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void producer();
void consumer();

int main() {

	//variables
	int pid;
	FILE *TURN;

	//initialize TURN to 0 before forking
	TURN = fopen("TURN.txt", "wt");
	if (TURN == NULL) {
		printf("Main.c could not open the turn file! :(\n");
		exit(1);
	}
	fputc('0', TURN);
	fclose(TURN);

	pid = fork();
	//Forked program starts here

	//something went wrong, gotta terminate
	if (pid == -1){
		printf("Something went wrong... :(\n");
		exit(1);
	}

	//producer will do its job here
	if (pid == 0) {
		producer();
	}

	//consumer will do its job here
	if (pid != 0) { 
		consumer();
	}

	return 0;
}

