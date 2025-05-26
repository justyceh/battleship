#include "ship.h"
#include "coordinate.h"
#include "abstractplayer.h"
#include "game.h"
int main(){
    Game newGame;
    bool play;
    int choice;
    do{
        cout << "Do you want to play Battleship?" << endl << "1. Play" << endl << "2. Quit" << endl << "Your Choice: ";
        cin >> choice;
        if(choice == 1){
            play = newGame.intialize();
        }
        else{
            play = false;
            cout << "Bye Bye!" << endl;
        }
    }while(play);
    return 0;
}