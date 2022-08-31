#include<bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;

void solve(int);
void dfs(int,int,vector<pair<int,int>>[],int&,int,vector<bool>);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++) solve(i);
    return 0;
}
void solve(int t){
    auto start = high_resolution_clock::now();
    //  Your code here
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> adj[n];
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        adj[u].push_back({v,w});
    }
    int s,d;
    cin>>s>>d;
    s--,d--;
    int res=0;
    vector<bool> visited(n,false);
    // dfs(s,d,adj,res,(int)1e9,visited);
    vector<int> dist(n,(int)1e9);
    priority_queue<int> q;
    q.push(s);
    dist[s]=0;
    while(!q.empty()){
        int x=q.top();
        q.pop();
        for(auto u:adj[x]){
            q.push(u.first);
            dist[u.first]=min(dist[u.first],dist[x]+u.second);
        }
    }
    cout<<dist[d]<<"\n";
    //
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time Taken for TC "<<t<<": "<<(float)(duration.count())/1000000 << endl;
    return;
}

void dfs(int s,int d,vector<pair<int,int>> adj[],int& res,int temp,vector<bool> visited){
    if(s==d){
        res=max(res,temp);
        return;
    }
    if(visited[s]) return;
    visited[s]=true;
    for(auto u:adj[s]){
        if(!visited[u.first]){
            int tmp=min(temp,u.second);
            dfs(u.first,d,adj,res,tmp,visited);
        }
    }
    return;
}