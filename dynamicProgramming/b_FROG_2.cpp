#include <bits/stdc++.h>
using namespace std;

vector<int> h;
int n, k;

int f(int i){
    if(i == n-1) return 0;

    int ans = INT_MAX;
    for(int j = 1; j <= k; j++){
        if(i + j < n){
            ans = min(ans, abs(h[i] - h[i+j]) + f(i+j));
        }
    }
    return ans;
}

int main(){
    cin >> n >> k;
    h.resize(n);
    for(int i = 0; i < n; i++) cin >> h[i];

    cout << f(0) << endl;
    return 0;
}
