#include <iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

int main()
{
    char first[10000],second[10000],mfirst[100],msecond[100];
    int t,com,tn,index,i;
    freopen("input.txt","r",stdin);
    tn=1;
    cin>>t;
    gets(first);
    while(tn<=t)
        {
            gets(first);
            gets(second);
            com=strcmp(first,second);
            if(com==0)
                {
                    cout<<"Case "<<tn<<": Yes"<<endl;
                    tn++;
                    continue;
                }
                index=0;
                for(i=0;first[i]!=NULL;i++)
                    {
                        if(first[i]!=' ')
                            {
                                mfirst[index]=first[i];
                                index++;
                            }
                    }
                mfirst[index]=NULL;
                index=0;
                for(i=0;second[i]!=NULL;i++)
                {
                if(second[i]!=' ')
                    {
                        msecond[index]=second[i];
                        index++;
                    }
                }
                msecond[index]=NULL;
                com=strcmp(mfirst,msecond);
                if(com==0)
                    {
                        cout<<"Case "<<tn<<": Output Format Error"<<endl;
                        tn++;
                        continue;
                    }
                else cout<<"Case "<<tn<<": Wrong Answer"<<endl;
            tn++;
        }
    return 0;
}
