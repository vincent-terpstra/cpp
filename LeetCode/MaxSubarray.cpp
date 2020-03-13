#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums) {
    int maxVal = nums[0];
    int runSum = maxVal;
    
    for_each(++begin(nums), end(nums),
        [&](int& val){
            if(runSum > 0){
                runSum += val;
            } else {
                runSum = val;
            }

            if(runSum > maxVal)
                maxVal = runSum;
        }
    );
    
    return maxVal;
}

int main(){
    vector<int> test1= {-2, 1, -2, -1, 4, -1, 2, 1, -5, 4};

    cout << maxSubArray(test1) << endl;

    return 1;
}