#include "Game.h"
#include <iostream>
#include <fstream>
using namespace std;


//Constants (additional constants allowed)



  /* Name: Game() Default Constructor
  // Desc - Builds a new game by: 
  // 1. Displaying the Game Title
  // 2. Loads all ships and their information into m_ships
  // 3. Loads all pirates and their information into m_pirates
  // Preconditions - None
  // Postconditions - m_allPirates and m_ships are populated
  */ 
Game::Game() {} //Default Constructor

  // Name: LoadShips
  // Desc - Loads each type of ship into m_ships from file (Do not use EOF)
  // Preconditions - Requires file with valid ship data
  // Postconditions - m_ships is populated with ship structs
void Game::LoadShips() {
    ifstream inputStream;
    inputStream.open(PROJ2_SHIPS);
    if (inputStream.is_open()) {
        string element;
        int x = 0; //Counter for splicting
        int arryCounter = 0;
        string type;
        int cannon;
        int toughness;
        int speed;
        string desc;
        while (getline(inputStream, element, ',')) {
            
            if (x == 0)
            {
                type = element;
                //cout <<"type: "  << element << endl;
            }
            if (x == 1)
            {
                cannon = stoi(element);
                //cout << "cannon: " << element << endl;
            }
            if (x == 2)
            {
                toughness = stoi(element);
               // cout << "toughness: " << element << endl;
            }
            if (x == 3)
            {
                speed = stoi(element);
               // cout << "speed: " << element << endl;
            }
            if (x == 4)
            {
                desc = element;
                
            }
            if (x == 5)
            {
               desc = desc + "," + element;

            }
            if (x == 6)
            {
                desc = desc + "," + element;
               // cout << "desc: " << desc << endl;

                Ship ship = Ship(type, cannon, toughness, speed, desc);
                m_ships[arryCounter] = ship;
                arryCounter++;
                x = 0;
                /*
                string locatedNewLine = strchr(element, '\n');
                reverse(element.begin(), element.end());
                int y = 0;
                string strBuilder="";
                char character = element[y];
                while (character != '\n')
                {
                    strBuilder = strBuilder + character;
                    character = element[++y];
                    
                }
                type  = strBuilder;
                reverse(type.begin(), type.end());
                */
            }
            x++;
        }
        /*
        for (int y = 0; y < arryCounter; y++)
        {
            cout << "Name: " << m_ships[y].m_type << endl;
            cout << "Number of Cannons: " << m_ships[y].m_cannon<< endl;
            cout << "Health: " << m_ships[y].m_curToughness << endl;
            cout << "Speed: " << m_ships[y].m_speed << endl;
            cout << "Desc: " << m_ships[y].m_desc << endl;
            cout << "___________________________________" << endl;
            cout << endl;

        }
        */

    }
}

  // Name: LoadPirates
  // Desc - Loads each pirate into m_allPirates from file (Do not use EOF)
  // Preconditions - Requires file with valid pirate data 
  // Postconditions - m_allPirates is populated with pirate objects
void Game::LoadPirates(){
    ifstream inputStream;
    inputStream.open(PROJ2_PIRATES);
    if (inputStream.is_open()){
        string pirateName; //Name of Pirate
        int pirateRating; //Rating of Pirate
        string pirateOrigin; //Country of Origin of Pirate
        string pirateDesc; //Description of Pirate
        int x = 0; //Counter for splicting
        int arryCounter = 0;
        string elementPirates;
        while (getline(inputStream,elementPirates, ',')){
            if (x == 0) {
                pirateName = elementPirates;

            }

            if (x == 1){
                pirateRating = stoi(elementPirates);
            }

            if (x == 2) {
                pirateOrigin = elementPirates;
            }

            if (x == 3) {
                pirateDesc = elementPirates;
                Pirate pirate = Pirate(pirateName,pirateRating, pirateOrigin, pirateDesc);
                m_allPirates[arryCounter] = pirate;
                arryCounter ++;
                x = 0; 
            }
            x++; 
            

            
        }
        for (int y = 0; y < arryCounter; y++)
        {
            cout << "Name: " << m_allPirates[y].GetName() << endl;
            cout << "Rating: " << m_allPirates[y].GetRating()<< endl;
            cout << "Origin: " << m_allPirates[y].GetOrigin() << endl;
            cout << "Desc: " << m_allPirates[y].GetDesc()<< endl;
            cout << "___________________________________" << endl;
            cout << endl;

        }
    }
    //remember to close file
}

  // Name: StartGame()
  // Desc - Does the following:
  //        1. Randomly assigns a pirate from the list as the user's pirate (m_myPirate)
  //        2. Randomly assigns a ship to the user's pirate (updates m_myPirate's ship)
  //        3. Manages the game itself including win conditions continually
  //         calling the main menu 
  // Preconditions - Player (Pirate) is placed in game
  // Postconditions - Continually checks to see if player has entered 4 (retires)
void Game::StartGame() {}
  // Name: MainMenu()
  // Desc - Displays and manages menu. 
  // Preconditions - Player has a Pirate
  // Postconditions - Returns number including exit
int Game::MainMenu() { return 0; }
  // Name: SearchTreasure()
  // Desc - Attempts to search for ships and allows user to either battle or attempt to flee
  // Preconditions - Pirates loaded
  // Postconditions - Identifies enemy pirate to fight
void Game::SearchTreasure() {}

//*
  // Name: RequestShip()
  // Desc - Requests ship for battle
  // Preconditions - Pirate has ship for battle
  // Postconditions - Returns integer of chosen ship for battle
//void RequestShip(int &choice);
//*

  // Name: GameTitle()
  // Desc - Title for Game (Do not edit)
  // Preconditions - None
  // Postconditions - None
