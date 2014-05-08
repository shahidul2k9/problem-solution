#include <iostream>
#include <map>
#include <stdio.h>
#include <vector>
using std :: cout;
using std :: cin;
using namespace std;

int main()
{
    map <int,int> m;
    vector <int> v;
    int num,size,i;
    while(std::cin>>num){
        if(m.find(num)==m.end()){
            m[num] = 1;
            v.push_back(num);
            }
        else m[num] = m[num]+1;
    }
    size = v.size();
    for(i=0;i<size;i++)
    std::cout<<v[i]<<" "<<m[v[i]]<<endl;
    v.clear();
    m.clear();

    return 0;
}
