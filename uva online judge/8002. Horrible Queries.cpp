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
#include <vector>

using namespace std;
#define SZ 100000

struct Node{
    long long int sum ;
    long long int acw ;
}t[SZ*3];
int n;
long long int  query(int node, int b, int e, int from, int to, long long int carry = 0){
    if( b > to || e < from) return 0;
    if(b >= from && e <= to) return t[node].sum + (e - b + 1)*carry ;
    int mid = (b + e) >> 1;
    int lson = node << 1;
    long long int  ret = 0;
    ret += query(lson, b, mid, from, to, carry+t[node].acw);
    ret+= query(lson|1, mid+1, e, from, to, carry+t[node].acw);
    return ret;

}
void update(int node, int b, int e, int from, int to, long long int  w){
    if( b > to || e < from)return;
    if(b >= from && e <= to){
        t[node].sum += (e - b +1)*w;
        t[node].acw += w;
        return;
    }
    int lson = node << 1;
    int mid = (b + e) >> 1;

        update(lson, b, mid, from, to, w);
        update(lson|1, mid+1, e, from, to, w);
        t[node].sum = t[lson].sum + t[lson|1].sum + (e - b + 1)*t[node].acw;
    }
int main(){
    int op;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    int from, to, w,q, test;
    scanf("%d", &test);
    while( test-- ){
        scanf("%d %d", &n, &q);
        for(int k = 0; k < 3*SZ; k++ )t[k].sum = t[k].acw = 0;
        while(q--){
            scanf("%d", &op);
            if(op){
                scanf("%d %d", &from, &to);
                printf("%lld\n", query(1, 1, n, from, to,0));
            }
            else{
                scanf("%d %d %d", &from, &to, &w);
                update(1,1,n,from,to,w);
            }
        }
    }
	return 0;
}
