#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <string.h>
#include <sstream>

using namespace std;

#define M 185
struct Box{
    int l,w,h;

}box[M], S[M];
bool comp(const Box&  a, const Box& b){
    return a.l*a.w > b.l*b.w;
}
int main()
{
    freopen("input.txt", "r", stdin);

    int L[M];
    int i,N, a, b, c, id, j, pos, cs = 1;


    while(scanf("%d", &N) == 1 && N){

       id = 0;
        for(int i = 0; i < N; i++){
            scanf("%d %d %d", &a, &b, &c);

            box[id].l = a;
            box[id].w = b;
            box[id].h = c;
            id++;
            box[id].l = a;
            box[id].w = c;
            box[id].h = b;


            id++;
            box[id].l = c;
            box[id].w = a;
            box[id].h = b;
            id++;
            box[id].l = c;
            box[id].w = b;
            box[id].h = a;


            id++;
            box[id].l = b;
            box[id].w = a;
            box[id].h = c;
            id++;
            box[id].l = b;
            box[id].w = c;
            box[id].h = a;

            id++;
        }
        N = id;
        sort(box, box + N, comp);
        for(i = 0; i < N; i++) L[i] = box[i].h;

        for(i = 1; i < N; i++)
            for(j = 0; j < i; j++)
                if(box[j].w > box[i].w && box[j].l > box[i].l) L[i] = max(L[i], L[j] + box[i].h);


        pos = 0;
        for(int i = 1; i < N; i++) if(L[pos] < L[i]) pos = i;
        printf("Case %d: maximum height = %d\n", cs++, L[pos]);;

    }
    return 0;
}
