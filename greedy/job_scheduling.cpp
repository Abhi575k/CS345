#include<bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;

void solve(int);
bool comp(pair<int,int>&,pair<int,int>&);
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
    int n,res=0;
    cin>>n;
    vector<pair<int,int>> a;
    for(int i=0;i<n;i++){
        int strt,end;
        cin>>strt>>end;
        a.push_back({strt,end});
    }
    sort(a.begin(),a.end(),comp);
    int time=0;
    for(int i=0;i<n;i++){
        if(a[i].first>=time){
            res++;
            time=a[i].second;
        }
    }
    cout<<res<<"\n";
    //
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time Taken for TC "<<t<<": "<<(float)(duration.count())/1000000 << endl;
    return;
}

bool comp(pair<int,int>& a,pair<int,int>& b){
    if(a.second==b.second) return a.first>b.first;
    return a.second<b.second;
}