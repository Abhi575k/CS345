#include<bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;

void solve(int);
int dfs(vector<int>&,int,vector<bool>&);
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
    int n;
    cin>>n;
    vector<int> a(24,(int)1e9);
    for(int i=0;i<n;i++){
        int s,e;
        cin>>s>>e;
        int diff_prev=(a[s]-s+24)%24,diff_new=(e-s)%24;
        if(diff_prev==0) diff_prev=24;
        if(diff_new==0) diff_new=24;
        if(diff_new<diff_prev) a[s]=e;
    }
    int res=0;
    vector<bool> visited(24,false);
    for(int i=0;i<24;i++){
        if(visited[i]) continue;
        res=max(res,dfs(a,i,visited));
    }
    cout<<res<<"\n";
    //
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time Taken for TC "<<t<<": "<<(float)(duration.count())/1000000 << endl;
    return;
}

int dfs(vector<int>& a,int s,vector<bool>& visited){
    if(a[s]==(int)1e9){
        while(a[s]==(int)1e9){
            s++;
            s=s%24;
        }
    }
    if(visited[s]) return 0;
    visited[s]=true;
    return 1+dfs(a,a[s],visited);
}