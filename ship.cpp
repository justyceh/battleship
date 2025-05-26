#include "ship.h"
// Constructors
Ship::Ship(){
    name = "Default Battleship";
    size = 0;
    numHits = 0;
    isSunk = false;
    orientation = 'N';
    startCoords.setX(3);
    startCoords.setY(5);
}
Ship::Ship(string n, int s, int nHits, bool sunk, char o, int xStart, int yStart, int xEnd, int yEnd){
    name = n;
    size = s;
    numHits = nHits;
    isSunk = sunk;
    orientation = o;
    startCoords.setX(xStart);
    startCoords.setY(yStart);
    endCoords.setX(xEnd);
    endCoords.setY(yEnd);
    
}
Ship::Ship(const Ship& rhs){
    name = rhs.name;
    size = rhs.size;
    numHits = rhs.numHits;
    isSunk = rhs.isSunk;
    orientation = rhs.orientation;
}
// Output operator overload
ostream& operator<<(ostream& os, const Ship& rhs){
    // os << "Ship Name: " << rhs.name << endl;
    // os << "Ship Size: " << rhs.size << endl;
    // os << "Ship's Hits Taken: " << rhs.numHits << endl;
    // os << "Ship Sunk Status: " << rhs.isSunk << endl;
    // os << "Ship's Orientation: " << rhs.orientation << endl;
    // os << "Ship's Starting Coordinates: " << rhs.startCoords;
    // os << "Ship's Ending Coordinates: " << rhs.endCoords;
    os << rhs.name;
    return os;
}
// Getters
int Ship::getSize(){
    return size;
}
int Ship::getNumHits(){
    return numHits;
}
// Setters

void Ship::setStartCoords(int x, int y){
    startCoords.setX(x);
    startCoords.setY(y);
}
void Ship::setEndCoords(int x, int y){
    endCoords.setX(x);
    endCoords.setY(y);
}
void Ship::setNumHits(int c){
    numHits = c;
}