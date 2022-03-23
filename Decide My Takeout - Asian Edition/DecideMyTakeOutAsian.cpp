/***********************************************************
Project: Decide My takeout - Asian Edition
Objective: Select a dish to recommend to user by random. 
User: Someone who is new to Asian cuisine and not sure what to try

Outcome: Selects a random dish for user to try

Things to Know: This program will only provide a few options per cuisine, would be like a starter pack to recommend a dish that people usually order
***********************************************************/
#include <iostream>
#include <string>
#include <vector> //For Cuisines
#include <unistd.h> //For timer
#include <stdlib.h>

using namespace std;

int main() {
  //Variables
  string Cuisine [] = {"Thai", "Korean", "Chinese", "Vietnamese", "Japanese", "Cantonese", "Burmese", "Malaysian", "Indian"};
  string Thai [] = {"Pad Thai", "Pad See Ew", "Green Curry", "Drunken Noodles", "Thai Curry (yellow, Penang, Green)" };
  string Korean [] = {"Bibimbap", "Nangmyeon", "Jajangmyeon", "Korean BBQ", "Korean Fried Chicken", "Soondubu Jjigae"};
  string Chinese [] = {"Fried Rice/Noodles", "Noodles w Peanut Sauce", "Hand Pulled Noodles", "Congee/Porridge", "Soup/Boiled/Fried Dumplings", "Mapo Tofu"};
  string Vietnamese [] = {"Pho", "Beef Vermicelli", "Ban Xeo (Savory Crepe)", "Bun Bo Hue (Noodles)", "Bahn Mi (Sandwich)"};
  string Japanese [] = {"Sushi/Sashimi", "Udon/Soba in Soup/Stir Fry", "Tempura", "Ramen", "Japanese Curry", "Tonkatsu", "Omurice"};
  string Cantonese [] = {"Stir Fried Noodle", "Baked Protugese Rice/Noodles", "Claypot Rice", "Dim Sum", "Barbecued Meat over Rice", "Wonton Noodle Soup", "Rice Rolls (Savory Crepes)", };
  string Burmese [] = {"Chicken Curry", "Ohn No Khao Swè", "Meeshay", "Dan Bauk", "Kyay Oh"};
  string Malaysian [] = {"Mee goreng", "Nasi Lemak", "Rendang", "Laksa Noodle Soup", "Char Kuey Teow", "Wonton Mee"};
  string Indian [] = {"Masala Dosa", "Chicken Tikka Masala", "Butter Chicken", "Tandoori Chicken", "Curry"};
  
  string *CuisineChoice;
  string DishChoice;
  char dChoice;

  int cCuisine;
  int rDish; //generate a random number for Cuisine chosen
  
  //Program starts
  //Intro/Banner
  cout << "--------------------------------------------" << endl;
  cout << "|    Decide My Takeout - Asian Edition.    |" << endl;
  cout << "------------------------------------------\n" << endl;
  
  cout << "So hungry! Time to choose meal for the day, but this will be different." << endl;
  cout << "Choose a cuisine you have not tried before and we will recommend a dish for you to try. Maybe you want to choose an Asian cuisine you had before? That is fine!\n" << endl;
  //Allow user to choose a cuisine
  //We should allow users to choose a cuisine that interests him/her
  cout << "So the first question to get you hungry, what cuisine are you interested in today?\n" <<endl;
  cout << "1. Thai\n2. Korean\n3. Chinese\n4. Vietnamese\n5. Japanese\n6. Cantonese\n7. Burmese\n8. Malaysian\n9. Indian\n" << endl;
  cin >> cCuisine;

  //Set CuisineChoice
  switch (cCuisine){
    case 1:
      CuisineChoice = Thai;
      break;
    case 2:
      CuisineChoice = Korean;
      break;
    case 3:
      CuisineChoice = Chinese;
      break;
    case 4:
      CuisineChoice = Vietnamese;
      break;
    case 5:
      CuisineChoice = Japanese;
      break;
    case 6:
      CuisineChoice = Cantonese;
      break;
    case 7:
      CuisineChoice = Burmese;
      break;
    case 8:
      CuisineChoice = Malaysian;
      break;
    case 9:
      CuisineChoice = Indian;
      break;
  }

  //Show what user chose
  cout << "You chose: " << Cuisine[cCuisine-1] << endl;
  //Randomly selected dish from the Cuisine
  //Put a timer
  cout << "\nNow, time to select a dish for you. We are now searching...\n";
  usleep(1000000); 
  cout << "searching...\n" ;
  usleep(1000000);
  cout << "searching...\n\n" ;
  
  //Select the dish
  rDish = rand() % (sizeof(CuisineChoice)/sizeof(int));
  //Need to access chosen Cuisine
  DishChoice = CuisineChoice [rDish];

  //Result
  usleep(1000000);
  cout << "Ahh! I have found it! The dish that has been selected is: " << DishChoice << ", a " << Cuisine[cCuisine-1]<< " dish." << endl;
  usleep(500000);
  cout << "Try to look up this dish on Google or Yelp and find the restaurant near you.\n" <<endl;

  //Also recommend a dessert/drink and can also recommend an appetizer
  //Switch case: dessert/drink/appetizer
  switch (cCuisine){
    case 1:
      usleep(1000000);
      cout << "I also recommend a Thai Tea/Coffee or Tom Yum soup along with your meal. If you want an appetizer/dessert try the Papaya Salad or Mango Sticky Rice.\n" <<endl;
      break;
    case 2:
      usleep(1000000);
      cout << "I also recommend mandu (dumplings) as an appetizer. Try some sikhye (rice drink) if you are thirsty from the heat!\n" <<endl;
      break;
    case 3:
      usleep(1000000);
      cout << "Along with your meal, get a hot and sour soup for the spice or some dumplings.\n" <<endl;
      break;
    case 4:
      usleep(1000000);
      cout << "If you need some appetizers, spring rolls (either fresh or fried) are soooo good! You can also get your hands on a Vietnamese Three Color Dessert, which is a dessert and drink, at the same time!\n" <<endl;
      break;
    case 5:
      usleep(1000000);
      cout << "Clean you palette with a green salad that comes with ginger dressing or a miso soup. For dessert, get a taiyaki (if available) or ice cream mochi.\n" <<endl;
      break;
    case 6:
      usleep(1000000);
      cout << "Most meals would be served with a free soup. If you are at a cafe, mixed sauce rice rolls are amazing or get condensed milk toast as a sweet.\n" <<endl;
      break;
    case 7:
      usleep(1000000);
      cout << "Get your hands on some coconut jelly or some dumplings!\n" <<endl;
      break;
    case 8:
      usleep(1000000);
      cout << "Satay chicken/beef skewers is a great appetizer for a savory and nutty dip or a roti with chicken curry dip is amazing too! Kaya toast for the sweet!\n" <<endl;
      break;
    case 9:
      usleep(1000000);
      cout << "Samosas can be a great appetizer to compliment your meal or add a Gulab Jamun as your dessert!\n" <<endl;
      break;
  }

  //End
  usleep(3000000);
  cout << "Hope you enjoy your meal! " << endl;
  
  return 0;
}