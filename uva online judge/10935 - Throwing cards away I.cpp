#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    vector <int> v;
    vector <int> :: iterator it;
    int n,i;
    scanf("%d",&n);
    while(n!=0){
        if(n==1){
            printf("Discarded cards:");
            printf("\nRemaining card: %d\n",n);
            scanf("%d",&n);
            continue;
        }
        for(i=1;i<=n;i++)v.push_back(i);

        it = v.begin();
        printf("Discarded cards: ");
        for(;v.size()>2;){
            printf("%d, ",(*it));
            v.erase(it);

            v.push_back(*it);
            v.erase(it);

        }
         for(;v.size()>1;){
            printf("%d\n",(*it));
            v.erase(it);

            v.push_back(*it);
            v.erase(it);

        }
        printf("Remaining card: %d\n",*it);
        scanf("%d",&n);
        v.clear();
    }
    return 0;
}
