#include <bits/stdc++.h>
using namespace std;

void EnterShip(char player[][10], int size, char replacement)
{
    char inichar;
    int inint;

    cout << "   Specify initial position: ";
    cin >> inichar >> inint;
    if (size != 1)
    {
        char orientation;
        cout << "   Specify orientation (H for horizontal and V for vertical): ";
        cin >> orientation;
        cout << endl;
        if (orientation == 'H')
        {
            if (inichar - 'A' > 10 - size)
            {
                cout << "ERROR! Try Again" << endl;
                EnterShip(player, size, replacement);
            }
            else
            {
                int count = 0;
                for (int i = 0; i < size; i++)
                    if (player[inint - 1][inichar - 'A' + i] == '.')
                        count++;
                if (count == size)
                    for (int i = 0; i < size; i++)
                        player[inint - 1][inichar - 'A' + i] = replacement;
                else
                {
                    cout << "ERROR! Try Again" << endl;
                    EnterShip(player, size, replacement);
                }
            }
        }

        if (orientation == 'V')
        {
            if (inint - 1 > 10 - size)
            {
                cout << "ERROR! Try Again" << endl;
                EnterShip(player, size, replacement);
            }
            else
            {
                int count = 0;
                for (int i = 0; i < size; i++)
                    if (player[inint - 1 + i][inichar - 'A'] == '.')
                        count++;
                if (count == size)
                    for (int i = 0; i < size; i++)
                        player[inint - 1 + i][inichar - 'A'] = replacement;
                else
                {
                    cout << "ERROR! Try Again" << endl;
                    EnterShip(player, size, replacement);
                }
            }
        }
    }
    else
    {
        if (player[inint - 1][inichar - 'A'] != '.')
        {
            cout << "ERROR! Try Again" << endl;
            EnterShip(player, size, replacement);
        }
        else
            player[inint - 1][inichar - 'A'] = replacement;
    }
}

void ChooseShip(char player[][10])
{
    cout << "1. Aircraft carrier (occupies 5 spaces)" << endl;
    EnterShip(player, 5, 'A');

    cout << "2. Battleship (4 spaces)" << endl;
    EnterShip(player, 4, 'B');

    cout << "3. Destroyer (3 spaces)" << endl;
    EnterShip(player, 3, 'D');

    cout << "4. Corvette (2 spaces)" << endl;
    EnterShip(player, 2, 'C');

    cout << "5. Frigate (1 spaces)" << endl;
    EnterShip(player, 1, 'F');
}

void ViewBoard(char player[][10])
{
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << player[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void TakeHit(int &hitsavail, char p2[][10], char playershots[][10], int &pa, int &pb, int &pd, int &pc, int &pf)
{
    char inichar;
    int inint;

    cout << "   Specify position: ";
    cin >> inichar >> inint;
    if (playershots[inint - 1][inichar - 'A'] == 'H')
    {
        cout << "       Already hit!";
    }

    else if (playershots[inint - 1][inichar - 'A'] == '*')
    {
        cout << "       Already missed!";
    }
    else if (p2[inint - 1][inichar - 'A'] != '.')
    {
        cout << "       HIT!";
        hitsavail--;
        playershots[inint - 1][inichar - 'A'] = 'H';
        if (p2[inint - 1][inichar - 'A'] == 'A')
        {
            pa--;
            if (pa == 0)
            {
                cout << " AND SINK!";
            }
        }
        if (p2[inint - 1][inichar - 'A'] == 'B')
        {
            pb--;
            if (pb == 0)
            {
                cout << " AND SINK!";
            }
        }
        if (p2[inint - 1][inichar - 'A'] == 'D')
        {
            pd--;
            if (pd == 0)
            {
                cout << " AND SINK!";
            }
        }
        if (p2[inint - 1][inichar - 'A'] == 'C')
        {
            pc--;
            if (pc == 0)
            {
                cout << " AND SINK!";
            }
        }
        if (p2[inint - 1][inichar - 'A'] == 'F')
        {
            pf--;
            if (pf == 0)
            {
                cout << " AND SINK!";
            }
        }
    }
    else
    {
        cout << "       MISS!";
        playershots[inint - 1][inichar - 'A'] = '*';
    }
    ViewBoard(playershots);
}

int main()
{
    cout << "                       WELCOME TO BATTLESHIP" << endl;
    string pl1, pl2;
    cout << "Player 1, choose a username: ";
    cin >> pl1;
    cout << "Player 2, choose a username: ";
    cin >> pl2;
    cout << endl;

    cout << "LET THE GAME BEGIN!" << endl;

    char p1[10][10];
    char p2[10][10];

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            p1[i][j] = '.';
            p2[i][j] = '.';
        }
    }

    cout << pl1 << ", CHOOSE WHERE TO PLACE YOUR SHIPS" << endl;
    ChooseShip(p1);
    cout << endl;
    cout << pl2 << ", CHOOSE WHERE TO PLACE YOUR SHIPS" << endl;
    ChooseShip(p2);

    int seeboard1, seeboard2;
    cout << pl1 << ", PRESS 1 IF YOU WISH TO SEE YOUR BOARD, ELSE PRESS ANY OTHER KEY" << endl;
    cin >> seeboard1;
    if (seeboard1 == 1)
        ViewBoard(p1);
    cout << pl2 << ", PRESS 1 IF YOU WISH TO SEE YOUR BOARD, ELSE PRESS ANY OTHER KEY" << endl;
    cin >> seeboard2;
    if (seeboard2 == 1)
        ViewBoard(p2);

    cout << "YOU HAVE PLACED THE SHIPS, NOW PREPARE TO FIRE YOUR SHOTS" << endl;

    int hits1avail = 15, hits2avail = 15;
    int p1a = 5, p2a = 5, p1b = 4, p2b = 4, p1d = 3, p2d = 3, p1c = 2, p2c = 2, p1f = 1, p2f = 1;
    char p1shots[10][10];
    char p2shots[10][10];

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            p1shots[i][j] = '.';
            p2shots[i][j] = '.';
        }
    }

    while (true)
    {
        cout << "   " << pl1 << ", take a shot" << endl;
        TakeHit(hits2avail, p2, p1shots, p2a, p2b, p2d, p2c, p2f);
        if (hits2avail == 0)
        {
            cout << pl1 << " WINS!" << endl;
            break;
        }

        cout << "   " << pl2 << ", take a shot" << endl;
        TakeHit(hits1avail, p1, p2shots, p1a, p1b, p1d, p1c, p1f);
        if (hits1avail == 0)
        {
            cout << pl2 << " WINS!" << endl;
            break;
        }
    }

    return 0;
}