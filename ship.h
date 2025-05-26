#ifndef SHIP_H
#define SHIP_H
#include "coordinate.h"
class Ship{
    string name;
    int size;
    int numHits;
    bool isSunk;
    char orientation;
    Coordinate<int> startCoords;
    Coordinate<int> endCoords;
    public:
    // Constructors
    Ship();
    Ship(string, int, int, bool, char, int, int, int, int);
    Ship(const Ship&);
    // Getters
    string getName();
    int getSize();
    int getNumHits();
    bool getIsSunk();
    char getOrientation();
    // Setters
    void setName(string);
    void setSize(int);
    void setNumHits(int);
    void setIsSunk(bool);
    void setOrientation(char);
    void setStartCoords(int, int);
    void setEndCoords(int, int);
    // Output operator overload
    friend ostream& operator<<(ostream&, const Ship&);
};
#endif