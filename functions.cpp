#include "ADT.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <fstream>
#include <vector>
#include "functions.h"
using namespace std;


/*******************************************************************************
 * void insertStar(char grid[][COL])
 *	This function randomly inserts a char '*' in the input grid.
 *	The function doesn't replace any existing entity in the grid (except ' ')
 *
 *
 * Input(s):
 *   char [][COL]
 *
 * Output:
 *   N/A
 *******************************************************************************/
void insertStar(char grid[][COL]){
	srand(time(0));
	int randRow = 0, randCol = 0;
	bool condition = false;
	do{
		randRow = rand() % ROW;
		randCol = rand() % COL;
		condition = (grid[randRow][randCol] == '*' || grid[randRow][randCol] == 'M' || grid[randRow][randCol] == 'P');
		if (!condition)
			grid[randRow][randCol] = '*';
	}while(condition);
}

/*******************************************************************************
 * void insertMonster(char grid[][COL])
 *	This function randomly inserts a char 'M' in the input grid.
 *	The function doesn't replace any existing entity in the grid (except ' ')
 *
 *
 * Input(s):
 *   char [][COL]
 *
 * Output:
 *   N/A
 *******************************************************************************/
void insertMonster(char grid[][COL]){
	srand(time(0));
	int randRow = 0, randCol = 0;
	bool condition = false;
	do{
		randRow = rand() % ROW;
		randCol = rand() % COL;
		condition = (grid[randRow][randCol] == '*' || grid[randRow][randCol] == 'M' || grid[randRow][randCol] == 'P');
		if (!condition)
			grid[randRow][randCol] = 'M';
	}while(condition);
}


/*******************************************************************************
 * void initializeGrid(char grid[][COL])
 *	This function initializes the input grid. It sets the initial position of user on the grid at (0,0),
 *	and sets all the other elements to ' '.
 *	It also calls the insertStar() [10 times] and insertMonster() [5 times] functions.
 *
 * Input(s):
 *   char [][COL]
 *
 * Output:
 *   N/A
 *******************************************************************************/
void initializeGrid(char grid[][COL]) {
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			if (i == 0 && j == 0)
				grid[i][j] = 'P';
			else
				grid[i][j] = ' ';
		}
	}
	//Calling insertGrid function 10 times
	for (int i = 0; i < 10; i++)
		insertStar(grid);
	//Calling insertMonster function 5 times
	for (int i = 0; i < 5; i++)
		insertMonster(grid);
}

/*******************************************************************************
 *void displayGrid(char grid[][COL])
 *	This function is displays the input grid as to the user.
 *	It hides the char 'M' while displaying the grid
 *
 *
 * Input(s):
 *   char [][COL]
 *
 * Output:
 *   N/A
 *******************************************************************************/
void displayGrid(char grid[][COL]) {
	for (int i = 0; i < ROW; i++) {
		cout << setw(COL * 2 + 2) << setfill('-') << "\n";
		for (int j = 0; j < COL; j++) {
			if (grid[i][j] == 'M')
				cout << "|" << ' ';
			else
				cout << "|" << grid[i][j];
		}
		cout << "|\n";
	}
	cout << setw(COL * 2 + 2) << setfill('-') << "\n";
}

/*******************************************************************************
 *void displayGridEnd(char grid[][COL])
 *	This function is displays the input grid. It displays all the characters in the 2D array.
 *
 *
 *
 * Input(s):
 *   char [][COL]
 *
 * Output:
 *   N/A
 *******************************************************************************/
void displayGridEnd(char grid[][COL]){
	for (int i = 0; i < ROW; i++) {
		cout << setw(COL * 2 + 2) << setfill('-') << "\n";
		for (int j = 0; j < COL; j++) {
			cout << "|" << grid[i][j];
		}
		cout << "|\n";
	}
	cout << setw(COL * 2 + 2) << setfill('-') << "\n";
}
/*******************************************************************************
 *bool moveValid(char grid[][COL],char c)
 *	The purpose of this function is to validate user input for input char c.
 *	The function makes sure that the movement (W,A,S,D) results in movement within the bounds of the 2D array.
 *	It also validates whether the input is W,A,S,D or w,a,s,d.
 *	Functions returns true if both the above conditions are valid. Else, returns false.
 *
 * Input(s):
 *   char [][COL], char, int&
 *
 * Output:
 *   bool value. True is the input is valid, else false.
 *******************************************************************************/
bool moveValid(char grid[][COL], char c){
	const char movements[4] = {'W', 'S', 'A', 'D'};
	int playerPos[2];
	bool condition = false;
	//finding player coordinates
	for (int i = 0; i < ROW; i++){
		for (int j = 0; j < COL; j++){
			if (grid[i][j] == 'P'){
				playerPos[0] = i;
				playerPos[1] = j;
			}
		}
	}
	//Validation whether the input is a valid letter (W,A,S,D) using ranged-based for loop
	c = toupper(c);
	for (char movement : movements){
		if (c == movement){
			condition = true;
			break;
		}
	}
	if (!condition){
		cout << "Invalid input\n";
		return false;
	}
	//Validating whether the movement is within the range of the the 2D array.
	switch(c){
	case 'W':
		if (((playerPos[0] - 1) >= 0 && (playerPos[0] - 1) < ROW) && (playerPos[1] >= 0 && playerPos[1] < COL))
			return true;
		else{
			cout << "Invalid move\n";
			return false;
		}
	case 'S':
		if (((playerPos[0] + 1) >= 0 && (playerPos[0] + 1) < ROW) && (playerPos[1] >= 0 && playerPos[1] < COL))
			return true;
		else{
			cout << "Invalid move\n";
			return false;
		}
	case 'A':
		if ((playerPos[0] >= 0 && playerPos[0] < ROW) && ((playerPos[1] - 1) >= 0 && (playerPos[1] - 1) < COL))
			return true;
		else{
			cout << "Invalid move\n";
			return false;
		}
	case 'D':
		if ((playerPos[0] >= 0 && playerPos[0] < ROW) && ((playerPos[1] + 1) >= 0 && (playerPos[1] + 1) < COL))
			return true;
		else{
			cout << "Invalid move\n";
			return false;
		}
	}

	return false;
}


/*******************************************************************************
 *bool movement(char grid[][COL],char c, int &score)
 *	This functions purpose is to enable proper movement of player 'P' around the grid.
 *	For every input char c (W,A,S,D) it checks whether the move results in gaining a star ('*') or ending the game ('M').
 *	It updates the score of the reference variable int &score.
 *	the function returns true if the move is possible, or false if the move results in the end of the game.
 *
 * Input(s):
 *   char [][COL], char, int&
 *
 * Output:
 *   bool value: True if the move doesn't result in the end of the game. False if it does.
 *******************************************************************************/
bool movement(char grid[][COL],char c, int &score){
	c = toupper(c);
	static int playerPos[2] = {0,0}; //holds the position of player 'P' throughout the game
	//finding player coordinates
	for (int i = 0; i < ROW; i++){
		for (int j = 0; j < COL; j++){
			if (grid[i][j] == 'P'){
				playerPos[0] = i;
				playerPos[1] = j;
			}
		}
	}

	switch(c){
	case 'W':
		if (grid[playerPos[0] - 1][playerPos[1]] == '*'){
			score++;
			grid[playerPos[0]][playerPos[1]] = '-';
			grid[playerPos[0] - 1][playerPos[1]] = 'P';
			return true;
		}else if (grid[playerPos[0] - 1][playerPos[1]] == 'M'){
			cout << "OH NO!! There is a monster there!\n";
			displayGridEnd(grid);
			return false;
		}else{
			grid[playerPos[0]][playerPos[1]] = '-';
			grid[playerPos[0] - 1][playerPos[1]] = 'P';
			return true;
		}
	case 'S':
		if (grid[playerPos[0] + 1][playerPos[1]] == '*'){
			score++;
			grid[playerPos[0]][playerPos[1]] = '-';
			grid[playerPos[0] + 1][playerPos[1]] = 'P';
			return true;
		}else if (grid[playerPos[0] + 1][playerPos[1]] == 'M'){
			cout << "OH NO!! There is a monster there!\n";
			displayGridEnd(grid);
			return false;
		}else{
			grid[playerPos[0]][playerPos[1]] = '-';
			grid[playerPos[0] + 1][playerPos[1]] = 'P';
			return true;
		}
	case 'A':
		if (grid[playerPos[0]][playerPos[1] - 1] == '*'){
			score++;
			grid[playerPos[0]][playerPos[1]] = '-';
			grid[playerPos[0]][playerPos[1] - 1] = 'P';
			return true;
		}else if (grid[playerPos[0]][playerPos[1] - 1] == 'M'){
			cout << "OH NO!! There is a monster there!\n";
			displayGridEnd(grid);
			return false;
		}else{
			grid[playerPos[0]][playerPos[1]] = '-';
			grid[playerPos[0]][playerPos[1] - 1] = 'P';
			return true;
		}
	case 'D':
		if (grid[playerPos[0]][playerPos[1] + 1] == '*'){
			score++;
			grid[playerPos[0]][playerPos[1]] = '-';
			grid[playerPos[0]][playerPos[1] + 1] = 'P';
			return true;
		}else if (grid[playerPos[0]][playerPos[1] + 1] == 'M'){
			cout << "OH NO!! There is a monster there!\n";
			displayGridEnd(grid);
			return false;
		}else{
			grid[playerPos[0]][playerPos[1]] = '-';
			grid[playerPos[0]][playerPos[1] + 1] = 'P';
			return true;
		}
	default:
		cout << "Invalid input\n";
		return false;
	}
}

/*******************************************************************************
 * void menu()
 *   Displays the menu options to the user.
 *
 * Input(s):
 *   N/A
 *
 * Output:
 *   N/A
 *******************************************************************************/
void menu(){
	cout << "\t\tDungeon Escape\n";
	cout << "Choose from the following options: \n";
	cout << "1. New Game\n"
		 << "2. Leaderboard\n"
		 << "3. Rules\n"
		 << "4. Quit Game\n";
}


/*******************************************************************************
 * void writeData(Player player, string filename)
 *   Creates a fstream object to store the data of the Player structure in "leaderboard.txt" file.
 *
 * Input(s):
 *   Player, string (string has a default parameter)
 *
 * Output:
 *   N/A
 *******************************************************************************/

void writeData(Player player, string filename){
	fstream myFile;
	//Opening file in append mode, as the file is already created and data is to be added
	myFile.open(filename, ios::app);
	//check for error in opening of file
	if (myFile.fail()){
		cout << "Error in file storage.\n";
		return;
	}
	string data = "";
	data += player.name + ",";
	data += to_string(player.score) + "\n";
	myFile << data;

	myFile.close();
}

/*******************************************************************************
 * void readData(string filename)
 *   Creates a fstream object to read data from the "leaderboard.txt" file.
 *   The function reads the required data and displays it in a formatted manner.
 *
 * Input(s):
 *   string (string has a default parameter)
 *
 * Output:
 *   N/A
 *******************************************************************************/
void readData(string filename){
	fstream myFile;
	myFile.open(filename, ios::in);
	//check for error in opening of file
	if (myFile.fail()){
		cout << "Error in file storage.\n";
		return;
	}
	//variables that store inputs from the file
	int count = 0;
	vector<string> names;
	vector<string> scores;
	//required by the getline function
	static const char delimiter1 = ',';
	//Stores the required data until end of the file
	while (!myFile.eof()){
		string temp = "";
		getline(myFile, temp, delimiter1);
		names.push_back(temp);
		getline(myFile, temp, '\n');
		scores.push_back(temp);
		count++;
	}

	//displaying in formatted manner
	for (int i = 0; i < (count - 1); i++){
		cout << i + 1 << ". ";
		cout << left << setw(30) << setfill(' ');
		cout << names.at(i);
		cout << "score:" << scores.at(i) << endl;
	}
	cout  << right;
}
/*******************************************************************************
 * void rules()
 *   Displays the ruls of the game to the player.
 *
 * Input(s):
 *   N/A
 *
 * Output:
 *   N/A
 *******************************************************************************/
void rules(){
	cout << "\t\t|Welcome to Dungeon Escape|\n";
	cout << "* In order to escape the dungeon you must collect all the gems scattered around the dungeon!\n"
		 << "* BEWARE! There are monsters hidden throughout the dungeon!\n";
	cout << "* You can spot yourself in the maze by looking for the letter: 'P' \n";
	cout << "* Use the keys: W(up), A(left), S(down), D(right) to move around the dungeon\n";
	cout << "* Collect the gems '*' in the dungeon and watch your score go up!\n";
	cout << "* It is advised that you don't try to explore too much\n"
		 <<	"  and attempt to travel along the path you have already cleared\n";
	cout << "* Collect all 10 gems to escape. That is, if a monster doesn't eat you before!\n" << endl;
}

/*******************************************************************************
 * void welcomeMessage()
 *   Displays the title of the game and a short background story about the game.
 *
 * Input(s):
 *   N/A
 *
 * Output:
 *   N/A
 *******************************************************************************/
void welcomeMessage(){
	cout << setw(43) << setfill('*') << "\n";
	cout << "**\t\tDUNGEON ESCAPE \t\t**\n";
	cout << setw(43) << setfill('*') << "\n";
	cout << "CRASHH...You land in a dark dungeon!\n";
	cout << "You helplessly scream in search for help\n"
			"Suddenly you see something... \n"
		 <<	"Rays of light shine into the sky.\n";
	cout << "\t\tMagic gems!!\t\n\t(The key to escaping the dungeon.)\n\n";
	cout << "Your quest is to collect all the magic gems to escape!\n";
	cout << "Meanwhile... evilness fills the atmosphere\n";
	cout << "\t\tRAWWWWWWARR...\n\tBeware, the dungeon is filled with deadly monsters\n\n";
}
