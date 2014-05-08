#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 10005
int input[MAX],item,pos, middle;
void binarySearch(int low, int high){
    if(low<=high){
        middle = (low+high)/2;
        if(input[middle]==item)
            pos = middle;
        if(item<=input[middle])binarySearch(low, middle-1);

        else binarySearch(middle+1, high);
    }
else return;
}
int main(){
    freopen("input.txt", "r", stdin);
    int n,q,i, cs=0;
    while(scanf("%d %d", &n, &q)==2&&(n||q)){
        for(i=0;i<n;i++)scanf("%d", &input[i]);
        sort(input,input+n);
        printf("CASE# %d:\n", ++cs);
        for(i=0;i<q;i++){
            scanf("%d", &item);
            pos = -1;
            binarySearch(0,n-1);
            if(pos<0)printf("%d not found\n", item);
            else printf("%d found at %d\n", item, pos+1);
        }
    }
    return 0;
}
