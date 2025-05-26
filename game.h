#ifndef GAME_H
#define GAME_H
#include "abstractplayer.h"
class Game{
    private:
    public:
    Game();
    bool checkWinCondition(HumanPlayer, ComputerPlayer);
    bool intialize();
};
#endif