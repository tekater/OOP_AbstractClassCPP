#pragma warning(disable:4996)
//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>
#include <direct.h>

using namespace std;

class Weapon {
public:
    virtual void useQ() {
    }
};

class Gun :public Weapon {
public:
    virtual void useQ() {
        cout << "Выстрел:\n";
    }
};
class Knife :public Weapon {
public:
    virtual void useQ() {
        cout << "Удар:\n";
    }
};
class Bomb :public Weapon {
public:
    virtual void useQ() {
        cout << "Бросок:\n";
    }
};


class Animals {
protected:
    string name;
    int year;
public:
    Animals(string n, int y) {
        name = n;
        year = y;
    }
    Animals() : Animals("None", 0) {}
    void print() {
        cout << "Name: " << name << endl;
        cout << "Year: " << year << endl;
    }
    void Sound() = 0;
    void Show() {
        cout << name << endl;
    }

    void Type() = 0;
};

class Dog : public Animals {
    int commands;
public:
    
    Dog(string n, int y, int com) :Animals(n, y), commands{ com } {}
    Dog() :Dog("Doh", 20, 10) {}
    void print() {
        Animals::print();
        cout << "Commands: " << commands << endl;
    }
    virtual void Sound() {
        cout << "Гав\n";
    }
    virtual void Type() {
        cout << "Type:" << " Dog\n";
    }
};

class Cat : public Animals {
    int sleeptime;
public:
    Cat(string n, int y, int st) :Animals(n, y), sleeptime{ st } {}
    Cat():Cat("Cit",10,14) {}
    void print() {
        Animals::print();
        cout << "SleepTime: " << sleeptime << endl;
    }
    virtual void Sound() {
        cout << "Мяу\n";
    }
    virtual void Type() {
        cout << "Type:" << " Cat\n";
    }
};

class Parrot : public Animals {
    string words;
public:
    Parrot(string n, int y, string w) :Animals(n, y), words{ w } {}
    Parrot() :Parrot("prt", 3, "I'm Sword") {}
    void print() {
        Animals::print();
        cout << "Words: " << words << endl;
    }
    virtual void Sound() {
        cout << "Чирик\n";
    }
    virtual void Type() {
        cout << "Type:" << " Parrot\n";
    }

};


int main()
{
    setlocale(0, "");
    srand(time(nullptr));

    /*A objA;
    A* ptrA;

    B objB;
    B* ptrB;

    C objC;
    C* ptrC;

    ptrA = &objA;
    ptrA->print();
    ptrA = &objB;
    ptrA->print();
    ptrA = &objC;
    ptrA->print();*/

    /*
    Weapon* w[3]{ new Gun,new Knife,new Bomb };
    int user = 0;
    cout << "[1] - Gun\n[2] - Knife\n[3] - Bomb\n";
    cout << "Ваш выбор:\n";
    cin >> user;
    w[user - 1]->useQ();*/

    Animals* anim[3]{ new Dog{"Steve",20,10},new Cat{ "Loki",4,14 },new Parrot{ "Aatrox",3,"I'm Sword" } };
    
    for (int i = 0; i < 3; i++) {
        anim[i]->print();
        anim[i]->Show();
        anim[i]->Sound();
        anim[i]->Type();
        cout << endl;
    }


}
