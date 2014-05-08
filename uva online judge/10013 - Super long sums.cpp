#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

int main()
{
    vector<int> x,y,v;
    int n,m,i,s,c,a,b;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&m);
        s = 0;c=0;
        for(i=0;i<m;i++)
            {
                scanf("%d%d",&a,&b);
                x.push_back(a);
                y.push_back(b);
            }
        for(i = m-1;i>-1;i--)
            {
                c = c + x[i]+y[i];
                s = c%10;
                c = c/10;
                //printf("%d",s);
                v.push_back(s);
            }
            for(;c!=0;)
            {
                v.push_back(c%10);
                c = c/10;
            }
                //printf("%d\n",c);

        for(i = v.size()-1;i>-1;i--)
            printf("%d",v[i]);

        printf("\n");
        if(n>0)
            printf("\n");
        x.clear();
        y.clear();
        v.clear();
    }
    return 0;
}
