
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void producer();
void consumer();

int main() {

	//initialize TURN to 0 before forking
	FILE *TURN;
	TURN = fopen("TURN.txt", "w+");
	if (TURN == NULL) {
		printf("Main.c could not open the turn file! :(\n");
		exit(1);
	}

	fputc('0', TURN);

	fclose(TURN);

	//Fork starts here

	printf("before fork");
	int pid = fork();

	//something went wrong, terminate
	if (pid == -1){
		printf("ca marche pas :(");
		exit(1);
	}

	//producer will do its job here
	if (pid == 0) {
		producer();
		exit(0);		//program terminates when producer finishes
	}

	//consumer will do its job here
	if (pid != 0) {
		consumer();
		wait();			//consumer will wait for producer to finish
	}

	return 0;
}
