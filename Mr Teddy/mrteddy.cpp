/**********************************************************
Project: Mr. Teddy!
Objective: Story RPG where you are on a journey to saving 
your favorite stuffed animal, Mr. Teddy

Goals:
- Include fighting (attack, defend, run)
 - Earn money by defeating enemies *DONE*
 - Find treasure *DONE* - New weapons
 - Look for enemies so it can trigger enemy fight to earn more buttons *DONE*
- Place to heal/rest (charge money for it) *DONE*
 - For each battle, each battle costs 10 HP. You die if health reaches 0
- Good ending/Bad ending *DONE*
 - Good: Nightmare defeated, you wake up and find Mr. Teddy
by your side
 - Bad: you lost to Nightmare, you wake up and find 1Mr. teddy not with you, you then remember you forgot to bring
him before uou moved to this new house.

Issues: 
- New weapon not showing up
- Counter issues 

Status: In progress
**********************************************************/
#include <iostream>
#include <unistd.h> //For timer
#include <stdlib.h>

using namespace std;

//Functions
/***********************New Function***********************/
void BadEnding(){
  cout << "Nightmare: You have failed to defeat me, you do not deserve Mr. Teddy. I will be lenient to let you go back to your world but he will stay here, where the lonely toys and children roam, in NIGHTOPIA." << endl;
  cout << "Nightmare uses his power and sends both you and Mr. teddy away into a vortex.\n" << endl;
  usleep(7000000);
  cout << "Mr. Teddy: It is of regret that I cannot stay with you but it has been an honor of being your friend, thank you." << endl;
  cout << "Mr. Teddy is vanished into the Bridge of the Lost.\n" << endl;
  usleep(5000000);
  cout << "---------------------------------------" << endl;
  cout << "|                 Home                |" << endl;
  cout << "---------------------------------------\n" << endl;
  usleep(3000000);
  cout << "You: Mr. Teddy!" << endl;
  cout << "You wake up panicking, again. You look to your side and Mr. Teddy isn't there." << endl;
  cout << "You start to sob realizing the truth: You and your family moved to a new house in a new neighborhood, but you forgot Mr. teddy when you left. You left him behind.\n" << endl;
  usleep(5000000);
  cout << "You: *Sobs* I'm sorry Mr. Teddy, I'm really sorry.\n" << endl;
  usleep(3000000);
  cout << "---------------------------------------" << endl;
  cout << "|         Kingdom of Nightmare        |" << endl;
  cout << "---------------------------------------\n" << endl;
  usleep(3000000);
  cout << "Nightmare: You have lost him alright. But one day, someone will come upon him and take him home and give him a new life." << endl;
  cout << "And there will be no more nightmares to come ...\n" << endl;
  usleep(7000000);
  cout << "The End" << endl;
};
/***********************New Function***********************/
void GoodEnding(){
  cout << "Nightmare: NO! THIS CAN'T BE! NOOOOOOO!" << endl;
  cout << "The light pierces through Nightmare. Suddenly, the land is filled with light and in front of you is a man armored in gold.\n" << endl;
  usleep(5000000);
  cout << "Hoperius: I am Hoperia, king of Sweetopia, a land of sweet dreams. My bad dream had taken over me, turning me into Nightmare. Now that he is gone, he shall be gone forever. You have not only saved me, but all of Sweetopia. Thank you. It is now my duty to send you home safe, are you ready?\n" << endl;
  usleep(5000000);
  cout << "You: Yes, let's go home, Mr. Teddy." << endl;
  cout << "Mr. Teddy: yes, let's go home.\n" << endl;
  usleep(3000000);
  cout << "Hoperius creates a portal, a portal that leads you and Mr. Teddy home. You walk through the portal and the path to Sweetopia closes behind you.\n" << endl;
  usleep(3000000);
  cout << "---------------------------------------" << endl;
  cout << "|                 Home                |" << endl;
  cout << "---------------------------------------\n" << endl;
  usleep(3000000);
  cout << "You: Mr. Teddy!" << endl;
  cout << "You wake up panicking, again. You look to your side and Mr. Teddy is sleeping right beside you. It was just a bad dream." << endl;
  cout << "You cry tears of joy and hug Mr. Teddy. You parents have rushed in to the room, asking if you are okay.\n" << endl;
  usleep(5000000);
  cout << "You: Yes, mommy, daddy. I am okay. I had a bad dream about Mr. Teddy being taken away from me but I defeated the bad guy." << endl;
  cout << "You are tucked into bed once again and fall fast alseep.\n" << endl;
  usleep(3000000);
  cout << "---------------------------------------" << endl;
  cout << "|       Kingdom of Sweet Dreams       |" << endl;
  cout << "---------------------------------------\n" << endl;
  usleep(3000000);
  cout << "Hoperius: Sweet dreams my child." << endl;
  cout << "And there will be no more nightmares to come ...\n" << endl;
  usleep(7000000);
  cout << "The End" << endl;
};
/***********************New Function***********************/
int replenish(int &h){
  h = 100;
  return h;
};
/***********************New Function***********************/
string newWeapon (string &w, string nw){
  w = nw;
  return w;
};
/***********************New Function***********************/
void battle (int &h, int &m, string &w, int &co){ 
  cout << "\nYou have encountered an enemy!" << endl;
  cout << "You fight fearlessly and defeat the enemy. You have gained 50 buttons" << endl;
  cout << "However, you have been injured and lose 10 HP\n" << endl;
  h = h - 10;
  m = m + 50; 
  co ++;
  if (co == 2){
    cout << "You have found an item: Rod of Good Dreams" << endl;
        cout << "It has now been set as your new weapon." << endl;
        newWeapon(w, "Rod of Good Dreams");        
      }
  else if (co == 4){
    cout << "You have found an item: Blade of Peace " << endl;
    cout << "It has now been set as your new weapon." << endl;
      newWeapon(w, "Blade of Peace");        
  }
  else if (co == 6){
    cout << "You have found an item: Sword of Light" << endl;
    cout << "It has now been set as your new weapon." << endl;
      newWeapon(w, "Sword of Light");        
  }
};
/***********************New Function***********************/
void options (char &p, int &c, int h, int m, string &w, int &co){  
  while(p == 'Y'){
    cout << "\nWhat would you like to do?" << endl;
    cout << "1. Search for enemies" << endl;
    cout << "2. Check my status" << endl;
    cout << "3. Proceed with journey" << endl;
    cin >> c;
    if(c == 1){
      battle (h, m, w, co); 
      if (h == 0){
        BadEnding();
      }
    }
    else if (c == 2){
      cout << "\nYour Status:" << endl;
      cout << "Health: " << h << "HP" << endl;
      cout << "Weapon: " << w << endl;
      cout << "Money: " << m << " buttons" << endl;
    }
    else if (c == 3){
      p = 'N';
      cout << "You have chosen to proceed.\n" << endl;
    }
  }
};
/***************************Main***************************/
int main() {
  //Variables
  int choice, choice2;
  char proceed = 'Y';
  int money = 0;
  int hp = 100;
  string weapon = "Flashlight";
  int counter = 0;
  
  //Title
  cout << "------------------------------------------------" << endl;
  cout << "|                    Mr. Teddy                 |" << endl;  
  cout << "------------------------------------------------" << endl;
  usleep(3000000);
  
/**********************Story Begins************************/
  cout << "It all begins in in the evening at a quiet home. You are a 3-year old who has been tucked in bed with Mr.Teddy. zZZ\n" << endl;
  usleep(3000000);
  cout << "---------------------------------------" << endl;
  cout << "|                 Home                |" << endl;
  cout << "---------------------------------------\n" << endl;
  usleep(3000000);
  cout << "You have this dream: You are having a lovely picnic with Mr. Teddy on a colorful field, enjoying a fresh cup of juice and some cookies. Suddenly, the sky turns dark and a big sharp hand quickly moves towards Mr. Teddy and GRABS him!\n" << endl;
  cout << "Nightmare: Want to save him? Meet me at the end of Nightopia MWA HA HA HA" << endl;
  cout << "And Nightmare vanishes with Mr. Teddy.\n" << endl;
  usleep (10000000);
  cout << "You: Mr. Teddy!" <<endl;
  cout << "You wake up panicking but calm down quickly as it was a dream, you turn to where Mr.Teddy should be but he's not there!" << endl;
  cout << "You search on the bed, under, over, and everywhere in the room, but he is nowhere to be found. You go to your parents room to ask for help.\n" << endl;
  usleep(7000000);
  cout << "You (sniffling): Mommy? Daddy? I can't find Mr. Teddy." << endl;
  cout << "You realize they are not in bed. You go downstairs, hoping they may be watching television but it is dark, so you go back to your room and grab a flashlight and head downstairs.\n" << endl;
  usleep(7000000);
  cout << "You: Mommy? Daddy? Where are you? I'm scared." << endl;
  cout << "You then see the front door opened and see a dim light shines through the gap. You know that you shouldn't open doors for strangers nor should go outside on your own but no one is home and you need help. You head towards the door and slowly open the door.\n" << endl;
  usleep(7000000);
  cout << "*Screech*" << endl;
  cout << "What is ahead of you is a road, and so your adventure in Nightopia begins ...\n" << endl;
  usleep(5000000);

/********************Adventure starts*********************/
/************************Nightopia************************/
  cout << "---------------------------------------" << endl;
  cout << "|               Nightopia             |" << endl;
  cout << "---------------------------------------\n" << endl;
  usleep(3000000);
  cout << "You are now in Nightopia, a land filled with monsters of the most famous nightmares in kids' dreams and lost/forgotten toys that have been abandoned by their owner.\n" << endl;
  usleep(5000000);
  
  /*******************Map******************/
  cout  << "You come upon a map of Nightopia. To reach the end of Nightopia, you must: " << endl;
  cout << "1. Pass through the Forest of Newmares" << endl;
  cout << "2. Proceed through the Cave of Misery" << endl; 
  cout << "3. Cross the Bridge of the Lost" << endl; 
  cout << "4. And then you will reach the Kingdom of Nightmare\n" << endl;
  usleep(7000000);

  cout << "After you read the map, to decide to head off to the Forest of Newmares.\n" << endl;
  usleep(3000000);
/********************Forest of Newmares********************/
  cout << "---------------------------------------" << endl;
  cout << "|         Forest of Newmares          |" << endl;
  cout << "---------------------------------------\n" << endl;
  usleep(3000000);
  //Situation: To gain a companion 
  cout << "You have now arrived at the Forest of Newmares, where children first arrive at from their nightmares.\n" << endl;
  usleep(3000000);
  cout  << "You have approached a lonely stuffed unicorn that has fallen down and can't get back up. She is calling for help and there are monsters coming towards her." << endl;
  cout << " You decide to: " << endl;
  cout  << "1. Sneak past the monsters through the monsters and make your escape" << endl;
  cout  << "2. Rush to the unicorns aid and fight the enemies" << endl;
  cin >> choice;
  cout << endl;
  /****************Battle Tutorial***************/
  if (choice == 2){
    battle (hp, money, weapon, counter);
  }
  /*******************Cutscene*******************/
  cout << "The enemies panick and run for their lives and you help the unicorn get back on its feet.\n" << endl;
  cout << "Unicorn: Thank you master for saving me, I am forever in your debt. To repay you, please ride on me and I will take you to where you shall go.\n" << endl;
  cout << "And off they head to the Bridge of the Lost." << endl;
  options (proceed, choice2, hp, money, weapon, counter);
  usleep(3000000);
/***********************Cave of Misery*********************/
  cout << "---------------------------------------" << endl;
  cout << "|            Cave of Misery           |" << endl;
  cout << "---------------------------------------\n" << endl;
  usleep(3000000);
  proceed = 'Y';
  cout << "You have arrived at the Cave of Misery, where children are in misery. Just like you, they came to find their lost toy, only to get stuck here and were forced to run and hide from the enemies every day, until they find the exit.\n" << endl;
  usleep(5000000);
  options (proceed, choice2, hp, money, weapon, counter);
  usleep(3000000);
  cout << "You shine your " << weapon << " and it leads you and all the children to the exit. You all have escaped the Cave of Misery!" << endl;
  cout << "You have now be friended the children from the cave and they continue the journey with you." << endl;
  usleep(5000000);
  /*******************Rest******************/ 
  cout << "You have now arrived at a very big inn. The owner comes out and greets you." << endl;
  cout  << "Owner: Hello masters, welcome. Would you like to take a rest before you proceed? It is getting dark out and it seems your weapon is losing light, I can even replace the batteries for your weapon. It will only cost you 100 buttons (Recover HP) per person." << endl;
  cout << " You decide to: " << endl;
  cout  << "1. Pay the 100 buttons and rest" << endl;
  cout  << "2. Politely decline and proceed with your journey" << endl;
  cin >> choice;
  if(choice == 1){
    replenish(hp);
    cout << "\nThe owner replaces new batteries for your weapon and it shines brighter than ever." << endl;
    cout << "Everyone else pays their fair share and you all have a good nap." << endl;
  }
  else if (choice == 2){
    cout << "You: Sorry, I will not be staying, I need to get to Mr. Teddy." << endl;
    cout << "Owner: Not a problem, please stay safe out there." << endl;
  }
  usleep(3000000);
  cout << "Before you leave, the owner stops you." << endl;
  cout << "Master, your weapon holds great power, it can help you get back to where you came from, but will only work once and you can never come back. Please use wisely." << endl;
  cout << "You understand and thank him for his advice." << endl;
  cout << "Hence, you and the children continue the journey and head to the Bridge of the Lost.\n" << endl;
usleep(7000000);
  
/*******************Bridge of the Lost*********************/
  cout << "---------------------------------------" << endl;
  cout << "|          Bridge of the Lost         |" << endl;
  cout << "---------------------------------------\n" << endl;
  usleep(3000000);
  proceed = 'Y';
  cout << "You have entered the Bridge of the Lost." << endl;
  cout << "Here lays the souls of toys that had lost their owners, they are looking for a new owner, or wanting to become the new owner ...\n" << endl;
  usleep(5000000);
  options (proceed, choice2, hp, money, weapon, counter);
  usleep(3000000);
  cout << "You have finally made it past the bridge. When you look back, you and the children realize that the lost souls are the toys that belonged to them. The children and the lost toys reunite with joy, happy to see each other again." << endl;
  cout << "You remember what the owner at the inn told you and you raise the staff in the air, commanding it to take the children who are reunited with toys home. They thank you for the help." << endl;
  cout << "Light shines and they all disappear." << endl;
  usleep(10000000);
  cout << "You: Mr. Teddy, I am coming for you, wait for me." << endl;
  cout << "You then head off with unicorn to your final destination, Kingdom of Nightmares.\n" << endl;
  usleep(3000000);
/*******************Kingdom of Nightmare*******************/
  cout << "---------------------------------------" << endl;
  cout << "|         Kingdom of Nightmare        |" << endl;
  cout << "---------------------------------------\n" << endl;
  usleep(3000000);
  cout  << "You have now arrived at the Kingdom of Nightmares, where Nightmare awaits with Mr. Teddy held hostage." << endl;
  usleep(3000000);
  cout  << "Nightmare: So you have finally made it." << endl;
  cout  << "You: Give back Mr. Teddy!" << endl;
  cout  << "Nightmare: Of course, but you will have to defeat me first ... if you can. MWA HA HA HA!" << endl;
  /*******************Boss Battle******************/
  usleep(5000000);
  cout << "You fight endlessly, dodge, take damage, and fight back ...\n" << endl;
  usleep(3000000);
  if (hp > 40){
    GoodEnding();
  }
  else {
    BadEnding();
  }
  
  return 0;
}