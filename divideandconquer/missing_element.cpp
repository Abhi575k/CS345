#include<bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;

int findMissing(vector<int>&,int,int,int,int);
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
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int res=findMissing(arr,0,n-1,arr[0],arr[1]-arr[0]);
    cout<<res<<"\n";


    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time Taken for TC "<<t<<": "<<(float)(duration.count())/1000000 << endl;
    return;
}

int findMissing(vector<int>& arr,int l,int r,int a,int d){
    if(l>r) return -1;
    if(l==r) return arr[l];
    int mid=(l+r)/2;
    if(mid+1<=r&&arr[mid+1]-arr[mid]>d) return arr[mid]+d;
    if(arr[mid]==a+d*mid) return findMissing(arr,mid+1,r,a,d);
    else return findMissing(arr,l,mid,a,d);
}
