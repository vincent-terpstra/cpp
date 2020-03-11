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
        char last = pat[pIdx];
        if(pIdx + 3 < pat.length() && last == pat[pIdx + 2] && pat[pIdx + 3] == '*'){
            return isMatch(str, pat, sIdx, pIdx + 2);
        } else {
            if(isMatch(str, pat, sIdx, pIdx + 2))
                    return true;

            while( sIdx < str.length() && (last == '.' || str[sIdx] == last)){
                if( isMatch(str, pat, sIdx + 1, pIdx + 2))
                    return true;
                sIdx++;
            }
        }
        
    } else if(sIdx < str.length() && (str[sIdx] == pat[pIdx] || pat[pIdx] == '.')){
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
    isMatch("aab", "c*a*b");
    /**/
    isMatch("ab", ".*c");
    isMatch("abc", ".bc");
    isMatch("dog", "dog");
    isMatch("aaaa", "a*");
    isMatch("abcde", "a.*e");
    isMatch("abc", "g*abc");
    isMatch("vincent", ".*");
    isMatch("aaaaaaaaaaaab", "a*a*a*a*a*a*a*c");
    isMatch("baaaaaaaaaaaa", "ca*a*a*a*a*a*a*");
    isMatch("aaaaaaaaaaaa", "a*a*a*a*a*a*a*");
    /**/


    return 1;
}