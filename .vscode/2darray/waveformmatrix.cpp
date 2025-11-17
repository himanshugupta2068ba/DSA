#include<iostream>
using namespace std;
int main(){
     int a;
    cout<<"enter number of rows for 1st matrix";
    cin>>a;
    int b;
    cout<<"enter number of columns for 1st matrix";
    cin>>b;
    int arr1[a][b];
    cout<<"enter element in 1st matrix";
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin>>arr1[i][j];
        }
    }
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cout<<arr1[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<a;i++){
        if(i%2!=0){
                
                for(int k=b-1;k>=0;k--){
                    cout<<arr1[i][k]<<" ";

                }
                
            }
            else{
        for(int j=0;j<b;j++){
            cout<<arr1[i][j]<<" ";
            
        }
    }
    }
}