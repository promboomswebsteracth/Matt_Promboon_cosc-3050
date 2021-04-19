//COSC 3050 Spring 2021
//Author: Matt Promboon
//Homework () - Problem ()
//Single linked list with append, prepend, find, remove, numelements
//Bonus: assertions (_ASSERT), DS-1 Spring 2021
#include "DSLL.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;
template <class T>
string myStack(string s) 
{
	DSStack<char> testLst;
	for (char c : s) 
    {
		if (c == '(') 
        {
			testLst.push(c);
		}
		else if (c == ')') 
        {
			try 
            {
				testLst.pop();
			}
			catch (const char* msg)
            {
				return "Not a valid mathematic expression.\n";
			}
		}
	}
	try
    {
		testLst.pop();
	}
	catch (const char* msg) 
    {
		return "Not a valid mathematic expression.\n";
	}

	return "Valid mathematic expression.\n";

}

void checkCoins(string input)
{
    input = "The value of Bitcoin was 8389.51, now it is 57625.40.";
	string targetStr1 = "was", targetStr2 = "is";

	string begin = input.substr(input.find(targetStr1) + targetStr1.length());
	begin = begin.substr(0, begin.find(','));

	double beginVal = stod(begin);

	string end = input.substr(input.find(targetStr2) + targetStr2.length());
	end = end.substr(0, end.find('.'));

	double endVal = stod(end), btcNum = 100/beginVal;
	double finalVal = btcNum * endVal;

	cout << "If you invested $100, the value would be " << finalVal << " now.\n";
}

class myPhoneBook 
{
	struct book 
    {
		int phoneNum;
		string name;
		book(int number = 0, string name = ""): 
			phoneNum(number),
			name(name)
		{}
		~book() {}

	};
	vector<vector<book>> phoneBook;
public:
	myPhoneBook() {
		for (int i = 0; i < 26; i++) {
			vector<book> temp;
			phoneBook.push_back(temp);
			temp.~vector();
		}
	}
	void addNum(string name, int phone) {
		int index = name[0] - 'a';
		book temp(phone, name);
		phoneBook[index].push_back(temp);
		temp.~book();
	}
	int retrieveNum(string name) {
		for (book myBook : phoneBook[name[0] - 'a']) {
			if (myBook.name == name) {
				return myBook.phoneNum;
			}
		}
		return 0;
	}

};

void main() {
	string test = "()()()()()()";
    string test2 = "( )( ))( )(( )( )(";
    string test3 ="((()((";
	//cout << myStack(test) <<endl << myStack(test2) << endl << myStack(test3) <<endl;

	myPhoneBook myBook;
}

