#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <string.h>
using namespace std;
char in[100];
map < string,bool > look;
bool isUniquePlaindrome(int index, int si){

    if(index >=si)return false;
    int i,tempIndex;
    tempIndex = index;
    i = 0;
    char temp[100];
    char rev[100];
    while(index<si)temp[i++]=in[index++];
    temp[i] = NULL;
    strcpy(rev,temp);
    reverse(rev,rev+i);
    if(strcmp(temp,rev) == 0){
        if(look[temp] == 1)return false;
        else {
            look[temp] = 1;
            return true;
        }
    }
return false;
}
int main()
{
    freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
    int i,k,len,num;

    while(cin >> in){
        num = 0;
        len = strlen(in);
        for(i = 0; i<len; i++ ){
            for(k = 0; k<len; k++){
                if(isUniquePlaindrome(i,len-k))num++;
            }
        }
        cout << "The string '" << in << "' contains " << num << " palindromes." << endl;
        look.clear();
    }

    return 0;
}
