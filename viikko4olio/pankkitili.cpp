#include "pankkitili.h"
#include <iostream>

Pankkitili::Pankkitili(string omistaja) {
    cout << omistaja << " Bank account created" << endl;
}

double Pankkitili::getBalance()
{
    return saldo;
}

bool Pankkitili::deposit(double deposit)
{
    if (deposit <= 0){
        cout << "Deposit cannot be 0 or smaller" << endl;
        return false;
    }
    saldo += deposit;
    cout << "Deposited: " << deposit << " Saldo is now: " << saldo << endl;
    return true;
}

bool Pankkitili::withdraw(double withdraw)
{
    if (withdraw <= 0){
        cout << "Withdraw cannot be smaller than 0" << endl;
        return false;
    }
    else if (saldo - withdraw < 0){
        cout << "Not enough money on bank account to withdraw" << endl;
        return false;
    }
    else {
        saldo -= withdraw;
        cout << withdraw << " Withdrawn, new balance is: " << saldo << endl;
        return true;
    }
}
