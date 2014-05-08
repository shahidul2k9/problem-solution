#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main () {
  string sa,sb;
  int choice,i,size;
  vector <char> :: iterator it,end;
  while(cin>>sa){
      cin>>sb;
      vector <char> v(sb.begin(),sb.end());
      size = sa.size();
      i=0;
      end = v.end();
      it =v.begin();
      choice =0;
      while(i<size){
      it = find(it,end,sa.at(i));
      if(it==end){
      cout<<"No"<<endl;
      choice = 1;
      break;
      }
      it = it+1;
      i++;
      }
      if(choice == 0)cout<<"Yes"<<endl;
      v.clear();
  }

  return 0;
}
