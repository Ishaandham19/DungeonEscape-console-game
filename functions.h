#include "ADT.h"

//Constant variables used by both functions.cpp and main.cpp
const int ROW = 5;
const int COL = 10;

//Function prototypes
void displayGrid(char [][COL]);
void initializeGrid(char [][COL]);
void insertStar(char [][COL]);
void insertMonster(char [][COL]);
void displayGridEnd(char grid[][COL]);
bool movement(char [][COL],char, int&);
bool moveValid(char [][COL], char );
void menu();
void WelcomeMenu();
void writeData(Player, string = "leaderboard.txt");
void readData(string = "leaderboard.txt");
void welcomeMessage();
void rules();
