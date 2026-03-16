#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,long long>>>adj(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b;
        long long c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    vector<bool>used(n+1,false);
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
    pq.push({0,1});
    long long totalCost=0;
    int visitedCount=0;
    while(!pq.empty())
    {
        auto p=pq.top();
        pq.pop();
        long long cost=p.first;
        int u=p.second;
        if(used[u])
        {
            continue;
        }
        used[u]=true;
        totalCost+=cost;
        visitedCount++;
        for(auto edge:adj[u])
        {
            int v=edge.first;
            long long w=edge.second;
            if(!used[v])
            {
                pq.push({w,v});
            }
        }
    }
    if(visitedCount==n)
    {
        cout<<totalCost<<"\n";
    }
    else
    {
        cout<<"IMPOSSIBLE\n";
    }
    return 0;
}