#include<stdio.h>
long long int ans=0;
void merge(long long int array[],long long int l,long long int mid,long long int r)
{
    long long int i=0,j=0,k;
    long long int n1=mid-l+1,n2=r-mid;
    long long int left[n1];
    long long int right[n2];
    for(long long int i=0;i<n1;i++)
    {
        left[i]=array[l+i];
 //       printf("%lld ",left[i]);
    }
//  printf("                     ");
    for(long long int j=0;j<n2;j++)
    {
        right[j]=array[mid+j+1];
//        printf("%lld ",right[j]);
    }
    i=0,j=0;
    for(k=l;i<n1 && j<n2;k++)
    {
        if(left[i]<=right[j])
            array[k]=left[i++];
        else
        {
            array[k]=right[j++];
            ans+=n1-i;
        }
    }
    for(;i<n1;i++)
        array[k++]=left[i];
    
    for(;j<n2;j++)
        array[k++]=right[j];
}
void sort(long long int array[],long long int l,long long int r)
{
    if(l<r)
    {
        long long int mid=l+(r-l)/2;
        sort(array,l,mid);
        sort(array,mid+1,r);
        merge(array,l,mid,r);
    }
}
int main()
{
    long long int n;
    scanf("%lld",&n);
    long long int array[n];
    for(long long int i=0;i<n;i++)
        scanf("%lld",&array[i]);
    sort(array,0,n-1);
    /*for(long long int i=0;i<n;i++)
        prlong long intf("%d ",array[i]);
    prlong long intf("\n");
    */
    printf("%lld\n",ans);
}