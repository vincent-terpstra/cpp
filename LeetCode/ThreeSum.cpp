/*
 * Finds sets of three values that add to 0
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

ostream& operator <<(ostream& os, vector<int>& values){
    for_each(values.begin(), values.end(), [&](int & val){
        os << val << ' ';
    });
    return os;

}

vector<vector<int>> threeSum(vector<int>& nums){
    int size = nums.size();
    vector<vector<int>> sets;
    
    if(size < 3)
        return sets;
    
    
    sort(nums.begin(), nums.end());
    
    
    int atA, atB, atC;
    for(int a = 0; a < size -2; a++){
        atA = nums.at(a);
        if(atA > 0)
            return sets;

        for(int c = size - 1; c >= a + 2; c--){
            atC = nums.at(c);
            if(atC < 0)
                return sets;

            for(int b = a + 1; b < c; b++ ){
                atB = nums.at(b);
                if(atA + atC == - atB){
                    vector<int> add = { atA, atB, atC, };
                    sets.push_back(add);
                    
                    if(atA == 0)
                        return sets;

                    break;
                }
            }
            
            //ignore duplicates
            while(atC == nums.at(c-1))
                c--;
        }
        
        //ignore duplicates
        while(atA == nums.at(a+1))
            a++;
    }

    return sets;
}



int main(){
    vector<int> set = {4,3,1}; ////{0,0,0,0}; //{-1, 0, 1, 2, -1, -4};
    
    vector<int> set2 = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    vector<int> set3 = {-1, 0, 1, 2, -1, -4};
    vector<int> set4 = {0,0,0};
    vector<vector<int>> values = threeSum(set2);

    for_each(values.begin(), values.end(), [&](vector<int>& vals){
        cout << vals << endl;
    });
    
}