#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
using namespace std;
typedef set<int> SI;
typedef vector<int> VI;
int main()
{
  //freopen("input.txt","r",stdin);
    VI a;
    VI s;
    int n,i,x;
    bool b;
    VI ::iterator it;
    while(scanf("%d",&n)==1){
        b = false;
        for(i = 0;i<n;i++){
            scanf("%d",&x);
            a.push_back(x);
        }
        for(i = 0;i<n-1;i++){
            s.push_back(abs(a[i+1]-a[i]));
        }
        sort(s.begin(),s.end());

            it = s.begin();
            for(i = 0;i<n-1;i++){
            if(*it!=i+1){
                b = true;
                break;
            }
            it++;
            }
            if(b == false||n ==1)
            cout<<"Jolly"<<endl;

            else cout<<"Not jolly"<<endl;
        s.clear();
        a.clear();
    }
    return 0;
}
