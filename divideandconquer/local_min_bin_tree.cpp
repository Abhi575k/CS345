#include<bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;

int findMinNode(vector<int>&,int,int,int);
void solve(int);
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
    int res=findMinNode(a,n,-1,0);
    cout<<res<<"\n";
    //
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time Taken for TC "<<t<<": "<<(float)(duration.count())/1000000 << endl;
    return;
}

int findMinNode(vector<int> &a,int n,int x,int v){
    if((2*v+2)>n) return (int)1e9;
    if(a[v]<a[2*v+1]&&a[v]<a[2*v+2]&&(x==-1||a[v]<a[x])) return v;
    else{
        if(a[2*v+1]<a[2*v+2]) return findMinNode(a,n,a[2*v+1],2*v+1);
        else return findMinNode(a,n,a[2*v+2],2*v+2);
    }
}