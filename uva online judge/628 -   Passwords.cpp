#include <iostream>
#include <stdio.h>
using namespace std;
#define MAX 101
int m,n,len,id;
string dic[MAX];
string law;
char touple[300];
void BackTrack(int index){
    int i;
    if(index==len){
        for(i=0;i<len;i++){
            if(touple[i]=='#')cout << dic[id];
            else printf("%c",touple[i] );
            }
        cout << endl;
    }
    else if(law[index]=='#'){
        touple[index]='#';
        BackTrack(index+1);
        }
    else {
        for(i=0;i<=9;i++){
            touple[index]=i+'0';
            BackTrack(index+1);
            }
    }
}
int main()
{
    int i;
    //freopen("input.txt", "r", stdin);
    while(scanf("%d", &n)==1){
        cout<<"--"<<endl;
        for(i=0;i<n;i++)
            cin >> dic[i] ;
        scanf("%d", &m);
        for(i=0;i<m;i++){
            cin >> law;
            len = law.size();
            for(int j=0;j<n;j++)
                {
                    id = j;
                    BackTrack(0);

                }
        }
    }
    return 0;
}
