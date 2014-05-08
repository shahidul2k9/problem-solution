#include <string.h>
#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>
using namespace std;
typedef pair < int , int > ii;



int main(){
    //freopen("input.txt", "r", stdin);
    vector<string> lis;
    string line;
    bool been[92];
    int ml = 0;
    while(cin >> line && line != "#"){
        lis.push_back(line);
        ml = max(ml, (int)line.size());
    }

    memset(been, false, sizeof(been));
    for(int i = 0; i < ml; i++)
        for(int k = 0; k < lis.size(); k++){
            if(lis[k].size()> i && been[lis[k][i]] == false){
                putchar(lis[k][i]);
                been[lis[k][i]] = true;
                }
        }
    puts("");

	return 0;
}
