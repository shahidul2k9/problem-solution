#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
#define MAXPEG 60
double sqr;
int n;
int subSum,sum,maxBall;
int pegs[MAXPEG][MAXPEG];
int pegsSZ[MAXPEG];
bool promising(int value, int pegId, int psz){
    if(psz==0)return true;
    else if(true){
        sqr = sqrt(pegs[pegId][psz]+value);
        if(floor(sqr)== ceil(sqr))return true;
    }
    return false;
}
void BackTrack(int index, int size[]){
    for(int i=1;i<=n;i++){
        if(promising(index,i, size[i])){
            size[i]++;
            pegs[i][size[i]] = index;
            BackTrack(index+1,size);
        }
        else {

                maxBall = max(maxBall,index-1);

        }
    }
}
int main()
{
    int test;
    scanf("%d", &test);
    while(test--){
        scanf("%d", &n);
        for(int i=1;i<=n;i++)pegsSZ[i]=0;
        maxBall = 0;
        pegsSZ[1] = 1;
        pegs[1][1] = 1;
        BackTrack(2,pegsSZ);
        printf("%d\n",maxBall);
    }
    return 0;
}

