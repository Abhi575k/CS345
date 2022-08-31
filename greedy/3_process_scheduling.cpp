#include<bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;

void solve(int);
bool comp(pair<int,int>& a,pair<int,int>& b){
    if(a.first==b.first) return a.second>b.second;
    return a.first>b.first;
}
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
    vector<pair<int,int>> a;
    for(int i=0;i<n;i++){
        int p,f;
        cin>>p>>f;
        a.push_back({p,f});
    }
    sort(a.begin(),a.end(),comp);
    int res=0,prev=0;
    for(int i=0;i<n;i++){
        res=max(res,prev+a[i].first+a[i].second);
        prev+=a[i].first;
    }
    cout<<res<<"\n";
    //
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time Taken for TC "<<t<<": "<<(float)(duration.count())/1000000 << endl;
    return;
}