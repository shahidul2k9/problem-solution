#include <string.h>
#include <cstdio>
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

#define FOR( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )
#define FORD( i, U, L ) for(int i=(int)U ; i>=(int)L ; i-- )
#define SQR(x) ((x)*(x))

#define INF INT_MAX


#define READ(filename)  freopen(filename, "r", stdin);
#define WRITE(filename)  freopen(filename, "w", stdout);

typedef pair< string , int> si;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<vector<int> > vvi;
typedef vector<vector<int> > vvc;
typedef map<int, int> mii;
typedef map<string, int> msi;
typedef map<int, string> mis;
typedef map<string, string> mss;
typedef map<string, char> msc;
typedef map<string, bool> msb;
#define INVALID "------"

bool comp( si a, si b){
    if(a.second != b.second)return a.second > b.second;
    return a.first < b.first;
}

inline bool isvalidName(string name){
     return !isdigit(name[0]);
}
int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    string project, user, s;
    mss userList;
    msi list;
    vector <si> ans;
    bool isproject, invalid;
    while(true){
        userList.clear();
        list.clear();
        ans.clear();
        while(getline(cin, s) ){

            if(s  == "0")return 0;
            if(s.length() == 1 && s == "1")break;
            if(s.size() == 0 )continue;

            invalid = false;
            isproject = true;
            for(int i = 0; i <(int) s.size(); i++)
                if( !isupper(s[i]) && !isspace(s[i])){
                    isproject = false;
                    break;
                }


            if(isproject ){
                project = s;
                if(list.find(s) == list.end()) list[project] = 0;
                continue;
                }
            if( !isproject && !isvalidName(s))
                continue;

            user = s;
            if(userList.find(user) == userList.end()){
                userList[user] = project;
                list[project] += 1;
                    }
                else {
                        if( userList[user] == INVALID || userList[user] == project) continue;
                        list[userList[user]]--;
                        userList[user] = INVALID;
                    }
        }
        ans = vector<si> (list.begin(), list.end());
        sort(ans.begin(), ans.end(), comp);
        for(int i = 0; i < (int)ans.size(); i++)cout << ans[i].first << " " << ans[i].second << endl;
    }
	return 0;
}
