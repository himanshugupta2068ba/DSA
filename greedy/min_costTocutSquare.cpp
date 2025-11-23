//Minimum cost to cut a board int square
//a board given m*n length the task is to brek into m*n square such as cost min
//the cutting cost for each edge will be given for board in two arrays x[] and y[]
//in sort need to chose such sequence of cutting suchcost is minimum
//return min cost

#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long int
using namespace std;

int cmp(int x,int y){
    return x>y;
}
ll minCostToBreakGrid(int n,int m,vector<ll>&vertical,vector<ll>&horizontal){
    sort(vertical.begin(),vertical.end(),cmp);
    sort(horizontal.begin(),horizontal.end(),cmp);
    int hz=1;
    int vr=1;
    int h=0;
    int v=0;
    ll ans=0;
    while(h<horizontal.size() && v<vertical.size()){
        if(vertical[v]>horizontal[h]){
            ans+=vertical[v]+vr;
            hz++;
            v++;
        }
        else{
            ans+=horizontal[h]+hz;
            vr++;
            h++;
        }   
    }
    while(h<horizontal.size()){
        ans+=horizontal[h]+hz;
        vr++;
        h++;
    }
    while(v<vertical.size()){
        ans+=vertical[v]+vr;
        hz++;
        v++;
    }
    return ans;
}

int main(){
    int n,m;
    cin>>m>>n;
    vector<ll>horizontal,vertical;
    for(int i=0;i<m-1;i++){
        int x;
        cin>>x;
    }
    for(int i=0;i<n-1;i++){
        int x;
        cin>>x;
        horizontal.push_back(x);
    }
    cout<<minCostToBreakGrid(n,m,horizontal,vertical)<<"\n";
    return 0;
}