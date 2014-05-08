#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
typedef long  long int ll;
ll table[6000+1];
int count(  int m, int n)
{
    // table[i] will be storing the number of solutions for
    // value i. We need n+1 rows as the table is consturcted
    // in bottom up manner using the base case (n = 0)
    int S [] = {1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000};

   // int S[] = {2000, 1000, 400, 200, 100, 40, 20, 10,4, 2, 1};
    // Initialize all table values as 0
    memset(table, 0, sizeof(table));
    // Base case (If given value is 0)
    table[0] = 1;

    // Pick all coins one by one and update the table[] values
    // after the index greater than or equal to the value of the
    // picked coin
    for(int i=0; i<m; i++)
        for(int j=S[i]; j<=n; j++)
            table[j] += table[j-S[i]];

    return table[n];
}
int main(){
    //freopen("input.txt","r",stdin);
    float amount;
    count(11, 6000);
    while(scanf("%f",&amount)==1){
        int n = amount*20;
        if(n == 0)break;
        printf("%6.2f%17lld\n",amount, table[n]);
    }
    return 0;
}
