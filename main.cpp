#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <fstream>
using namespace std;

struct gameStatus{ // Data structure to store the game status
    char base[10][15]; // Create a 2-D C-string to store the information of a base board,
                       // which contains 25 randomly-generated bombs
    char game[10][15]; // Create a 2-D C-string to store the information of a game board for player use
    int rBomb; // Count the remaining bombs that the player needs to detect
};
gameStatus game;

int again = 1; // Create variable for storing the value of whether to start a new game
int endGame = 1; // Create a variable for counting the number of commands that the player inputs;
                 // determining whether a game ends or not, "0" denotes end


// Decide the number of neighboring bombs
void neighborBomb(int x, int y) {
    if( x == 0 ) {
        if( y == 0 ) {
            if( game.base[x+1][y] != '*' ) game.base[x+1][y]++;
            if( game.base[x][y+1] != '*' ) game.base[x][y+1]++;
            if( game.base[x+1][y+1] != '*') game.base[x+1][y+1]++;
        }
        else if( y == 14 ){
            if( game.base[x+1][y] != '*' ) game.base[x+1][y]++;
            if( game.base[x][y-1] != '*') game.base[x][y-1]++;
            if( game.base[x+1][y-1] != '*') game.base[x+1][y-1]++;
        }
        else{
            if( game.base[x][y-1] != '*' ) game.base[x][y-1]++;
            if( game.base[x][y+1] != '*' ) game.base[x][y+1]++;
            if( game.base[x+1][y] != '*' ) game.base[x+1][y]++;
            if( game.base[x+1][y-1] != '*' ) game.base[x+1][y-1]++;
            if( game.base[x+1][y+1] != '*' ) game.base[x+1][y+1]++;
        }
    }
    else if(x == 9) {
        if( y == 0 ) {
            if( game.base[x-1][y] != '*' ) game.base[x-1][y]++;
            if( game.base[x][y+1] != '*' ) game.base[x][y+1]++;
            if( game.base[x-1][y+1] != '*' ) game.base[x-1][y+1]++;
        }
        else if( y == 14 ){
            if( game.base[x-1][y] != '*' ) game.base[x-1][y]++;
            if( game.base[x][y-1] != '*' ) game.base[x][y-1]++;
            if( game.base[x-1][y-1] != '*' ) game.base[x-1][y-1]++;
        }
        else{
            if( game.base[x][y-1] != '*' ) game.base[x][y-1]++;
            if( game.base[x][y+1] != '*' ) game.base[x][y+1]++;
            if( game.base[x-1][y] != '*' ) game.base[x-1][y]++;
            if( game.base[x-1][y-1] != '*' ) game.base[x-1][y-1]++;
            if( game.base[x-1][y+1] != '*' ) game.base[x-1][y+1]++;
        }
    }
    else{
        if( y == 0 ) {
            if( game.base[x-1][y] != '*' ) game.base[x-1][y]++;
            if( game.base[x-1][y+1] != '*' ) game.base[x-1][y+1]++;
            if( game.base[x][y+1] != '*' ) game.base[x][y+1]++;
            if( game.base[x+1][y] != '*' ) game.base[x+1][y]++;
            if( game.base[x+1][y+1] != '*' ) game.base[x+1][y+1]++;
        }
        else if( y == 14 ){
            if( game.base[x-1][y] != '*' ) game.base[x-1][y]++;
            if( game.base[x-1][y-1] != '*' ) game.base[x-1][y-1]++;
            if( game.base[x][y-1] != '*' ) game.base[x][y-1]++;
            if( game.base[x+1][y] != '*' ) game.base[x+1][y]++;
            if( game.base[x+1][y-1] != '*' ) game.base[x+1][y-1]++;
        }
        else{
            if( game.base[x-1][y-1] != '*' ) game.base[x-1][y-1]++;
            if( game.base[x-1][y] != '*' ) game.base[x-1][y]++;
            if( game.base[x-1][y+1] != '*' ) game.base[x-1][y+1]++;
            if( game.base[x][y-1] != '*' ) game.base[x][y-1]++;
            if( game.base[x][y+1] != '*' ) game.base[x][y+1]++;
            if( game.base[x+1][y-1] != '*' ) game.base[x+1][y-1]++;
            if( game.base[x+1][y] != '*' ) game.base[x+1][y]++;
            if( game.base[x+1][y+1] != '*' ) game.base[x+1][y+1]++;
        }
    }
}

// Randomly generate 35 bombs
void bombGenerator() {
    srand(time(NULL)); // Set the seed to be current time, generate bombs differently each play time
    int i=1;
    while (i<=35) {
        int x = rand() % 10;
        int y = rand() % 15;
        if (game.base[x][y] != '*') {
            game.base[x][y] = '*';
            neighborBomb(x, y);
            i++;
        }
    }
}




// Generate a 10*15 grid board with hidden bombs and numbers
void baseBoard() {
    for(int i=0; i<10; i++) {
        for(int j=0; j<15; j++) {
            game.base[i][j]='0';
        }
    }

    bombGenerator(); // Randomly generate 35 bombs on the board
}

// Generate a 10*15-grid empty game board
void gameBoard() {
    for(int i=0; i<10; i++) {
        for(int j=0; j<15; j++) {
            game.game[i][j]= 32;
        }
    }
}

// Print the grid board
void printBoard(char b[10][15]) {
    // Print the horizontal axis for player convenience
    cout << "0  | ";
    for(int i=1; i<16; i++) {
        cout << left;
        cout << setw(3) << i;
    }
    cout << endl;

    cout << "-    ";  // Create a format of the printed board, for better visual effect
                      // Make the board less messy
    for(int i=1; i<16; i++) {
        cout << left;
        cout << setw(3) << "-";
    }
    cout << endl;
    for(int i=1; i<11; i++) {
        cout << left;
        cout << setw(2) << i;
        cout << " | "; // Print the vertical axis for player convenience
        for(int j=0; j<15; j++) {
            cout << left;
            cout << setw(3) << b[i-1][j];
        }
        cout << endl;
    }
}

// Check whether the input row and col numbers are outside the rage
// If not, ask the player to input again
void checkrcInput(int & row, int & col ) {
    while( row<1 || row>10 || col<1 || col>15 ) {
        cout << "Incorrect input, please input grid's coordinate again." << endl;
        cin >> row >> col;
    }
}

// Bonus at the start of a new game
// Print a randomly selected 3*3 grids
// Make the game friendlier to the player, give hints at the beginning
void bonus(int & b) {
    srand(time(NULL));
    int x = rand() % 8 + 1;
    int y = rand() % 13 +1;
    while( game.game[x][y] == '*' ) {
        x = rand() % 8 + 1;
        y = rand() % 13 +1;
    }
    game.game[x][y] = game.base[x][y];
    for(int i=(x-1); i<=(x+1); i++) {
        for(int j=(y-1); j<=(y+1); j++ ) {
            if( game.base[i][j] == '*' ) b--;
            game.game[i][j] = game.base[i][j];
        }
    }
}

// Mark the bomb in the game board as the player command
void markBomb(int row, int col) {
    game.game[row-1][col-1] = '*';
}

// Remove the bomb mark
void removeBomb(int row, int col) {
    game.game[row-1][col-1] = 32;
}

// If the player opens a grid that contains a bomb, (s)he lose
void lose() {
    endGame = 0; // this game ends, no more user's command input needed
    cout << "BOOM!!!" << endl;
    cout << "You have stepped on a bomb and lose." << endl;
    cout << "\n";
    cout << "Another game? Please input \"Y\" or \"N\": ";
    char ag;
    cin >> ag;
    while ( ag != 'Y' && ag != 'N' ) {
        cout << "Wrong input! Please input \"Y\" or \"N\" again: ";
        cin >> ag;
    }
    if( ag == 'N' ) {
        again = 0;
    }
    else if( ag == 'Y' ) {
        again++;
    }
}

// Open a grid to show the number the bomb
void openGrid(int row, int col) {
    if ( game.base[row-1][col-1] == '*' ) { //If the grid player opens contains a bomb, the player lose
        lose();
    }
    else {
        game.game[row-1][col-1] = game.base[row-1][col-1];
    }
}

// Mark the uncertainty of a grid
void markUncertain(int row, int col) {
    game.game[row-1][col-1] = '?';
}

// The player wins the game, ask whether to start a new game or not
void win() {
    endGame = 0; // this game ends, no more user's command input needed
    cout << "WIN!!!" << endl;
    cout << "Congratulations!!!" << endl;
    cout << "\n";
    cout << "Another game? Please input \"Y\" or \"N\": ";
    char ag;
    cin >> ag;
    while ( ag != 'Y' && ag != 'N' ) {
        cout << "Wrong input! Please input \"Y\" or \"N\" again: ";
        cin >> ag;
    }
    if( ag == 'N' ) {
        again = 0;
    }
    else if( ag == 'Y' ) {
        again++;
    }
}

// Decide whether the game board is the same as the base board, if it is, the player wins
bool whetherWin() {
    bool result = true;
    for(int i=0; i<10; i++) {
        for(int j=0; j<15; j++) {
            if ( game.game[i][j] != game.base[i][j] ) result = false;
        }
    }
    return result;
}

// Read from the game archive, for resuming the previous game
void readArchive() {
    ifstream fin1, fin2;
    fin1.open("game_archive.txt");
    fin2.open("base_archive.txt");

    if( fin1.fail() || fin2.fail() ) {
        cout << "Error in file opening!" << endl;
        cout << "Initiating a new game..." << endl;
    }
    else {
        fin1 >> game.rBomb; // Read the number of remaining bombs that the player needs to detect

        for(int i=0; i<10; i++) {
            for(int j=0; j<15; j++) {
                fin1 >> game.game[i][j]; // Read the previously-saved game board information from "game_archive.txt"
                if( game.game[i][j] == '-' ) game.game[i][j] = 32;
                fin2 >> game.base[i][j]; // Read the previously-saved game's base board information from "base_archive.txt"
            }
        }
    }

    fin1.close();
    fin2.close();
}

// Save the game status to archive, for later continuation of game
void writeArchive() {
    ofstream fout1, fout2;
    fout1.open("game_archive.txt");
    fout2.open("base_archive.txt");

    if( fout1.fail() || fout2.fail() ) {
        cout << "Error in file opening!" << endl;
        cout << "Game status is not saved, sorry..." << endl;
    }
    else {
        fout1 << game.rBomb << endl; // Save the number of remaining bombs that the player needs to detect

        for(int i=0; i<10; i++) {
            for(int j=0; j<15; j++) {
                if( game.game[i][j] == 32 ) fout1 << '-'; // Save the current game board information to "game_archive.txt"
                else fout1 << game.game[i][j];
                fout2 << game.base[i][j]; // Save this game's base board information to "base_archive.txt"
            }
            fout1 << endl;
            fout2 << endl;
        }
        cout << "Game status saved." << endl;
    }

    fout1.close();
    fout2.close();
}

// Print the command formation that player can input
void inputCommand() {
    cout << "Input command:" << endl;
    cout << "(\"i\" and \"j\" denotes the i-th row, j-th column grid)" << endl;
    cout << "1.mark a bomb: \"b i j\"" << endl;
    cout << "2.remove a bomb: \"r i j\"" << endl;
    cout << "3.open a number grid: \"n i j\"" << endl;
    cout << "4.uncertain about a grid: \"? i j\"" << endl;
    cout << "5.quit the game: \"Q\"" << endl;
}

int main() {

    cout << "Welcome to MineSweeper!" << endl;
    inputCommand();


    while (again != 0) { // Start a new game
        endGame = 1; // Reset the variable for counting the number of commands that the player inputs;
                     // determining whether a game ends or not, "0" denotes end

        game.rBomb = 35; // Count the remaining bombs that the player needs to detect

        // If this is the second game, need to ask whether to resume the game or not
        if( again == 1 ) {
            // Ask whether to resume the previous game
            char resume;
            cout << "Do you want to resume the previous game?" << endl;
            cout << "Please input \"Y\" or \"N\".";
            cin >> resume;
            while ( resume != 'Y' && resume != 'N' ) {
                cout << "Wrong input! Please input \"Y\" or \"N\" again: ";
                cin >> resume;
            }
            if ( resume == 'Y' ) {
                cout << "Loading game status..." << endl;
                readArchive();
            }
            else {
                cout << "Starting a new game..." << endl;
                baseBoard(); // Generate a new base board
                gameBoard(); // Generate an empty game board
                // printBoard(game.base); check whether the base board generated is correct or not
                bonus(game.rBomb);
                cout << "\n";
            }
        }

        // If this is the second game, no need to ask whether to resume the game or not
        // Directly start a new game
        else {
            cout << "Starting a new game..." << endl;
            baseBoard(); // Generate a new base board, overwrite the previous game status record
            gameBoard(); // Generate an empty game board, clear the previous game status record
            //printBoard(game.base); check whether the base board generated is correct or not
            bonus(game.rBomb);
            cout << "\n";
        }


        while ( endGame != 0 ) {

            endGame++; // Update the variable for counting the number of commands that the player inputs;
                       // determining whether a game ends or not, "0" denotes end

            printBoard(game.game);
            cout << game.rBomb << " bombs to go." <<endl;

            // Receive player's command and update the game board according to their inputs
            char input;
            int row, col;
            cin >> input;

            // If the player want to mark a bomb
            if( input == 'b' ) {
                cin >> row >> col;
                //checkrcInput(row, col);
                markBomb(row, col);
                game.rBomb--;
                if (whetherWin()) win();
            }

                // If the player want to remove a mark of the bomb
            else if( input == 'r' ) {
                cin >> row >> col;
                //checkrcInput(row, col);
                removeBomb(row, col);
                game.rBomb++;
            }

                // If the player want to open a grid
            else if( input == 'n' ) {
                cin >> row >> col;
                //checkrcInput(row, col);
                openGrid(row, col);
                if (whetherWin()) win();
            }

                // If the player can't decide what's in the grid, want to mark the uncertainty
            else if( input == '?' ) {
                cin >> row >> col;
                //checkrcInput(row, col);
                markUncertain(row, col);
            }

                // If the player want to quit the game
            else if( input == 'Q' ) {
                endGame = 0; // this game ends, no more user's command input needed

                char save;
                // Ask whether the player want to save the current game status
                cout << "Do you want to save the game?" << endl;
                cout << "Please input \"Y\" or \"N\".";
                cin >> save;
                if( save=='Y' ) {
                    writeArchive();
                }

                again = false; // Reset the again value to exit the loop
            }

        }

    }

    cout << "Bye bye, hope to see you again!" << endl;



    //printBoard(game);
    //printBoard(base);

    return 0;
}
