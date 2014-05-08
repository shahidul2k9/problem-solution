#include <cstdio>
#include <cstring>
using namespace std;
typedef long long int Type;
#define MAX_ELEMENTS 100000
#define step(x) ((x)& (-x))

// Point update range query BIT
struct Bit{
    int MaxVal;
    Type ft[MAX_ELEMENTS+1];
    Bit(int N):MaxVal(N){memset(ft, 0, sizeof(Type)*(N+1));}
    void add(int idx, Type val){
        while(idx <= MaxVal){
            ft[idx] += val;
            idx += step(idx);
        }
    }
    //Returns cumulative sum in rnage [1...idx]
    Type cumulativeSum(int idx){
        Type sum = 0;
        while(idx > 0){
            sum += ft[idx];
            idx -=step(idx);
        }
        return sum;
    }
    Type query(int a, int b){
        return cumulativeSum(b) - cumulativeSum(a-1);
    }

};
int main(){
    freopen("input.txt", "r", stdin);
    int T, tc = 1, command, n, i, j, q, pos;
    Type val;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &n, &q);
        Bit bit = Bit(n);
        for(int idx = 1; idx <= n; idx++){
            scanf("%lld", &val);
            bit.add(idx, val);
        }
        printf("Case %d:\n", tc++);
        while(q--){
            scanf("%d", &command);
            if(command == 1){
                scanf("%d", &pos);
                pos++;
                val = bit.query(pos, pos);
                bit.add(pos, -val);
                printf("%lld\n", val);
            }
            else if(command == 2){
                scanf("%d %lld", &pos, &val);
                ++pos;
                bit.add(pos, val);
            }
            else{
                scanf("%d %d", &i, &j);
                ++i, ++j;
                printf("%lld\n", bit.query(i, j) );
            }
        }
    }
    return 0;
}
