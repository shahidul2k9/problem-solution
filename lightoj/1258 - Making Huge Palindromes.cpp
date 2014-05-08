#include <algorithm>
#include <bitset>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <string.h>
#include <ctime>
#include <vector>
using namespace std;
int M;
char pat[1000000+10],txt[1000000+10];
int b[1000000+10];
void builtFA(){
    int i = 1;
    int len = 0;
    b[0]  = len = 0;
    while( i < M){
        if( pat[i] == pat[len]){
            len++;
            b[i] = len;
            i++;
        }
        else if(len == 0){
            b[i] = 0;
            i++;
        }
        else{
            len = b[len-1];
        }
    }
}
int KMP(){
    int k,i;
    for( k = 0, i = 0; i < M; i++ ){
        while( k && txt[i] != pat[k] )
            k = b[k-1];
        if(txt[i] == pat[k]) k++;
    }
    return M - k;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    int test,  cs=1;
    scanf("%d", &test);
    while(test--){
        scanf("%s", txt);
        M = strlen(txt);
        strcpy(pat,txt);
        reverse(pat,pat+M);
        builtFA();
        printf("Case %d: %d\n",cs++, M + KMP());
    }

	return 0;
}
