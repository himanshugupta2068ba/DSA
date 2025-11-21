#include<iostream>
#include<queue>
using namespace std;

int main(){
    priority_queue<int>hp;//max heap
    priority_queue<int,vector<int>,greater<int>>lp;//min heap
    hp.push(10);
    hp.push(5);
    hp.push(20);
    while(!hp.empty()){
        cout<<hp.top()<<" ";
        hp.pop();
    }
    cout << endl;
    lp.push(10);
    lp.push(5);
    lp.push(20);
    while(!lp.empty()){
        cout<<lp.top()<<" ";
        lp.pop();
    }
    vector<int> arr={15,10,8,12,20,5};
    priority_queue<int>pq(arr.begin(),arr.end());
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    int arr2[]={7,2,9,1,6,3};
    priority_queue<int,vector<int>,greater<int>>pq2(arr2,arr2+6);
    while(!pq2.empty()){
        cout<<pq2.top()<<" ";
        pq2.pop();
    }  
    cout<<endl;
    return 0;
}