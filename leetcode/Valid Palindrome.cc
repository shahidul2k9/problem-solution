
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        char seq[s.length()];
        int ind = 0;
        for(int i = 0; i < s.length();i++){
            if(isalpha(s[i]))
                seq[ind++]=tolower(s[i]);
            if(isdigit(s[i]))
                seq[ind++] = s[i];
        }

        int lo = 0;
        int hi = ind-1;
        while(lo < hi){
            if(seq[lo] != seq[hi]) return false;
            lo++;hi--;
        }
        return true;
    }
};
