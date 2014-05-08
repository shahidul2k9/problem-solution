
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>

#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<climits>
#include<sstream>


using namespace std;
#define DIGITS 200
long long M[DIGITS][11];
long long memo[DIGITS];
int len, test;

long long maximize(int s){
    if(s >= len) return 0;
    if(memo[s] != -1) return memo[s];
    long long ans = 0;
    for(int i = 1; i <= 10; i++){
        if(M[s][i] <= INT_MAX) ans = max( M[s][i] + maximize(s + i) , ans);
    }
    return memo[s] = ans;
}
char src[DIGITS+1];
    char dest[11];
void normalize(){
    for(int i = 0; i < len; i++){
            for(int j = 1; j <= 10 && i + j <= len; j++){
                strncpy(dest, src+i, j);

                dest[j] = NULL;
                //puts(dest);

                M[i][j] = atoll(dest);
            }
        }
}
int main(){
    //freopen("input.txt", "r", stdin);


    scanf("%d", &test);gets(src);
    while(test--){
        gets(src);
        len = strlen(src);
        //printf("*%d*\n", len);
        memset(M, -1, sizeof(M));
        memset(memo, -1, sizeof(memo));

        normalize();


        printf("%lld\n", maximize(0));

    }

}

