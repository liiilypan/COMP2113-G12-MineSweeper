# COMP2113-G12-MineSweeper

COMP2113 Group Project  
Game: MineSweeper  
Team numbers: 12  
Pan Chen 3035534828     

Description: The program will randomly generate a 10\*15 grid board with 35 hidden bombs on it. The rest of the 115 grids contains numbers 0-8 which indicate how many neighboring bombs.  
With these numbers as clues, the player needs to find out all the bombs and mark them without detonating them.  

Rules: 
The program will first generate a 10\*15 grid board with all grids zero. (consider it as a 10\*15 matrix).  
When the player wants to open a grid to see the hidden number, (s)he will need first to enter "n", then enter i, j that denotes the position of the grid (i-th row, j-th column). If the grid contains a number, the program will print a updated board showing the number in grid[i][j], as well as the number of remaining bombs. Otherwise, if the grid contains a bomb, the program will output "BOMB!!!" and ask the player whether (s)he will re-start a game or not.  
When the player wants to mark a grid with bombs, (s)he will need first to enter "b", then enter i, j that denotes the position of the grid (i-th row, j-th column).  
When the player wants to remove a bomb mark, (s)he will need first to enter "r", then enter i, j that denotes the position of the grid (i-th row, j-th column).  
When the player is uncertain about a grid, (s)he can first enter "?", then enter i, j that denotes the position of the grid (i-th row, j-th column) to mark the grid with uncertainty.  
When all the grids in the board are filled with numbers and "*", the program will output "WIN!!!" and ask the player whether (s)he will re-start a game or not.  

Features:  

1. A structure to store the game status: (Code Requirement 2)  
• a 2-D C-string to store the base board of current game  
• a 2-D C-string to store the updated game boarch after executing player's commands  
• an interger to store the number of remaining bombs that the player needs to detect  
2. A 10\*15 grid base board with hidden bombs and numbers: (Code Requirement 1)  
• base board is used as a standard for the program to decide winning or lossing  
•	Use "char" to generate a 10\*15 base table  
•	Use "rand()": using time as seed to generate the 35 bombs in the table previous created  
•	Use a function to determine the number of neighboring bombs of the rest 115 grids  
3. A 10\*15 blank game board to store the player's input  
4. Player’s inputs:  
• Player's inputs will only stop when the game end, that is the player wins or loses  
•	Use "if" statement to determine whether the player want to mark a bomb or check the number  
•	If player input is "b", use a function to replace the "0" in chosen grid of game table with "\*" then print the updated table with number of remaining bombs  
• If player input is "n", check the chosen grid in base table: if it contains a bomb, output "BOMB!!!", use a function to ask the player whether to re-start the game; otherwise, use a function to replace the "0" in chosen grid of game table with the number shown in the base table, then print the updated table with number of remaining bombs  
•	if player input is "r", use a function to remove the bomb mark in game table, which means replacing "\*" with "0", then print the updated table with number of remaining bombs  
•	if player input is "?", use a function to replace "\*" or "0" in the chosen grid with question mark "?", then print the updated table with number of remaining bombs  
5. Print the updated game table  
•	After the player inputs the command and the grid coordinate, the program will print the updated game table  
•	The opened grids with numbers and the determined bombs will be shown in the print table, while the unopened grids remain blank  
6. Winning determination  
•	In the main() function, there is a function to compare whether the game board is the same as the base board: if it is, print "WIN!!!" and ask the player whether to re-start the game; if it is not, let player continue to input  
7. Losing determination  
• If the player commands to open a grid that contains a bomb, (s)he loses  
8. Quit the game  
•	The player can quit the game whenever they want by inputting "q", the program will use a function to identify their input and then lead to the process of saving game status  
9. Save/Load system: (Code Requirement 4)  
•	Use some functions to create a TXT document to store the important data in the current game progress to achieve the effect of saving the game status  
•	Use some functions to read the information stored in TXT and achieve the effect of loading the previous game status  
10. Start of a new game:  
• After the player wins or loses, the program will ask (s)he whether to start a new game or not  

Assumptions:  
1. player will enter only 5 kinds of commands after the game starts: "b", "r", "n", "?" and "Q"  
2. when denoting the coordinate of the grid, player will first enter a row number between 1 and 10 (1 and 10 included),then enter a space, last enter a column number between 1 and 15 (1 and 15 included) e.g. "3 6"  
