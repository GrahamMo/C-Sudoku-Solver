#include <stdio.h>
#include <math.h>

const int N = 9;

void checkNum(int puzzleptr[N][N], int numbers[9], int row, int col) { //function checks if number can be placed in location and if it can then it changes the boolean at the assoiated index of the number

	for (int i = 0; i < N; i++) {
		numbers[i] = 1; //init that all numbers can be placed in the square
	}

	//CHECK BOX
	int rowStart = (floor(row / 3))*3; //find which box it is in by dividing by 3 and removing remainder
	int colStart = (floor(col / 3))*3;

	for (int i = 0; i < 3; i++) { //go through each row
		for (int j = 0; j < 3; j++){ //and thorugh each col
			if (puzzleptr[rowStart + i][colStart + j] != 0){ //check if a non 0 number is there
				numbers[puzzleptr[rowStart + i][colStart + j] - 1] = 0; //set that the number cannot be placed there in the list of booleans
			}
		}
	}
	
	//CHECK ROW AND COL
	//just itterate through entire row because obviously the 0 in the current location will not have the test number	
	for (int i = 0; i<N; i++) {  //go through the line...
		if (puzzleptr[row][i] != 0) { //checking for non-zero values
			numbers[puzzleptr[row][i] - 1] = 0; //set that the number cannot be placed there
		}
	}
	//same for col
	for (int j = 0; j < N; j++) {
		if (puzzleptr[j][col] != 0) {
			numbers[puzzleptr[j][col] - 1] = 0;
		}
	}
}

void findEmpty(int puzzleptr[N][N], int *x, int *y) { //find the first empty box cords
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			if (puzzleptr[row][col] == 0) {
				*x = row; //if selected index is empty return that that the current cords
				*y = col;
				return;
			}
		}
	}
	*x = -1; //if already chosen assign -1
	*y = -1;

}


int findSolution(int puzzleptr[N][N]) {
	int x, y;
	findEmpty(puzzleptr, &x, &y);

	if (x == -1) { //if already solved space then return
		return 1;
	}
	
	int numbers[9];
	checkNum(puzzleptr, numbers, x, y);

	//Solving loop
	for (int i = 0; i < N; i++) {
		if (numbers[i] == 0) { //if the the position is invalid then do nothing
			continue;
		}
		puzzleptr[x][y] = i + 1; //otherwise it can go there so give it a try
		
		if (findSolution(puzzleptr) == 1) { //and keep calling the function until there is a contrediction and then it will try the next number or until it solves the puzzle
			return 1;
		}
	}

	puzzleptr[x][y] = 0; //to reset when inputs wrong
	return 0;
}


int main() { //type int because if an error returns 1

	int puzzleptr[N][N] = {
		{0,0,4,0,5,0,0,0,0},
		{9,0,0,7,3,4,6,0,0},
		{0,0,3,0,2,1,0,4,9},
		{0,3,5,0,9,0,4,8,0},
		{0,9,0,0,0,0,0,3,0},
		{0,7,6,0,1,0,9,2,0},
		{3,1,0,9,7,0,2,0,0},
		{0,0,9,1,8,2,0,0,3},
		{0,0,0,0,6,0,1,0,0}
	}; //defining the POINTER

	int solved = findSolution(puzzleptr); 
	printf("%d\n", solved);
	
	//just pretty printing
	for (int x =0; x < N; ++x) {
		printf("|");
		for (int y = 0; y < N; ++y) {
			printf("%d|", puzzleptr[x][y]);
		}
		printf("\n");
	}		
	return 0;
}
