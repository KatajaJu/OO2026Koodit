#include "asiakas.h"
#include <iostream>

using namespace std;

int main()
{
    Asiakas asiakas("Pekka", 2000);

    asiakas.talletus(600);
    asiakas.nosto(200);
    asiakas.luotonNosto(500);
    asiakas.luotonMaksu(400);
    asiakas.showSaldo();
    return 0;
}
