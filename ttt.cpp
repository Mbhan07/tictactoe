#include <iostream>

#include <cstring>

/*

This is a two player tic-tac-toe game. Created by Mahika Bhan, 10/15/2024

Concepts of interest:

 - using cstring library to compare user input
 - using for loops to iteratre through two dimensional arrays
 - using functions/methods to avoid redundancy
 - enjoy!
 - this is my 3rd different variation of this project
 */  


using namespace std;



//print the board
void printBoard(int board[3][3]){
  int BLANK = 0;
  int X_MOVE = 1;
  int O_MOVE = 2;
  int X_TURN = 0;
  int O_TURN = 1;
  int X_WINS = 0;
  int O_WINS = 0;

  //prints the numbered columns
  cout << "\t1\t2\t3\n" << endl;
  for (int i = 0; i < 3; i++){ //iterate through a two dimensional array
    char letter = (char)('a' + i); //my mom said to do this so i did it!
    cout << letter << "\t"; // output the letter rows
    for (int j = 0; j < 3; j++) {
      if(board[i][j] == BLANK){ // if board is blank, indent
	cout << "\t"; 
      }else if(board[i][j] == X_MOVE){ // if it is X move, print X
	cout << "X\t";
      } else if(board[i][j] == O_MOVE){
	cout << "O\t";
      }
      
  }
    cout << "\n";
  }
    

}

//to clear the board of any moves
void clearBoard(int board[3][3]){
  int BLANK = 0;
  //iteratre through two dimensional array and every coordinate should be blank
  for (int row = 0; row < 3; row++){
    for (int column = 0; column < 3; column++){
      board[row][column] = BLANK;
    }
  }
}

//check for ties by seeing if every spot is filled
bool checkTie(int board[3][3]){
  int BLANK = 0;
  for(int row = 0; row < 3; row++){
    for (int column = 0; column < 3; column++){
      if(board[row][column] == BLANK){
	return false; // if any spot is not filled, tie is not true
      }
    }
  }
  return true;
}

//check for wins, diganoal, vertical, or horizontal
//return true if the case is met, return false otherwise
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
//prompts the user after a win,or tie
void playAgain(int board[3][3], int X_MOVE, int O_MOVE){
  char ans[10];
  int X_TURN = 0;
  int turn = X_TURN;
  bool playing = true;
  //if win, or tie is true, the following should happen
 if (checkWin(X_MOVE, board) == true || checkWin(O_MOVE, board) == true || checkTie(board) == true){
   //ask user if they want to play again

         cout << "Do you want to play again? (yes or no)" << endl;
         cin >> ans;
	 //use strcmp to determine if user entered yes or no
         if (strcmp(ans, "yes") == 0){
             clearBoard(board);
             playing = true; // if yes, clear board and restart the loop
         }else if (strcmp(ans, "no") == 0){ //else, thank them for their time and exit loop
          cout << "Thanks for playing!" << endl;
          exit(0);
         }else { //ensures that they input the right thing
          cout << "Invalid input! Please enter 'yes' or 'no': " << endl;
         }
       }
       }  


int main(){

  //necessary variables
  	int BLANK = 0;
	int X_MOVE = 1;
	int O_MOVE = 2;
	int X_TURN = 0;
	int O_TURN = 1;
	int X_WINS = 0;
	int O_WINS = 0;
	int TIE = 0;
	char blah[10];
	int board[3][3]; // initialize gameboard
	int turn = X_TURN;
	bool playing = true;
	char ans[10];
	clearBoard(board);
	while(playing){ //while the game is actively happening
      int row;
      int column;
      printBoard(board); //print the board and check for tie first so that gameplay can flow smoothly
      if(checkTie(board) == true){ // if there is a tie
	    //cout <<"test" << endl;
	printBoard(board); //print board, incrrement number of ties
	    TIE++;
	    cout << "It's a tie!" << endl; //inform user and print number of wins
	    cout << "X wins: " << X_WINS << "\tO wins: " << O_WINS << "\tTies: " << TIE << endl;
	    playAgain(board, X_MOVE, O_MOVE); //prompt user for next steps
	    turn = X_TURN; //switch turn
	  }
	  
      cout << "\n" << endl; //instruct user how to enter inputt
	  cout << "Place your move by inputting a letter followed by a number (e.g. a1 or b2): " << endl;
	  cin >> blah;
	  cout << "\n";

	  if (strlen(blah) != 2){ // if length is more than two, prompt user to enter proper input
	    cout << "Invalid input! Please enter a letter followed by a number (e.g. a1 or b2): " << endl;
	  }
	  else if (blah[0] != 'a' && blah[0] != 'b' && blah [0] != 'c'){ // if the first character is not a letter
	    cout << "Invalid input! The first character must be a letter (a, b, or c): \n" << endl;
	  }
	  else if (blah[1] != '1' && blah[1] != '2' && blah[1] != '3'){ // if the second character is not a number
	    cout << "Invalid input! The second character must be a number (1, 2, or 3): \n" << endl;
	
	  }
	  else { // covert the letter/number input to coordinates on the game board
	    if (strcmp(blah, "a1") == 0){
	      row = 0;
	      column = 0;
	    }else if(strcmp(blah, "a2") == 0){
	      row = 0;
	      column = 1;
	    }else if (strcmp(blah, "a3") == 0){
	      row = 0;
	      column = 2;
	    }
	    else if (strcmp(blah, "b1") == 0){
	      row = 1;
	      column = 0;
	    }
	    else if (strcmp(blah, "b2") == 0){
	      row = 1;
	      column = 1;
	    }
	    else if (strcmp(blah, "b3") == 0){
	      row=  1;
	      column = 2;
	    }
	    else if (strcmp(blah, "c1") == 0){
	      row = 2;
	      column = 0;
	    }
	    else if (strcmp(blah, "c2") == 0){
	      row = 2;
	      column = 1;
	    }
	    else if(strcmp(blah, "c3") == 0){
	      row = 2;
	      column = 2;
	    }
	    if(board[row][column] == BLANK){ // if the coordinate given is blank, 
	      //cout << row << ", " << column << endl;
	      if(turn == X_TURN){ // if it is X's turn, place X, then check for wins
		board[row][column] = X_MOVE;
		if (checkWin(X_MOVE, board) == true){// if true, 
		  printBoard(board); //print the final game board, increment number of x wins, inform user, and ask if they want to play again
		  X_WINS++;
		  cout << "X wins! " << endl;
		  cout << "X wins: " << X_WINS << "\t O Wins: "<< O_WINS << "\tTies: " << TIE << endl;
		 playAgain(board, X_MOVE, O_MOVE);
		 //cout <<"Theoretically, it should switch to X here." << endl;
		 turn = X_TURN; // if win, turn should go back to x 
		}else { // else, turn goes back to o
		  //cout << "Is this why it's not starting with X?" << endl;
		turn = O_TURN;
		}
		
	      } else if (turn == O_TURN){ // if it is O's turn, place O where they have given the coordinates
		board[row][column] = O_MOVE;
		// check if O has won
		if(checkWin(O_MOVE, board)){
		  //cout << "gaga" << endl; 
		  printBoard(board); //print final board, increment O wins, inform user they won and prompt to play again
		    O_WINS++;
		    cout << "O won!"<< endl;
		    cout << "X wins: " << X_WINS << "\t O Wins: "<< O_WINS << "\t Ties: " << TIE << endl;
		    playAgain(board, X_MOVE, O_MOVE);
		    turn = X_TURN; // switch turn
		}else{
		  //cout << "O should switch to X move after winning here." << endl;
		  turn = X_TURN; // should switch to X normally, but this is outside of the win condition
		}
	      }
	    }else{ // if spot is not blank, tell user that there is already a piece there
	      cout << "Invalid move! There is already a piece there \n" << row << ", " << column;
	    }
	  }

       }    
return 0;

}

// thanks!


//            > - <
//          ( ^   ^ )
//          (       )
//            ^  ^



