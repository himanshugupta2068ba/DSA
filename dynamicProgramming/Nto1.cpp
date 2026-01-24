// given a no n, yo can perform 3 operation in it divide by 2, divide by 3, or subtract by 1 . find out no of steps to rweduce n to 1
#include<iostream>
#include<bits/stdc++.h>
#define inf INT_MAX
using namespace std;
vector<int>dp;
 int ftd(int n){
    if(n==0)  return 0;
    if(n==2 or n==3) return 1;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=1+min({ftd(n-1),(n%2==0)?ftd(n/2):inf,(n%3==0)?ftd(n/3):inf});
 }
 int fbd(int n){
    dp.clear();
    dp.resize(n+1,-1);
    dp[1]=0;
    dp[2]=dp[3]=1;
    for(int i=4;i<=n;i++){
            return dp[i]=1+min({dp[i-1],(i%2==0)?dp[i/2]:inf,(i%3==0)?dp[i/3]:inf});
    }
    cout<<dp[n];
return dp[n];
 }
 int main(){
    dp.clear();
    int n;
    cin>>n;
    dp.resize(1005,-1);
    cout<<fbd(n);
    return 0;
 }