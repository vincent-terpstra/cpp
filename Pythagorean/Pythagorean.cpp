/**
 * Vincent Terpstra
 * 26 September 2019
 * 
 * A program that finds all pythagorean triples with hypotenus less then input or MAX_VALUE
 *   a pythagorian triple has values a^2 + b^2 = c^2 where a, b, c are integers
 * 
 * g++ *.cpp ../Bitmap.cpp -std=c++17 && ./a.out
 */

#include <iostream>
#include <functional>
#include <math.h>

#include "../Bitmap.h"

using namespace std;

#define MAX_VALUE 1000

int main(int size, char* args[]){
    int  max = MAX_VALUE;
    try {
        if(size > 1)
            max = atoi(args[1]);
    } catch(...){}

    int found(0);
    Bitmap black("black.bmp", max, max);
        black.fill(0);
    for(int hyp = 1; hyp <= max * 2; hyp++){
        for(int a = 1; a < hyp; ++a){
            for(int b = 1; b < a; ++b){
                if(a * a + b * b == hyp * hyp ){
                    cout << "[ "<< b << ", " << a << ", " << hyp <<"]" << endl;
                    if(a < max){
                        float re = 255 * (float)a / hyp;
                        float gr = 255 * (float)b / hyp;
                        float bl = 255 * (float)hyp / max;
                    
                        black.add(a, b, re, gr, bl);
                        black.add(b, a, gr, re, bl);
                    }
                    ++found;
                }
            }
        }
    }
    cout << found << " triples found!" << endl;
    

}