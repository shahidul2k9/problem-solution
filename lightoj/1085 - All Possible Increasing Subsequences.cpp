#include <cstdio>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
#define offset(b) (b&(-b))
#define MOD 1000000007
#define SZ 100009
typedef long long int i64;
struct Node{
    int val;
    int pos;
    Node(){}
    Node(int V, int P): val(V), pos(P){}
    bool operator <(const Node& node) const{
        if(val != node.val) return val < node.val;
        return pos > node.pos;
    }
};
struct Bit{
    int MaxValue;
    i64 t[SZ];
    Bit(int n): MaxValue(n){
        memset(t, 0, sizeof(i64)* (n+1));
    }
    i64 query(int idx){
        i64 ans(0);
        while(idx > 0){
            ans = (ans + t[idx])%MOD;
            idx -= offset(idx);
        }
        return ans;
    }
    void add( int idx , i64 val){
        while(idx <= MaxValue){
            t[idx] = (t[idx] + val )%MOD;
            idx += offset(idx);
        }
    }

};
int main(){
   // freopen("input.txt", "r", stdin);
    Node lis[SZ];
    int n;
    int test, val, pos,  tc = 1;
    scanf("%d", &test);
    while( test-- ){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", &val);
            lis[i] = Node(val, i);
        }
        sort(lis+1, lis+n+1);

        Bit bt = Bit(n);
        for(int idx = 1; idx <= n; idx++){
            pos = lis[idx].pos;
            bt.add(pos, 1 + bt.query(pos-1));
        }
        printf("Case %d: %lld\n", tc++, bt.query(n));
    }

    return 0;
}
