#include <climits>
#include <cstdio>
using namespace std;
#define N 10001

int array[N];
int main(){
    freopen("input.txt", "r", stdin);
    int n, curSum, maxSum, el;
    while(scanf("%d", &n) == 1 && n){
        curSum = maxSum = 0;
        for(int i = 1; i<=n; i++){
            scanf("%d", &el);
            curSum += el;
            if(curSum > maxSum) maxSum = curSum;
            if(curSum < 0) curSum = 0;
        }
        if(maxSum == 0)puts("Losing streak.");
        else printf("The maximum winning streak is %d.\n", maxSum);
    }
    return 0;
    }
/*
#include <climits>
#include <cstdio>
using namespace std;
#define N 10001

int array[N];
//this only works if at least one element is positive
int kadane(int n){
    int MS, maxSI, maxEI ,curMS, curSI;
    MS = INT_MIN;
    curMS = 0;
    curSI = 1;
    for(int curEI = 1; curEI <= n; curEI++){
        curMS += array[curEI];
        if(curMS >MS){
            MS = curMS;
            maxSI = curSI;
            maxEI = curEI;
        }
        else if(curMS < 0){
            curSI = curEI + 1;
            curMS = 0;
        }
    }
    return MS;
}
int main(){
    //this solution get WA why?
    freopen("input.txt", "r", stdin);
    int n;
    bool possible;
    while(scanf("%d", &n) == 1 && n){
        possible = false;
        for(int i = 1; i<= n; i++){
            scanf("%d", &array[i]);
            if(array[i]>0) possible = true;
            }
        if(!possible)puts("Losing streak.");
        else
            printf("The maximum winning streak is %d.\n",kadane(n));
    }
    return 0;
}
*/
