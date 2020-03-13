#include <iostream>

using namespace std;

bool winningMove(bool* moves, int max, int total){
        for(int idx = max; idx >0; idx--){
            if(!moves[idx - 1] && total <= idx)
                return true;
        }
        
        for(int idx = max; idx > 0; idx--){
            if(!moves[idx-1]){
                moves[idx-1] = true;
                //check that opponent can't win
                if(!winningMove(moves, max, total - idx)){
                    moves[idx-1] = false;
                    return true;
                }
                //forget last move
                moves[idx-1] = false;
            }
        }
        return false;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        bool moves[20]{false};
        
        return winningMove(moves, maxChoosableInteger, desiredTotal);
    }

    bool method2(int maxChoosableInt, int total){
        if(total <= maxChoosableInt)
            return true;

        if(maxChoosableInt + 1 == total)
            return false;
        
        int maxVal = (maxChoosableInt + 1) * maxChoosableInt / 2;
        if(total > maxVal)
            return false;
        /**/
        if(!(maxChoosableInt % 2) && maxChoosableInt > 2 && maxChoosableInt > maxVal - total + 2){
            return false;
        }
        /**/
        
        return true;
    }

    int main(){
        for(int i = 1; i <= 10; i++){
            int maxVal = i * (i+1)/2;
            printf("%2d:", i);
            for(int j = 1; j <= maxVal; j++){
                bool canWin = canIWin(i, j);
                bool check  = method2(i, j);

                if(canWin != check){
                    cout << j << ' ';
                } else {
                    cout << "   ";
                }
                
            }
            cout << endl;
        }
    }