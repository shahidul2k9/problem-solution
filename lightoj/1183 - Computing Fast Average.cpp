#include <bits/stdc++.h>
using namespace std;
#define MX 1 << 18
int minVal[MX],maxVal[MX];
#define left(n) n << 1
#define right(n) (n << 1)|1
 
#define MX 1 << 18
int sum[MX], c[MX];
void build(){
    memset(sum, 0, sizeof(sum));
    memset(c, -1, sizeof(c));
}
void pushUp(int p){
    sum[p] = sum[left(p)] + sum[right(p)];
}
void pushDown(int p, int beg, int end){
    if(c[p] == -1)return;
 
    int mid = (beg + end) >> 1;
    sum[ left(p) ] = (mid-beg+1)*c[p];
    sum[ right(p) ] = (end-mid)*c[p];
    c[left(p)] = c[right(p)] = c[p];
    c[p] = -1;
}
void update(int p, int curBeg, int curEnd, int beg, int end, int v){
    if(curBeg > end || curEnd < beg)return;
    if(curBeg >= beg && curEnd <= end){
        sum[p] = (curEnd - curBeg+1)*v;
        c[p] = v;
        return;
    }
 
    pushDown(p, curBeg, curEnd);
    int curMid = (curBeg + curEnd) >> 1;
 
    update(left(p), curBeg, curMid, beg, end, v);
    update(right(p), curMid+1, curEnd, beg, end, v);
    pushUp(p);
}
int query(int p, int curBeg, int curEnd, int beg, int end ){
    if(curBeg > end || curEnd < beg) return 0;
 
    if(curBeg >= beg && curEnd <= end)return sum[p];
 
    pushDown(p,curBeg, curEnd);
 
    int curMid = (curBeg + curEnd) >> 1;
    int ret = 0;
    ret += query(left(p), curBeg, curMid, beg, end);
    ret += query(right(p), curMid+1, curEnd, beg, end);
    //pushUp(p);
    return ret;
 
}
 
int gcd(int a, int b){
    if(b == 0)return a;
    return gcd(b, a%b);
}
int main(){
      #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        #endif
        int n,q, i, j, type,  test, num, den, div, v, cs = 1;
        scanf("%d", &test);
        while(test--){
            scanf("%d %d", &n, &q);
            printf("Case %d:\n", cs++);
            build();
            while(q--){
                scanf("%d %d %d", &type, &i, &j);
                i++;j++;
                switch(type){
                    case 1:
                        scanf("%d", &v);
                        update(1,1,n,i,j,v);
                        break;
                    case 2:
                        num = query(1,1,n,i,j);
                        den = j-i+1;
                        div = gcd(num,den);
                        num /= div;
                        den /= div;
                        if(den==1)printf("%d\n",num);
                        else if(num == 0)puts("0");
                        else printf("%d/%d\n", num, den);
 
                        break;
 
                }
            }
 
        }
    return 0;
}