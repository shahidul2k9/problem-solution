#include <bits/stdc++.h>
using namespace std;
#define MX 1 << 19
#define left(n) n << 1
#define right(n) (n << 1)|1
 
#define QUERY 50000
#define N 100000
 
int sum[MX], ids[N+QUERY+1];
 
void init(){
    memset(sum,0,sizeof(sum));
}
 
 
void update(int par, int curBeg, int curEnd, int pos,  int value){
    if(curBeg > pos || curEnd < pos)return;
    if(pos >= curBeg && pos <= curEnd){
        sum[par] += value;
        if(curBeg == curEnd) return;
    }
    int curMid = (curBeg+curEnd) >> 1;
    update(left(par), curBeg, curMid,pos, value);
    update(right(par), curMid+1, curEnd, pos, value);
}
 
int query(int par, int curBeg, int curEnd, int beg, int end){
    if(curBeg > end || curEnd < beg)return 0;
    if(curBeg >= beg && curEnd <= end) return sum[par];
    int curMid = (curBeg + curEnd) >> 1;
    return query(left(par), curBeg, curMid, beg,end) + query(right(par), curMid+1, curEnd, beg,end);
    }
 
 
int query(int par, int curBeg, int curEnd, int th){
    if(curBeg == curEnd)
        return curBeg;
 
 
    int leftSum = sum[left(par)];
    int curMid = (curBeg+curEnd) >> 1;
    if(leftSum >= th) return query(left(par),curBeg, curMid, th);
    return query(right(par), curMid+1, curEnd, th-leftSum);
 
}
 
int main(){
      #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
      #endif
    int test, cs = 1, n, v, pos, nq, cn, q;
    char s[10];
    scanf("%d", &test);
    while(test--){
        scanf("%d %d", &n, &q);
        nq = n  + q;
        cn = n;
        for(int i = 1; i <= n; i++)
            scanf("%d", ids+i);
 
        init();
        for(int i = 1; i <= n; i++)
            update(1,1,nq,i,1);
        printf("Case %d:\n", cs++);
        while(q--){
            scanf("%s %d", &s, &v);
            switch(s[0]){
                case 'c':
                    if(n < v)puts("none");
                    else {
                        n--;
                        pos = query(1,1,nq,v);
                        printf("%d\n", ids[pos]);
                        update(1,1,nq,pos,-1);
                    }
                    break;
                case 'a':
                    n++;
                    cn++;
                    ids[cn] = v;
                    update(1,1,nq,cn,1);
                    break;
                default:
                    break;
            }
        }
    }
    return 0;
}