#include<iostream>
using namespace std;
int main(){
    int x;
    cout<<"enter number x";
    cin>>x;
    cout<<"enter value in x";
    int a[10];
    for(int i=0;i<10;i++){
        cin>>a[i];
    }
    for(int i=0;i<10;i++){
        if(a[i]>x){
            cout<<a[i];
        }
        cout<<endl;
    }
}