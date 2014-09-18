#include<vector>
#include<iostream>
#include<climits>
using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int C[m];
        for(int i = 0; i < m; i++)
            C[i]= A[i];
        int pos = 0, i = 0, j=0;

        while(i < m || j < n){
            if(i==m) A[pos++] = B[j++];
            else if(j == n) A[pos++] = C[i++];
            else if(C[i] < B[j])
                A[pos++] = C[i++];
            else A[pos++] = B[j++];
        }
    }
};
