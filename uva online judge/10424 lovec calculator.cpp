#include<stdio.h>
#include<iostream>
using namespace std;
  int finalCalculation (int n)
        {
            int sum=0;
            for(;n>0;)
                {
                sum=sum+n%10;
                n=n/10;
                }
            if(sum<10)return sum;
            else return finalCalculation(sum);
        }
int calculation(char str[])
    {
            int n,i;
            n=0;
            for(i=0;str[i]!=NULL;i++)
                {

                    if(str[i]>='a'&&str[i]<='z')
                        {
                         n=n+str[i]-96;
                        }
                    else if(str[i]>='A'&&str[i]<='Z')
                        {
                         n=n+str[i]-64;
                        }
                }
                return finalCalculation(n);
    }

int main()
    {
        float percen,b,g;
        char boy[25],girl[25];
        while(gets(boy)!=NULL)
            {

                gets(girl);

                b = calculation(boy);
                g = calculation(girl);
                if(b>g)
                    {
                    percen= g/b*100;
                    }
                else
                    {
                    percen = b/g*100;
                    }
                printf("%.2f",percen);
                cout<<" %"<<endl;
            }
        return 0;
    }
