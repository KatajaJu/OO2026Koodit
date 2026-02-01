#include "luottotili.h"
#include <iostream>

Luottotili::Luottotili(string omistaja, double luottoRaja) : Pankkitili(omistaja), luottoRaja(luottoRaja) {
    cout << omistaja << " Credit account created" << endl;
}

bool Luottotili::deposit(double deposit)
{
    if (deposit <= 0){
        cout << "Deposit cannot be 0 or smaller" << endl;
        return false;
    }
    if (saldo + deposit > 0){
        cout << "Credit connot be overpaid" << endl;
        return false;
    }
    saldo += deposit;
    cout << deposit << " Deposited, credit balnce is: " << saldo << endl;
    return true;
}

bool Luottotili::withdraw(double withdraw)
{
    if (withdraw <= 0){
        cout << "withdraw cannot be smaller than 0" << endl;
        return false;
    }
    if (saldo - withdraw < -luottoRaja){
        cout << "Credit limit exceeded" << endl;
        return false;
    }
    saldo -= withdraw;
    cout << withdraw << " Withdrawn, new balance is: " << saldo << endl;
    return true;
}
