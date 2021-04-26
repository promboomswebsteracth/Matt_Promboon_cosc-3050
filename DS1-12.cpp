//COSC 3050 Spring 2021
//Author: Matt Promboon
//Homework () - Problem ()

#include <cctype>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <vector>
#include "DSLL.h"
using namespace std;

class piece_of_art 
{
    int id;
    int price;
    string name;
public:
    piece_of_art(int id=0, int price=0, string name="") 
	{ 
        this->id = id; this->price = price;  this->name = name;
    }
    int get_id() const { return id; }
    int get_price() const { return price; }
    string get_name() const { return name; }
    //virtual void say() { cout << "Art\n";  }
};

class painting : public piece_of_art 
{
    int w; //width
    int h; //height
public:
    painting(int id, int price, string name, int w, int h) : piece_of_art(id, price, name)
	{
        this->w = w; this->h = h;
    }
    int get_h() const { return h; }
    int get_w() const { return w; }
    //void say() { cout << "Painting\n"; }
};

class sculpture : public piece_of_art 
{
    int weight;
public:
    sculpture(int id, int price, string name, int w) : piece_of_art(id, price, name)
	{
        this->weight = w;
    }
    int get_weight() const { return weight; }
    //void say() { cout << "Sculpture\n"; }
};

class furniture : public piece_of_art 
{
    char condition;
public:
    furniture(int id, int price, string name, char c) : piece_of_art(id, price, name) 
	{
        this->condition = c;
    }
    char get_condition() const { return condition; }
    //void say() { cout << "Furniture\n"; }
};

int main() {
    painting myp(1, 6000000, "Sunflowers", 30, 60);
    sculpture myc(1, 2000000, "Thinker", 1500);
    furniture myf(1, 30, "Ikea Chair", 'a');
    DSLinkedList<piece_of_art*> artlist;
    artlist.append(&myp);
    artlist.append(&myc);
    artlist.append(&myf);
    piece_of_art* artptr = *artlist.front();
    int totalprice = 0;
    cout << artlist.numelements() << "\n";
    while (true) 
	{
        cout  << artptr->get_price() << "\n";
        totalprice = totalprice + artptr->get_price();
        if (artlist.tail())
		{
            break;
        }
        artptr = *artlist.next();
    }
    cout << "Total: " << totalprice << "\n";
    return 0;
}
