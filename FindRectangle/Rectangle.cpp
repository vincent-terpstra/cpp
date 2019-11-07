/**
 * Vincent Terpstra
 * 3 November 2019
 * 
 * A program that finds all rectangles from a list of 2D points
 * 
 * g++ *.cpp -std=c++17 && ./a.out
 */

#include <iostream>

using namespace std;
#define SIZE 10
class Point {
    int x;
    int y;
    public:
    Point(int _x, int _y) : x(_x), y(_y) {}

    Point const operator-(const Point p) const {
        return Point(x - p.x, y - p.y);
    }

    Point const operator+(const Point p) const {
        return Point(x + p.x, y + p.y);
    }

    bool const operator==(const Point p) const {
        return (x == p.x) && (y == p.y);
    }

    operator int() const {
        return x * x + y * y;
    }

    friend ostream& operator <<(ostream& os, const Point p);
};

ostream& operator << (ostream& os, const Point p){
    os << "(" << p.x << " : " << p.y << ")";
    return os;
}

void findRect(const Point* points, const int size){
    if(size < 4) return; //no possible rectangle found

    for(int i = 0; i < size - 3; ++i){
        Point p1 = points[i];

        for(int i2 = i + 1  ; i2 < size - 2; ++i2){
            Point p2 = points[i2];
            int d_12 = p1 - p2;

            for(int i3 = i2 + 1; i3 < size - 1; ++i3){
                Point p3 = points[i3];
                int d_13(p1 - p3),
                    d_23(p2 - p3);

                Point next(0,0);
                if(d_12 == d_13 + d_23){
                    next = p1 + p2 - p3;
                } else if(d_13 == d_12 + d_23){
                    next = p1 + p3 - p2;
                } else if(d_23 == d_12 + d_13){
                    next = p2 + p3 - p1;
                } else {
                    continue;
                }
                for(int i4 = i3+1; i4 < size; ++i4){
                    if(next == points[i4]){
                        cout << p1 << " " << p2 << " " << p3 << " " << points[i4] << endl;
                    }
                }
            }
        }
    }
}

int main(){
    Point points[SIZE] = { 
        Point(0, 0), Point(1,0), Point(2,0),
        Point(0, 1),             Point(2,1),Point(2,3),
                     Point(1,2),            Point(3,2),
                     Point(1,3), Point(5,5)
        };
    findRect(points, SIZE);
    return 0;
}