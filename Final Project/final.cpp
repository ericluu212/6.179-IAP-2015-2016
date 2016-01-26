//Final Project: Battleships

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cctype>

//Command window width: 82
static int window_width = 82;

void wait(clock_t tiempo){
	clock_t now = clock();
	while (clock() - now < tiempo){
		//do nothing
	}
}

void populateArray(char arr[][11], int row, int col){
	for (int r = 0; r < row; r = r + 1){
		for (int c = 0; c < col; c = c + 1) {
			if (c == 0 && r == 0){
				arr[c][r] = ' ';
			}
			else if (c == 0){
				char x = r - 1 + '0';
				arr[c][r] = x;
			}
			else if (r == 0){
				char x = c - 1 + '0';
				arr[c][r] = x;
			}
			else {
				arr[c][r] = '-';
			}
		}
	}
}

void printArray(char arr[][11], int row, int col){
	for (int r = 0; r < row; r = r + 1){
		for (int c = 0; c < col; c = c + 1) {
			printf("%c", arr[c][r]);
		}
		printf("%c", '\n');
	}
}

int generateShips(char arr[][11], int numShips, int x){ //Fix this method
	int lives = 0;
	srand(time(NULL) + x);
	for (int i = 0; i < numShips; i++){
		int r = rand();
		int row = (rand() % 8) + 1;
		int col = (rand() % 8) + 1;
		if (rand() % 2 == 0){ //Horizontal
			for (int j = 0; j < 3; j++) {
				if (arr[col][row + j] != 'S'){
					arr[col][row + j] = 'S';
					lives++;
				}
			}
		}
		else { //Vertical
			for (int j = 0; j < 3; j++) {
				if (arr[col + j][row] != 'S') {
					arr[col + j][row] = 'S';
					lives++;
				}
			}
		}
	}
	return lives;
}

int hitCoordinate(char arr[][11], char arr2[][11], int row, int col){
	if (arr[col + 1][row + 1] == 'S'){
		printf("%s\n", "Hit Confirmed! Updating info...");
		arr2[col + 1][row + 1] = 'X';
		return 1;
	}
	else{
		printf("%s\n", "Attack Missed. Updating info...");
		arr2[col + 1][row + 1] = 'M';
		return 0;
	}
}

int main() {
	system("cls");
	char title[] = "BATTLESHIPS!";
	char author[] = "By: Eric Luu";
	int x = 1;
	while (x < (window_width - strlen(title)) / 2){
		printf("%c", ' ');
		x++;
	}

	for (int i = 0; i < strlen(title); i++){
		printf("%c", title[i]);
		wait(100);
	}

	x = 1;
	while (x < (window_width - strlen(author)) / 2){
		printf("%c", ' ');
		x++;
	}

	x = 1;
	while (x < (window_width - strlen(author)) / 2){
		printf("%c", ' ');
		x++;
	}

	for (int i = 0; i < strlen(author); i++){
		printf("%c", author[i]);
		wait(100);
	}

	x = 1;
	while (x < (window_width - strlen(author)) / 2){
		printf("%c", ' ');
		x++;
	}
	wait(1000);

	//Display Instructions
	system("cls");
	printf("%s\n\n", "Instructions:");

	printf("%s\n", "You & your CPU enemy will each have 10x10 grids containing 3 randomly-generated");
	printf("%s\n", "ships of length 3.");
	
	printf("%s\n", "To win, select a coordinate on your enemy's grid and hope that you hit a ship.");

	printf("%s\n", "Please enter the coordinates in x y form, where x is row number and y is column");
	printf("%s\n", "number (Note: this program uses zero-based numbering for coordinates).");

	printf("%s\n", "Coordinate hits will be represented by 'X'. Misses will be represented by 'M'.");

	printf("%s\n\n", "Lives are represented by the number of ship coordinates that haven't been hit.");

	printf("%s\n", "Press the Enter key to continue");

	while (getchar() != '\n'){
		//do nothing
	}

	//Generate grids
	//system("cls");
	char myShips[11][11];
	char foeShips[11][11];
	char dummyFoeShips[11][11];
	populateArray(myShips, 11, 11);
	populateArray(foeShips, 11, 11);
	populateArray(dummyFoeShips, 11, 11);
	int yourLives = generateShips(myShips, 3, 0);
	int foeLives = generateShips(foeShips, 3, 1); 

	srand(time(NULL));
	while (yourLives > 0 && foeLives > 0) {
		system("cls");
		printf("%s %d\n", "Your lives remaining: ", yourLives);
		printf("%s\n", "Your grid:" );
		printArray(myShips,11,11);

		for (int i = 0; i < 3; i++){
			printf("%c", '\n');
		}

		printf("%s %d\n", "Foe's lives remaining: ", foeLives);
		printf("%s\n", "Foe's grid:" );
		printArray(dummyFoeShips,11,11);

		for (int i = 0; i < 3; i++){
			printf("%c", '\n');
		}

		/*
		//for debugging
		printf("%c", '\n');
		printArray(foeShips,10,10);
		*/

		//Player Attack
		printf("%s\n", "Your Turn: ");
		printf("%s\n", "Specify the coordinates that you wish to attack: ");
		char input[4];
		fgets(input, 5, stdin);

		int rowTarget = input[0] - '0';
		int colTarget = input[2] - '0';
		/*
		printf("%c\n", input[0]);
		printf("%c\n", input[1]);
		printf("%c\n", input[2]);
		*/
		//printf("%c\n", input[3]);
		//scanf("%d %d", &rowTarget, &colTarget);

		while (input[1] != ' ' || isalpha(input[0]) || isalpha(input[2]) ||
			rowTarget >= 10 || rowTarget < 0 || colTarget >= 10 || colTarget < 0 || 
			dummyFoeShips[colTarget + 1][rowTarget + 1] == 'X' || dummyFoeShips[colTarget + 1][rowTarget + 1] == 'M'){
			printf("%s\n", "Invalid coordinates. Please try again.");
			fgets(input, 5, stdin);
			rowTarget = input[0] - '0';
			colTarget = input[2] - '0';
			/*
			printf("%c\n", input[0]);
			printf("%c\n", input[1]);
			printf("%c\n", input[2]);
			*/
			//printf("%c\n", input[3]);
		}

		int x = hitCoordinate(foeShips, dummyFoeShips, rowTarget, colTarget);
		if (x == 1){
			foeLives--;
		}
		wait(1500);
		if (foeLives == 0){
			system("cls");
			printf("%s\n", "Congratulations! You have eliminated all of the enemy ships!");
			break;
		}

		//CPU Attack
		system("cls");
		printf("%s %d\n", "Your lives remaining: ", yourLives);
		printf("%s\n", "Your grid:" );
		printArray(myShips,11,11);

		for (int i = 0; i < 3; i++){
			printf("%c", '\n');
		}

		printf("%s %d\n", "Foe's lives remaining: ", foeLives);
		printf("%s\n", "Foe's grid:" );
		printArray(dummyFoeShips,11,11);


		for (int i = 0; i < 3; i++){
			printf("%c", '\n');
		}

		printf("%s\n", "CPU's Turn:");
		int CPUrowTarget = (rand() % 10) + 1;
		int CPUcolTarget = (rand() % 10) + 1;
		wait(1500);

		/*
		srand(time(NULL));
		while ( myShips[CPUcolTarget][CPUrowTarget] == 'M' ||  myShips[CPUcolTarget][CPUrowTarget] == 'X' ){ //To prevent repeat selection of coords
			int CPUrowTarget = rand() % 10;
			int CPUcolTarget = rand() % 10;
		}
		*/

		printf("%s %d %d\n", "CPU targets coordinate ", CPUrowTarget, CPUcolTarget);
		int y = hitCoordinate(myShips, myShips, CPUrowTarget, CPUcolTarget);
		if (y == 1){
			yourLives--;
		}
		wait(1500);
		if (yourLives == 0){
			system("cls");
			printf("%s\n", "Oh no! All of your ships have been eliminated! Better luck next time!");
			break;
		}
	}



/*
	printf("%s\n", "Your ship placement:");
	printf("%s\n\n", "Note: In this version of the game, ships are allowed to overlap."); //maybe?
	printf("%s\n", "Ship 1:");

	printf("%s\n", "Specify your ship orientation (v for vertical; h for horizontal): ");
	scanf("%c", &orient);
	//orient = getchar();
	while (orient != 'h' && orient != 'v'){
		printf("%s\n", "Invalid input. Specify orientation again (v for vertical; h for horizontal): ");
		scanf("%c", &orient);
		//break;
	}
*/

	return 0;
}
 
