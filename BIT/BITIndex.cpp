#include<bits/stdc++.h>
using namespace std;
int tree[1000];

int query(int idx)
{
    idx= idx+1;
    int sum =0;
    while(idx>0)
    {
        sum+= tree[idx];
        idx-=(idx)&(-idx);
    }
    return sum;
}
void update(int index, int val, int n)
{
    index = index+1;
    while(index<=n)
    {
      tree[index]+= val;
      index+= (index)&(-index);
    }

}

int main()
{
    int i,j,m,n,a,b,x;
    cin>>n;
    for(i=0 ;i<n ; i++)
    {
        tree[i]= 0;
    }

    for(i=0; i<n; i++)
    {
       cin>>x;
       update(i,x,n);
    }
    cout<<"Enter range "<<endl;
    cin>>a>>b;
    cout<<(query(b)-query(a-1))<<endl;;
}

