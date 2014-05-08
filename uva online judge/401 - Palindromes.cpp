#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
   // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    map <char,char> lookup;
    int i;
    char in[23],re[23];
    int  plain,mirr,len;
    while(gets(in)){
        cout << in;
        cout << " -- ";
        len = strlen(in);
        for(i = 0;i<len;i++){if(in[i]=='0')in[i]='O';in[i]=toupper(in[i]);}

        strcpy(re,in);

        reverse(re,re+len);
        plain = strcmp(in,re);
    lookup['A'] = 'A';
   	lookup['E'] = '3';
   	lookup['H'] = 'H';
   	lookup['I'] = 'I';
   	lookup['J'] = 'L';
   	lookup['L'] = 'J';
   	lookup['M'] = 'M';
   	lookup['O'] = 'O';
   	lookup['S'] = '2';
   	lookup['T'] = 'T';
   	lookup['U'] = 'U';
   	lookup['V'] = 'V';
   	lookup['W'] = 'W';
   	lookup['X'] = 'X';
   	lookup['Y'] = 'Y';
   	lookup['Z'] = '5';
   	lookup['1'] = '1';
   	lookup['2'] = 'S';
   	lookup['3'] = 'E';
   	lookup['5'] = 'Z';
   	lookup['8'] = '8';
        for(i = 0;i<(len/2)+1;i++){
        if(lookup[in[i]] != in[len-1-i]){mirr =1;break;}
        mirr = 0;
        }
        if(plain == 0 && mirr == 0) cout << "is a mirrored palindrome." << endl;
        else if(plain !=0 && mirr ==0) cout << "is a mirrored string." << endl;
        else if(plain == 0&& mirr!=0) cout << "is a regular palindrome." << endl;
        else cout << "is not a palindrome." << endl ;
        cout << endl;
    }
    return 0;
}
