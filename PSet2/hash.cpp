//H4$H Browns
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>	
#include <cstdlib>
#include <iostream>
#include <string>

/* Notes on meaning of variables

D = Number of digits (5 <= D <= 20)
M = Number of credit cards (1 <= M <= 1000)
N = Number of accounts (1 <= N <= 1000)

*/


unsigned long long int hash(int digit, int index, int length) {
	unsigned long long int x = (index*index*index*index);
	unsigned long long int y = (length - index) * (length - index) * (length - index) * (length - index);
	unsigned long long int numerator = (digit + x + y) * length * length;
	unsigned long long int denominator = (length - 3) * (length - 3);
	return long(numerator / denominator);
}

/*
int printArray(int arr[][20], int row, int col){
	for (int i = 0; i < col; i++){
		printf("%d", arr[row][i]);
	}
	printf("%c", '\n');
	return 0;
}
*/

int main() {

	//printf("%d\n", hash(3, 0, 5));
	int accounts, cards, digits;
	scanf("%d %d %d", &accounts, &cards, &digits); //N, M, D
	//printf("%d\n", digits);

	unsigned long long int hashNumbers[cards][digits]; 

	int placeHold[cards][digits];

	for (int i = 0; i < cards; i++){
		char hold[digits];
        scanf("%s", hold);
		//scanf("%d", placeHold[i]);


		for(int j = 0; j < digits; j++) {
			int convert = hold[j] - '0';
			placeHold[i][j] = convert;
			int x = hash(convert, j, digits);
			hashNumbers[i][j] = x;
		}
		/*
		for (int b = 0; b < digits; b++){
			printf("%d", placeHold[i][b]);
		}
		printf("%c", '\n');
		*/
	}

	//Read in hashed numbers for accounts
	for(int k = 0; k < accounts; k++){
		int inp[digits];

		for(int z = 0; z < digits; z++){
			scanf("%d", &inp[z]);
		}

		for(int y = 0; y < cards; y++){
			int work = 0;
			for(int a = 0; a < digits; a++){
				if (inp[a] != hashNumbers[y][a]) {
					work = 1;
				}
				else if (a == digits - 1 && work != 1 && inp[a] == hashNumbers[y][a]) {
					//printArray(placeHold, y, digits);
					for (int b = 0; b < digits; b++){
						printf("%d", placeHold[y][b]);
					}
					printf("%c", '\n');
				}
			}
		}
	}
/*
	//print output (debug)
	for (int i = 0; i < cards; i++){
		for (int j = 0; j < digits + 2; j++) {
			printf("%d ", hashNumbers[i][j]);
		}
		printf("%c", '\n');
	}
*/
	return 0;
}