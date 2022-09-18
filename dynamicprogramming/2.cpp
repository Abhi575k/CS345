#include<bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;

void solve(int);
int createDP(vector<int>&,vector<int>&,int,vector<int>&,int);
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
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> dp_incl(n,-1),dp_excl(n,-1);
    createDP(dp_incl,dp_excl,n-1,a,(int)1e9);
    cout<<max(dp_incl[n-1],dp_excl[n-1])<<"\n";
    //
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time Taken for TC "<<t<<": "<<(float)(duration.count())/1000000 << endl;
    return;
}

int createDP(vector<int> &dp_incl,vector<int> &dp_excl,int x,vector<int> &a,int prev){
    if(x==0){
        if(a[x]<=prev){
            if(dp_incl[x]==-1) dp_incl[x]=1;
            return dp_incl[x];
        }else{
            if(dp_excl[x]==-1) dp_excl[x]=0;
            return dp_excl[x];;
        }
    }
    if(a[x]<=prev){
        if(dp_incl[x]==-1) dp_incl[x]=1+createDP(dp_incl,dp_excl,x-1,a,a[x]);
    }
    if(dp_excl[x]==-1) dp_excl[x]=createDP(dp_incl,dp_excl,x-1,a,prev);
    return max(dp_incl[x],dp_excl[x]);
}