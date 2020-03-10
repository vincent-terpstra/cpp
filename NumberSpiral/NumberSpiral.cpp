/**
 * Vincent Terpstra
 * 3 November 2019
 * 
 * A program that draws all numbers in polar coordinates
 * 
 * g++ *.cpp ../Bitmap.cpp -std=c++17 && ./a.out
 */

#include <iostream>
#include <functional>
#include <math.h>

#include "../Bitmap.h"

#define PI 3.1415f
#define DIM 500
#define SHIFT DIM/2

#define MAX 10000
#define SCALE SHIFT/MAX
using namespace std;

void addPolar(float, float, Bitmap&);
bool isPrime(int);

int main(){
    Bitmap black("spiral.bmp", DIM, DIM);
        black.fill(0);

    for(int i = 0; i < MAX; ++i)
            addPolar(i, i, black);
}

bool isPrime(int value){
    float max = sqrt(value);
    for(int i = 2; i < max; ++i){
        if(value % i == 0)
            return false;
    }
    return true;
}

void addPolar(float rad, float beta, Bitmap& input){
    float c = cos(beta) * rad;
    float s = sin(beta) * rad;
    //coloring
    float intensity = 255 * rad / MAX / 2 + 80;
    int region = beta / PI / 2;
    float reduced = beta - region * PI * 2;
    float r = reduced;
    float g = reduced - 2;
    float b = reduced - 4;
    
    input.add(c * SCALE + SHIFT, s * SCALE + SHIFT, r * intensity, g * intensity, b * intensity);
}