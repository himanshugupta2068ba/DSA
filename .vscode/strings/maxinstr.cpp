#include<iostream>
#include<string>
using namespace std;
int main(){
    string arr[]={"1223","124542","3235","3352"};
    int max=stoi(arr[0]);
    for(int i=0;i<arr->size();i++){
        int x=stoi(arr[i]);
        if(x>max) max=x;
    }
    cout<<max;
}