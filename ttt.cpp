#include <iostream>
#include <cstring>

using namespace std;


int main(){

  char board[3][3] = {{0, 0, 0}, {0, 0,0}, {0, 0, 0}};
  int X_WINS = 0;
  int O_WINS = 0;
  int ties = 0;
  char player = 'X';
  bool X_TURN = false;
  int row;
  int column;
  bool playing = true;
  bool gameEnd = false;

  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      board[i][j] = '-';
    }
  }
  printBoard(board);
  takeTurn(player, board, X_WINS, O_WINS, ties);
  return 0;
}

bool validMove(int row, int column, char board[3][3]){

  if (board[row][column] == '-'){
    return true;
  }else if (board[row][column] == 'X' || board[row][column] == 'O'){
    return false;
  }else {
    return false;
  }
}

void placePlayer(char player, int row, int column, char board[3][3]){
  if (validMove(row, column, board)){
    board[row][column] = player;
  }
}

void printBoard(char board[3][3]){
  cout << "\n";
  cout << "\ta\tb\tc";
  for(int i = 0; i < 3; i++){
    cout << "/n" << endl;
    cout << i;
    for (int j = 0; j < 3; j++){
      cout << "\t" << board[i][j]<< "\t";
    }
    cout << "\n" << endl;
  }
}

void checkTie(char player, char board[3][3], int X_WINS, int O_WINS, int ties){

  if (board[0][0] == '-' || board[0][1] == '-' || board[0][2] == '-' || board[1][0] == '-'; || board[1][1] == '-' || board[1][2] == '-' || board[2][0] == '-' || board[2][1] == '-' || board[2][2] == '-'){
    cout << '   ' << endl;
  }else {
    ties += 1;
    player = 'T';
    promptUser(player, board, X_WINS, O_WINS, ties);
  }
}


bool checkWin(char player, char board[3][3]){
  if(board[0][0] == player && board[1][0] == player && board[2][0]){
    return true;
  }
  else if (board[0][2] == player && board[1][2] == player && board[2][2] == player){
    return true;
  }
  else if (board[0][0] == player && board[0][1] == player && board[0][2] == player){
    return true;
  }
  else if (board[0][1] == player && board[1][1] == player && board[2][1] == player){
    return true;
  }
  else if (board[1][0] == player && board[1][1] == player && board[1][2] == player){
    return true;
  }
  else if (board[2][0] == player && board[2][1] == player && board[2][2] == player){
    return true;
  }
  else if (board[0][0] == player && board[1][1] == player && board[2][2] == player){
    return true;
  }
  else if (board[0][2] == player && board[1][1] == player && board[2][0] == player){
    return true;
  }
}


void takeTurn(char player, char board[3][3], int X_WINS, int O_WINS, int ties){
  int row;
  int column;
  bool stillPlaying = true;

  while(stillPlaying){
    while (true){
      checkBoard(player, board, X_WINS, O_WINS, ties;
      cout << "Player " << player << "Please enter a row (0, 1, 2) for your move: " << endl;
      cin>>row;
      if (row == 0 || row == 1 || row == 2){
	break;
      }else {
	cout << "Please enter a valid input (0, 1, or 2): " << endl;
      }
		 
    }
    while (true){
      checkTie(player, board, X_WINS, O_WINS, ties);
      cout << "Player" << player << "please enter a number (0, 1, 2) for your move: " << endl;
      cin >> column;
      if (column ==0 || column == 1 || column ==2){
	break;
      } else {
	cout << "Please enter a valid move (0, 1, 2): " << endl;
      }
    }

    if (validMove(row, column, board) == false){
      printBoard(board);
      cout << "Enter your input again here: " << endl;
      takeTurn(player, board, X_WINS, O_WINS, ties);
    } else {
      ;
    }

    placePlayer(player, row, column, board);
    printBoard(board);

    if (player == 'X'){
      if(checkWin(player, board)){
	cout << player << " wins! Yay!" << endl;
	X_WINS += 1;
	promptUser(player, board, X_WINS, O_WINS, ties);
      }
      player = 'O';
      takeTurn(player, board, X_WINS, O_WINS, ties);
    } else{
      if (checkWin(player, board)){
	cout << player << " wins! Yay!" << endl;
	O_WINS += 1;
	promptUser(player, board, X_WINS, O_WINS, ties);
      }
      player = 'X';
      takeTurn(player, board, X_WINS, O_WINS, ties);
     
    }
  }
}

