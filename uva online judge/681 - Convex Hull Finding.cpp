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
#define EPS 1e-9
#define MAX 520

typedef  long long ET;
enum{CCW,CW,CL};
struct Point{
    ET x;
    ET y;
    Point(){
        x=0;
        y=0;
        }
    Point(ET x, ET y){
    this->x = x;
    this->y = y;
    }
};
Point p[MAX], c[MAX];

double dist(const Point &a, const Point &b){
    return sqrt(SQR(a.x-b.x)+SQR(a.y-b.y));
}
double sqr_dist(const Point &a, const Point &b){
    return SQR(a.x-b.x)+SQR(a.y-b.y);
}


inline double triArea(const Point &a, const Point &b, const Point &c) {
	return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}

inline bool comp(const Point &b, const Point &c) {
	ET d = triArea(p[0], b, c);
	if(d > 0) return true;
	if(d <0)return false;
	return sqr_dist(p[0],b)<sqr_dist(p[0],c);
}
inline bool issame(const Point& a, const Point& b){
    if(a.x==b.x&&a.y==b.y)return true;
    return false;
}
void compress(int &nc) {
    int i, j, d;
    c[nc] = c[0];
    for(i=j=1; i < nc; i++) {
        d = triArea(c[j-1], c[i], c[i+1]);
        if(d || (!d && issame(c[j-1], c[i+1]))) c[j++] = c[i];
    }
    nc = j;
}
void convexHull(int &np, int &nc) {
	int i, top,pos = 0;
	for(i = 1; i < np; i++)
		if(p[i].y<p[pos].y || (p[i].y==p[pos].y && p[i].x<p[pos].x))
			pos = i;
	swap(p[0], p[pos]);
	sort(&p[1], &p[np], comp);
	//np =unique(&p[0],&p[0]+np,issame)-p;
	for(i = 0; i < 2; i++) c[i] = p[i];
	for(i = 2,top = 1; i < np; i++) {
		while(top>0&&triArea(c[top-1], c[top], p[i]) <=0) top--;
		c[++top] = p[i];
	}
	nc = top+1;
	//compress(nc);
}


int main(){
   //freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdin);
    int np,nc,test,ajgobi;
    scanf("%d",&test);
    if(test>0)cout<<test<<endl;
    while(test--){
    scanf("%d", &np);
    for(int i=0;i<np;i++)cin>> p[i].x >> p[i].y;

    convexHull(np,nc);
    if(test)cin >>ajgobi;
    cout << nc+1<<endl;

    for(int i=0;i<nc;i++)cout << c[i].x << " " << c[i].y << endl;
    cout<<c[0].x << " "<< c[0].y<<endl;
    if(test)cout<<"-1"<<endl;
    }
return 0;
}
