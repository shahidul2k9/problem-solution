//============================================================================
// Name        : 11385.cpp
// Author      : Shahidul
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
typedef long long int ll;
map < int, int > h;

int main() {
	freopen("input.txt","r", stdin);
	//freopen("output.txt","w", stdout);
	int test, N, lo, key, cind;
	int e[100+10];
	string s;
	char str[100+10];
	int id = 0;
	h[1] = id++;
	h[2] = id++;
	ll a = 1;
	ll b = 2;
	while(a + b < (ll)INT_MAX){
		key = a + b;
		h[key] = id++;


		a = b;
		b = key;
	}
/*
	for(map < int , int > :: iterator it = h.begin(); it != h.end(); it++){
		cout << (*it).first << " " << (*it).second << endl;
	}
*/
	scanf("%d", &test);
	while(test--){
		scanf("%d", &N);
		for(int i = 0; i < N; i++)scanf("%d", &e[i]);getline(cin,s);
		getline(cin, s);
		memset(str, ' ', sizeof str);
		lo = 0;

		int ind = -1;
		int minind = 100;
		for(int i = 0; i < (int)s.size() && lo < N; i++){
			if(isupper(s[i])){
				cind = h[e[lo++]];
				str[cind] = s[i];
				ind = max(ind, cind);
				minind = min(cind, minind);
			}
		}

		for(int i = 0; i <= ind;i++)printf("%c", str[i]);
		puts("");

	}
	return 0;
}
