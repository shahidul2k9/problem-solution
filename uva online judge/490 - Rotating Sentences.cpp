#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <string.h>

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    char lines[110][110];
    int len[110];
    int j,i=0,MAX=0;
    while(gets(lines[i])){
       int  l = strlen(lines[i]);
        MAX = max(MAX,l);
        for(j=l;j<MAX;j++)lines[i][j] = ' ';
        lines[i][MAX] = '\0';
        len[i] = MAX;
        i++;
    }

    int totalLines =  i;
    //for(i=0;i<totalLines;i++)len[i] = strlen(lines[i]);
    int maxLength = *max_element(len,len+totalLines);
    i=0;
    while(i<maxLength){
        for(j=totalLines-1;j>=0;j--){
            if(i<len[j])printf("%c",lines[j][i]);
        }
        printf("\n");
        i++;
    }
    return 0;
}
