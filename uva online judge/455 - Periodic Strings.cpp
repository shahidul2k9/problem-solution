#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main()
{

    int test,i,j,len;
    string s;
    int got;
    scanf("%d", &test);
    while(test--){
        cin>>s;
        len = s.length();
        got = true;
        for(i=1;i<=len;i++){
            if(len%i!=0)continue;
            for(j=i;j<len;j++)
                if(s[j]!=s[j%i]){
                    got = false;
                    break;
                }
            if(got)break;
            got = true;
        }
            printf("%d\n",i);
        if(test)printf("\n");
    }
    return 0;
}
