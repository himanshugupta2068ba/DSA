#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main(){
    vector<int>v(5);
    for( int i=0;i<5;i++){
        cin>>v[i];
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5-i-1;j++){
           if(v[j]>v[j+1])
            swap(v[j],v[j+1]);
        }
    }
    for( int i=0;i<5;i++){
        cout<<v[i]<<" ";
    }
}