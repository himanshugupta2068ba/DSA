#include<iostream>
using namespace std;
void greet(int n){
    if(n>0)
    cout<<"hello";
    greet(n-1);
}
int product(int a, int b){
    int n;
    cout<<"enter n";
    cin>>n;
    greet(n);
    return a*b;
    
}
int main(){
    int a=3;
    int b=2;
    cout<<product(a,b);
}