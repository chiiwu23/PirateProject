//*                                                                              
// File Name: Pirate.cpp                                                   
// Assignment Name:Pirate.cpp                                                       
// Author: Chidera Iwudyke                                                     
// Date: 10/8/2020 
// Section: 15                                                                 
// E-mail: rz68853@umbc.edu                                                    
// Description:implementing getters and setters. Also this will create functions for the pirate.h file. 
//*

#include "Pirate.h"
#include <iostream>
#include <ctime>
using namespace std;

Pirate::Pirate(){
}

  // Name: Pirate(name, rating, years, origin, desc) - Overloaded Constructor
  // Desc: Used to build a new Pirate
  // Preconditions - Requires new values
  // Postconditions - Creates a new Pirate
Pirate::Pirate(string name, int rating, string origin, string desc) {
  m_pirateName = name;
  m_pirateRating = rating;
  m_pirateOrigin = origin;
  m_pirateDesc = desc;
}

  // Name: GetName()
  // Desc - Getter for Pirate name
  // Preconditions - Pirate exists
  // Postconditions - Returns the name of the Pirate  
string Pirate::GetName(){
  return m_pirateName;
}
  // Name: GetRating()
  // Desc - Gets the Pirate's rating
  // Preconditions - Pirate exists
  // Postconditions - Returns rating of Pirate
int Pirate::GetRating() {
  return m_pirateRating;
}

  // Name: SetRating()
  // Desc - Sets the Pirate's rating
  // Preconditions - Pirate exists
  // Postconditions - Updates the Pirate's rating
void Pirate::SetRating(int rating) {
  if (rating >= 1 && rating <= 100){
    m_pirateRating = rating;
  }
}


// Name: GetOrigin()                                                                                                                                                        
  // Desc - Describes the country of origin of the Pirate                                                                                                                    
  // Preconditions - Pirate exists         
  // Postconditions - Returns the country of origin on the Pirate 
string Pirate::GetOrigin() {
  return m_pirateOrigin;  
}

  // Name: GetDesc()
  // Desc - Describes the Pirate
  // Preconditions - Pirate exists
  // Postconditions - Returns the description of the Pirate
string Pirate::GetDesc() {
  return m_pirateDesc;
}

  // Name: SetCurShip (ship)
  // Desc - Sets the pirates' type of ship
  // Preconditions - Pirate exists
  // Postconditions - Updates m_curShip
void Pirate::SetCurShip(Ship curShip) {
  m_curShip = curShip;
}

  // Name: CalcTreasure
  // Desc - Calculates treasure and added to m_pirateCargo
  // Calculated as enemy ship's cannon, max toughness, and speed divided by 3
  // Preconditions - Pirate exists and battle has concluded
  // Postconditions - Updates total cargo
void Pirate::CalcTreasure(Ship enemyShip) {
  int calcTreasure = (enemyShip.m_cannon + enemyShip.m_toughness + enemyShip.m_speed)/3;
  m_pirateCargo += calcTreasure;
}



  // Name: Battle(pirate, ship)
  // Desc - Battles user pirate vs computer's enemy pirate
  //        If user's ship has m_curToughness of 0 then must repair before battle
  //        Two outcomes possible - User pirate wins = CalcTreasure and maybe damaged ship
  //        Computer pirate wins = damaged ship and pirate's m_cargo halved
  //        User always attacks enemy pirate first
  //        Pirate rating (higher = better) is percentage liklihood of hit
  //        (rating 95 = 95% hit per cannon)
  //        When either user curToughness < 1 or enemyShip curToughness < 1 battle is over
  // Preconditions - Enemy pirate found
  // Postconditions - Either user pirate wins or enemy pirate wins

void Pirate::Battle(Pirate enemyPirate, Ship enemyShip) {
  if (m_curShip.m_curToughness = 0 ){
      cout << "Unable to Battle, Ships Toughness is " << m_curShip.m_curToughness << endl;
  }
  else{
      cout << "A naval battle of the ages commences between " << m_pirateName << " and "<< enemyPirate.GetName() << endl;
      while (m_curShip.m_curToughness >= 1 || enemyShip.m_curToughness >= 1){
          //current ship fires 
          cout << m_pirateName << " fires " << m_curShip.m_cannon << " cannons" << endl;
          int hitsMade = (m_curShip.m_cannon * m_pirateRating) % 100;
          enemyShip.m_curToughness -= hitsMade;
          cout << hitsMade<< " hit! " << endl;
        //enemy ship fires 
          cout << enemyPirate.GetName() << " fires " << enemyShip.m_cannon << " cannons" << endl;
          int eHitsMade = (enemyShip.m_cannon * enemyPirate.GetRating()) % 100;
          m_curShip.m_curToughness -= eHitsMade;
          cout << eHitsMade<< " hit! " << endl;
          if (m_curShip.m_curToughness < 1){
              m_pirateCargo/= 2;
              cout <<"You lost!" << endl;
          }
          else if (enemyShip.m_curToughness < 1){
              calcTreasure(enemyShip);
              cout << "You Win!" << endl;
          }

          }
  
      }
  }
}

  // Name: RepairShip                                                                                                                                                        
  // Desc - Repairs m_curShip and increases m_pirateDays by 1 per m_maxToughness - m_curToughness                                                                            
  // Preconditions - Ship damaged                                                                                                                                            
  // Postconditions - Repairs ship and increases days (1 day per point of damage)

void Pirate::RepairShip() {
    int damageShip = m_curShip.m_toughness - m_curShip.m_curToughness;                                                                                    
  m_curShip.m_curToughness = m_curShip.m_toughness;
  m_pirateDays = m_pirateDays + damageShip;
}

  // Name: Flee(pirate, ship)
  // Desc - User pirate tries to fleet enemy pirate.
  // If m_curShip's speed is higher than enemy then successful flee otherwise Battle occurs
  // Preconditions - Pirate tries to flee
  // Postconditions - Returns to menu or Battle occurs

void Pirate::Flee(Pirate enemyPirate, Ship enemyShip) {
  if (m_curShip.m_speed < enemyShip.m_speed){
      Battle(enemyPirate, enemyShip);
  }
}


  // Name: DisplayScore()
  // Desc - Describes information about the Pirate
  // Preconditions - Pirate exists
  // Postconditions - Displays name, rating, origin, desc, cargo, days, cargo/days, and
  //  info about m_curShip
void Pirate::DisplayScore() {
    cout << "Name: " << m_pirateName << endl;
    cout << "Rating: " << m_pirateRating << endl; 
    cout << "Origin: " << m_pirateOrigin << endl; 
    cout << "Desc: " << m_pirateDesc << endl; 
    cout << "Cargo: " << m_pirateCargo << endl; 
    cout << "Days: " << m_pirateDays << endl;
    cout << "Cargo Per Day: " << m_pirateCargo/m_pirateDays << endl;   
}