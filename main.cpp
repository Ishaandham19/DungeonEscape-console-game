#include <iostream>
#include <iomanip>
#include <fstream>
#include "functions.h"

using namespace std;

/*******************************************************************************
 * int main()
 *   Starting point of the program.It contains the main game loop that give the user options to either start
 *   a new game, view the leaderboard, read the rules or exit the game.
 *
 * Input(s):
 *   N/A
 *
 * Output:
 *   An integer that signals the exit code to the operating system (OS)
 *******************************************************************************/
int main() {
	//initializes variables required to store input
	int choice = 0;
	char direction = '\0';
	int score = 0;
	//Initializing grid
	char grid[ROW][COL];

	//displaying welcome message
	welcomeMessage();

	do {
		//Calling function to initialize the grid
		initializeGrid(grid);
		//Calling function to display menu
		menu();
		cin >> choice;

		switch (choice) {
		case 1:
		{
			//declaring variables used to hold input values
			string name;
			Player player;
			cout << "Please enter you name: " << endl;
			cin.ignore();
			getline(cin, name);
			player.name = name;
				//main game loop.
				do {
					cout << "Score: " << score << endl;
					displayGrid(grid);
					//input validation using the moveValid() function
					do {
						cout << "Up = W, Down = S, Right = D, Left = A\n";
						cin >> direction;
					} while (!moveValid(grid, direction));
				//Calling movement() function to check game status
				} while (movement(grid, direction, score) && score != 10);
				//updating player score
				player.score = score;
				//Checking if the loop ended due to winning(score = 10)  or touching a monster('M')
				if (score == 10){
					cout  << "Well Done! You have collected all the gems!\n";
					cout  << "You have escaped the dungeon!!\n";
					cout  << "Check out your score in the leaderboards" << endl;
				}
				else{
					cout << player.name << " was eaten by the monster!\n";
					cout << "\t\tGAME OVER\n";
					cout << "Final score: " << player.name << " collected " << player.score << " gems" << endl;
				}
				score  = 0; //resetting score
				//writing data into file using writeData() function (into "leaderboard.txt" file)
				writeData(player);
		}
			break;
		case 2:
			//displaying the leaderboards to the user in a formatted manner
			cout << "***************LEADERBOARD******************" << endl;
			readData();
			break;
		case 3:
			//Displaying the rules of the game to the player
			rules();
			break;
		case 4:
			//User exiting the game
			cout << "Thanks for playing Dungeon Escape\n";
			cout << "\t\tGame End" << endl;
			break;
		default:
			cout << "Invalid input\n";
			break;
		}
	} while (choice != 4);

	//terminating program
	return 0;
}
