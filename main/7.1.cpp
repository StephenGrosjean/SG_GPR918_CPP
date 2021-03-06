
#include "pch.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int GRID_X_SIZE = 3; //X grid size
const int GRID_Y_SIZE = 3;//Y grid size

bool gridFull = false; //Is the grid full (Tie)

bool player1Active = true; //Is it the player  turn?

vector<vector<string>> grid; //two dimensionnal vector representing the grid


//Class fo the player
class Player {
public:
	string symbol = ""; //Symbol of the player
	bool AsWin = false; //Did he win?
};

Player player1; //Create the first player
Player player2; //Create the second player

//Set the symbols
void InitializePlayer() {
	player1.symbol = "X"; 
	player2.symbol = "O";
}

void GenerateMap() {
	grid = { { "_","_","_" },{ "_","_","_" }, { "_","_","_" } }; //Put "_" to all grid coordinates
}

void ShowMap() {
	//Display the map

	//Display the name of the player if it's his turn
	if(!player1.AsWin && !player2.AsWin){ //Check if player 1 and player 2 have not won
		if (player1Active) {
			cout << " ------------- " << endl;
			cout << " Player 1 : " << player1.symbol << endl;
			cout << " ------------- " << endl;
		}
		else {
			cout << " ------------- " << endl;
			cout << " Player 2 : " << player2.symbol << endl;
			cout << " ------------- " << endl;
		}
	}

	//Display the grid with the coordinates 
	cout << "   " << "1" << " " << "2" << " " << "3" << endl;
	cout << "1" << "  " << grid[0][0] << " " << grid[0][1] << " " << grid[0][2] << endl;
	cout << "2" << "  " << grid[1][0] << " " << grid[1][1] << " " << grid[1][2] << endl;
	cout << "3" << "  " << grid[2][0] << " " << grid[2][1] << " " << grid[2][2] << endl;
	cout << " " << endl;
}

void SetNewPosition() {
	//Set the position of the player symbol

	bool CorrectPosition = false; //Is the position of the symbol correct

	while(!CorrectPosition){ //Loop until the position is correct
		int l; //Line variable
		int c; //Column variable

		cout << "Line (1,2,3) : "; //Ask for the line
		cin >> l;
		cout << " " << endl;
		cout << "Column (1,2,3) : "; //Ask for the column
		cin >> c;

		l--; //Reduce by 1 the variable
		c--; //Reduce by 1 the variable

		if(l > -1 && l<3){ //Check if the line number is not outside the range
			if (c > -1 && c < 3) { //check if the column number is not outside the range
				if (grid[l][c] != player2.symbol && grid[l][c] != player1.symbol) { //Check if there is no symbol to this grid position
					CorrectPosition = true; //if everything is good, then the position is correct
					if (player1Active) {  //if it's player 1 turn put his symbol
						grid[l][c] = player1.symbol;
						player1Active = false; //Pass the turn to the other player
						break; //Exit the while loop
					}
					else {
						grid[l][c] = player2.symbol; //Put player 2 symbol
						player1Active = true; //pass the turn to the other player
						break; //Exit the while loop
					}

				}
			}
		}
		system("cls"); //Clear screen
		ShowMap(); //Show the map
	}
}

void CheckWin() {
	//Check every possible situation for a win case for both players

	if ((grid[0][0] == player1.symbol && grid[1][1] == player1.symbol && grid[2][2] == player1.symbol) || //Right to left diag
		(grid[2][0] == player1.symbol && grid[1][0] == player1.symbol && grid[0][0] == player1.symbol) || //Left to right diag
		(grid[0][0] == player1.symbol && grid[1][0] == player1.symbol && grid[2][0] == player1.symbol) || //Vertical line left 
		(grid[0][1] == player1.symbol && grid[1][1] == player1.symbol && grid[2][1] == player1.symbol) || //Vertical line middle
		(grid[0][2] == player1.symbol && grid[1][2] == player1.symbol && grid[2][2] == player1.symbol) || //Vertical line right
		(grid[0][0] == player1.symbol && grid[0][1] == player1.symbol && grid[0][2] == player1.symbol) || //Horizontal line top
		(grid[1][0] == player1.symbol && grid[1][1] == player1.symbol && grid[1][2] == player1.symbol) || //Horizontal line middle
		(grid[2][0] == player1.symbol && grid[2][1] == player1.symbol && grid[2][2] == player1.symbol)) { //Horizontal line bottom

		player1.AsWin = true; //If one of these case is true then the player as won
	}

	if ((grid[0][0] == player2.symbol && grid[1][1] == player2.symbol && grid[2][2] == player2.symbol) || //Right to left diag
		(grid[2][0] == player2.symbol && grid[1][0] == player2.symbol && grid[0][0] == player2.symbol) || //Left to right diag
		(grid[0][0] == player2.symbol && grid[1][0] == player2.symbol && grid[2][0] == player2.symbol) || //Vertical line left 
		(grid[0][1] == player2.symbol && grid[1][1] == player2.symbol && grid[2][1] == player2.symbol) || //Vertical line middle
		(grid[0][2] == player2.symbol && grid[1][2] == player2.symbol && grid[2][2] == player2.symbol) || //Vertical line right
		(grid[0][0] == player2.symbol && grid[0][1] == player2.symbol && grid[0][2] == player2.symbol) || //Horizontal line top
		(grid[1][0] == player2.symbol && grid[1][1] == player2.symbol && grid[1][2] == player2.symbol) || //Horizontal line middle
		(grid[2][0] == player2.symbol && grid[2][1] == player2.symbol && grid[2][2] == player2.symbol)) { //Horizontal line bottom

		player2.AsWin = true; //If one of these case is true then the player as won
	}

	//If none of the player as won check if the grid is full
	if (!player1.AsWin && !player2.AsWin) {
		if (grid[0][0] != "_" && grid[0][1] != "_" && grid[0][2] != "_" &&
			grid[1][0] != "_" && grid[1][1] != "_" && grid[1][2] != "_" &&
			grid[2][0] != "_" && grid[2][1] != "_" && grid[2][2] != "_") {

			gridFull = true; //The grid is full if all the conditions are true
		}
	}
	

}

void PlayGame() {
	while (!player1.AsWin && !player2.AsWin && !gridFull) { //loop until one of the player as won or the grid is full
		ShowMap(); //Show the map
		SetNewPosition();  //Set the symbol position
		CheckWin(); //Check if someone as won
		system("cls"); //Clear the screen
	}
	if (player1.AsWin) { //If the player 1 won
		cout << "----------------------------" << endl;
		cout << " Player 1 as won the game ! " << endl;
		cout << "----------------------------" << endl;
		cout << " " << endl;
		ShowMap();
	}
	else if(player1.AsWin){ //If the player 2 won
		cout << "----------------------------" << endl;
		cout << " Player 2 as won the game ! " << endl;
		cout << "----------------------------" << endl;
	}
	else{ //If the grid is full and no one win
		cout << "----------------------------" << endl;
		cout << "            TIE !           " << endl;
		cout << "----------------------------" << endl;
	}

}

int main()
{
	InitializePlayer(); //Initialize the players
	GenerateMap(); //Generate the map
	PlayGame(); //Play the game
	system("pause");

}
