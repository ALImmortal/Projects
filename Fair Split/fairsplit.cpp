#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h> 
using namespace std;

//Class : Expense
class Expense{
  public:
    string whatExpense;
    double amount;
    string owner;

  Expense(string we, double a, string o){
    whatExpense = we;
    amount = a;
    owner = o;
  }

  string setNameExp(string we){
    whatExpense = we;
    return whatExpense;
  }

  string getNameExp(){
    return whatExpense;
  }

  int setExp(double d){
    amount = d;
    return amount;
  }
  int getExp(){
    return amount;
  }

  string setName(string o){
    owner = o;
    return owner;
  }

  string getName(){
    return owner;
  }

};
//Class: Person
class Person{
  public:
    int groupNum;
    string name;
    double spent;
    double owe;
    vector <Expense> expMade;
    vector <Expense> expOwed;
    
  
    Person(int gn, string n){
      groupNum = gn;
      name = n;
      spent = 0;
      owe = 0;
    }

    //Group Number
    int setGN(int gn){
      groupNum = gn;
      return groupNum;
    }
    int getGN(){
      return groupNum;
    }

    //Name
    string getName(){
      return name;
    }
    string setName(string n){
      name = n;
      return "Name has been set to: " + name + "\n";
    }

    //Add expense
    double addSpent(double a){
      spent = spent+ a;
      return spent;
    }
    double getSpent(){
      return spent;
    } 

    //Add how much you owe
    double addOwe(double o){
      owe = owe + o;
      return owe;
    }   
    double getOwe(){
      return owe;
    } 

    void listOwe(Person p){
      for(int i=0;i<expOwed.size();i++){
        cout << expOwed[i].getName() << ": "; 
      }
    }
};

int main() {
  //Title
  cout << "------------------------------------------------" << endl;
  cout << "|                                              |" << endl;
  cout << "|                 *FairSplit*                  |" << endl;
  cout << "|          Split those expenses right!         |" << endl;
  cout << "------------------------------------------------" << endl;
  
  //Introduction
  cout << "So you finally have to split the bill right? How do they want to split? Equally, just by what was ordered, or both? We got you covered. Just let me know the following information and I'll get the math done for you." << endl;
  cout << "1. The people involved,\n2. The expense,\n3. Who owes who from that expense." << endl;

  //Variables
    int groupNumber = 1; //Make a Person class that has expenses?
    bool proceed = true; //Start as true and change to false once ready to end program
    int choice;
    string namePerson;
    Person p(groupNumber, namePerson);
    vector <Person> group;
    string nameExpense;
    double exp;
    Expense e(nameExpense, exp, namePerson);

  while (proceed == true){
    //Option Menu: Make presentation simple
    cout << "\nMenu:\n";
    cout << "1. Add person (Please add all names involved before adding expenses)\n";
    cout << "2. Add expense\n";
    cout << "3. Check current status\n";
    cout << "4. Finalize and end program\n";

    //Enter option
    cout << "\nWhat would you like to do? ";
    cin >> choice;

    //Choices
    if(choice == 1){
      cout << "\nCan I get the name? ";
      cin >> namePerson;
      p.setName(namePerson);
      p.setGN(groupNumber);
      cout << "\n" << endl;      
      group.push_back(p);
      cout << namePerson <<" has been added.\n";
      cout << "Group Number assigned: " << groupNumber << "\n";
      groupNumber++;
    }
    else if(choice == 2){
      //Name of expense
      cout << "\nPlease enter the name of the expense: ";
      cin >> nameExpense;
      e.whatExpense = nameExpense;
      cout << endl;
      //Amount of expense
      cout << "Please enter the amount of the expense: ";
      cin >> exp;
      e.amount = exp;
      cout << endl;
      //Who owns this expense
      cout << "Please enter who paid the expense: ";
      cin >> namePerson;
      e.owner = namePerson;
      cout << endl;

      //Return the expense added
      cout << "\nYou have added a new expense:\n";
      cout << "Expense: "<< nameExpense <<"\n";
      cout << "Amount: $"<< exp <<"\n";
      cout << "Owner: "<< namePerson <<"\n";  

      //Add expense to vectors expMade and expOwed
      //Find the person
      for (int i=0;i<group.size();i++){
        //Add to madeExpense
        if(group[i].getName()==namePerson){
          group[i].expMade.push_back(e);
          group[i].addSpent(exp);
        }
        else if(group[i].getName()!=namePerson){
          group[i].expOwed.push_back(e);
          group[i].addOwe(exp/(group.size()));
        }
      }
    }
    else if (choice == 3){
      cout << "\nWho do you want to get status for? ";
      cin >> namePerson;
      cout << endl;
      //Find the person
      for (int i=0;i<group.size();i++){
        if(group[i].getName()==namePerson){
          cout << "ID: " << group[i].getGN() << endl;
          cout << "Name: " << group[i].getName() << endl;
          cout << "Spent: " << group[i].getSpent() << endl;
          cout << "Owes: " << group[i].getOwe() << endl;
          cout << endl;

          //List Expenses made
          cout << "Expenses Made\n";
          for (int j=0;j<group[i].expMade.size();j++){
            cout << "Expense: " << group[i].expMade[j].getNameExp() << endl;
            cout << "Amount: " << group[i].expMade[j].getExp() << "\n\n";
          }
        }
      }
    }
    else if(choice == 4){
      //Return all users expenses/owes
      cout << "\nHere are the results:\n";
      for (int i=0;i<group.size();i++){
        cout << "ID: " << group[i].getGN() << endl;
        cout << "Name: " << group[i].getName() << endl;
        cout << "Spent: " << group[i].getSpent() << endl;
        cout << "Owes: " << group[i].getOwe() << endl;
        cout << endl;
      }

      //Ending message
      cout << "Thank you for using this program, hope to have helped you get the split as fair as possible.";
      proceed = false;
    }
    else{
      cout << "The choice you selected was incorrect. Please restart program.\n";
      proceed = false;
    }
  }
}