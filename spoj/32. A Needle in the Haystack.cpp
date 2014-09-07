#include <cstdio>
#include <string>
#include <string.h>
using namespace std;
int M, N;
char pat[1000000+10],txt[10000000+10];
int lps[1000000+10];
void builtFA(){
    int i = 1;
    int len = 0;
    lps[0]  = len = 0;
    while( i < M){
        if( pat[i] == pat[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else if(len == 0){
            lps[i] = 0;
            i++;
        }
        else{
            len = lps[len-1];
        }
    }
}
void KMP(){
    int k,i;
    for( k = 0, i = 0; i < N; i++ ){
        while( k && txt[i] != pat[k] )
            k = lps[k-1];
        if(txt[i] == pat[k]) k++;
        if(k == M){
            printf("%d\n", i - M + 1);
            k = lps[M-1];
        }
    }
}
int main(){
    bool old = false;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    while(scanf("%d", &M) == 1){
        if(old)puts("");
        scanf("%s %s", pat, txt);
        N = strlen(txt);
        builtFA();
        KMP();
        old = true;
    }

	return 0;
}
