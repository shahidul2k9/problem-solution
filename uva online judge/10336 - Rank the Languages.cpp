#include <cstdio>
#include <cmath>
#include <iostream>
#include <string.h>		// For memset function
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <bitset>
#include <sstream>
#include <map>

using namespace std;

#define FOR( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )
#define FORD( i, U, L ) for(int i=(int)U ; i>=(int)L ; i-- )
#define SQR(x) ((x)*(x))

#define INF 99999999
#define SZ size()
#define PB push_back
#define PF push_front

#define READ(filename)  freopen(filename, "r", stdin);
#define WRITE(filename)  freopen(filename, "w", stdout);

typedef long long LL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<vector<char> > VVC;
typedef vector<double> VD;
typedef vector<char> VC;
typedef vector<string> VS;
typedef pair<int, int> II;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<char, bool> MCB;
typedef map<string, int> MSI;
typedef map<string, char> MSC;

#define WHITE 0
#define GRAY 1
#define BLACK 2
int M,N;
VVC g;
MCB track;
//int dr[] = {0, -1, -1, -1,  0,  1, 1, 1};
//int dc[] = {1,  1,  0, -1, -1, -1, 0, 1};
int dr[4] ={0, -1,  0, 1};
int dc[4] ={1,  0, -1, 0};
int fill(int r, int c, char penitrative, char obstacle){
    if(r<0||c<0||r>=M||c>=N||g[r][c]!=penitrative)return 0;
    g[r][c] = obstacle;
    int ans = 1;
    FOR(i,0,3){
        ans += fill(r+dr[i], c+dc[i], penitrative, obstacle);
    }
    return ans;
}
bool comp(pair<char, int> a, pair<char, int> b){
    if(a.second!=b.second)return a.second>b.second;
    else return a.first< b.first;
}
int main()
{
     //READ("input.txt");
    //WRITE("output.txt");
    map<char,bool> ::iterator it;
    vector<pair<char, int> > language;
    int test, tc = 1;
    string buf;
    int ans;
    scanf("%d", &test);
    while(test--){
        scanf("%d %d", &M, &N);
        g = VVC(M);
        getline(cin,buf);
        FOR(i,0,M-1){
            getline(cin,buf);
            g[i].assign(buf.begin(),buf.end());
        }
    track.clear();
    FOR(i,0,M-1)
        FOR(j,0,N-1)
            if(track[g[i][j]]==false)track[g[i][j]]=true;


    language.clear();
    for(it = track.begin();it!=track.end();it++){
            ans = 0;
            FOR(i,0,M-1)
                FOR(j,0,N-1)
                        if(fill(i,j,it->first,'*')>0) ans++;
        language.push_back(make_pair(it->first,ans));
    }
    sort(language.begin(),language.end(),comp);
    printf("World #%d\n", tc++);
    FOR(i,0,language.size()-1)
        printf("%c: %d\n", language[i].first, language[i].second);
    }
	return 0;
}
