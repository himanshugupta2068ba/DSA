#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(pair<int,int>&p1,pair<int,int>&p2){
    double r1=(double)p1.first/p1.second;
    double r2=(double)p2.first/p2.second;
    return r1>r2;
}
//W: capacity of knapsack
//n: number of items
//profit: array of profits
//weights: array of weights
double fractionalKnapsack(vector<int>&profit,vector<int>&weights,int n,int W){
    vector<pair<int,int>> items;
    for(int i=0;i<n;i++){
        items.push_back({profit[i],weights[i]});
    }
    sort(items.begin(),items.end(),cmp);
    double totalProfit=0.0;
    for(int i=0;i<n;i++){
        if(W==0) break;
        if(items[i].second<=W){
            totalProfit+=items[i].first;
            W-=items[i].second;
        }else{
            totalProfit+=items[i].first*((double)W/items[i].second);
            W=0;
        }
    }
    return totalProfit;
}

int main(){
    vector<int> profit={60,100,120};
    vector<int> weights={10,20,30};
    int W=50;
    int n=profit.size();
    double maxProfit=fractionalKnapsack(profit,weights,n,W);
    cout<<"Maximum profit in Knapsack = "<<maxProfit<<endl;
    return 0;
}