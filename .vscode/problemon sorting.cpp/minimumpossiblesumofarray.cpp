//form 2 numbers from all valye of array and find minimum possible sum of array
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
      cout<<"Enter the size of array";
    cin>>n;
    vector<int>v(n);
      vector<int>v1(n);
  
    cout<<"Enter the elements of array";
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        v1[i]=v[i];
    }
    for(int i=n-1;i>0;i--){
        if(v[i-1]!=v[i]){
            swap(v[i-1],v[i]);
            break;
        }
    }
    // swap(v[n-1],v[n-2]);
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<v1[i]<<" ";
    }
    cout<<endl;
   int n1=0;
   int n2=0;
   int j=1;
   string s1="";
   string s2="";
   for(int i=0;i<n;i++){
    //    n1+=v[i]*j;
    //    n2+=v1[i]*j;
    //      j*=10;
    s1+=to_string(v[i]);
    s2+=to_string(v1[i]);
   }
//    s1.reserve();
   n1=stoi(s1);
   n2=stoi(s2);
   cout<<n1<<" "<<n2<<endl;
    cout<<n1+n2;
     return 0;
    
}