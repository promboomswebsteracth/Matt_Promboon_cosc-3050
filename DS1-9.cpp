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
class lnkdLst
{
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
	ListNode* head;
	ListNode* tail;
	public:
	lnkdLst(){head = NULL;}

	void append(T val)
	{
		ListNode* newNode =  new ListNode(val);
		if (head == NULL) {head = newNode; tail = newNode;}
		else
		{
			ListNode* tp = head;
			while(tp-> next !=NULL) tp=tp->next;
			tp->next = newNode;
			tail->next = newNode;
			tail = newNode;
		}
	}
    void print() {
        ListNode* tp = head;
        while (tp != NULL) {
            cout << tp->value << "\n";
            tp = tp->next;
        }
    }

    bool find(T needle) {
        ListNode* tp = head;
        while (tp != NULL) {
            if (tp->value == needle) return true;
            tp = tp->next;
        }
        return false;
    }

	void prepend(T element) // add an element in the beginning
	{
		ListNode* sp = new ListNode;
		sp -> Value = element;
		sp -> next = head;
		head = sp;
	}

	unsigned int numelements() //returns the number of elements in the list
	{
		int cnt = 0;  
    	ListNode* curr = head;  
   		while (curr != NULL)  
		{  
			cnt++;  
			curr = curr->next;  
		}  
		return cnt;  
	}

	bool remove(T element) //remove an element from the list if it exists. Return true. If it does not exists, return false.
{  
	ListNode* temp = head;
	ListNode* prev = NULL;
    ListNode* cur = head;
    while (cur != NULL)  
    {  
        if (cur-> value == element) 
		{
   			prev->next = temp->next;
    		delete temp;
		} 
        cur = cur->next;  
    }  
	cout<<element<<"does not exist"<<endl;
    return false;  
}  

	~lnkdLst()
	{
		cout<<"destrctor called"<<endl;
		ListNode* tmp = head;
		ListNode* prev;
		while (tmp)
		{
			prev = tmp;
			tmp = tmp -> next;
			delete prev;
		}

	}
};

int main() {
    lnkdLst <int> myll;
    myll.append(1);
    myll.append(2);
    myll.print();
    if (myll.find(1)) cout << "Found 1\n";
    if (!myll.find(100)) cout << "Not found 100\n";
    return 0;
}