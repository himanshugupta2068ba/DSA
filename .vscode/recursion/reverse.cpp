#include<iostream>
using namespace std;
int reverse(int n,int s=0){
    if(n==0) return s;
     s=s*10+n%10;
     return reverse(n/10,s);
     

}
int main(){
    cout<<reverse(2345,0);
}
