#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef int Type;
#define MAX_ELEMENTS 100000
#define step(x) ((x)& (-x))

//Range Update Point Query BIT
struct Bit{
    int MaxVal;
    Type ft[MAX_ELEMENTS+1];
    Bit(int N):MaxVal(N){memset(ft, 0, sizeof(Type)*(N+1));}
    void update(int idx, Type val){
        while(idx <= MaxVal){
            ft[idx] += val;
            idx += step(idx);
        }
    }
    //Returns value at index[idx]
    Type query(int idx){
        Type sum = 0;
        while(idx > 0){
            sum += ft[idx];
            idx -= step(idx);
        }
        return sum;
    }
    //Add value val in range [a...b]
    void add(int a, int b, Type val){
        update(a, val);
        update(b+1, -val);
    }

};
int main(){
    freopen("input.txt", "r", stdin);
    int test, cs = 1, N, a, b, Q, times;
    char qs[2];
    char s[MAX_ELEMENTS+1];
    scanf("%d", &test);
    while( test-- ){
        scanf("%s", s);
        N = strlen(s);
        scanf("%d", &Q);
        Bit bit = Bit(N);
        printf("Case %d:\n", cs++);
        while(Q--){
            scanf("%s", qs);
            if(qs[0] == 'I'){
                scanf("%d %d", &a, &b);
                bit.add(a, b, 1);

            }
            else{
                scanf("%d", &a);
                times = bit.query(a);
                if(times&1)printf("%c\n", s[a-1] == '0'?'1':'0');
                else printf("%c\n", s[a-1]);
            }
        }
    }
    return 0;
}
