/***********************************************************
Project: Tic Tac Toe
Objective: Play a game of Tic Tac Toe with computer
Status: Complete
************************************************************/
#include <iostream>
#include <array>
#include <stdlib.h>

using namespace std;
//Functions
int randOrow(int &o){
  o = rand()%3;
  return o;
};

int randOcol(int &o){
  o = rand()%3;
  return o;
};

//Main
int main() {
  //Variables
  string playerName;
  char grid[3][3];
  char xX = 'X';
  char oO = 'O';
  bool winX = false;
  bool winO = false;
  //Logo
  cout << "T|I|C" << endl;
  cout << "- - -" << endl;
  cout << "T|A|C" << endl;
  cout << "- - -" << endl;
  cout << "T|O|E" << endl;
  //Welcome Message
  cout << "Welcome to the game of Tic Tac Toe!" << endl;
  cout <<"2 person game whom the first to get 3-in-a-row wins!" << endl;
  //User can decide if they want to go against computer or another player
  cout << "So, what is your name? ";
  cin >> playerName;
  cout << "\nHey! "<<playerName<<"! Welcome to the game!"<<endl;
  cout << "You will be X for this game.\n"<<endl;
  
  //Start the game
  for(int i=0; i<3; i++){
    for (int j=0; j<3; j++){
      grid[i][j]='?';
      cout << grid[i][j];
      if (j<2){
        cout<< "|";
      }         
    }
    cout << endl;
    if(i<2){
      cout << "- - -" << endl;
    }
  }
  int availGrid=9;
  int a,b;
  int c,d;

  //Switch cases OR should I change to while loop?
  while(availGrid != 0 && (winX == false && winO == false)){
    cout << "\nOkay, " << playerName <<"! Enter where to put your choice (rows 0-2 and column 0-2. Ex: 0 2)" << endl;
    cin >> a >> b;
    if(grid [a][b]=='?'){
      grid[a][b]=xX;
    }
    for(int i=0; i<3; i++){
      for (int j=0; j<3; j++){
        cout << grid[i][j];
        if (j<2){
          cout<< "|";
        }         
      }
      cout << endl;
      if(i<2){
        cout << "- - -" << endl;
      }
    }
    availGrid--;
    cout << endl;
  //Determine if there was a win
  //Rows
  if(grid[0][0]==xX && grid[0][1]==xX && grid[0][2]==xX){
    winX = true;
  }
  else if(grid[1][0]==xX && grid[1][1]==xX && grid[1][2]==xX){
    winX = true;
  }
  else if(grid[2][0]==xX && grid[2][1]==xX && grid[2][2]==xX){
    winX = true;
  }
  //Colums
  else if(grid[0][0]==xX && grid[1][0]==xX && grid[2][0]==xX){
    winX = true;
  }
  else if(grid[0][1]==xX && grid[1][1]==xX && grid[2][1]==xX){
    winX = true;
  }
  else if(grid[0][2]==xX && grid[1][2]==xX && grid[2][2]==xX){
    winX = true;
  }
  //Diagonal
  else if(grid[0][0]==xX && grid[1][1]==xX && grid[2][2]==xX){
    winX = true;
  }
  else if(grid[0][2]==xX && grid[1][1]==xX && grid[2][0]==xX){
    winX = true;
  }
  else{
    winX = false;
  }

  if(winX == true){
    cout << endl;
    cout << "We have a winner! You beat O!!!"<<endl;
    cout << "Thank you for playing the game!"<<endl;
    break;
  }
    //Maybe want to delay O's output a bit, to make it look like O is thinking
    //O's turn (Computer) 
    //Print out O's move
    int o1;
    int o2;

    cout << endl;
    cout << "Now it's O's turn" <<endl;
    cout << "O is making it's turn ..." << endl;

    //O makes a move
    do{
      randOrow(o1);
      randOcol(o2);
      if(grid[o1][o2]=='?'){
        grid[o1][o2]='O';
        break;
      }
    }
    while(grid[o1][o2]=='?');

    
    for(int i=0; i<3; i++){
      for (int j=0; j<3; j++){
        cout << grid[i][j];
        if (j<2){
          cout<< "|";
        }         
      }
      cout << endl;
      if(i<2){
        cout << "- - -" << endl;
      }
    }
    availGrid--;
  }

}