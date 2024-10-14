#include <iostream>

#include <cstring>

using namespace std;

void printBoard(int board[3][3]){
  int BLANK = 0;
  int X_MOVE = 1;
  int O_MOVE = 2;
  int X_TURN = 0;
  int O_TURN = 1;
  int X_WINS = 0;
  int O_WINS = 0;

  cout << "\t1\t2\t3\n" << endl;
  for (int i = 0; i < 3; i++){
    char letter = (char)('a' + i); //my mom said to do this so i did it!
    cout << letter << "\t";
    for (int j = 0; j < 3; j++) {
      if(board[i][j] == BLANK){
	cout << "\t";
      }else if(board[i][j] == X_MOVE){
	cout << "X\t";
      } else if(board[i][j] == O_MOVE){
	cout << "O\t";
      }
      
  }
    cout << "\n";
  }
    

}

void clearBoard(int board[3][3]){
  int BLANK = 0;
  for (int row = 0; row < 3; row++){
    for (int column = 0; column < 3; column++){
      board[row][column] = BLANK;
    }
  }
}


bool checkTie(int board[3][3]){
  int BLANK = 0;
  for(int row = 0; row < 3; row++){
    for (int column = 0; column < 3; column++){
      if(board[row][column] == BLANK){
	return false;
      }
    }
  }
  return true;
}


bool checkWin(int player, int board[3][3]){

  if (board[0][0] == player && board[0][1] == player && board[0][2] == player){
    return true;
  }
  else if(board[1][0] == player && board[1][1] == player && board[1][2] == player){
    return true;
  }
  else if(board[2][0] == player && board[2][1] == player && board[2][2] == player){
    return true;
  }
  else if(board[0][0] == player && board[1][0] == player && board[2][0] == player){
    return true;
  }
  else if(board[0][1] == player && board[1][1] == player && board[2][1] == player){
    return true;
  }
  else if(board[0][2] == player && board[1][2] == player && board[2][2] == player){
    return true;
  }
  else if(board[0][0] == player && board[1][1] == player && board[2][2] == player){
    return true;
  }
  else if(board[2][0] == player && board[1][1] == player && board[0][2] == player){
    return true;
  }else {
    return false;
  }
}

void playAgain(int board[3][3], O_MOVE, X_MOVE){
  char ans[10];
  bool playing = true;
 if (checkWin(X_MOVE, board) == true || checkWin(O_MOVE, board) == true || checkTie(board) == true){
         cout << "Do you want to play again? (yes or no)" << endl;
         cin >> ans;

         if (strcmp(ans, "yes") == 0){
             clearBoard(board);
             playing = true;
         }else if (strcmp(ans, "no") == 0){
          cout << "Thanks for playing!" << endl;
          //      break;
         }else {
          cout << "Invalid input! Please enter 'yes' or 'no': " << endl;
         }
       }


}  


int main(){
  	int BLANK = 0;
	int X_MOVE = 1;
	int O_MOVE = 2;
	int X_TURN = 0;
	int O_TURN = 1;
	int X_WINS = 0;
	int O_WINS = 0;
	int TIE = 0;
	char blah[10];
	int board[3][3];
	int turn = X_TURN;
	bool playing = true;
	char ans[10];
	clearBoard(board);
    while(playing){
	  printBoard(board);
	  cout << "\n" << endl;
	  cout << "Place your move by inputting a letter followed by a number (e.g. a1 or b2): " << endl;
	  cin >> blah;
	  cout << "\n";

	  if (strlen(blah) != 2){
	    cout << "Invalid input! Please enter a letter followed by a number (e.g. a1 or b2): " << endl;
	  }
	  else if (blah[0] == '1'){
	    playing = false;
	  }
	  else if (blah[0] != 'a' && blah[0] != 'b' && blah [0] != 'c'){
	    cout << "Invalid input! The first character must be a letter (a, b, or c): \n" << endl;
	  }
	  else if (blah[1] != '1' && blah[1] != '2' && blah[2] != '3'){
	    cout << "Invalid input! The second character must be a number (1, 2, or 3): \n" << endl;
	
	  }
	  else {
	    int row = (char)(blah[0] - 'a');
	    int column = (char)(blah[1] - '1');
	    if(board[row][column] == BLANK){
	      if(turn == X_TURN){
		board[row][column] = X_MOVE;
		turn = O_TURN;
	      } else {
		board[row][column] = O_MOVE;
		turn = X_TURN;
	      }
	    } else {
	      cout << "Invalid move! There is already a piece there \n" << row << ", " << column;
	    }
	  }

	  if (checkWin(X_MOVE, board)){
	    printBoard(board);
	      X_WINS++;
	      turn = X_TURN;
	      cout << "\n X won! "<< endl;
	      cout << "X wins: "<< X_WINS << "\t O Wins: " << O_WINS << "\t Ties: " << TIE << endl;
	      clearBoard(board);
	      playAgain(board, O_MOVE, X_MOVE);
	   }else if(checkWin(O_MOVE, board)){
		clearBoard(board);
		O_WINS++;
		turn = X_TURN;
		cout << "\nO Won!\n";
		cout << "\nX Wins: " << X_WINS << "\tO Wins: " << O_WINS << "\tTies: " << TIE << "\n\n";
	
	  }else if(checkTie(board)) {
	    TIE++;
	    clearBoard(board);
	    turn = X_TURN;
	    cout << "\nIt is a tie!\n";
	    cout << "\nX Wins: " << X_WINS << "\tO Wins: " << O_WINS << "\tTies: " << TIE << "\n\n";
	
	  }
    

	  /*   if (checkWin(X_MOVE, board) == true || checkWin(O_MOVE, board) == true || checkTie(board) == true){
	 cout << "Do you want to play again? (yes or no)" << endl;
	 cin >> ans;

	 if (strcmp(ans, "yes") == 0){
	     clearBoard(board);
	     playing = true;
	 }else if (strcmp(ans, "no") == 0){
	  cout << "Thanks for playing!" << endl;
	  //	  break;
	 }else {
	  cout << "Invalid input! Please enter 'yes' or 'no': " << endl;
	 }
	 }*/
    }    
return 0;

}





