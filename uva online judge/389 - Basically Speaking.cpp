#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int main()
{
       string str;

       vector <char> v;
       int from,to,d,size,r,x,i;
       char ch;
       while(cin>>str){

           cin>>from>>to;
           size = str.size();
           d =0;
           r=0;
           for(i=size-1;i>-1;i--){
               ch = str.at(i);
               if(ch>='a')ch = ch-87;
               else if(ch>='A')ch = ch-55;
               else ch = ch-48;
               d = d+ch*pow(from,r);
               r = r+1;
           }
           if(d ==0){cout<<"      0"<<endl;continue;}
           for(;d!=0;d = d/to){
               x = d%to;
               if(x>-1&&x<10)v.push_back(x+48);
               else if(x>9&&x<16)v.push_back(x+55);
           }
           size =v.size();
           if(size<=7){
               for(i=0;i<7-size;i++)cout<<" ";
               for(i=size-1;i>-1;i--)cout<<v[i];cout<<endl;
               }
           else cout<<"  ERROR"<<endl;
           v.clear();
       }

       return 0;
}
