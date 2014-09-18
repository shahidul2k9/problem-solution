#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int power(int a, int n){
        int pw = 1;
        for(int i = 1; i <=n;i++)
            pw *= a;
        return pw;
    }
    int atoi(const char *str) {
        int e = 0;
        if(!isdigit(str[0]))
            e++;
        int p = 0;
        int ans = 0;
        for(int i = strlen(str)-1; i>=e;i--){
            ans += (str[i]-'0')*power(10,p);
            p++;
        }

        if(str[0]=='-')
            ans = -ans;
        return ans;
    }
};
