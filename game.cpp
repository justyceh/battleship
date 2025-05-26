#include "game.h"

Game::Game(){
    
}
bool Game::checkWinCondition(HumanPlayer human, ComputerPlayer computer){
    if(human.getNumShips() == 0){
        cout << "Computer has won!" << endl;
        return true;
    }
    else if(computer.getNumShips() == 0){
        cout << "Human has won!" << endl;
        return true;
    }
    else{
        return false;
    }
}
bool Game::intialize(){
    bool gameOver;
    // Define Player Variables
    char columnChoice;
    int rowChoice;
    int playerMissleState;
    int validPlayerSelection = 0;
    srand(time(0));
    int randomNum = rand() % 2 + 1;
    // Define Computer Variables
    int computerRowChoice;
    int computerColChoice;
    int computerMissleState;
    int validComputerSelection = 0;
    // Declare / Define Shipes
    Ship Destroyer("Destroyer", 3, 0, false, 'V', 0, 0, 0, 0);
    Ship Carrier("Carrier", 5, 0, false, 'V', 0, 0, 0, 9);
    Ship Battleship("Battleship", 4, 0, false, 'V', 0, 0, 0, 0);
    Ship Submarine("Submarine", 3, 0, false, 'V', 0, 0, 0, 0);
    Ship Patrol("Patrol Boat", 2, 0, false, 'V', 0, 0, 0, 0);
    // Create ship array with ships
    Ship* ships;
    ships = new Ship[5];
    ships[0] = Destroyer;
    ships[1] = Carrier;
    ships[2] = Battleship;
    ships[3] = Submarine;
    ships[4] = Patrol;
    // Create player and computer objects
    HumanPlayer human(5, ships);
    ComputerPlayer computer(5, ships);
    // Place AI ships
    computer.placeShips(ships[0], 'D');
    computer.placeShips(ships[1], 'C');
    computer.placeShips(ships[2], 'B');
    computer.placeShips(ships[3], 'S');
    computer.placeShips(ships[4], 'P');
    // Place Player ships
    cout << "When placing a ship choose a coordinate that will represent the head of the ship" << endl;
    cout << "Vertically: The ship will extend downward from the head coordinate." << endl << "Horizontally: The ship will extend to the right from the head coordinate." << endl;
    human.placeShips(ships[0], 'D');
    human.placeShips(ships[1], 'C');
    human.placeShips(ships[2], 'B');
    human.placeShips(ships[3], 'S');
    human.placeShips(ships[4], 'P');
    switch(randomNum){
        case 1:
        {
            cout << "Player starts" << endl;
             do{
        human.displayOpponentBoard();
        human.displayMyBoard();

        // Players turn
        cout << endl << "Player's turn!" << endl;
        do{
            cout << "Which column would you like to fire your missle at? (A-J)" << endl << "Enter a UPPERCASE letter: ";
            cin >> columnChoice;
            while(columnChoice < 'A' || columnChoice > 'J'){
                cin.clear();
                cin.ignore();
                cout << "Which column would you like to fire your missle at? (A-J)" << endl << "Enter a UPPERCASE letter: ";
                cin >> columnChoice;
            }
            do{
                cout << "Which row would you like to fire your missle at? (0-9)" << endl << "Enter a Number: ";
                cin >> rowChoice;
                while(cin.fail()){
                    cin.clear();
                    cin.ignore();
                    cout << "Please pick a number between 0 and 9" << endl;
                     cout << "Which row would you like to fire your missle at? (0-9)" << endl << "Enter a Number: ";
                     cin >> rowChoice;
                }
                if(rowChoice < 0 || rowChoice > 9){
                cout << "Please pick a number between 0 and 9" << endl;
                }
            }while(rowChoice < 0 || rowChoice > 9);
            validPlayerSelection = human.checkPlayerMissle(columnChoice, rowChoice);
        }while(validPlayerSelection == 0);
        
        playerMissleState = computer.recieveMissle(columnChoice, rowChoice);
        human.fireMissle(columnChoice, rowChoice, playerMissleState);
        if(playerMissleState == 1){
            cout << "You hit a ship!" << endl;
        }
        else{
            cout << "You missed!" << endl;
        }
        if(checkWinCondition(human, computer)){
            gameOver = true;
            break;
        }


        // Computers turn
        cout << endl << "Computer's turn!" << endl;
        do{
            computerColChoice = rand() % 10;
            computerRowChoice = rand() % 10;
            validComputerSelection = computer.checkComputerMissle(computerColChoice, computerRowChoice);
        }while(validComputerSelection == 0);

        computerMissleState = human.recieveMissle(computerColChoice, computerRowChoice);
        computer.fireMissle(computerColChoice, computerRowChoice, computerMissleState);
        if(computerMissleState == 1){
            cout << "Computer hit your ship!" << endl;
        }
        else{
            cout << "Computer missed!" << endl << endl;
        }
        if(checkWinCondition(human, computer)){
            gameOver = true;
            break;
        }
    }while(true);
        }
        break;
        case 2:
        {
            cout << "Computer starts" << endl;
             do{
        // Computers turn
        cout << endl << "Computer's turn!" << endl;
        do{
            computerColChoice = rand() % 10;
            computerRowChoice = rand() % 10;
            validComputerSelection = computer.checkComputerMissle(computerColChoice, computerRowChoice);
        }while(validComputerSelection == 0);

        computerMissleState = human.recieveMissle(computerColChoice, computerRowChoice);
        computer.fireMissle(computerColChoice, computerRowChoice, computerMissleState);
        if(computerMissleState == 1){
            cout << "Computer hit your ship!" << endl;
        }
        else{
            cout << "Computer missed!" << endl << endl;
        }
        if(checkWinCondition(human, computer)){
            gameOver = true;
            break;
        }
        human.displayOpponentBoard();
        human.displayMyBoard();
        // Players turn
        cout << endl << "Player's turn!" << endl;
        do{
            cout << "Which column would you like to fire your missle at? (A-J)" << endl << "Enter a UPPERCASE letter: ";
            cin >> columnChoice;
            while(columnChoice < 'A' || columnChoice > 'J'){
                cin.clear();
                cin.ignore();
                cout << "Which column would you like to fire your missle at? (A-J)" << endl << "Enter a UPPERCASE letter: ";
                cin >> columnChoice;
            }
            do{
                cout << "Which row would you like to fire your missle at? (0-9)" << endl << "Enter a Number: ";
                cin >> rowChoice;
                while(cin.fail()){
                    cin.clear();
                    cin.ignore();
                    cout << "Please pick a number between 0 and 9" << endl;
                     cout << "Which row would you like to fire your missle at? (0-9)" << endl << "Enter a Number: ";
                     cin >> rowChoice;
                }
                if(rowChoice < 0 || rowChoice > 9){
                cout << "Please pick a number between 0 and 9" << endl;
                }
            }while(rowChoice < 0 || rowChoice > 9);
            validPlayerSelection = human.checkPlayerMissle(columnChoice, rowChoice);
        }while(validPlayerSelection == 0);
        
        playerMissleState = computer.recieveMissle(columnChoice, rowChoice);
        human.fireMissle(columnChoice, rowChoice, playerMissleState);
        if(playerMissleState == 1){
            cout << "You hit a ship!" << endl;
        }
        else{
            cout << "You missed!" << endl;
        }
        if(checkWinCondition(human, computer)){
            gameOver = true;
            break;
        }

    }while(true);
        }
        break;
    }
    return gameOver;
   
}