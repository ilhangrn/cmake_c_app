#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <vector>
#include <algorithm>
#include <list>
#include "ig_lib.h"
#include "ig_class.h"

using namespace std;

int Critter::totalCount;

void Critter::greed()
{
    cout << "greed() " << mHunger << endl;
}

Critter::Critter(int hunger, const string& argname)
{
    cout << "+";
    totalCount++;
    mHunger = hunger;
    pName = new string(argname);
}

Critter::Critter(const Critter &c){
    cout << "+";
    pName = new string(*(c.pName));
    mHunger = c.mHunger;
    totalCount++;
}

Critter& Critter::operator=(const Critter& c){
    if(this != &c){
        delete pName;
        pName = new string(*(c.pName));
        mHunger = c.mHunger;
    }
    return *this;
}

Critter::~Critter(){
    cout << "~";
    totalCount--;
    delete pName;
}

int Critter::getHunger()
{
    return mHunger;
}

int Critter::getTotal()
{
    return totalCount;
}

Farm::Farm(int spaces){
    mCritters.reserve(spaces);
}

void Farm::Add(const Critter& critter){
    mCritters.push_back(critter);
}

void Farm::RollCall() const{
    vector<Critter>::const_iterator myIter;
    for(myIter = mCritters.begin(); myIter != mCritters.end(); ++myIter)
        cout << *(myIter);
}

void Critter::setHunger(int hunger)
{
    mHunger = hunger;
}



void classRunner()
{
    Critter cr1;
    cout << "count: " << cr1.getTotal() << endl;
    Critter cr2(70, "second");
    cr1.setHunger(50);
    // cout << "count: " << Critter::totalCount << endl; // it is not public
    // cout << "count: " << cr2.totalCount << endl; // it is not public
    cout << "count: " << Critter::getTotal() << endl; // it is static
    cout << cr2.getHunger() << endl;
    cr1.greed();
    cr2.greed();
    Farm farm1;
    farm1.Add(Critter(10, "crit"));
    farm1.Add(Critter(20, "critobig"));
    farm1.Add(Critter(30, "crisa"));
    farm1.RollCall();
    Peek(cr2);
    cout << cr2;
    cr1 = cr2;
    Critter cr3 = Critter(cr1);
    Critter cr4 = Critter();
    cout << "cr1 : " << cr1 << endl;
    cout << "cr2 : " << cr2 << endl;
    cout << "cr3 : " << cr3 << endl;
    cout << "cr4 : " << cr4 << endl;
    cout << "total: "<< Critter::getTotal() << endl;
    Enemy en1 = Enemy();
    en1.attack();
    Boss b1 = Boss();
    b1.attack();
    b1.specialAttack();
    en1.speak();
    b1.speak();
}

void Peek(const Critter& crita){
    cout << crita.mHunger << endl;
}

ostream& operator<< (ostream& os, const Critter & crita){
    os << "Crite obj";
    os << "name : " << *(crita.pName) << endl;
    return os;
}

Enemy::Enemy(){
    damage = 10;
}

void Enemy::attack(){
    cout << "attacking with: " << damage << endl;
}

void Enemy::speak(){
    cout << "i am enemy" << endl;
}

void Boss::speak(){
    Enemy::speak();
    cout << "but boss!" << endl;
}

Boss::Boss(){
    power = 5;
}

void Boss::specialAttack(){
    cout <<"attacking with: " << this->damage * power << endl;
}