//COSC 3050 Spring 2021
//Author: Matt Promboon
//Homework () - Problem ()
//Single linked list with append, prepend, find, remove, numelements
//Bonus: assertions (_ASSERT), DS-1 Spring 2021
#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

template <class T>
class DSLinkedList {

    // internal presentation of list node
    struct ListNode {
        T value;
        ListNode* next;
        ListNode(T value1, ListNode* next1 = NULL) {
            value = value1;   next = next1;
        }
    };

    ListNode* head;
    ListNode* tail;
    ListNode* curr;

    unsigned int num_elements;

public:
    DSLinkedList() {
        head = NULL;
        tail = NULL;
        curr = NULL;
        num_elements = 0;
    }

    T* front()
    {
        if(head == NULL) return NULL;
        curr = head->next;
        return &(head->value);
    }

    T* next()
    {
        if(curr == NULL) return NULL;
        ListNode* tmp=curr;
        curr= curr->next;
        return &(tmp->value);
    }

    bool delFirst()
    {
        if(head == NULL) return false;
        ListNode* tmp=head;
        head = head->next;
        delete tmp;
        num_elements--;

    }

    void append(T val) {
        ListNode* newNode = new ListNode(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        num_elements++;
    }

    void prepend(T element) {
        ListNode* newNode = new ListNode(element);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
        num_elements++;
    }

    void print() {
        ListNode* tp = head;
        while (tp != NULL) {
            cout << tp->value << "\n";
            tp = tp->next;
        }
    }

    unsigned int numelements() {
        return num_elements;
    }

    bool find(T needle) {
        ListNode* tp = head;
        while (tp != NULL) {
            if (tp->value == needle) return true;
            tp = tp->next;
        }
        return false;
    }

    bool remove(T element) {
        //Removes all instances of element
        bool found = false;
        ListNode* tpprev = NULL;
        ListNode* tp = head;

        while (tp != NULL) {
            if (tp->value == element) {
                found = true;
                if (tpprev == NULL) {  // To check if current node is head node
                    head = tp->next;
                    tp = head;
                }
                else {
                    tpprev->next = tp->next;
                    tp = tpprev->next;
                }
                // If found, make previous node's 'next' point to following node
                num_elements--;
            }
            else {
                if (tpprev == NULL) {
                    tpprev = tp;
                    tp = tp->next;
                }
                else {
                    tp = tp->next;
                    tpprev = tpprev->next;
                }
                // If not found, move to the next
            }
        }
        return found;
    }

    ~DSLinkedList() {
        //cout << "Destructor called\n";
        ListNode* tmp = head;
        ListNode* prev;
        while (tmp) {
            prev = tmp;
            tmp = tmp->next;
            delete prev;
        }
    }
};

int main() {
    DSLinkedList<int> myll;
    myll.append(0);
    myll.append(1);
    myll.append(3);
    myll.append(7);
    myll.append(5);
    myll.prepend(2);
    myll.append(1);
    myll.append(2);
    myll.append(3);
    myll.append(4);
    myll.append(5);
    myll.append(6);


    myll.print();
    cout << "\nNum elements: " << myll.numelements() << endl;
    for (int i=0;i<6;i++)
    {
        cout<<"deleting: "<<myll.front()<<endl;
        myll.delFirst();
    }
    myll.remove(0);
    myll.remove(7);
    //_assert(myll.numelements() == 2);

    if (myll.find(1)) cout << "Found 1\n";
    //_assert(myll.find(1));
    if (!myll.find(100)) cout << "100 not found\n";
    //_assert(!myll.find(100));
    int* f = myll.front();
    cout << "First " << *f << "\n";
    while (f != NULL) {
        f = myll.next();
        if (f != NULL) cout << "Next " << *f << "\n";
    }
    return 0;
}
