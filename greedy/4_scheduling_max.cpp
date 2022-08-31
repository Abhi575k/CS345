#include<bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;

void solve(int);
bool comp(pair<int,int> &a,pair<int,int> &b){
    return (b.second*a.first)<(a.second*b.first);
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
        int t,w;
        cin>>t>>w;
        a.push_back({t,w});
    }
    sort(a.begin(),a.end(),comp);
    int res=0,scale=0;
    for(int i=0;i<n;i++){
        cout<<a[i].first<<" "<<a[i].second<<"\n";
        res+=(scale+a[i].first)*a[i].second;
        scale+=a[i].first;
    }
    cout<<res<<"\n";
    //
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time Taken for TC "<<t<<": "<<(float)(duration.count())/1000000 << endl;
    return;
}