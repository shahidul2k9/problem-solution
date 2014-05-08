#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>

using namespace std;
typedef pair < int, int > ii;
int memo[10001][2];
int mini , mega, M, N, x, y, d;

ii  maxBurgers(int t){



    if(memo[t][0] != -1)return  ii(memo[t][1], memo[t][0]);

    if(t < mega && t >= mini){
        ii m = maxBurgers(t - mini);
        memo[t][0] = 1 + m.second;
        memo[t][1] = m.first;
        return ii(memo[t][1], memo[t][0]);
    }


    ii iiM = maxBurgers(t - M);
    ii iiN =  maxBurgers(t - N);


    if(iiM.first == iiN.first){
        memo[t][0] = max(iiM.second, iiN.second);
        memo[t][1] = iiM.first;
    }
    else if(iiM.first < iiN.first){
        memo[t][0] = iiM.second;
        memo[t][1] = iiM.first;
    }
    else {
        memo[t][0] = iiN.second;
        memo[t][1] = iiN.first;
    }

        memo[t][0]++;
          return ii(memo[t][1],memo[t][0]);
}

int main()
{
    freopen("input.txt", "r", stdin);
    int T;
    while(scanf("%d %d %d", &M, &N, &T) == 3){
        mini = min(M, N);
        mega = max(M,N);
        for(int i = 0; i < mini; i++){
            memo[i][0] = 0;
            memo[i][1] = i;
            }
        for(int i = mini; i <= T; i++)memo[i][0] = -1;
        memo[0][0] =  memo[0][1] = 0;
        ii ans = maxBurgers(T);
        printf("%d", ans.second);
        if(ans.first != 0)printf(" %d", ans.first);
        puts("");

    }

    return 0;
}
