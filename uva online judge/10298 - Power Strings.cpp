#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    char s[1000000+5];
    bool got;
    int i,j,len;
    while(gets(s)&&s[0]!='.'){
        len = strlen(s);
        got = true;
        for(i=1;i<len-1;i++){
            if(len%i!=0)continue;
            for(j=i;j<len;j++)
                if(s[j]!=s[j%i]){
                    got = false;
                    break;
                }
        if(got)break;
        got = true;
        }
        if(got)printf("%d\n",len/i);
        else printf("%d\n",len);
    }
    return 0;
}
