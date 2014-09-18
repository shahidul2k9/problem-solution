#include<vector>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int power(int a, int b){
        int ans = 1;
        for(int i = 1; i <= b; i++)
            ans *=a;
        return ans;
    }
    int reverse(int x) {
        bool negative = false;
        if(x < 0){
            x *=-1;
            negative = true;
        }
        int digits = 0;
        int p = x;
        while(p){
            digits++;
            p /=10;
        }
        int r = 0;
        p  = x;
        while(p) {
            r += power(10,--digits)*(p%10);
            p /= 10;
        }
        if(negative)
            r = -r;
        return r;
    }
};

int main(){
    printf("%d", Solution().reverse(-123));
    return 0;
}
