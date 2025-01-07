#include "Menu.h"
#include <iostream>
#include <stdio.h>

using namespace std;


int Menu::menu()
{
    cout<<"Revenge's Island \n1. Jouer\n2. Instructions\n3. Quitter"<<endl;
    choice=fgetc(stdin);
    return choice;
}

