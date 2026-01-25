#include <iostream>
#include "chef.h"
#include "italianchef.h"

using namespace std;

int main()
{
    Chef chef("Gordon");
    chef.makeSalad(12);
    chef.makeSoup(15);

    ItalianChef italianchef("Mario");
    italianchef.makeSoup(10);
    italianchef.askSecret("pizza", 15, 13);
    return 0;
}
