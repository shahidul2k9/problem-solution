#include <string.h>
#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>
using namespace std;

bool callback(int a, int b){
    return a > b;
}
int main(){
    //freopen("input.txt", "r", stdin);
    int C, S, cs;
    double avg, imbalance;
    cs = 0;
    int mass[10];
    while(scanf("%d %d", &C, &S) == 2){

        for(int i = 0; i < S; i++)
            scanf("%d", &mass[i]);
        avg = (double)accumulate(mass,mass+S,0)/C;

        for(int i = S; i< 2*C; i++)
            mass[i] = 0;
        sort(mass, mass+2*C,callback);

        imbalance = 0;

        printf("Set #%d\n", ++cs);

        for(int i = 0; i< C; i++){
            printf(" %d:",i);

            if(mass[2*C-i-1]){
                printf(" %d", mass[2*C-i-1]);

            }
            if(mass[i])
                printf(" %d", mass[i]);

            imbalance += fabs(mass[i] + mass[2*C-i-1] - avg);
            printf("\n");
        }
        printf("IMBALANCE = %.5lf\n\n", imbalance);
    }
    return 0;
}
