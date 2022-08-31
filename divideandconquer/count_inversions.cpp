#include<bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;

int cntInversion(vector<int>&,int,int);
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
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int res=cntInversion(a,0,n-1);
    res=res%(int)(1e9+7);
    cout<<res<<"\n";
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time Taken for TC "<<t<<": "<<(float)(duration.count())/1000000 << endl;
    return;
}
int cntInversion(vector<int>& a,int l,int r){
    if(l>=r) return 0;
    int res=0;
    int mid=(l+r)/2;
    res+=cntInversion(a,l,mid);
    res+=cntInversion(a,mid+1,r);
    res=res%(int)(1e9+7);
    int idx1=l,idx2=mid+1;
    long long int temp=0;
    while(idx1<=mid&&idx2<=r){
        if(a[idx2]>=a[idx1]){
            idx1++;
            res+=temp;
        }else{
            idx2++,temp++;
        }
        if(idx2>r){
            while(idx1<=mid){
                res+=temp;
                idx1++;
            }
        }
        res=res%(int)(1e9+7);
    }
    vector<int> sorted_a;
    idx1=l,idx2=mid+1;
    while(idx1<=mid&&idx2<=r){
        if(a[idx2]>=a[idx1]){
            sorted_a.push_back(a[idx1]);
            idx1++;
        }else{
            sorted_a.push_back(a[idx2]);
            idx2++;
        }
        if(idx1>mid){
            while(idx2<=r){
                sorted_a.push_back(a[idx2]);
                idx2++;
            }
        }
        if(idx2>r){
            while(idx1<=mid){
                sorted_a.push_back(a[idx1]);
                idx1++;
            }
        }
    }
    for(int i=l;i<=r;i++){
        a[i]=sorted_a[i-l];
    }
    res=res%(int)(1e9+7);
    return res;
}