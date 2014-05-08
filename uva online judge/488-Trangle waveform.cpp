#include <iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int amp,fre,i,p,q,test;
    cin>>test;
    while(test--)
    {

        scanf("%d%d",&amp,&fre);
        for(i=0;i<fre;i++)
        {
            for(p=1;p<=amp;p++)
            {
                for(q=1;q<=p;q++)cout<<p;
                cout<<endl;
            }
            for(p=amp-1;p>=1;p--)
            {
              for(q=1;q<=p;q++)cout<<p;
              cout<<endl;
            }
            //cout<<"******"<<fre<<i<<"****"<<endl;
            if(fre!=i+1)
            cout<<endl;
        }
    if(test)printf("\n");
    }

    return 0;
}
