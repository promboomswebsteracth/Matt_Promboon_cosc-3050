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

using namespace std;
template<class T>
struct ListNode  
{  
	T value;
	ListNode *next;   
	ListNode(T value1, ListNode *next1 = NULL)
	{ 
		value = value1;
		next = next1;
	}
};
//template<class T>
int main()
{  
	ListNode <int> *itemList = NULL;   // List of items   
	int itemFile;
	cout<<"Enter a list of objects, separated with spaces, enter to submit: ";
	cin>> itemFile;
	int items;
	cout << "The contents are: " << endl;   
	while (itemFile >> items)   
	{  
		cout << items << "  ";
		itemList = new ListNode<int> (items, itemList);
	}   
	cout << endl << "The contents of the list are: " << endl;   
	ListNode <int> *ptr = itemList;   
	while (ptr != NULL)   
	{  
		cout << ptr->value << "  "; // Process node    
		ListNode <int> *deleteMe = ptr; 
		ptr = ptr->next;            // Move to next node
		delete deleteMe;   
	}   
}

// int main()
// {
// 	listTemp();
// 	return 0;
// }