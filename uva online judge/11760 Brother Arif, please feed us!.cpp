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
int R, C, N;
inline bool isinside(int x, int y ){
    return x >= 0 && x < R && y >= 0 && y < C;
}
int main(){
    //freopen("input.txt", "r", stdin);

    int x, y;
   vector < ii > ls;
    vector< ii > room;
    int cs = 1;
   while(scanf("%d %d %d", &R, &C, &N) == 3 && R){
       ls.clear();
       room.clear();
       for( int i = 0; i < N;i++ ){
           scanf("%d %d", &x, &y);
           ls.push_back(ii(x, y));
       }
       scanf("%d %d", &x, &y);
       room.push_back(ii(x,y));
       if(isinside(x-1,y))room.push_back(ii(x-1,y));
       if(isinside(x+1,y))room.push_back(ii(x+1,y));
       if(isinside(x,y-1))room.push_back(ii(x,y-1));
       if(isinside(x,y+1))room.push_back(ii(x,y+1));
       for( int i = 0; i < N && (int)room.size() != 0; i++ ){
           for( int k = 0; k <(int) room.size(); k++ ){

                //printf("-----------\n");
                //for(int l = 0; l < room.size(); l++) printf("%d %d \n", room[l].first, room[l].second);

               if( room[k].first == ls[i].first || room[k].second == ls[i].second){
                    room.erase(room.begin()+k);
                    i--;
                    break;
               }
           }
       }
    printf("Case %d: ", cs++);
    if (room.size() != 0)
        printf("Escaped again! More 2D grid problems!\n");
    else printf("Party time! Let's find a restaurant!\n");
   }
	return 0;
}
