#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
 
using namespace std;
 
#define N 101
int l[N][N];
string x,y;
string t[N][N];
int m,n;
string minlcs;
void lcs(){
    int i,j;
    for(i=0;i<=m;i++){
        l[i][0] = 0;
        t[i][0] = "";
    }
    for(j=0;j<=n;j++){
        l[0][j] = 0;
        t[0][j] = "";
        }
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++){
            if(x[i-1]==y[j-1]){
                l[i][j] = l[i-1][j-1]+1;
                t[i][j] = t[i-1][j-1]+x[i-1];
                }
            else if(l[i-1][j]>l[i][j-1]){
                l[i][j] = l[i-1][j];
                t[i][j] = t[i-1][j];
                }
            else if(l[i][j-1]>l[i-1][j]){
                l[i][j] = l[i][j-1];
                t[i][j] = t[i][j-1];
 
            }
            else {
                l[i][j] = l[i-1][j];
                //l[i][j] = l[i][j-1];
                t[i][j] = min(t[i-1][j],t[i][j-1]);
            }
        }
}
void traverse(int i,int j, string s){
    if(l[i][j]==0){
        minlcs = min(s,minlcs);
        return;
    }
    if(x[i-1]==y[j-1])traverse(i-1,j-1,x[i-1]+s);
    else if(l[i-1][j]>l[i][j-1])
        traverse(i-1,j,s);
 
    else if(l[i][j-1]>l[i-1][j])
        traverse(i,j-1,s);
    else {
        traverse(i-1,j,s);
        traverse(i,j-1,s);
    }
}
void printTable(){
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++)cout<<l[i][j] <<  " ";
        cout<<endl;
 
    }
}
 
int main()
{
 
 
   // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int test,cs=0;
    scanf("%d",&test);
    while(test--){
        cin>>x >> y;
        m = x.length();
        n = y.length();
 
        lcs();
       // printTable();
        printf("Case %d: ",++cs);
        if(l[m][n]==0){
            printf(":(\n");
        }
 
        else
            cout<< t[m][n]<<endl;
    }
    return 0;
}