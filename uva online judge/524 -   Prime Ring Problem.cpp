#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;
#define MAX 35
bool prime[MAX];
int ntouple[17];
int n,total;
bool isPrime(int x){
    if(x%2==0)return false;
    for(int i=3;i<=sqrt(x);i +=2) if(x%i==0)return false;
    return true;
}

bool isPromising(int level, int u){
    for(int i=2;i<level;i++)if(ntouple[i]==u)return false;
    if(level==n)
        return prime[u+1]&&prime[ntouple[level-1]+u];
    else return prime[ntouple[level-1]+u];
}
void BackTrack(int level){
    for(int i=2;i<=n;i++){
        if(isPromising(level, i)){
            ntouple[level] = i;
            if(level==n){
                total++;
                for(int j = 1;j<n;j++)printf("%d ", ntouple[j]);
                printf("%d\n",ntouple[n]);
            }
        else BackTrack(level+1);
        }
    }
}
int main()
{
   freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    bool isBalank = false;
    int cs=0;
    prime[2] = prime[3] = true;
    for(int i=4;i<MAX;i++) prime[i] = isPrime(i);
    while(scanf("%d", &n)==1){
        if(isBalank)printf("\n");
        isBalank = true;
        total = 0;
        printf("Case %d:\n", ++cs);
        if(n==1)printf("1\n");
        ntouple[1] = 1;
        BackTrack(2);

    }
    return 0;
}
