#include <cstdio>
#include <cmath>
#include <climits>
#include <iostream>
#include <string.h>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <bitset>
#include <sstream>
#include <set>
#include <map>
using namespace std;
#define ifor( i, L, U ) for(int i=(int)L ; i<=(int)U ; i++ )
#define dfor( i, U, L ) for(int i=(int)U ; i>=(int)L ; i-- )

#define SQR(x) ((x)*(x))
#define INF INT_MAX
#define EPS 1e-9
#define PI (2*acos(0.0))
#define SZ size()

#define READ(filename)  freopen(filename, "r", stdin);
#define WRITE(filename)  freopen(filename, "w", stdout);

typedef long long ll;
typedef vector<char> vc;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<vector<int> > vvi;
typedef pair<int, int> ii;
typedef map<int, int> mii;
typedef map<string, int> msi;
typedef map<string, char> msc;
typedef vector<vector<ii>  > vvii;
#define WHITE 0
#define GRAY 1
#define BLACK 2

int main()
{
    READ("input.txt");
    //WRITE("output.txt");
    bool one,two,three,four,five,six;
    string s;
    int len;
    while(cin>>s){
        len = s.length();
        one=two=three=four=five=six = true;
        ifor(i,0,len-1){
            switch(s[i]){
                case 'B':
                case 'F':
                case 'P':
                case 'V':
                    if(one){
                        printf("1");
                        one=two=three=four=five=six = true;
                        one = false;
                    }
                    break;
                case 'C':
                case 'G':
                case 'J':
                case 'K':
                case 'Q':
                case 'S':
                case 'X':
                case 'Z':
                    if(two){
                        printf("2");
                        one=two=three=four=five=six = true;
                        two = false;
                    }
                    break;
                case 'D':
                case 'T':
                    if(three){
                        printf("3");
                        one=two=three=four=five=six = true;
                        three = false;
                    }
                    break;
                case 'L':
                    if(four){
                        printf("4");
                        one=two=three=four=five=six = true;
                        four = false;
                    }
                    break;
                case 'M':
                case 'N':
                    if(five){
                        printf("5");
                        one=two=three=four=five=six = true;
                        five = false;
                    }
                    break;
                case 'R':
                    if(six){
                        printf("6");
                        one=two=three=four=five=six = true;
                        six = false;
                    }
                    break;
                default :
                    one=two=three=four=five=six = true;
                    break;

                }
        }
        printf("\n");
    }
    return 0;
}
