#include<bits/stdc++.h>
using namespace std;

void merge(int *a,int s,int e)
{
    int mid=(s+e)/2;
    int i=s;
    int j=mid+1;
    int k=s;

    int temp[100];
    while(i<=mid and j<=e)
    {
        if(a[i]<a[j])
        {
            temp[k++]=a[i++];
        }
        else
        {
            temp[k++]=a[j++];
        }
    }

    while(i<=mid)
    {
        temp[k++]=a[i++];
    }
    while(j<=e)
    {
        temp[k++]=a[j++];
    }

    //copy all elements to original array
    for(int i=s;i<=e;i++)
    {
        a[i]=temp[i];
    }
}

void mergeSort(int a[],int s,int e)//time comp. O(n*logn) , space comp. O(n)
{
    //base case - 1 or 0 elements
    if(s>=e)
    {
        return ;
    }

    //3 steps

    //1. divide
    int mid=(s+e)/2;

    //2. sort
    mergeSort(a,s,mid);
    mergeSort(a,mid+1,e);

    //3, merge two parts
    merge(a,s,e);
}

void display(int *a,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    display(arr,n);
    mergeSort(arr,0,n-1);
    display(arr,n);

    return 0;
}