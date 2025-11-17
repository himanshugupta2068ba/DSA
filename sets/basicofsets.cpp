#include<iostream>
#include<unordered_set>
using namespace std;
int main(){
    unordered_set<int>s;
    s.insert(1);
    s.insert(12);
    s.insert(3);
    s.insert(4);
    //s.find()->it searches in the set,and if it is not found then return the last element
    // we use
    int target=2;
    if(s.find(target)!=s.end()){
        cout<<"exist";
    }
    for(int ele:s){
        cout<<ele<<endl;
    }
}