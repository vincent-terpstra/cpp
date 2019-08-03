/**
 * Vincent Terpstra
 * 31 July 2019
 * 
 * A program that helps visualize the Collatz conjecture  
 */

#include <iostream>
#include <functional>
#include <math.h>

using namespace std;

void loop(long);
void loop(long, std::function<void(long)> func);

long collatz(long input);

void printBool(long input){
    if(input > 0){
        printBool(input / 2);
        cout << input % 2;
    }
}

std::function<void (long)> printBool(const int size){
    const int length = pow(2, size);
    return [=](const long in){ 
        long input(in);
        if(input >= 0 ){
            int tmp = length;
            while(tmp > 0){
                cout << (input / tmp ? 'X' : ' ');
                input %= tmp;
                tmp /= 2;
            }
            cout << " : " << in << endl;
        }
        
    };
}


int main(){
    auto print = printBool(10);
    loop( 101, print);
    return 0;
}


void loop(long input){
    loop(input, [=](long input){cout << input << endl; });
}

void loop (long input, std::function<void (long)> func ){
    try {
        cout << "INPUT: " << input << endl;
        while(true){
            func(input);
            input = collatz(input);
        }
    } catch (char const* ex){
        cout << ex << endl;
    } catch (int ex){
        cout << "END found" << endl;
    }
}

long collatz(long input){
    if(input == 1) 
        throw 1;
    if(input < 0) 
        throw "Invalid input";
    return input % 2 ? 3 * input + 1 : input / 2; 
}





