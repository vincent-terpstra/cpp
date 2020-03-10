/*
 * Finds the longest initial string from the list of strings
 */

#include <iostream>
#include <vector>

#include <algorithm>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    const string check = strs.at(0);
    int length = check.length();

    for_each(++strs.begin(), strs.end(), 
        [&](const string & s){
            int comp = 0;
            length = min((int)s.length(), length);
            while(comp < length && check.at(comp) == s.at(comp)){
                ++comp;
            }
            length = comp;
    });
    return check.substr(0, length);
}

int main(){
    vector<string> fl = {"flower", "flow", "flight"};
    vector<string> dog = {"dog", "racecar", "car"};

    cout << longestCommonPrefix(fl) << endl;
    cout << longestCommonPrefix(dog) << endl;


    return 1;
}