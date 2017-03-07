#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

typedef priority_queue <int> mib;
mib high, low;

int main() {
 bool off;
    int sum = 0, num;
    //maintain two heaps, low can have one more than high heap. return max from low heap
    while(scanf("%d", &num) != EOF) {
        if((int)high.size() == (int)low.size()) //have to insert in low
            low.push(num);
        else //insert in high
           high.push(-num);
        if(high.size() && -high.top() < low.top()) {
            num = -high.top();
            high.pop();
            high.push(-low.top());
            low.pop();
            low.push(num);
        }
        //cout << "Median: " << low.top() << endl;
        sum = (sum + low.top()) % 10000;
        
    }
    cout << sum << endl;
    
    return 0;
}