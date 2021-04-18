// Single linked list with append, prepend, find, remove, numelements
//Bonus: assertions (_ASSERT), DS-1 Spring 2021
//The file now contains a stack class, too
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

    T* front() {
        if (head == NULL) return NULL;
        curr = head->next;
        return &(head->value);
    }

    T* next() {
        if (curr == NULL) return NULL;
        ListNode* tmp = curr;
        curr = curr->next;
        return &(tmp->value);
    }

    bool del_first() {
        if (head == NULL) return false;
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
        num_elements--;
        return true;
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
                ListNode* delme = tp;
                if (tpprev == NULL) {  // To check if current node is head node
                    head = tp->next;
                    tp = head;
                }
                else {
                    tpprev->next = tp->next;
                    tp = tpprev->next;
                }
                delete delme;
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


template <class T>
class DSStack {
    //implements a stack using DSLinkedList
    DSLinkedList<T> impl;
public:
    void push(T myobj) {
        impl.prepend(myobj);
    }
    bool is_empty() { impl.numelements() == 0; }
    T pop() {
        T* myobjptr = impl.front();
        if (myobjptr == NULL) throw("Stack empty");
        T myobj = *(myobjptr);
        impl.del_first();
        return myobj;
    }
};

template <class T>
class DSQueue {
    //implements a stack using DSLinkedList
    DSLinkedList<T> impl;
public:
    void enqueue(T myobj) {
        impl.append(myobj);
    }
    bool is_empty() { impl.numelements() == 0; }
    T dequeue() {
        T* myobjptr = impl.front();
        if (myobjptr == NULL) throw("Queue is empty");
        T myobj = *(myobjptr);
        impl.del_first();
        return myobj;
    }
};