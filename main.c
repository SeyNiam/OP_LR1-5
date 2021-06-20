#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#pragma warning(disable:6031)
#endif

#define N 15

#include <stdio.h>

int main() {
	int endFlag = 1; //a flag that stops the application
	int Arr[N] = { 0 }; //array of integer numbers
	int min = 2147483647;
	int minNum = -1;
	int max = -2147483647-1;
	int maxNum = -1;

	//a global cycle that prevents the program from endting without the user's desire
	do {
		//a cycle for reading characters from a stream associated with the keyboard
		printf("Please type down your array:\n");
		for (int i = 0; i < N; i++) {
			scanf("%d", &Arr[i]);
		}

		//finding min and max elements and their position
		for (int i = 0; i < N; i++) {
			if (Arr[i] < min){
				minNum = i;
				min = Arr[i];
			}
			else if (Arr[i] > max){
				maxNum = i;
				max = Arr[i];
			}
		}

		//now swapping the minimum and maximum elements
		if (minNum != -1 && maxNum != -1) {
			Arr[minNum] = max;
			Arr[maxNum] = min;
		}

		//output of the result
		printf("Your new array is: ");
		for (int i = 0; i < N; i++) {
			printf("%d ", Arr[i]);
		}

		//resetting the variables
		endFlag = 1; 
		memset(&Arr[0], 0, sizeof(Arr)); //filling the array with the specified characters
		min = 2147483647;
		minNum = -1;
		max = -2147483647-1;
		maxNum = -1;
		

		//suggesting to user to run program again or exit.
		printf("\n\nPlease choose from the following:\n\t1 - Count again.\n\t2 - Exit.\n");		
		scanf("%d", &endFlag);
		switch (endFlag) {
			case 1: endFlag = 1; break;
			case 2: endFlag = 0; break;
			default: printf("Incorrect answer. The program will be closed."); endFlag = 0; break;
		}
	} while (endFlag); //if flag is 0, then exiting out of cycle 
	return 0;
}