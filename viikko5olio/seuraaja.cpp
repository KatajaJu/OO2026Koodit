#include "seuraaja.h"
#include <iostream>

Seuraaja::Seuraaja(string a) {
    cout << "Follower " << a << " created." << endl;
    nimi = a;
    next = nullptr;
}

string Seuraaja::getNimi()
{
    return nimi;
}

void Seuraaja::paivitys(string viesti)
{
    cout << "Follower " << nimi << " got message: " << viesti << endl;
}
