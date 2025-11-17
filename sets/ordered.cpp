#include<iostream>
#include<set>
using namespace std;
int main(){
    set<int>s;
    s.insert(5);
    s.insert(3);
    for(int ele:s){
        cout<<ele<<" ";
    }
}
//orders set take logn t.c but unorderd take o(1)