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

int main(int argc, char** args) {
    std::fstream myFile;
    if (argc < 2) 
	{
        cout << "Required parameter filename missing.\n";
        return 1;
    }
    myFile.open(args[1]);
    if (!(myFile.is_open())) { cout << "File " << args[1] << " not found\n"; return 1; }
    string s;
    vector<string> strVec;
    int count = 0;
    while (myFile >> s) 
	{
        count++;
        //cout << s << "\n";
        strVec.push_back(s);
    }
    std::sort(strVec.begin(), strVec.end());
    cout << "Num words: " << count << "\n";
    myFile.close();
    string current = "";
    string previous = "";
    string mostFr[10][2];
	int arrRowCount;
    int curCount = 0;
    int maxCount = 0;
    for (int i = 0; i < strVec.size(); i++) 
	{
        current = strVec[i];
        if (current == previous) 
		{
            curCount++;
        }
        else 
		{
            curCount = 1;
        }
        if (curCount > maxCount) 
		{
            maxCount = curCount;
            mostFr[arrRowCount][0] = current;
			mostFr[arrRowCount][1] = to_string(maxCount);
			arrRowCount++;
			if(arrRowCount==9) arrRowCount = 0;
        }
        previous = current;
    }
    for(int j=0;j<10;j++)
    {
        cout<<"Most Frequent word "<<j<<": "<<mostFr[j][0]<<"it appears: "<<mostFr[j][1]<<" times"<<endl;
    }
    //cout << "The most freq word is " << mostfr << ". It appears " << maxcount << " times.\n";
    return 0;
}