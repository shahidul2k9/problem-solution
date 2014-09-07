#include <iostream>
#include <deque>
#include <map>
#include <cstdio>
using namespace std;

int main() {
    // freopen("input.txt","r",stdin);
    int test, ctc = 1, val, n, ins, i, id=0;
    string com;
    map<string,int> m;
    m["pushLeft"] = id++;
    m["pushRight"] = id++;
    m["popLeft"] = id++;
    m["popRight"] = id++;
    deque<int>q;
    scanf("%d",&test);
    while(test--) {
        q.clear();
        printf("Case %d:\n", ctc++);
        scanf("%d %d",&n,&ins);
        for(i = 0; i<ins; i++) {
            cin >> com;
            switch(m[com]) {
            case 0:
                cin >> val;
                if(q.size()==n)printf("The queue is full\n");
                else q.push_front(val), printf("Pushed in left: %d\n", val);
                break;
            case 1:
                cin >> val;
                if(q.size()==n)printf("The queue is full\n");
                else q.push_back(val), printf("Pushed in right: %d\n",val);
                break;
            case 2:
                if(q.empty())printf("The queue is empty\n");
                else printf("Popped from left: %d\n",q.front()),q.pop_front();
                break;
            case 3:
                if(q.empty())printf("The queue is empty\n");
                else printf("Popped from right: %d\n",q.back()),q.pop_back();
                break;
            default:
                break;
            }
        }
    }
    return 0;
}
