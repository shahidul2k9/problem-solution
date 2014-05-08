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

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define SQR(x) ((x)*(x))
#define PI 2*acos(0)
#define EPS 1e-7
#define MAX 200
#define N 5
int p[120][N];
int t[N];
int o[4];
bool solved;
int calculate(int opa1,int opa2,int op){
    if(op==0)return opa1+opa2;
    if(op==1)return opa1-opa2;
    if(op==2)return opa1*opa2;
    return 0;
}
void hasSolution(){
    int ans;
    FOR(i,0,119){
        ans = calculate(t[p[i][0]], t[p[i][1]],o[0]);
        //cout<<ans << "op"<< o[0]<< " ";
        ans = calculate(ans, t[p[i][2]], o[1]);
        //cout<<ans << "op"<< o[1]<< " ";
        ans = calculate(ans, t[p[i][3]], o[2]);
        //cout<<ans << "op"<< o[2]<< " ";
        ans = calculate(ans, t[p[i][4]], o[3]);
        //cout<<ans << "op"<< o[3] << " "<<endl;
        if(ans==23){
            solved = true;
          //  cout<<o[0]<<o[1]<<o[2]<<o[3]<<endl;
           // cout << t[p[i][0]] <<" "<<  t[p[i][1]]<<" "<<  t[p[i][2]] << " "<<  t[p[i][3]]<<" "<<  t[p[i][4]]<< endl;
            return;
        }
    }
}
void BackTrack(int l){
    if(solved)return;
    if(l==4){
        hasSolution();
        return;
        }
    FOR(i,0,2){
        o[l]=i;
        BackTrack(l+1);
    }
}
int main()
{
    READ("input.txt");
    //WRITE("output.txt");
    int h[] = {0,1,2,3,4};
    bool terminated;
    int i=0;
    do{

            FOR(j,0,4)p[i][j]=h[j];
            //cout<<h[0]<<" "<< h[1] << " "<< h[2] << " "<< h[3]<< " " << h[4]<<endl;
        i++;
    }
    while(next_permutation(h,h+5));

    while(true){
        FOR(i,0,4)
            scanf("%d",&t[i]);
        terminated = true;
        FOR(i,0,4)if(t[i])terminated=false;
        if(terminated)break;
        solved = false;
        BackTrack(0);
        if(solved)printf("Possible\n");
        else printf("Impossible\n");

    }

	return 0;
}
