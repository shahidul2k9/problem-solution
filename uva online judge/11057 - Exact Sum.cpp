#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;
int mid,n,total,item,pos;
int price[10005];
void binarySearch(int lo, int hi){
    if(lo>hi)return;
    else {
        mid = lo+hi;

        if(item==price[mid]){
            pos = mid;
            return;
        }
        else if(item<=price[mid])binarySearch(lo,mid-1);
        else binarySearch(mid+1,hi);
    }
}
int main()
{
   // freopen("input.txt", "r", stdin);
    int i;
    while(scanf("%d", &n)!=EOF){
        for(i=0;i<n;i++)scanf("%d", &price[i]);
        scanf("%d", &total);
        sort(price,price+n);
        pos = -1;
        item = total/2;
        binarySearch(0,n-1);

        if(pos!=-1&&price[pos]*2==total){
            if((pos-1>=0&&price[pos-1]==item)||(pos+1<n&&price[pos+1]==item)){
                printf("Peter should buy books whose prices are %d and %d.\n", item, item);
                printf("\n");
                continue;
            }
        }

            for(i=mid;i>=0;i--){
                item = total-price[i];
                pos =-1;
                binarySearch(pos+1,n-1);
                if(pos!=-1){
                    printf("Peter should buy books whose prices are %d and %d.\n", price[i], item);
                    break;
                    }
            }

    printf("\n");
    }
    return 0;
}
