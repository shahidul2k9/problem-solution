#include<vector>
#include<cstdio>
#include<iostream>
using namespace std;


 class Solution {
public:
    int singleNumber(int A[], int n) {

        int a[32];
        for(int i = 0; i < 32; i++)
            a[i] = 0;
        for(int i = 0; i < n; i++)
            for(int k = 0; k <=31; k++)
                if(A[i] & (1 <<k))
                    a[k]++;

        for(int k = 0; k < 32; k++)
            a[k] %=3;

        int ans = 0;
        for(int i = 0; i < 32;i++)
            if(a[i])
                ans |= (1 << i);
        return ans;
    }
};

int main(){
    int a[] = {1,1,1,3,3,3, 10};
    printf("%d", Solution().singleNumber(a, 7));
    return 0;
}
