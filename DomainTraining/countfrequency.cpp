#include<iostream>
#include<vector>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,1,2,4,4,5,5,7,5,6,3,5,4,6,4,2,6,7,5,5,4,3,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<n<<endl;
    vector<int>v(10,0);
    for(int i=0;i<n;i++){
         v[arr[i]]++;
    }
    for(int i=0;i<10;i++){
        cout<<v[i];
    }
}