#pragma warning(disable:4996)
//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>
#include <direct.h>

using namespace std;

class Employer {
protected:
    string name;
    int exp;
    int salary;
public:
    Employer(string n,int e, int s) {
        name = n;
        exp = e;
        salary = s;
    }
    Employer() :Employer("None", 0, 0) {}
    virtual void print() {
        cout << "Name: " << name << endl;
        cout << "Exp: " << exp << " years." <<  endl;
        cout << "Salary: " << salary << "$" << endl;
    }
};

class President: public Employer{
    int workers;
public:
    President(string n, int e, int s, int w) : Employer(n, e, s), workers{ w } {}
    President() :President("None", 0, 0, 0) {}
    virtual void print() {
        Employer::print();
        cout << "Workers: " << workers << endl;
    }
};

class Manager: public Employer {
    int sum;
public:
    Manager(string n, int e, int s, int uSum) : Employer(n, e, s), sum{ uSum } {}
    Manager() :Manager("None", 0, 0, 0) {}
    virtual void print() {
        Employer::print();
        cout << "Sum: " << sum << endl;
    }
};

class Worker : public Employer {
    int WorkShift;
public:
    Worker(string n, int e, int s, int ws) : Employer(n, e, s), WorkShift{ ws } {}
    Worker() :Worker("None", 0, 0, 0) {}
    virtual void print() {
        Employer::print();
        cout << "WorkShift: " << WorkShift << endl;
    }
};



class figure {
protected:
    double square = 0;
public:
    figure(double square = 0) :square{ square } {}
    virtual double S() = 0;
};

class circle :public figure {
    int R;
public:
    circle(int R) : figure() {
        this->R = R;
    }
    virtual double S() {
        square = 3.14 * (R * R);
        return square;
    }
};

class rectangle :public figure {
protected:
    int a;
    int b;
public:
    rectangle(int a, int b) {
        this->a = a;
        this->b = b;
    }
    virtual double S() {
        square = a * b;
        return square;
    }
};

class triangle : public rectangle {
public:
    triangle(int a, int b) :rectangle(a, b) {}
    virtual double S() {
        square = rectangle::S() / 2.0;
        return square;
    }
};

class trapezoid : public triangle {
    int h;
public:
    trapezoid(int a, int b, int h) :triangle(a, b), h{ h } {

    }
    virtual double S() {
        square = ((a + b) / 2.0) * h;
        return square;
    }
};

class rooter {
protected:
    int a;
    int b;
    int c;
public:
    rooter(int a, int b, int c) : a{ a }, b{ b }, c{ c } {}
    virtual void diser() = 0;
};

class linear: public rooter{
public:
    linear(int a, int b, int c) : rooter(a, b, c) {};

    virtual void diser() {
        cout << a << "x" << " + " << b << " = " << c << endl;
        a = (-b + c) / a;
        cout << "x = " << a << endl;
    }
};

class square : public rooter{
    int d = 0;
    int x1 = 0;
    int x2 = 0;
public:
    square(int a, int b, int c) : rooter(a, b, c) {};//2х^2  + 5x - 7 = 0

    virtual void diser() {
        cout << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
        d = (b * b) - (4 * a) * c;
        cout << "D = k" << d << endl;
        {
            x1 = ((-b) - sqrt(d)) / (2 * a);
            cout << "X1 = " << x1 << endl;
        }

        {
            x2 - ((-b) + sqrt(d)) / (2 * a);
            cout << "X2 = " << x2 << endl;
        }
    }
};

int main()
{
    setlocale(0, "");
    srand(time(nullptr));

    Employer* emp[3]{ new President{"Elon",14,9860432,4650},
        new Manager{"Lotos",40,2000,15000},
        new Worker{"Pavel",6,400,10}
    };

    for (int i = 0; i < 3; i++) {
        emp[i]->print();
        cout << endl;
    }

    figure* figures[4] { new circle{6},
        new rectangle{4,8},
        new triangle{3,6},
        new trapezoid{3,6,8} 
    };

    int i = 0;

    cout << "Circle S=" << figures[i++]->S() << endl; 
    cout << "Rectangle S=" << figures[i++]->S() << endl;
    cout << "Triangle S=" << figures[i++]->S() << endl;
    cout << "Trapezoid S=" << figures[i++]->S() << endl; cout << endl;

    rooter* r[2]{ new linear{2,-3,5} ,new square{2,5,-7} };
    r[0]->diser(); cout << endl;
    r[1]->diser();


}
