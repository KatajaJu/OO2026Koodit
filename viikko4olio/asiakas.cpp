#include "asiakas.h"
#include <iostream>

Asiakas::Asiakas(string nimi, double luottoRaja)
{
    pankkitili = new Pankkitili(nimi);
    luottotili = new Luottotili(nimi, luottoRaja);
}

string Asiakas::getNimi()
{
    return nimi;
}

void Asiakas::showSaldo()
{
    cout << "Pankkitili: " << pankkitili->getBalance() << endl;
    cout << "Luottotili: " << luottotili->getBalance() << endl;
}

bool Asiakas::talletus(double summa)
{
    return pankkitili->deposit(summa);
}

bool Asiakas::nosto(double summa)
{
    return pankkitili->withdraw(summa);
}

bool Asiakas::luotonMaksu(double summa)
{
    return luottotili->deposit(summa);
}

bool Asiakas::luotonNosto(double summa)
{
    return luottotili->withdraw(summa);
}
