//What is the largest prime factor of the number 600851475143 ?
#include<iostream>
using namespace std;
int primefactor(long int num_li){
    long int maxp=0;
    for(int i=2;i<=num_li;i++){
        
        while(num_li%i==0){
            num_li/=i;
            //cout<<i<<" ";
            maxp=i;
        }
    }
    return maxp;
}
int main(){
    cout<<"\n"<<primefactor(600851475143);
    return 0;
}
    