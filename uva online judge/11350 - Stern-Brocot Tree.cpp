#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>


using namespace std;
typedef long long int ll;
ll gcd(ll a, ll b){
    if(b == 0)return a;
    else return gcd( b, a%b);
}
struct Fraction{
    ll N;
    ll D;
    Fraction(){}
    Fraction(ll N, ll D){
        this->N = N;
        this->D = D;
    }
};

struct Node{
    Fraction left;
    Fraction right;
    Fraction root;
}T;

Fraction get(const Fraction lf, const Fraction rg){
    Fraction t = Fraction(lf.N + rg.N, lf.D + rg.D);
    ll m = gcd(t.N, t.D);
    t.N = t.N / m;
    t.D = t.D /m;
    return t;
}
int main()
{
 freopen("input.txt", "r", stdin);
    string s;
    int test;
    scanf("%d", &test);getline(cin, s);


    while(test--){

        getline(cin, s);
        T.left = Fraction(0,1);
        T.root = Fraction(1,1);
        T.right = Fraction(1,0);

        for(ll i = 0; i < s.size(); i++){
            if(s[i] == 'L'){
                T.right = T.root;
                T.root = get(T.left, T.root);
                T.left = T.left;

            }
            else{
                T.left = T.root;
                T.root = get(T.root, T.right);

                T.right = T.right;
            }
        }
        printf("%lld/%lld\n", T.root.N, T.root.D);


    }
    return 0;
}
