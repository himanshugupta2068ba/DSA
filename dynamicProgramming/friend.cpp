//there are n friends thay have to go on party they can go inpair or single findthe number of ways they can go to party
#include <iostream>
using namespace std;

int countway(int n){
    if(n==1) return 1; 
    if(n==2) return 2; 
    return countway(n-1) + (n-1)*countway(n-2);
}

int main(){
    return 0;
}