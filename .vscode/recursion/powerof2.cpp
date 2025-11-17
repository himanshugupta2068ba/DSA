#include<iostream>
using namespace std;
bool powerof2(int n){
    if(n==1) return true;
    if(n%2!=0) return false;
    if(powerof2(n/2)==true) return true;
    return false;
}
int main(){
    if(powerof2(24)) cout<<"yes";
    else cout<<"no";
}