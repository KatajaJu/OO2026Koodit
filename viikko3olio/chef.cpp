#include "chef.h"
#include <string>
#include <iostream>
using namespace std;

Chef::Chef(string Name) {
    chefName = Name;
    cout << "Chef " << chefName << " constructor" << endl;
}

Chef::~Chef(){
    cout << "Chef " << chefName << " deconstructor" << endl;
}

string Chef::getName(){
    return chefName;
}

int Chef::makeSalad(int ingredient){
    int salad = ingredient / 5;
    cout << "Chef " << chefName << " with " << ingredient << " items can make salad " << salad << " portions" << endl;
    return salad;
}

int Chef::makeSoup(int ingredient){
    int soup = ingredient / 3;
    cout << "Chef " << chefName << " with " << ingredient << " items can make soup " << soup << " portions" << endl;
    return soup;
}
