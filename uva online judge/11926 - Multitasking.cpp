#include <cstdio>
#include <vector>
#include <cstdlib>
#include <climits>
#include <iostream>
#include <cmath>
#include <bitset>
#include <algorithm>
using namespace std;
#define FOR(i, L, U) for( int i = (int) L; i<=(int)U; i++)
#define FORD(i, U, L) for( int i = (int) U; i>=(int)L; i--)
typedef vector <int> vi;
int  MaxVal = 1000000;
vi tree = vi(MaxVal+1);
int read(int idx){
	int sum = 0;
	while (idx > 0){
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}
void update(int idx ,int val){
	while (idx <= MaxVal){
		tree[idx] += val;
		idx += (idx & -idx);
	}
}
int rsq(int lo, int hi){
    return read(hi) - ( (lo == 1) ? 0 : read(lo - 1) );
}
void setWorks(int a, int b){
    FOR(i,a,b) update(i, 1);
}
int main(){
    //freopen("input.txt", "r", stdin);
    int m, n, a, b, dif;
    bool conflict;
    while(scanf("%d %d", &n, &m)==2 &&(m || n)){
        tree.assign(MaxVal + 1,0);
        conflict = false;
        FOR(i,1,n){
            scanf("%d %d", &a, &b);
            a++;
            if (!conflict){
                conflict = rsq(a,b);
                setWorks(a,b);
            }
        }

        FOR(i,1,m){
            scanf("%d %d %d", &a, &b, &dif);
            a++;
            do{
                if(conflict)break;
                conflict = rsq(a,b);
                setWorks(a,b);
                a += dif;
                b += dif;
            }
            while(b<=MaxVal);
        }
    if(conflict)puts("CONFLICT");
    else puts("NO CONFLICT");
    }

    return 0;
}
