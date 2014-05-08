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
int n,q;
int h[50000];
int key, mid, shouldBeIndex;
int binarySearch(int lo, int hi){
    if(lo>hi){
        shouldBeIndex = ceil(double(lo+hi)/2);
        return -1;
    }
    mid = lo + (hi-lo)/2;
    if(key==h[mid])return mid;
    else if(key<h[mid])return binarySearch(lo, mid-1);
    else return binarySearch(mid+1,hi);
}
int main()
{
    int i,height,index;
    READ("input.txt");
    //WRITE("output.txt");
    scanf("%d", &n);
    for(i=0;i<n;i++)scanf("%d",&h[i]);
    scanf("%d", &q);
    for(i=0;i<q;i++){
        scanf("%d", &height);
        key = height-1;
        index = binarySearch(0,n-1);
        if(index!=-1)printf("%d", h[index]);
        else if(shouldBeIndex-1<0)printf("X");
        else printf("%d",h[shouldBeIndex-1]);

        printf(" ");
        key = height +1;
        index = binarySearch(0,n-1);
        if(index!=-1)printf("%d", h[index]);
        else if(shouldBeIndex==n)printf("X");
        else printf("%d",h[shouldBeIndex]);

        printf("\n");

    }
	return 0;
}
