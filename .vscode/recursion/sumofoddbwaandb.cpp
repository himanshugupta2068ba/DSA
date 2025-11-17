#include<iostream>
using namespace std;
void oddsum(int a,int b,int &sum){
    // int sum=0;
    if(a>b) return ;
    if(a%2!=0) {
       sum+=a;
       oddsum(a+2,b,sum);
    }
     else oddsum(a+1,b,sum);
    // return sum;
}
int main(){
    int sum=0;
    oddsum(1,9,sum);
    cout<<sum;
}