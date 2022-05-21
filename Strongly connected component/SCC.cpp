#include<bits/stdc++.h>
using namespace std;
vector<int>g[1000];
vector<int>rg[1000];
int st[100];
int ed[100];
int t=1;
stack<int>stk;
int vis[100];
int vis2[100];

void dfs(int u)
{

    st[u]=t;
    t++;
    vis[u]=1;
    for(int i=0; i<g[u].size(); i++)
    {
        int v = g[u][i];
        if(vis[v]==0)
        {
            dfs(v);
        }
    }
    ed[u] = t;
    t++;
    stk.push(u);
}

void dfs2(int u)
{

    vis2[u]=1;
    for(int i=0; i<rg[u].size(); i++)
    {
        int v = rg[u][i];
        if(vis2[v]==0)
        {
           dfs2(v);
        }
    }
}



int main()
{
    int i,j,m,n,a,b,v,u;
    int node, edge;
    cin>>node>>edge;
    for(i=0; i<edge; i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        rg[v].push_back(u);
    }
    for(i=1; i<=node; i++)
    {
        if(vis[i]==0)
        {
            dfs(i);
        }

    }

    int scc=0;
    while(!stk.empty())
    {
        cout<<"Top : "<<stk.top()<<endl;
        if(vis2[stk.top()]==0)
        {
            dfs2(stk.top());
            scc++;
        }
        stk.pop();
    }

    cout<<"Number of Strongly connected components are " <<scc<<endl;

}
