
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
	TURN = fopen("TURN.txt", "w+");
	if (TURN == NULL) {
		printf("Main.c could not open the turn file! :(\n");
		exit(1);
	}
	fputc('0', TURN);
	fclose(TURN);



	pid = fork();
	//Fork starts here

	//something went wrong, terminate
	if (pid == -1){
		printf("ça marche pas :(\n");
		exit(1);
	}

	printf("Processes forked successfully.\n");
	printf("I have PID #%d", pid);

	//producer will do its job here
	//i.e. producer is the child(?)
	if (pid == 0) {
		producer();
		exit(0); //program terminates when producer finishes
	}

	//consumer will do its job here
	if (pid > 0) { //probably don't have negative PIDs
		consumer();
		wait();	//consumer will wait for producer to finish
	}

	return 0;
}
