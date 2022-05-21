
#include<bits/stdc++.h>
using namespace std;
int segment[1000];

void preprocess(int arr[], int n)
{
    int currentsegemnt=-1;
    int segment_size=sqrt(n);
    for(int i=0; i<n; i++)
    {
        if(i%segment_size ==0)
        {
            currentsegemnt++;
        }
        segment[currentsegemnt]+= arr[i];
    }
}

int query(int arr[],int n, int l, int r)
{
    int sum=0;
    int segment_size = sqrt(n);

    while(l<r&& l%segment_size!=0)
    {
        sum+=arr[l];
        l++;
    }
    while(l+segment_size<=r)
    {
        sum+= segment[l/segment_size];
        l=+ segment_size;
    }
    while(l<=r)
    {
        sum+= arr[l];
        l++;
    }

    return sum;

}

int main()
{
    int i,j,m,n;

    cin>>n;
    int arr[n+10];
    for(i=0; i<n; i++)
        cin>>arr[i];

    preprocess(arr,n);

    cout<<query(arr,n,0,2);


}
