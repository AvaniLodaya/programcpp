//Find the largest palindrome made from the product of two 3-digit numbers.
#include<iostream>
using namespace std;
long int reverse(long int input_li){

    long int temp=0;
    while(input_li!=0)
    {
    
        temp=temp*10+input_li%10;
        input_li/=10;
    }
    //cout<<"\n"<<temp<<endl;
    return temp;
    
}
int main(){
    long int pal=0;
    for(int i=999;i>=100;i--){
        for(int j=999;j>=100;j--)
        {
            long int k=i*j;
            if (k==reverse(k)){
     
                pal=(pal>k)?pal:k;
            }
        }
    }
    cout<<pal;
    return 0;
}
