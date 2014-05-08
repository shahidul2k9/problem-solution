#include <iostream>
#include <map>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    /*
    Time limit Exceedee

    map <char, int> m;
    map <char, int> ::iterator it;
    map <char, int> ::iterator be;
    map <char, int> ::iterator en;
    int TC,k,nl,i;
    double t;
    string line;
    char ch;
    cin >> TC;

    while(TC--){
        cin >> k;
        ch = getchar();
        for(i=0;i<k;i++){
        ch = getchar();
        cin >> t;
        m[ch]=t;
        ch = getchar();
        }
        cin >> nl;
        ch = getchar();
        be = m.begin();
        en = m.end();
        t = 0;
        for(i=0;i<nl;i++){
            getline(cin,line);
           // vector <char> v(line.begin(),line.end());
            for(it=be;it!=en;it++){
                t = t + count(line.begin(),line.end(),((*it).first))*(*it).second;
            }
        }
        printf("%.2lf$\n",t/100);
        m.clear();

    }*/
    map <char, int> m;

    int TC,k,nl,i;
    double t;
    string line;
    char ch;
    cin >> TC;

    while(TC--){
        cin >> k;
        ch = getchar();
        for(i=0;i<k;i++){
        ch = getchar();
        cin >> t;
        m[ch]=t;
        ch = getchar();
        }
        cin >> nl;
        ch = getchar();
        t = 0;
        for(i=0;i<nl;i++){
            getline(cin,line);
           int length = line.length();
            for(k=0;k<length;k++)
                t =t +m[line[k]];
        }
        printf("%.2lf$\n",t/100);
        m.clear();
    }
    return 0;
}
