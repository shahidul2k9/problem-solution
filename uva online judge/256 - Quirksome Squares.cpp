#include <iostream>
#include <cstring>
#include <cstdio>


using namespace std;

int main()
{

    char* two[] = {"00", "01", "81"};
    char* four[] = {"0000", "0001", "2025", "3025", "9801"};
    char* six[] = {"000000", "000001", "088209", "494209", "998001"};
    char* eight[] = {"00000000", "00000001", "04941729", "07441984", "24502500", "25502500", "52881984", "60481729", "99980001"};
    int n;
    while(scanf("%d",&n) == 1){
        switch(n){
        case 2: for(int i = 0; i < 3; i++)puts(two[i]);
            break;
        case 4: for(int i = 0; i < 5; i++)puts(four[i]);
            break;
        case 6: for(int i = 0; i < 5; i++)puts(six[i]);
            break;
        case 8: for(int i = 0; i < 9; i++)puts(eight[i]);
            break;
        }
    }

    return 0;
}
/*
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <map>
#define NOLINK -2
using namespace std;
string tostring(int x){
    stringstream ss;
    ss << x;
    string str;
    ss >> str;
    return str;
}
int main(){
    freopen("output.txt", "w",stdout);
    char out[15];
    char lef[15];
    char* rig;
    int x, y, ans;
    string str;
    for(int i = 2; i <= 8; i = i+2){
        str = "%0" + tostring(i) + "d";

        for(int j = 0; true; j++){
        sprintf(out,str.c_str(), j);
        if(strlen(out)> i)break;

        strncpy(lef, out, i/2);
        lef[i/2] = 0;
        rig = out + i/2;


        x = atoi(lef);
        y = atoi(rig);
        ans = x + y;
        if(ans * ans == atoi(out)){
           // printf("%s %s %s\n",lef, rig, out);
           printf("\"%s\", ", out);
        }
        }
        puts("");
    }
    return 0;
}
*/
