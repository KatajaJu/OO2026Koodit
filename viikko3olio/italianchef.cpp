#include "italianchef.h"
#include <string>
#include <iostream>
using namespace std;

ItalianChef::ItalianChef(string Name) : Chef(Name) {
   // cout << "Chef " << chefName << " constructor" << endl;
}

ItalianChef::~ItalianChef()
{
   // cout << "Chef " << chefName << " destructor" << endl;
}

bool ItalianChef::askSecret(string pw, int flour, int water)
{
    if (pw == password){
        cout << "Password ok!" << endl;
        makepizza(flour, water);
        return true;
    }
    else {
        cout << "Wrong password!" << endl;
        return false;
    }
}

int ItalianChef::makepizza(int flour, int water)
{
    int FlourForPizza = flour / 5;
    int WaterForPizza = water / 5;
    int pizzas;
    if (FlourForPizza < WaterForPizza){
        pizzas = FlourForPizza;
        cout << "ItalianChef " << chefName << " with " << flour << " and " << water << " can make " << pizzas << " pizzas" << endl;
    }
    else{
        pizzas = WaterForPizza;
        cout << "ItalianChef " << chefName << " with " << flour << " and " << water << " can make " << pizzas << " pizzas" << endl;
    }
    return pizzas;

}
