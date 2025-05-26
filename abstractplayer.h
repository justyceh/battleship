#include "ship.h"
#ifndef ABSTRACTPLAYER_H
#define ABSTRACTPLAYER_H
class AbstractPlayer{
    protected:
    char** myBoard;
    char** opponentBoard;
    public:
    virtual void placeShips(Ship, char) = 0;
};
class HumanPlayer : public AbstractPlayer{
    private: 
    int numShips;
    Ship* myShips;
    public:
    HumanPlayer();
    HumanPlayer(int, Ship*);
    HumanPlayer(const HumanPlayer&);
    ~HumanPlayer();
    int getNumShips();
    void placeShips(Ship, char) override;
    void fireMissle(char, int, int);
    void loadShipsArray(Ship*);
    void intializeBoards();
    void displayMyBoard();
    void displayOpponentBoard();
    int checkPlayerMissle(char, int);
    void addHitToShip(char);
    int recieveMissle(int, int);
    friend ostream& operator<<(ostream&, const HumanPlayer&);
};
class ComputerPlayer : public AbstractPlayer{
    private: 
    int numShips;
    Ship* myShips;
    public:
    ComputerPlayer();
    ComputerPlayer(int, Ship*);
    ComputerPlayer(const ComputerPlayer&);
    ~ComputerPlayer();
    int getNumShips();
    void placeShips(Ship, char) override;
    void fireMissle(int, int, int);
    void loadShipsArray(Ship*);
    void intializeBoards();
    void displayMyBoard();
    void displayOpponentBoard();
    int checkComputerMissle(int, int);
    void addHitToShip(char);
    int recieveMissle(char, int);
    friend ostream& operator<<(ostream&, const ComputerPlayer&);
};
#endif