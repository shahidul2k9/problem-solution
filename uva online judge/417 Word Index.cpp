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


map < string, int > h;
void bfs(){
    int cur = 1;
    queue<string> q;
    string seq = "";
    for( char i = 'a'; i <= 'z'; i++ ){
        seq = i;
        q.push(seq);
        h[seq]  = cur++;
    }
    string str;
    while( !q.empty() ){
        str = q.front();q.pop();
        if(str.size() == 5)continue;
        for( char ch = str[str.size()-1]+1; ch <= 'z'; ch++ ){
            seq = str + ch;
            h[seq] = cur++;
            q.push(seq);
        }

    }
}
int main(){
    //freopen("input.txt", "r", stdin);
    string str;
    bfs();
    map<string, int > :: iterator it;
    while(cin >> str){
        it = h.find(str);
        if(it == h.end()) puts("0");
        else printf("%d\n", (*it).second);
    }
	return 0;
}
