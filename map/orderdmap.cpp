//ordered map
#include<iostream>
#include<map>
using namespace std;
int main(){
map<int,int>m;
m[2]=30;
m[1]=20;
for(auto x :m){
    cout<<x.first<<" ";
}
//ist 1 key print then second key not matter of value or insertion
}