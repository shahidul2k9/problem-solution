#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <numeric>
using namespace std;
#define COINS 7
#define BIG_NUMBER 999999999
#define MAX 50000
int wt[COINS] = {0, 1, 2, 4,10, 20, 40};
int num[COINS];
int buyer[MAX];
int seller[MAX];

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int WT, sum, ans;
    double x;
    while(true){
        sum = 0;
        for(int i = 1; i<= 6; i++){
            scanf("%d", &num[i]);
            sum += num[i]*wt[i];
        }

        if(sum == 0)break;
        scanf("%lf", &x);
        x += .01;

        WT = x*100;


        WT = WT/5;


        memset(seller, 0, sizeof(seller));
        memset(buyer, 0, sizeof(buyer));

        for(int i = 1; i<= sum;i++)
            buyer[i] = seller[i] = BIG_NUMBER;
        buyer[0] = seller[0] = 0;

        for(int i = 1; i<= 6; i++){
            for(int j = sum; j>0; j--){
                ans = BIG_NUMBER;
                for(int k = 0; k <= num[i] && k*wt[i] <= j ; k++)
                    ans = min(ans, k + buyer[j - k*wt[i] ]);
                buyer[j] = ans;

            }
        }

        for(int i = 1; i<= 6; i++){
            for(int j = sum; j>0; j--){
                ans = BIG_NUMBER;
                for(int k = 0; k*wt[i] <= j ; k++)
                    ans = min(ans, k + seller[j - k*wt[i]]);
                seller[j] = ans;

            }
        }


        ans = INT_MAX;
        for(int i = WT; i <= sum; i++){
            ans = min(buyer[i]+seller[i-WT], ans);
        }
        printf("%3d\n", ans);
    }

    return 0;
}
