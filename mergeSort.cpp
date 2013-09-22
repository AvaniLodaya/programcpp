#include<iostream>
using namespace std;
int a[20];
void merge( int, int, int);
void merge_sort(int low,int high){
    if(low<high){
        int mid;
        mid=(low+high)/2;
        merge_sort(low,mid);
        merge_sort(mid+1,high);
        merge(low,mid,high);
    }
}
void merge(int low, int mid, int high){

    int h,i,j,k,b[20];
    h=low;
    i=low;
    j=mid+1;

    while((h<=mid)&&(j<=high)){
    
        if(a[h]<=a[j])
        {
            b[i]=a[h];
            h++;
        }
        else{
            b[i]=a[j];
            j++;
        }
        i++;
    }
    if(h>mid){
    
        for(k=j;k<=high;k++){
            b[i++]=a[k];
        }
    }
    else{
        for(k=h;k<=mid;k++)
        {       b[i++]=a[k];
    
        }
    }
    for(k=low;k<=high;k++)
        a[k]=b[k];
}

int main(){
 
    int num,i;
    cout<<"\nEnter the number of elements you want to sort ";
    cin>>num;
    cout<<"\nNow enter the elements\n";
    for(i=0;i<num;i++){
        cin>>a[i];
    }
    merge_sort(0,num-1);
    cout<<"\nSorted list\n";
    for(i=0;i<num;i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    return 0;
}

