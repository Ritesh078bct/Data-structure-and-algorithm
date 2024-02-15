#include<stdio.h>
void swap( int *a, int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int arr[],int p,int r){
    int x,i,j;
    x=arr[r];
    i=p-1;
    for(j=p;j<=r-1;j++){
        if(arr[j]<=x){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[r]);
    return i+1;
}

void quickSort(int arr[],int p,int r){
    int q;
    if(p<r){
        q=partition(arr,p,r);
        quickSort(arr,p,q-1);
        quickSort(arr,q+1,r);
    }

}

int main(){
    int arr[]={10,1,5,8,3,4,6},i,p,r;
    p=0;
    r=(sizeof(arr)/sizeof(int))-1;
    // printf("%d",r);
    quickSort(arr,p,r);
    for(i=0;i<=r;i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}