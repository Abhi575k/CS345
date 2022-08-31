#include<bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;

void solve(int);
void dfs(int,int,vector<pair<int,int>>[],vector<int>&,vector<int>,vector<bool>,int&,int);
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
    vector<int> path;
    int path_wt=0;
    vector<bool> visited(n,false);
    cin>>s>>d;
    s--,d--;
    dfs(s,d,adj,path,{s},visited,path_wt,0);
    int o=path.size();
    if(o==0){
        cout<<"-1\n";
    }else{
        cout<<o<<"\n";
        for(int i=0;i<o;i++) cout<<path[i]+1<<" ";
        cout<<"\n";
    }
    //
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time Taken for TC "<<t<<": "<<(float)(duration.count())/1000000 << endl;
    return;
}

void dfs(int s,int d,vector<pair<int,int>> adj[],vector<int>& path,vector<int> temp,vector<bool> visited,int &path_wt,int temp_wt){
    if(s==d){
        // int m=temp.size();
        // cout<<m<<"\n";
        // for(int i=0;i<m;i++) cout<<temp[i]<<" ";
        // cout<<"\n";
        if(temp.size()<path.size()||path.size()==0){
            path=temp;
            path_wt=temp_wt;
        }else{
            if(temp.size()==path.size()){
                if(temp_wt<path_wt){
                    path=temp;
                    path_wt=temp_wt;
                }
            }
        }
        return;
    }
    if(visited[s]) return;
    visited[s]=true;
    for(auto u:adj[s]){
        temp.push_back(u.first);
        temp_wt+=u.second;
        dfs(u.first,d,adj,path,temp,visited,path_wt,temp_wt);
        temp.pop_back();
        temp_wt-=u.second;
    }
    return;
}