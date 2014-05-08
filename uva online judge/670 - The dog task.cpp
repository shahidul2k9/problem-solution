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
#define MAX_NODES 202

struct Point {
	int x, y;
} b[100], r[100];
int R[MAX_NODES][MAX_NODES];
int match[MAX_NODES];
int N, M, src, dest, nodes;
int pre[MAX_NODES];
double dist2d(Point a, Point b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void printMatrix(){
	for(int i = 0; i < nodes; i++){

		for(int j = 0; j < nodes; j++){
			printf("%d ", R[i][j]);
		}
		puts("");
	}
}
bool bfs() {
	queue<int> q;

	int from;
	memset(pre, -1, sizeof pre);
	pre[src] = src;
	q.push(src);
	while (!q.empty()) {
		from = q.front();
		q.pop();
		if (from == dest)
			return true;
		for (int i = 0; i < nodes; i++) {
			if (R[from][i] > 0 && pre[i] == -1) {
				q.push(i);
				pre[i] = from;
			}
		}

	}

	return false;

}

int main() {
	//READ("input.txt");
	//WRITE("output.txt");
	int test;
	scanf("%d", &test);
	while (test--) {
		scanf("%d %d", &N, &M);

		src = M + N;
		dest = M + N + 1;
		nodes = M + N + 2;

    for (int i = 0; i < N; i++)
        scanf("%d %d", &b[i].x, &b[i].y);

    for (int i = 0; i < M; i++)
        scanf("%d %d", &r[i].x, &r[i].y);

    memset(R, 0, sizeof R);
    memset(match, -1, sizeof match);


    for (int i = 0; i < N - 1; i++)
        for (int j = 0; j < M; j++)
            if (dist2d(b[i], r[j]) + dist2d(r[j], b[i + 1])<= 2*dist2d(b[i], b[i + 1]))
            R[i+1][j + N] = 1;
		//printMatrix();


		for (int i = 0; i < N; i++)
			R[src][i] = 1;
		for (int i = N; i < N + M; i++)
			R[i][dest] = 1;

		int maxflow = 0;
		int x;

		while (bfs()) {
			maxflow++;
			x = dest;
			while (x != pre[x]) {
			    match[pre[x]] = x;
				R[pre[x]][x]--;
				R[x][pre[x]]++;
				x = pre[x];
			}
		}
		printf("%d\n", maxflow + N);
		for (int i = 0; i < N; i++) {
		    if(match[i] >= N ) match[i] -= N;
		    if (match[i] != -1)
                printf("%d %d ", r[match[i]].x, r[match[i]].y);
            printf("%d %d", b[i].x, b[i].y);
            if( i + 1 == N )puts("");
            else printf(" ");
		}
		if(test)puts("");

	}

	return 0;
}
