/* Game clone of 2048 flash game */

#include <iostream>
#include <stdlib.h>
using namespace std;


class board{
private:
	int board[4][4];
	int score;

public:

void moveLeft(){
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			if (board[i][j] != 0){
				for (int a = i-1; a >= 0; a--){
					if (board[a][j] == 0){
						board[a][j] = board[a+1][j];
						board[a+1][j] = 0;
					}
					else if (board[a][j] == board[a+1][j]){
						board[a][j] *= 2;
						score += board[a][j];
						board[a+1][j] = 0;
						a = 0;
					}
				}
			}
		}
	}
	newNum();
}		

void moveRight(){
	for (int i = 3; i >= 0; i--){
		for (int j = 0; j < 4; j++){
			if (board[i][j] != 0){
				for (int a = i+1; a < 4; a++){
					if (board[a][j] == 0){
						board[a][j] = board[a-1][j];
						board[a-1][j] = 0;
					}
					else if (board[a][j] == board[a-1][j]){
						board[a][j] *= 2;
						score += board[a][j];
						board[a-1][j] = 0;
						a = 4;
					}
				}
			}
		}
	}
	newNum();
}		

void moveUp(){
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			if (board[i][j] != 0){
				for (int a = j-1; a >= 0; a--){
					if (board[i][a] == 0){
						board[i][a] = board[i][a+1];
						board[i][a+1] = 0;
					}
					else if (board[i][a] == board[i][a+1]){
						board[i][a] *= 2;
						score += board[i][a];
						board[i][a+1] = 0;
						a = 0;
					}
				}
			}
		}
	}
	newNum();
}		

void moveDown(){
	for (int i = 0; i < 4; i++){
		for (int j = 3; j >= 0; j--){
			if (board[i][j] != 0){
				for (int a = j+1; a < 4; a++){
					if (board[i][a] == 0){
						board[i][a] = board[i][a-1];
						board[i][a-1] = 0;
					}
					else if (board[i][a] == board[i][a-1]){
						board[i][a] *= 2;
						score += board[i][a];
						board[i][a-1] = 0;
						a = 4;
					}
				}
			}
		}
	}
	newNum();
}		

void printBoard(){
	cout << "\033[2J\033[1;1H";
	for (int j = 0; j < 4; j++){
		for (int i = 0; i < 4; i++){
			if (board[i][j] != 0){
				if (board[i][j] < 10)
				 	cout << "[  " << board[i][j] << " ]";
				else if (board[i][j] < 100)
					cout << "[ " << board[i][j] << " ]";
				else if (board[i][j] < 1000) cout << "[ " << board[i][j] << "]";
				else cout << "[" << board[i][j] << "]";
			}
			else cout << "[    ]";
		}
		cout << endl;
	}
	cout << "Score: " << score << endl;
	cout << "Press 'a' to shift left, 'd' to shift right, 'w' to shift up, 's' to move down" << endl;
	cout << "Press 'x' to end the game" << endl;
	char move;
	cin >> move;
	if (move == 'a') moveLeft();
	else if (move == 'd') moveRight();
	else if (move == 'w') moveUp();
	else if (move == 's') moveDown();
	else if (move == 'x') endGame();
}

void begin(){
	score = 0;
 	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			board[i][j] = 0;
		}
	}

	newNum();
}

void newNum(){
	int stay = 0;
	while (stay == 0){
		int holdX = rand() % 4;
		int holdY = rand() % 4;
		if (board[holdX][holdY] == 0){
			board[holdX][holdY] = 2;
			stay = 1;
		}
	}
	printBoard();
}
	
void endGame(){
	cout << "\033[2J\033[1;1H";
	cout << "GAME OVER" << endl << "Final score: " << score << endl;
}
};


int main(){
	board a;
	a.begin();
	return 0;
}
