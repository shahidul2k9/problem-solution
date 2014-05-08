#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define INSERT_LEFT 'l'
#define INSERT_RIGHT 'r'
#define NONE 'x'
int memo[1000][1000];
char track[1000][1000];

char text[1001];

int minCost(int i, int j){
    if(i >= j) return 0;
    if(memo[i][j] != -1) return memo[i][j];
    if(text[i] == text[j]){
        track[i][j] = NONE;
        return memo[i][j] = minCost(i + 1, j - 1);
    }
    int a = minCost(i+1, j);
    int b = minCost(i, j-1);
    if(a < b) {
        track[i][j] = INSERT_RIGHT;
        return memo[i][j] = a  + 1;
    }
    track[i][j] = INSERT_LEFT;
    return memo[i][j] = b + 1;

}
void construct(int i, int j){
    char left[1001];
    int pos = 0;
    while(i < j){
        if(track[i][j] == NONE){
            putchar(text[i]);
            left[pos++] = text[i];
            i++;j--;
        }
        else if(track[i][j] == INSERT_RIGHT){
            putchar(text[i]);
            left[pos++] = text[i];
            i++;
        }
        else{
            putchar(text[j]);
            left[pos++] = text[j];
            j--;
        }
    }

    if(i == j)putchar(text[i]);
    for(int i = pos-1; i>= 0; i--)putchar(left[i]);
    puts("");
}
int main(){

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int len;
    while(gets(text)){

        len = strlen(text);
        memset(memo, -1, sizeof(memo));


        printf("%d ", minCost(0,len-1));
        construct(0, len-1);

    }
}
