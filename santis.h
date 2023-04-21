#include <iostream>
#include <string>
#include "conio.h"
using namespace std;
int v()
{
    int a;
    do
    {
        cin >> a;
        if (cin.fail() || cin.bad())
        {
            cin.clear();
            cin.ignore(80, '\n');
            cout << "INGRESA UN VALOR NUMERICO, ES LO QUE SE TE PIDE C:" << endl;
            getch();
            continue;
        }
        else
        {
            break;
        }
    } while (true);
    return a;
}
