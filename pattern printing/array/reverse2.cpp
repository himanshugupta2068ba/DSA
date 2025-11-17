#include<bits/stdc++.h>
using namespace std;
int main(){
int x;
cout<<"eneter number want to reverse";
cin>>x;
int rem, rev=0;
for(int i=x;i!=0;i=i/10){
    rem=i%10;
    rev=(rev*10)+rem;
}
cout<<rev;
}