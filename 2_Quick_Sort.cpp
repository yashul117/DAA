#include<bits/stdc++.h>
using namespace std;

int partition(int *arr,int s,int e)
{
    //inplace - so can't take extra array
    int pivot = arr[e];
    int i=s-1;
    for(int j=s;j<=e-1;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[e]);
    return (i+1);
}

void quickSort(int *arr,int s,int e)// nlogn - average case ; n^2 - worst case
{
    if(s<e)
    {
        int p=partition(arr,s,e);
        quickSort(arr,s,p-1);
        quickSort(arr,p+1,e);
    }

    return ;
}

void display(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
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
    quickSort(arr,0,n-1);
    display(arr,n);

    return 0;
}