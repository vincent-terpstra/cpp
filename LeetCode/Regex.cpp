/**
 * Matches strings to the pattern 
 *     . single character instance
 *     * multiple character repeated
 */

#include <iostream>

using namespace std;

bool isMatch(string str, string pat, int sIdx, int pIdx){
    if(pat.length() == pIdx)
        return str.length() == sIdx;
    
    if(pIdx + 1 < pat.length() && pat[pIdx + 1] == '*'){
        //WILD FOUND
        //can match ZERO characters
        if(isMatch(str, pat, sIdx, pIdx + 2))
            return true;

        char last = pat[pIdx];
        //can match Multiple characters
        if(last == '.' || last == str[sIdx])
            return isMatch(str, pat, sIdx + 1, pIdx);
        
    } else if(str[sIdx] == pat[pIdx] || pat[pIdx] == '.'){
        return isMatch(str, pat, sIdx + 1, pIdx + 1);
    }

    return false;
}

bool isMatch(string s, string p){
    bool check = isMatch(s, p, 0, 0);
    cout << s << " " << p << " " << check << endl;

    return check;
}

int main(){
    isMatch("abc", ".bc");
    isMatch("dog", "dog");
    isMatch("aaaa", "a*");
    isMatch("abcde", "a.*e");
    isMatch("abc", "g*abc");
    isMatch("vincent", ".*");


    return 1;
}