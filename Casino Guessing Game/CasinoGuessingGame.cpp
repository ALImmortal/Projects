/**********************************************
Project: Casino Number Guessing Game
Objective: Make a guessing game where users put a bet on guessing a number from 1 - 10

What I need:
- Function to make sure bet is 
**********************************************/
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

// Function to confirm if game is to br proceeded or not and to make sure there is no errors
bool continueGame (char& c){
  //Conditions for what user enters to proceed or end game
  char d;
  if(c == 'Y' || c == 'y'){
    return true;
  }
  else if (c == 'N' || c == 'n'){
    return false;
  }
  else {
    cout << "The response you entered is incorrect. Please try again." << endl;
    cout << "Enter 'Y' or 'N': ";
    cin >> c;
    return continueGame(c);
  }
}

//Function to make sure guess user enters is valid (Guess is between 1-10)
int checkNum(int& i){
  if(i >= 1 && i <= 10){
    return i;
  }
  else{
    cout << "The number you entered is not from 1 - 10." << endl;
    cout << "Please enter a number that is between 1 - 10: ";
    cin >> i;
    return checkNum(i);
  }
}

//Function to make sure guess user enters is valid (Amount of money available)
double checkAmt(double& j){
  if(j > 0){
    return j;
  }
  else{
    cout << "It seems you do not have enough funds, did you make a typo?"<< endl;
    cout << "How much money will you be putting into the game?";
    cin >> j;
    return checkAmt(j);
  }
}

//Main code
int main(){
//Variables
string player;
double moneyAvailable;
double moneyBet;
int guess;
int randNum;
char con = 'Y';

//Welcome Message: explain rules of game
cout << "-------------------------------------------------------------------" << endl;
cout << "***********************Casino Guessing Game***********************" << endl;
cout << "-------------------------------------------------------------------" << endl;
cout << "Welcome to the Casion Guessing Game!" <<endl;
cout << "So what's your name? ";
cin >> player;
cout << "Great to see you join, " << player << "!" << endl;
cout << endl;
//Explain rules of the game
cout << "*******************************Rules*******************************" << endl;
cout << "The rules are simple: " << endl;
cout << "Make a bet and guess a number between 1 - 10. If it's right, you win and you get money added to your balance! Guess it wrong, you lose the bet and we deduct the bet from your balance ..." << endl;
cout << "*******************************************************************" << endl;
cout << endl;
//Ask for how much money you have that he/she/they want to put into game
cout << "To start, how much money will you be putting into the game? ";
cin >> moneyAvailable;
cout << "You have now put in $" << moneyAvailable << " into the game! Enjoy!" <<endl;
//Need to make sure user enters an amount greater than 0
checkAmt(moneyAvailable);

//While loop: The game starts
while(continueGame(con) == true && moneyAvailable > 0){
  //Ask for bet
  cout << endl;
  cout << "What is your bet? ";
  cin >> moneyBet;
  cout << endl;

  //Need to end game if balance is $0
  if (moneyBet > moneyAvailable){
    cout << "You don't have enough money to make the bet." << endl;
    break;
  }
  //Guess a number
  cout << "Guess a number from 1 to 10: ";
  cin >> guess;
  //Need to make sure number entered matches criteria of being from 1 - 10
  checkNum(guess);
  cout << endl;

  //Generate the random number
  randNum = (rand()%10)+1;
  //COmpare the guess and random number geenrated
  if (guess == randNum) {
    cout << "Yes! The number is: " << randNum << endl;
    moneyAvailable = moneyAvailable + moneyBet;
  }
  // Need condiiton if number does not meet requirement
  //If guess is wrong
  else {
    cout << "Sorry, the number is: " << randNum << endl;
    moneyAvailable = moneyAvailable - moneyBet;
  }
  //Displays user’s current balance
  cout << endl;
  cout << "Current Balance: $" << moneyAvailable << endl; 
  //Conditions for what user enters to proceed or end game
  //Ask if user wants to proceed
  cout << endl;
  cout << "Would you like to place another bet? Please respond with Y (for Yes) or N (for No): ";
  cin >> con;
  continueGame(con);
  }

//Announce results of game after user chooses not to proceed
//Make some space for results
cout << endl;
cout << "-------------------------------------------------------------------" << endl;
cout << "*******Thank you for playing the Casino Guessing Game!*******" << endl;
cout << "-------------------------------------------------------------------" << endl;
cout << "Results:" << endl;
cout << "Player: " << player << endl;
cout << "Total you have now: $" << moneyAvailable << endl;

return 0;
}