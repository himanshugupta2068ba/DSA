#include<iostream>
using namespace std;
int  sumofdigit(int n,int sum){
    if(n==0) return sum;
    // int sum=0;
    sum+=n%10;
    return sumofdigit(n/10,sum);
}
int main(){
    cout<<sumofdigit(44323,0);
}