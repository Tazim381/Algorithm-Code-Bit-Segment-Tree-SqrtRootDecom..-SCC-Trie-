#include<bits/stdc++.h>
using namespace std;
int tree[1000000];
int arr[1000000];

int query(int n, int b, int e,int l , int r)
{
    if(l>e||r<b)
    {
        return INT_MAX;
    }
    if(b>=l && e<=r)
    {
        return tree[n];
    }
    int mid = (b+e)/2;
    int left = 2*n;
    int right = 2*n+1;

    int p = query(left,b,mid,l,r);
    int q = query(right,mid+1,e,l,r);
    return min(p,q);

}

void buildtree(int n, int b, int e)
{
    if(e==b)
    {
        tree[n]= arr[e];
        return;
    }
    int mid =(e+b)/2;
    int left = 2*n;
    int right = 2*n+1;
    buildtree(left,b,mid);
    buildtree(right,mid+1,e);
    tree[n] = min(tree[left],tree[right]);

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,m,n,q,a,b,x=0;
    int t;
    cin>>t;
    while(t--)
    {
        x++;


    cin>>n>>q;
    for(i=1; i<=n ;i++)
    {
        cin>>arr[i];
    }
    buildtree(1,1,n);
    cout<<"Case "<<x<<":"<<endl;
    for(i=1; i<=q; i++)
    {
        cin>>a>>b;
        cout<<query(1,1,n,a,b)<<endl;
    }



    }
}
