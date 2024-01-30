#include <bits/stdc++.h>
#include <cctype>
using namespace std;

char board[8][8] = {' '};

void sett_board(int pc1, int pc2)
{
//	board [8][8]=
//	{
//    {' ', pc1, ' ', pc1, ' ', pc1, ' ', pc1},
//    {pc1, ' ', pc1, ' ', pc1, ' ', pc1, ' '},
//    {' ', pc1, ' ', pc1, ' ', pc1, ' ', pc1},
//    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
//    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
//    {pc2, ' ', pc2, ' ', pc2, ' ', pc2, ' '},
//    {' ', pc2, ' ', pc2, ' ', pc2, ' ', pc2},
//    {pc2, ' ', pc2, ' ', pc2, ' ', pc2, ' '},
//	};


	// Setting player 1
	for(int i=0; i<5; i++)
	{
		for(int j=0; j<8; j++)
		{
			if(i == 0 && j%2 != 0)
			{
				board[i][j] = pc1;
			}
			else if(i == 0 && j%2 == 0)
			{
				board[i][j] = ' ';
			}
			
			if(i == 1 && j%2 == 0)
			{
				board[i][j] = pc1;
			}
			else if(i == 1 && j%2 != 0)
			{
				board[i][j] = ' ';
			}
			
			if(i == 2 && j%2 != 0)
			{
				board[i][j] = pc1;
			}
			else if(i == 2 && j%2 == 0)
			{
				board[i][j] = ' ';
			}
			
			if(i > 2)
			{
				board[i][j] = ' ';
			}
		}
	}
	
	
	// Setting Player 2
	for(int i=7; i>=5; i--)
	{
		for(int j=7; j>=0; j--)
		{
			if(i == 7 && j%2 == 0)
			{
				board[i][j] = pc2;
			}
			else if(i == 7 && j%2 != 0)
			{
				board[i][j] = ' ';
			}
			
			if(i == 6 && j%2 != 0)
			{
				board[i][j] = pc2;
			}
			else if(i == 6 && j%2 == 0)
			{
				board[i][j] = ' ';
			}
			
			if(i == 5 && j%2 == 0)
			{
				board[i][j] = pc2;
			}
			else if(i == 5 && j%2 != 0)
			{
				board[i][j] = ' ';
			}
		}
	}
	
}

string p1, p2;
char pc1, pc2, turn;
char upperPc1, upperPc2;
bool leap;
bool game_running = true;
int row1, row2, column1, column2;


void display_board();
void input();
bool check_move();
void move();
void do_leap();
void king();
void game_over();

int main()
{
    cout << "========== CHECKERS GAME ==========\n";
    cout << "-> Player 1, please enter your name:\n";
    cin >> p1;
    pc1 = tolower(p1[0]);
    upperPc1 = toupper(pc1);

    turn = upperPc1;
    cout << "->Player 2, Enter your name:\n";
    cin >> p2;
    pc2 = tolower(p2[0]);
	upperPc2 = toupper(pc2);

    // Setting board
    sett_board(pc1,pc2);

    cout << "->capital letter represents a king piece.\n";
    cout << "->Please resize your terminal window so that this line fits the screen:\n";
    cout << "_____________________________________________________________________________________\n\n";
    cout << "Press enter to begin...";
    cin.get();
	
	// Game loop
    while (game_running)
    {
        display_board();
        
        if (turn == upperPc1)
        {
            cout << "--Player 1 ["<<turn<<"]--\n";
        }
        else if (turn == upperPc2)
        {
            cout << "--Player 2 ["<<turn<<"]--\n";
        }
        
        input();
        move();
        king();
        game_over();
    }
    
	// Display winner at the end
    if (turn == 'B')
    {
        cout << endl << endl << "Player 2 [Red] wins!\n";
    }
    else if (turn == 'R')
    {
        cout << endl << endl << "Player 1 [Black] wins!\n";
    }
    
    cout << "GAME OVER!\n";
}

// Displaying checkers board
void display_board()
{
    cout << "==================================================================================\n\n\n\n";
    cout << "       0         1         2         3         4         5         6         7     \n";
    cout << "  _________________________________________________________________________________\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "0 |    " << board[0][0] << "    |    " << board[0][1] << "    |    " << board[0][2] << "    |    "  << board[0][3] << "    |    " << board[0][4] << "    |    " << board[0][5] << "    |    " << board[0][6] << "    |    " << board[0][7] << "    |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |_________|_________|_________|_________|_________|_________|_________|_________|\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "1 |    " << board[1][0] << "    |    " << board[1][1] << "    |    " << board[1][2] << "    |    "  << board[1][3] << "    |    " << board[1][4] << "    |    " << board[1][5] << "    |    " << board[1][6] << "    |    " << board[1][7] << "    |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |_________|_________|_________|_________|_________|_________|_________|_________|\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "2 |    " << board[2][0] << "    |    " << board[2][1] << "    |    " << board[2][2] << "    |    "  << board[2][3] << "    |    " << board[2][4] << "    |    " << board[2][5] << "    |    " << board[2][6] << "    |    " << board[2][7] << "    |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |_________|_________|_________|_________|_________|_________|_________|_________|\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "3 |    " << board[3][0] << "    |    " << board[3][1] << "    |    " << board[3][2] << "    |    "  << board[3][3] << "    |    " << board[3][4] << "    |    " << board[3][5] << "    |    " << board[3][6] << "    |    " << board[3][7] << "    |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |_________|_________|_________|_________|_________|_________|_________|_________|\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "4 |    " << board[4][0] << "    |    " << board[4][1] << "    |    " << board[4][2] << "    |    "  << board[4][3] << "    |    " << board[4][4] << "    |    " << board[4][5] << "    |    " << board[4][6] << "    |    " << board[4][7] << "    |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |_________|_________|_________|_________|_________|_________|_________|_________|\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "5 |    " << board[5][0] << "    |    " << board[5][1] << "    |    " << board[5][2] << "    |    "  << board[5][3] << "    |    " << board[5][4] << "    |    " << board[5][5] << "    |    " << board[5][6] << "    |    " << board[5][7] << "    |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |_________|_________|_________|_________|_________|_________|_________|_________|\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "6 |    " << board[6][0] << "    |    " << board[6][1] << "    |    " << board[6][2] << "    |    "  << board[6][3] << "    |    " << board[6][4] << "    |    " << board[6][5] << "    |    " << board[6][6] << "    |    " << board[6][7] << "    |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |_________|_________|_________|_________|_________|_________|_________|_________|\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "7 |    " << board[7][0] << "    |    " << board[7][1] << "    |    " << board[7][2] << "    |    "  << board[7][3] << "    |    " << board[7][4] << "    |    " << board[7][5] << "    |    " << board[7][6] << "    |    " << board[7][7] << "    |\n";
    cout << "  |         |         |         |         |         |         |         |         |\n";
    cout << "  |_________|_________|_________|_________|_________|_________|_________|_________|\n";
}

// Takes in user input
void input()
{
    cout << "Move piece\n";
    cout << "Row: ";
    cin >> row1;
    cout << "Column: ";
    cin >> column1;
    
    while (row1 < 0 || row1 > 7 || column1 < 0 || column1 > 7)
    {
        cout << "Incorrect input. Enter numbers between 0 and 7.\n";
        cout << "Move piece\n";
        cout << "Row: ";
        cin >> row1;
        cout << "Column: ";
        cin >> column1;
    }
    
    cout << "To box\n";
    cout << "Row: ";
    cin >> row2;
    cout << "Column: ";
    cin >> column2;
    
    while (row2 < 0 || row2 > 7 || column2 < 0 || column2 > 7)
    {
        cout << "Incorrect input. Enter numbers between 0 and 7.\n";
        cout << "To box\n";
        cout << "Row: ";
        cin >> row2;
        cout << "Column: ";
        cin >> column2;
    }
    
    while (check_move() == false)
    {
        cout << "ILLEGAL MOVE!\n";
        input();
    }
}

// if a move is legal
bool check_move()
{
    // if a non-king piece is moving backwards
    if (board[row1][column1] != upperPc1 && board[row1][column1] != upperPc2)
    {
        if ((turn == upperPc1 && row2 < row1) || (turn == upperPc2 && row2 > row1))
        {
            leap = false;
            return false;
        }
    }
    
    // if the location have space or not
    if (board[row2][column2] != ' ')
    {
        leap = false;
        return false;
    }
    
    // if location entered by the user contains a piece to be moved
    if (board[row1][column1] == ' ')
    {
        leap = false;
        return false;
    }
    
    // if the piece isn't moving diagonally
    if (column1 == column2 || row1 == row2)
    {
        leap = false;
        return false;
    }
    
    //  if the piece is moving by more than 1 column and only 1 row
    if ((column2 > column1 + 1 || column2 < column1 - 1) && (row2 == row1 +1 || row2 == row1 - 1))
    {
        leap = false;
        return false;
    }
    
    //  if the piece is leaping
    if (row2 > row1 + 1 || row2 < row1 - 1)
    {
        // Checks if the piece is leaping too far
        if (row2 > row1 + 2 || row2 < row1 - 2)
        {
            leap = false;
            return false;
        }
        
        //  if the piece isn't moving by exactly 2 columns
        if (column2 != column1 + 2 && column2 != column1 - 2)
        {
            leap = false;
            return false;
        }
        
        // if the piece is leaping over another piece from the other player
		char otherPlayer;
		if (toupper(board[row1][column1]) == upperPc2) {
			otherPlayer = upperPc1;
		} else {
			otherPlayer = upperPc2;
		}
		
        if (row2 > row1 && column2 > column1)
        {
            if (toupper(board[row2 - 1][column2 - 1]) != otherPlayer)
            {
                leap = false;
                return false;
            }
        }
        else if (row2 > row1 && column2 < column1)
        {
            if (toupper(board[row2 - 1][column2 + 1]) != otherPlayer)
            {
                leap = false;
                return false;
            }
        }
        else if (row2 < row1 && column2 > column1)
        {
            if (toupper(board[row2 + 1][column2 - 1]) != otherPlayer)
            {
                leap = false;
                return false;
            }
        }
        else if (row2 < row1 && column2 < column1)
        {
            if (toupper(board[row2 + 1][column2 + 1]) != otherPlayer)
            {
                leap = false;
                return false;
            }
        }
        
        leap = true;
        return true;
    }
    
    leap = false;
    return true;
}


// k226007 Performs a move
void move()
{
    bool king_piece = false;
    
    if (board[row1][column1] == upperPc1 || board[row1][column1] == upperPc2)
    {
        king_piece = true;
    }
    
    board[row1][column1] = ' ';
    
    if (turn == upperPc1)
    {
        if (king_piece == false)
        {
            board[row2][column2] = tolower(pc1);
        }
        else if (king_piece == true)
        {
            board[row2][column2] = upperPc1;
        }
        
        turn = upperPc2;
    }
    else if (turn == upperPc2)
    {
        if (king_piece == false)
        {
            board[row2][column2] = tolower(pc2);
        }
        else if (king_piece == true)
        {
            board[row2][column2] = upperPc2;
        }
        
        turn = upperPc1;
    }
    
    if (leap == true)
    {
        do_leap();
    }
}

// Performs leap over a checkers piece
void do_leap()
{
    char answer;
    
    // Removes the checker piece after leap
    if (row2 > row1 && column2 > column1)
    {
        board[row2 - 1][column2 - 1] = ' ';
    }
    else if (row2 > row1 && column2 < column1)
    {
        board[row2 - 1][column2 + 1] = ' ';
    }
    else if (row2 < row1 && column2 > column1)
    {
        board[row2 + 1][column2 - 1] = ' ';
    }
    else if (row2 < row1 && column2 < column1)
    {
        board[row2 + 1][column2 + 1] = ' ';
    }
    
    display_board();
    
    // Asks the user to leap again
    do
    {
        cout << "You just leaped once. Do you want to try a second (y/n): ";
        cin >> answer;
    }
    while (answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n');
    
    if (answer == 'y' || answer == 'Y')
    {
        row1 = row2;
        column1 = column2;
        cout << "Leap piece: row: " << row1 << ", column: " << column1 << endl;
        cout << "To box\n";
        cout << "row: ";
        cin >> row2;
        cout << "column: ";
        cin >> column2;
        
        while (row2 < 0 || row2 > 7 || column2 < 0 || column2 > 7)
        {
            cout << "Incorrect input. Enter numbers between 0 and 7.\n";
            cout << "To box\n";
            cout << "Row: ";
            cin >> row2;
            cout << "Column: ";
            cin >> column2;
        }	
        
        if (turn == upperPc1)
        {
            turn = upperPc2;
        }
        else if (turn == upperPc2)
        {
            turn = upperPc1;
        }
        
        check_move();
        
        if (leap == false)
        {
            cout << "INVALID LEAP!\n";
            
            if (turn == upperPc1)
            {
                turn = upperPc2;
            }
            else if (turn == upperPc2)
            {
                turn = upperPc1;
            }
        }
        else if (leap == true)
        {
            move();
        }
    }
}

// Converts regular checkers pieces that have reached the other side of the board to king pieces
void king()
{
    for (int i = 0; i < 8; i++)
    {
        if (board[0][i] == pc2)
        {
            board[0][i] = upperPc2;
        }
        
        if (board[7][i] == pc1)
        {
            board[7][i] = upperPc1;
        }
    }
}

// Determins if the game is over
void game_over()
{
    int counter = 0;
    
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] != ' ')
            {
                counter++;
            }
        }
    }
    
    if (counter > 1)
    {
        game_running = true;
    }
    else if (counter == 1)
    {
        game_running = false;
    }
}



