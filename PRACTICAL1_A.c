#include <stdio.h>
void average(float *sum,float *avg,int n,int a[]){
    for (int i = 0; i < n; i++)
    {
        *sum+=a[i];
    }
    *avg=*sum/n;    
}
void display(int a[],int n){
    printf("Array : [ ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("]\n");
}
void reverse(int a[],int n){
    int tmp;
    for (int i = 0; i < (n/2); i++)
    {
        tmp=a[i];
        a[i]=a[n-i-1];
        a[n-i-1]=tmp;
    }    
}
void min_max(int a[],int n,int *min,int *max){
    *min=a[0],*max=a[0];
    for (int i = 0; i < n; i++)
    {
        if(*min>a[i]){
            *min=a[i];
        }
        if(*max<a[i]){
            *max=a[i];
        }
    }
}
void insert(int a[],int pos,int n,int element){
    for (int i = n-1; i >pos; i--)
    {
        a[i]=a[i-1];
    }
    
    a[pos]=element;
}
void delete(int a[],int pos,int n){
    for (int i = pos; i < n-1; i++)
    {
        a[i]=a[i+1];
    }
    a[n-1]=0;
    
}
int main()
{   int n=10,min=0,max=0;
    float sum=0,avg=0;
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    average(&sum,&avg,n,a);
    printf("Sum : %f \n",sum);
    printf("AVG : %f\n",avg);
    display(a,n);
    reverse(a,n);
    display(a,n);
    min_max(a,n,&min,&max);
    printf("Max Digit : %d \n",max);
    printf("Min Digit : %d \n",min);

    //remove element
    int pos=2; //2nd position
    delete(a,pos-1,n);
    display(a,n);
    
    
    //insert element at pos=2 ,999
    insert(a,pos-1,n,999);
    display(a,n);
    return 0;
}
