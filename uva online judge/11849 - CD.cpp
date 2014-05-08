// set_union example
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector <int> VI;
int main () {
  int m,n,i,x;
  VI a,b;
  vector<int> v(2000000);
  vector<int>::iterator it;
  cin >> m >> n;
  while(m!=0&&n!=0){
      for(i = 0; i<m;i++) {cin >> x;a.push_back(x);}
      for(i = 0; i<n;i++) {cin >> x;b.push_back(x);}
      //sort (a.begin(),a.end());
      //sort (b.begin(),b.end());
      it=set_intersection(a.begin(), a.end(), b.begin(), b.end(), v.begin());
      cout << int(it - v.begin()) << endl;
      cin >> m >> n;
      a.clear();
      b.clear();
      v.clear();
  }

  return 0;
}
