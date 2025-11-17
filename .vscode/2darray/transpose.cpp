#include<iostream>
using namespace std;
int main(){
    int n;
    int m;
   
    cout<<"enter number of rows";
    cin>>n;
    cout<<"enter number of coloumn";
    cin>>m;
    cout<<"enter elementin matrix";
     int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
        
    }
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           cout<<arr[i][j]; 
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
           cout<<arr[j][i]; 
        }
        cout<<endl;
    }
}