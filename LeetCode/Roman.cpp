/**
 * A function to convert a string into it's roman numeral equivalent
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int romanToInt(string s){
    int sum(0);
    char last(' ');
    std::for_each(s.rbegin(), s.rend(), [&](char &c){
        switch(c){
            case 'I':
                sum += (last == 'V' || last == 'X')? -1 : 1;
                break;
            case 'V':
                sum += 5;
                break;
            case 'X':
                sum += (last == 'L' || last == 'C')? -10 : 10;
                break;
            case 'L':
                sum += 50;
                break;
            case 'C':
                sum += (last == 'D' || last == 'M')? -100 : 100;
                break;
            case 'D':
                sum += 500;
                break;
            case 'M':
                sum += 1000;
                break;
            default:
                throw "Illegal character";
        } 
        last = c;
    });
    return sum;
}

int main(){
    cout << romanToInt("III")       << endl;
    cout << romanToInt("IV")        << endl;
    cout << romanToInt("IX")        << endl;
    cout << romanToInt("LVIII")     << endl;
    cout << romanToInt("MCMXCIV")   << endl;
}