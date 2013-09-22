//here exists exactly one Pythagorean triplet for which a + b + c = 1000.
//Find the product abc.
// (2m,m^2-1,m^2+1), 
#include<iostream>
using namespace std;
int main(){
//i=5;j=1,2
//u=4,3
//v=1,2,

    for(int i=1;i<100;i++){
        for(int j=1;j<=i/2;j++){
            int u= i-j;
            int v=j;
            if(((2*u)*(v+u))==1000)
            {
                cout<<v<<" "<<u<<">>";
            }
        }
    }
            
    return 0;
}