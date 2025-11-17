#include<iostream>
using namespace std;
int main(){
    int arr[][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int arra[][3] = {11,2,3,4,5,6,77,8,9};
    cout<<arr[0][0]<<endl;
    cout<<arra[0][1]<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            arr[i][j]=arr[i][j]+arra[i][j];
        }
        
    }
     for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

}