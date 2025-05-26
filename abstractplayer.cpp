#include "abstractplayer.h"
// Human Player
void HumanPlayer::placeShips(Ship newShip, char shipLetter){
    // For checking valid ship placement for horizontally placed ships add colChoice + size of the ship, if its greather than 10 then its a invalid placement, else its good
    // For checking valid ship placement for vertically placed ships, add rowChoice + size of ship, if its greater then 10 its a invalid placement, else its good
    int check = 0;
    int orientationChoice;
    int rowChoice;
    char columnChoice;
    int colChoice;
    int validLocation = 0;
    int size = newShip.getSize();
    do{
        displayMyBoard();
        do{
            cout << "How would you like to place your " << newShip << "?"  << endl << "1. Horizontally" << endl << "2. Vertically" << endl << "Enter a Number: ";
            cin >> orientationChoice;
            while(cin.fail()){
                cin.clear();
                cin.ignore();
                cout << "How would you like to place your " << newShip << "?"  << endl << "1. Horizontally" << endl << "2. Vertically" << endl << "Enter a Number: ";
                cin >> orientationChoice;
            }
            if(orientationChoice != 1 && orientationChoice != 2){
                cout << "Invalid Option, Please choose 1 or 2" << endl;
            }
        }while(orientationChoice != 1 && orientationChoice != 2);
        cout << "Which column would you like to place your ship on? (A-J)" << endl << "Enter a UPPERCASE Letter: ";
        cin >> columnChoice;
        while(columnChoice < 'A' || columnChoice > 'J'){
                cin.clear();
                cin.ignore();
                cout << "Which column would you like to place your ship on? (A-J)" << endl << "Enter a UPPERCASE Letter: ";
                cin >> columnChoice;
            }
        do{
            cout << "Which row would you like to place your ship on? (0-9)" << endl << "Enter a Number: ";
            cin >> rowChoice;
            while(cin.fail()){
                    cin.clear();
                    cin.ignore();
                     cout << "Which row would you like to place your ship on? (0-9)" << endl << "Enter a Number: ";
                     cin >> rowChoice;
                }
            if(rowChoice < 0 || rowChoice > 9){
                cout << "Invalid Option, Please choose a number between 0-9" << endl;
            }
        }while(rowChoice < 0 || rowChoice > 9);    

        switch(columnChoice){
            case 'A': 
            {
                colChoice = 0;
            }
            break;
            case 'B': 
            {
                colChoice = 1;
            }
            break;  
            case 'C': 
            {
                colChoice = 2;
            }
            break;
            case 'D': 
            {
                colChoice = 3;
            }
            break;
            case 'E': 
            {
                colChoice = 4;
            }
            break;
            case 'F': 
            {
                colChoice = 5;
            }
            break;
            case 'G': 
            {
                colChoice = 6;
            }
            break;
            case 'H': 
            {
                colChoice = 7;
            }
            break;
            case 'I': 
            {
                colChoice = 8;
            }
            break;
            case 'J': 
            {
                colChoice = 9;
            }
            break;
        }

        if(orientationChoice == 2){
            if((rowChoice + size) > 10){
                cout << "Invalid placement, please place ship within range" << endl;
                check = 0;
            }
            else{
                for(int i = rowChoice; i < rowChoice + size; i++){
                if(myBoard[i][colChoice] != '*'){
                    check = 0;
                    validLocation = 0;
                    cout << "Invalid placement, another ship is in the way" << endl;
                    break;
                }
                else{
                    validLocation = 1;
                }
                }
                if(validLocation == 1){
                    for(int i = rowChoice; i < rowChoice + size; i++){
                    myBoard[i][colChoice] = shipLetter;
                    }
                    check = 1;
                    newShip.setStartCoords(colChoice, rowChoice);
                    newShip.setEndCoords(colChoice, rowChoice + size - 1);
                }
                }
            }
            else if(orientationChoice == 1){
            if((colChoice + size) > 10){
                cout << "Invalid placement, please place ship within range" << endl;
            }
            else{
                for(int i = colChoice; i < colChoice + size; i++){
                if(myBoard[rowChoice][i] != '*'){
                    check = 0;
                    validLocation = 0;
                    cout << "Invalid placement, another ship is in the way" << endl;
                    break;
                    }
                    else{
                        validLocation = 1;
                    }
                }
                if(validLocation == 1){
                    for(int i = colChoice; i < colChoice + size; i++){
                        myBoard[rowChoice][i] = shipLetter;
                    }
                    check = 1;
                    newShip.setStartCoords(colChoice, rowChoice);
                    newShip.setEndCoords(colChoice + size - 1, rowChoice);
                }
            }
        }
        displayMyBoard();
        if(check == 0){
            cout << "Invalid Options, try again!" << endl;
        }
        else if(check == 1){
            cout << "Human Placed their " << newShip << endl;
        }
    }while(check == 0);
}
void HumanPlayer::fireMissle(char col, int row, int hit){
    int colChoice;
    switch(col){
            case 'A': 
            {
                colChoice = 0;
            }
            break;
            case 'B': 
            {
                colChoice = 1;
            }
            break;  
            case 'C': 
            {
                colChoice = 2;
            }
            break;
            case 'D': 
            {
                colChoice = 3;
            }
            break;
            case 'E': 
            {
                colChoice = 4;
            }
            break;
            case 'F': 
            {
                colChoice = 5;
            }
            break;
            case 'G': 
            {
                colChoice = 6;
            }
            break;
            case 'H': 
            {
                colChoice = 7;
            }
            break;
            case 'I': 
            {
                colChoice = 8;
            }
            break;
            case 'J': 
            {
                colChoice = 9;
            }
            break;
        }
        if(hit == 1){
            opponentBoard[row][colChoice] = 'X';
        }
        else{
            opponentBoard[row][colChoice] = 'O';
        }

}
int HumanPlayer::checkPlayerMissle(char col, int row){
    int colChoice;
    switch(col){
            case 'A': 
            {
                colChoice = 0;
            }
            break;
            case 'B': 
            {
                colChoice = 1;
            }
            break;  
            case 'C': 
            {
                colChoice = 2;
            }
            break;
            case 'D': 
            {
                colChoice = 3;
            }
            break;
            case 'E': 
            {
                colChoice = 4;
            }
            break;
            case 'F': 
            {
                colChoice = 5;
            }
            break;
            case 'G': 
            {
                colChoice = 6;
            }
            break;
            case 'H': 
            {
                colChoice = 7;
            }
            break;
            case 'I': 
            {
                colChoice = 8;
            }
            break;
            case 'J': 
            {
                colChoice = 9;
            }
            break;
        }
    if(opponentBoard[row][colChoice] == '*'){
        return 1;
    }
    else{
        cout << "Please enter a coordinate you have not choosen" << endl;
        return 0;
    }
}
int HumanPlayer::recieveMissle(int col, int row){
        if(myBoard[row][col] != '*'){
        addHitToShip(myBoard[row][col]);
        myBoard[row][col] = 'X';
        return 1;
    }
    else{
        myBoard[row][col] = 'O';
        return 0;
    }
}
void HumanPlayer::addHitToShip(char shipLetter){
    switch(shipLetter){
        case 'D':
        {
            myShips[0].setNumHits(myShips[0].getNumHits() + 1);
            if(myShips[0].getNumHits() == myShips[0].getSize()){
                cout << "Player's " << myShips[0] << " has been destroyed!" << endl;
                numShips = numShips - 1;
            }
        }
        break;
        case 'C':
        {
            myShips[1].setNumHits(myShips[1].getNumHits() + 1);
            if(myShips[1].getNumHits() == myShips[1].getSize()){
                cout << "Player's " << myShips[1] << " has been destroyed!" << endl;
                numShips = numShips - 1;
            }
        }
        break;
        case 'B':
        {
            myShips[2].setNumHits(myShips[2].getNumHits() + 1);
            if(myShips[2].getNumHits() == myShips[2].getSize()){
                cout << "Player's " << myShips[2] << " has been destroyed!" << endl;
                numShips = numShips - 1;
            }
        }
        break;
        case 'S':
        {
            myShips[3].setNumHits(myShips[3].getNumHits() + 1);
            if(myShips[3].getNumHits() == myShips[3].getSize()){
                cout << "Player's " << myShips[3] << " has been destroyed!" << endl;
                numShips = numShips - 1;
            }
        }
        break;
        case 'P':
        {
            myShips[4].setNumHits(myShips[4].getNumHits() + 1);
            if(myShips[4].getNumHits() == myShips[4].getSize()){
                cout << "Player's " << myShips[4] << " has been destroyed!" << endl;
                numShips = numShips - 1;
            }
            
        }
        break;
    }
}
void HumanPlayer::loadShipsArray(Ship* newShips){
        // Allocate memory for ships
    myShips = new Ship[numShips];
        // Copy all ships into new ships array
    for(int i = 0; i < numShips; i++){
        myShips[i] = newShips[i];
    }
}
void HumanPlayer::intializeBoards(){
    // Create character pointer array of size 10 for player board and opponent board
    myBoard = new char*[10];
    opponentBoard = new char*[10];
    // Assign each column a row
    for(int i = 0; i < 10; i++){
        myBoard[i] = new char[10];
        opponentBoard[i] = new char[10];
    }
    // Set all spots on board to be a asterik
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            myBoard[i][j] = '*';
            opponentBoard[i][j] = '*';
        }
    }
}
void HumanPlayer::displayMyBoard(){
    cout << "   " << "A B C D E F G H I J" << endl;
    for(int i = 0; i < 10; i++){
        cout << i << "  ";
        for(int j = 0; j < 10; j++){
            cout << myBoard[i][j] << " ";
        }
        cout << endl;
    }
}
void HumanPlayer::displayOpponentBoard(){
    cout << "   " << "A B C D E F G H I J" << endl;
    for(int i = 0; i < 10; i++){
        cout << i << "  ";
        for(int j = 0; j < 10; j++){
            cout << opponentBoard[i][j] << " ";
        }
        cout << endl;
    }
}
HumanPlayer::HumanPlayer(int n, Ship* newShips){
    numShips = n;
    loadShipsArray(newShips);
    intializeBoards();
}
HumanPlayer::HumanPlayer(){
    numShips = 5;
    intializeBoards();
    myShips = new Ship[numShips];
}
HumanPlayer::HumanPlayer(const HumanPlayer& rhs){
    numShips = rhs.numShips;
    loadShipsArray(rhs.myShips);
    intializeBoards();
}
HumanPlayer::~HumanPlayer(){
    delete [] myShips;
    for(int i = 0; i < 10; i++){
        delete [] myBoard[i];
        delete [] opponentBoard[i];
    }
    delete [] myBoard;
    delete [] opponentBoard;
}
int HumanPlayer::getNumShips(){
    return numShips;
}
ostream& operator<<(ostream& os, const HumanPlayer& rhs){
    os << "Num Ships Human has: " << rhs.numShips;
    return os;
}

// Computer Player

void ComputerPlayer::placeShips(Ship newShip, char shipLetter){
    srand(time(0));
    int orientationNum;
    int rowChoice;
    int colChoice;
    int check = 0;
    int validLocation = 0;
    int size = newShip.getSize();
    do{
        orientationNum = rand() % 2 + 1;
        rowChoice = rand() % 10;
        colChoice = rand() % 10;



        if(orientationNum == 2){
            if((rowChoice + size) > 10){
                // cout << "Invalid placement, please place ship within range" << endl;
                check = 0;
            }
            else{
                for(int i = rowChoice; i < rowChoice + size; i++){
                if(myBoard[i][colChoice] != '*'){
                    check = 0;
                    validLocation = 0;
                    // cout << "Invalid placement, another ship is in the way" << endl;
                    break;
                }
                else{
                    validLocation = 1;
                }
                }
                if(validLocation == 1){
                    for(int i = rowChoice; i < rowChoice + size; i++){
                    myBoard[i][colChoice] = shipLetter;
                    }
                    check = 1;
                    newShip.setStartCoords(colChoice, rowChoice);
                    newShip.setEndCoords(colChoice, rowChoice + size - 1);
                }
                }
            }
            else if(orientationNum == 1){
            if((colChoice + size) > 10){
                // cout << "Invalid placement, please place ship within range" << endl;
            }
            else{
                for(int i = colChoice; i < colChoice + size; i++){
                if(myBoard[rowChoice][i] != '*'){
                    check = 0;
                    validLocation = 0;
                    // cout << "Invalid placement, another ship is in the way" << endl;
                    break;
                    }
                    else{
                        validLocation = 1;
                    }
                }
                if(validLocation == 1){
                    for(int i = colChoice; i < colChoice + size; i++){
                        myBoard[rowChoice][i] = shipLetter;
                    }
                    check = 1;
                    newShip.setStartCoords(colChoice, rowChoice);
                    newShip.setEndCoords(colChoice + size - 1, rowChoice);
                }
            }
        }
    }while(check == 0);
}
void ComputerPlayer::fireMissle(int col, int row, int hit){
        if(hit == 1){
            opponentBoard[row][col] = 'X';
        }
        else{
            opponentBoard[row][col] = 'O';
        }
}
int ComputerPlayer::checkComputerMissle(int col, int row){
    if(opponentBoard[row][col] == '*'){
        return 1;
    }
    else{
        return 0;
    }
}
int ComputerPlayer::recieveMissle(char col, int row){
    int colChoice;
    switch(col){
            case 'A': 
            {
                colChoice = 0;
            }
            break;
            case 'B': 
            {
                colChoice = 1;
            }
            break;  
            case 'C': 
            {
                colChoice = 2;
            }
            break;
            case 'D': 
            {
                colChoice = 3;
            }
            break;
            case 'E': 
            {
                colChoice = 4;
            }
            break;
            case 'F': 
            {
                colChoice = 5;
            }
            break;
            case 'G': 
            {
                colChoice = 6;
            }
            break;
            case 'H': 
            {
                colChoice = 7;
            }
            break;
            case 'I': 
            {
                colChoice = 8;
            }
            break;
            case 'J': 
            {
                colChoice = 9;
            }
            break;
        }
    if(myBoard[row][colChoice] != '*'){
        addHitToShip(myBoard[row][colChoice]);
        myBoard[row][colChoice] = 'X';
        return 1;
    }
    else{
        myBoard[row][colChoice] = 'O';
        return 0;
    }
}
void ComputerPlayer::addHitToShip(char shipLetter){
    switch(shipLetter){
        case 'D':
        {
            myShips[0].setNumHits(myShips[0].getNumHits() + 1);
            if(myShips[0].getNumHits() == myShips[0].getSize()){
                cout << "Computer's " << myShips[0] << " has been destroyed!" << endl;
                numShips = numShips - 1;
            }
        }
        break;
        case 'C':
        {
            myShips[1].setNumHits(myShips[1].getNumHits() + 1);
            if(myShips[1].getNumHits() == myShips[1].getSize()){
                cout << "Computer's " << myShips[1] << " has been destroyed!" << endl;
                numShips = numShips - 1;
            }
        }
        break;
        case 'B':
        {
            myShips[2].setNumHits(myShips[2].getNumHits() + 1);
            if(myShips[2].getNumHits() == myShips[2].getSize()){
                cout << "Computer's " << myShips[2] << " has been destroyed!" << endl;
                numShips = numShips - 1;
            }
        }
        break;
        case 'S':
        {
            myShips[3].setNumHits(myShips[3].getNumHits() + 1);
            if(myShips[3].getNumHits() == myShips[3].getSize()){
                cout << "Computer's " << myShips[3] << " has been destroyed!" << endl;
                numShips = numShips - 1;
            }
        }
        break;
        case 'P':
        {
            myShips[4].setNumHits(myShips[4].getNumHits() + 1);
            if(myShips[4].getNumHits() == myShips[4].getSize()){
                cout << "Computer's " << myShips[4] << " has been destroyed!" << endl;
                numShips = numShips - 1;
            }
            
        }
        break;
    }
}
void ComputerPlayer::loadShipsArray(Ship* newShips){
        // Allocate memory for ships
    myShips = new Ship[numShips];
        // Copy all ships into new ships array
    for(int i = 0; i < numShips; i++){
        myShips[i] = newShips[i];
    }
}
void ComputerPlayer::intializeBoards(){
    // Create character pointer array of size 10 for player board and opponent board
    myBoard = new char*[10];
    opponentBoard = new char*[10];
    // Assign each column a row
    for(int i = 0; i < 10; i++){
        myBoard[i] = new char[10];
        opponentBoard[i] = new char[10];
    }
    // Set all spots on board to be a asterik
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            myBoard[i][j] = '*';
            opponentBoard[i][j] = '*';
        }
    }
}
void ComputerPlayer::displayMyBoard(){
    cout << "   " << "A B C D E F G H I J" << endl;
    for(int i = 0; i < 10; i++){
        cout << i << "  ";
        for(int j = 0; j < 10; j++){
            cout << myBoard[i][j] << " ";
        }
        cout << endl;
    }
}
void ComputerPlayer::displayOpponentBoard(){
    cout << "   " << "A B C D E F G H I J" << endl;
    for(int i = 0; i < 10; i++){
        cout << i+1 << " ";
        for(int j = 0; j < 10; j++){
            cout << opponentBoard[i][j] << " ";
        }
        cout << endl;
    }
}
ComputerPlayer::ComputerPlayer(int n, Ship* newShips){
    numShips = n;
    loadShipsArray(newShips);
    intializeBoards();
}
ComputerPlayer::ComputerPlayer(){
    numShips = 5;
    intializeBoards();
    myShips = new Ship[numShips];
}
ComputerPlayer::ComputerPlayer(const ComputerPlayer& rhs){
    numShips = rhs.numShips;
    loadShipsArray(rhs.myShips);
    intializeBoards();
}
ComputerPlayer::~ComputerPlayer(){
    delete [] myShips;
    for(int i = 0; i < 10; i++){
        delete [] myBoard[i];
        delete [] opponentBoard[i];
    }
    delete [] myBoard;
    delete [] opponentBoard;
}
int ComputerPlayer::getNumShips(){
    return numShips;
}
ostream& operator<<(ostream& os, const ComputerPlayer& rhs){
    os << "Num Ships Computer has: " << rhs.numShips;
    return os;
}