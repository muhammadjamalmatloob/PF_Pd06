#include<iostream>
#include<string>
#include<cmath>
#include<windows.h>
#include<conio.h>

using namespace std;


//Prototype of different functions

void print_title();
void gameInfo();
void gotoxy(int x, int y);
char getCharAtxy(short int x, short int y);
void print_table_of_game();
bool horizontal();
void moveLeft();
void moveRight();
void moveUp();
void moveDown();
void moveUpLeft();
void moveUpRight();
void moveUpLeft();
void moveUpRight();
void moveDownLeft();
void moveDownRight();
void drawline();
bool leftBoxCompleting();
bool rightBoxCompleting();
bool upBoxCompleting();
bool downBoxComleting();
void fillUpBox();
void fillDownBox();
void fillLeftBox();
void fillRightBox();
void printPlayersScore();

/*These variables will be used repeatedly in the whole code 
so I have declared them globally*/

int x = 6, y = 6;
int rows, cols;
int p1_score = 0, p2_score = 0 , p3_score = 0 , p4_score = 0;
int p = 1;

//Start of the main function

int main()
{

    //Menu of the game

    menu:
    system("cls");

    //To print logo

    print_title();

    //To enter User's choice
    cout << "\a";
    char choice;
    cout << "\n\n\n\n";
    cout << " 1. Start New Game\n";
    cout << " 2. How to play\n";
    cout << " 3. Exit\n\n\n";
    cout << " Enter your choice: ";
    choice = getch();
    cout << "\a";

    //When chioce is 1(Start new game) the following code will be executed

    if (choice == '1')
    {
        step1:
        system("cls");

        //To print logo

        print_title();

        //To take number of rows and cols of the game maze

        cout << "\n\n";
        cout << " Enter number of rows(4-12): ";
        cin >> rows;
        cout << " Enter number of columns(4-12): ";
        cin >> cols;

        //When rows and cols are in defined range(4-20)

        if (rows>=4 && cols>=4 && rows<=12 && cols<=12)
        {
            //Clear screen

            system("cls");

            //Game start

            //Initial scores of players

            printPlayersScore();

            //Printing game maze

            cout << "\n\n\n\n\a";
            print_table_of_game();

            //Moving cursor to start of the maze

            gotoxy(x,y);

            /*Playing the game until the loop is stopped(break statement)
            when game is ended*/ 

            while (true)
            {
                //Player 1 Try
                while (true)
                {
                    char move = getch();
                    cout << "\a";
                    if (move == 'd' || move == 'D')
                    {
                        moveRight();
                    }
                    else if (move == 'a' || move == 'A')
                    {
                        moveLeft();
                    }
                    else if (move == 'c' || move == 'C')
                    {
                        moveDownRight();
                    }
                    else if (move == 'z' || move == 'Z')
                    {
                        moveDownLeft();
                    }
                    else if (move == 'q' || move == 'Q')
                    {
                        moveUpLeft();
                    }
                    else if (move == 'e' || move == 'E')
                    {
                        moveUpRight();
                    }
                    else if (move == 'w' || move == 'W')
                    {
                        moveUp();
                    }
                    else if (move == 'x' || move == 'X')
                    {
                        moveDown();
                    }
                    else if (move == 's' || move == 'S')
                    {
                        if (getCharAtxy(x,y) == ' ')
                        {
                            drawline();
                            if (leftBoxCompleting() && rightBoxCompleting())
                            {
                                fillLeftBox();
                                fillRightBox();
                                p1_score +=2;
                                printPlayersScore();
                                continue;
                            }
                            else if (rightBoxCompleting())
                            {
                                fillRightBox();
                                p1_score ++;
                                printPlayersScore();
                                continue;
                            }
                            else if (leftBoxCompleting())
                            {
                                fillLeftBox();
                                p1_score ++;
                                printPlayersScore();
                                continue;
                            }
                            else if (upBoxCompleting() && downBoxComleting())
                            {
                                fillUpBox();
                                fillDownBox();
                                p1_score +=2;
                                printPlayersScore();
                                continue;
                            }
                            else if (upBoxCompleting())
                            {
                                fillUpBox();
                                p1_score ++;
                                printPlayersScore();
                                continue;
                            }
                            else if (downBoxComleting())
                            {
                                fillDownBox();
                                p1_score ++;
                                printPlayersScore();
                                continue;
                            }
                            else
                            {
                                break;
                            }
                        }
                    }
                }
                //End of Player 1 Try
            }
        }
        //End of Game Play
        else
        {
            system("cls");
            cout << "Number of rows and columns should be between (4-12).\n\n\nPress any key to re-enter number of rows and columns";
            getch();
            goto step1;
        }
    }

    //End of choice 1

    //When chioce is 2(How to play) the following code will be executed

    else if (choice == '2')
    {
        system("cls");
        gameInfo();
        cout << "\n\n\n Press B to go back to main menu.";
        char opt = getch();
        if (opt == 'B' || opt == 'b')
        {
            goto menu;
        }
    }

    //End of choice 2

    //When chioce is 3(Start new game) the following code will be executed

    else if (choice == '3')
    {
        return 0;//To end program(Exit)
    }

    //End of choice 3

    getch();
    return 0;
}
//End of the main function

//Function to print game logo
void print_title()
{
    cout << "\n";
    cout << " --------------------------------------------------------------------------------\n";
    cout << " | #########    #######  ##########  #######     ######   ####  ### #########   |\n";
    cout << " |   ##     ## ##     ## ##  ##  ## ##          ##    ##   ####  ##   ##     ## |\n";
    cout << " |   ##     ## ##     ##     ##      ######     ########   ## ## ##   ##     ## |\n";
    cout << " |   ##     ## ##     ##     ##           ##    ##    ##   ##  ####   ##     ## |\n";
    cout << " |   ##     ## ##     ##     ##           ##    ##    ##   ##   ###   ##     ## |\n";
    cout << " | #########    #######     ####    #######     ##    ##  ###    ## #########   |\n";
    cout << " |                                                                              |\n";
    cout << " |            #########    #######  ###     ### ##########  #######             |\n";
    cout << " |              ##     ## ##     ##   ##   ##     ##       ##                   |\n";
    cout << " |              #######   ##     ##     ###       ######    ######              |\n";
    cout << " |              ##     ## ##     ##   ##   ##     ##             ##             |\n";
    cout << " |              ##     ## ##     ##  ##     ##    ##             ##             |\n";
    cout << " |            #########    #######  ##       ## ########## #######              |\n";
    cout << " --------------------------------------------------------------------------------\n";
}
//End of the function body

//Function to move cursor to any (x,y) position in the plane of the game
void gotoxy(int x, int y)
{
  COORD coordinates;
  coordinates.X = x;
  coordinates.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
//End of the function body

/*Function to print game maze in the form of dots containing 
rows and cols equal to the num entered by the user*/
void print_table_of_game()
{
    int a = 0;
    for(int i = 1; i <= (rows+1);i++)
    {
        gotoxy(5,a + 6);
        for(int j = 1;j <= (cols+1);j++)
        {
            cout << ".   ";
        }
        a +=2;
    }
}
//End of the function body

//Function to print instructions for playing the game 
void gameInfo()
{
    cout << " About\n\n";
    cout << " It is a four players game." << endl;
    cout << " How to play?" << endl;
    cout << " Player  can move the cursor to left, right, up, down, down to left, down to right, up to left and up to right by the characters A, D, W, X, Z, C, Q and E respectively." << endl;
    cout << " Players have to join dots by lines." << endl;
    cout << " In case, if a box is completed, the scores of the respective players will increased by one and will be given another chance." << endl;
    cout << " At the end the player with more scores will be declared as winner." << endl;
}
//End of the function body

bool horizontal()
{
    return ((y-6)%2 == 0);
}

//To move right in the game maze
void moveRight()
{
    if (horizontal())
    {
        if (x <= (cols*4-2))
        {
            x = x + 4;
            gotoxy(x,y);
        }
    }
    else
    {
        if (x <= (cols*4+2))
        {
            x = x + 4;
            gotoxy(x,y);
        }
    }
}
//End of the function body

//To move left in the game maze
void moveLeft()
{
    if (horizontal())
    {
        if (x >= (9))
        {
            x = x - 4;
            gotoxy(x,y);
        }
    }
    else
    {
        if (x >= (8))
        {
            x = x - 4;
            gotoxy(x,y);
        }
    }
}
//End of the function body

void moveDownRight()
{
    if (x <= (cols*4+2) && y <= (rows*2+5))
    {
        if (horizontal())
        {
            x += 3;
            y++;
            gotoxy(x,y);
        }
        else
        {
            x++;
            y++;
            gotoxy(x,y);
        }
    } 
}

void moveDownLeft()
{
    if (x >= 6 && y <= (rows*2+5))
    {
        if (horizontal())
        {
            x--;
            y++;
            gotoxy(x,y);
        }
        else
        {
            x-=3;
            y++;
            gotoxy(x,y);
        }
    }
}

void moveUpLeft()
{
    if (y>=7 && x>=6)
    {
        if (horizontal())
        {
            x--;
            y--;
            gotoxy(x,y);
        }
        else
        {
            x-=3;
            y--;
            gotoxy(x,y);
        }
    }
}

void moveUpRight()
{
    if (y >= 7 && x <= cols*4+2)
    {
        if (horizontal())
        {
            x+=3;
            y--;
            gotoxy(x,y);
        }
        else
        {
            x++;
            y--;
            gotoxy(x,y);
        }
    }
}

void moveUp()
{
    if (!horizontal())
        if(y >= 9)
        {
            y -=2;
            gotoxy(x,y);
        }
}

void moveDown()
{
    if (!horizontal())
        if(y <= rows*2+3)
        {
            y +=2;
            gotoxy(x,y);
        }
}

void drawline()
{
    if (horizontal())
    {
        if (x <= cols*4+3)
        {
            cout << "---";
        }
    }
    else
    {
        if (x <= cols*4+6)
        {
            cout << "|";
        }
    }
}

char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0,0};
    SMALL_RECT rect = {x,y,x,y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}

//To print scores of all players of the game
void printPlayersScore()
{
    gotoxy(5,1);
    cout << "Player 1(User) Scores: " << p1_score;
    gotoxy(5,2);
    cout << "Player 2(Comp) Scores: " << p2_score;
    gotoxy(5,3);
    cout << "Player 3(Comp) Scores: " << p3_score;
    gotoxy(5,4);
    cout << "Player 4(Comp) Scores: " << p4_score;
    gotoxy(x,y);
}
//End of the function body

bool leftBoxCompleting()
{
    return (getCharAtxy(x-4,y) == '|' && getCharAtxy(x-3,y-1) == '-' && getCharAtxy(x-3,y+1) == '-');
}



bool rightBoxCompleting()
{
    return (getCharAtxy(x+4,y) == '|' && getCharAtxy(x+1,y-1) == '-' && getCharAtxy(x+1,y+1) == '-');
}



bool upBoxCompleting()
{
    return (getCharAtxy(x-1,y-1) == '|' && getCharAtxy(x+3,y-1) == '|' && getCharAtxy(x,y-2) == '-');
}



bool downBoxComleting()
{
    return (getCharAtxy(x-1,y+1) == '|' && getCharAtxy(x+3,y+1) == '|' && getCharAtxy(x,y+2) == '-');
}


void fillUpBox()
{
    if (getCharAtxy(x+1,y-1) == ' ')
    {
        gotoxy(x+1,y-1);
        cout << p;
        gotoxy(x,y);
    }
}



void fillDownBox()
{
    if (getCharAtxy(x+1,y+1) == ' ')
    {
        gotoxy(x+1,y+1);
        cout << p;
        gotoxy(x,y);
    }
}



void fillLeftBox()
{
    if (getCharAtxy(x-2,y) == ' ')
    {
        gotoxy(x-2,y);
        cout << p;
        gotoxy(x,y);
    }
}



void fillRightBox()
{
    if (getCharAtxy(x+2,y) == ' ')
    {
        gotoxy(x+2,y);
        cout << p;
        gotoxy(x,y);
    }
}
