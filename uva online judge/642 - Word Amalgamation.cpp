#include <cstdio>
#include <cmath>
#include <climits>
#include <iostream>
#include <string.h>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <bitset>
#include <sstream>
#include <set>
#include <map>
using namespace std;
#define ifor( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )
#define dfor( i, U, L ) for(int i=(int)U ; i>=(int)L ; i-- )

#define SQR(x) ((x)*(x))
#define INF INT_MAX
#define EPS 1e-9
#define PI (2*acos(0.0))
#define SZ size()

#define READ(filename)  freopen(filename, "r", stdin);
#define WRITE(filename)  freopen(filename, "w", stdout);

typedef long long ll;
typedef vector<char> vc;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<vector<int> > vvi;
typedef pair<int, int> ii;
typedef map<int, int> mii;
typedef map<string, int> msi;
typedef map<string, char> msc;
typedef vector<vector<ii>  > vvii;
typedef multimap<string,string> mmss;
#define WHITE 0
#define GRAY 1
#define BLACK 2

int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int co;
    mmss dic;
    string word,stword;
    mmss ::iterator itup,itlw;
    vs store;
    while(cin >> word&&word!="XXXXXX"){
        stword = word;
        sort(stword.begin(),stword.end());
        dic.insert(pair<string,string>(stword,word));

    }
    while(cin >> word && word!="XXXXXX"){
        stword = word;
        sort(stword.begin(),stword.end());
        co = (int)dic.count(stword);
        if(co>0){
            store.clear();
            itlw = dic.lower_bound(stword);
            ifor(i,1,co){
                //cout << (*itlw).second << endl;
                store.push_back((*itlw).second);
                itlw++;
            }
            sort(store.begin(),store.end());
            ifor(i,0,co-1){
                cout << store[i] << endl;
            }
        }
        else cout << "NOT A VALID WORD" << endl;
        cout << "******" << endl;
    }
    return 0;
}
