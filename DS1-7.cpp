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
#include <algorithm>
#include <ctime>
#include <vector>

using namespace std;

// Prints 10 most frequent words from a sorted word vector.
// @param sortedvec a sorted vector containing words.
void print10wordsfromvector(vector<string> sortedvec) 
{
    vector<string> alreadyprinted;
    unsigned int printno = 0;
    while (printno < 10)
    {
        printno++;
        string cur = "";
        string prev = "";
        string mostfr = "";
        int curcount = 0;
        int maxcount = 0;
        for (unsigned int i = 0; i < sortedvec.size(); i++)
        {
            cur = sortedvec[i];
            //did we already print this word?
            bool wasprinted = false;
            for (unsigned int j=0; j<alreadyprinted.size(); j++)
            {
                if (cur == alreadyprinted[j]) wasprinted = true;
            }
            if (wasprinted) continue;
            if (cur == prev) 
            {
                curcount++;
            }
            else 
            {
                curcount = 1;
            }
            if (curcount > maxcount) 
            {
                maxcount = curcount;
                mostfr = cur;
            }
            prev = cur;
        }
        cout << "The " << printno << " most freq word is " << mostfr << ". It appears " << maxcount << " times.\n";
        alreadyprinted.push_back(mostfr);
    }
}

int main(int argc, char** args) 
{
    std::fstream myfile;
    if (argc < 2) {
        cout << "Required parameter filename missing.\n";
        return 1;
    }
    char** second = args;
    for (int i = 0; i < argc; i++) 
    {
        cout << i << " " << *second << "\n";
        second++;
    }
    myfile.open(args[1]);
    if (!(myfile.is_open())) { cout << "File " << args[1] << " not found\n"; return 1; }
    string s;
    vector<string> strvec;
    int count = 0;
    while (myfile >> s) 
    {
        count++;
        //cout << s << "\n";
        strvec.push_back(s);
    }
    std::sort(strvec.begin(), strvec.end());
    cout << "Num words: " << count << "\n";
    print10wordsfromvector(strvec);
    myfile.close();
    return 0;
}