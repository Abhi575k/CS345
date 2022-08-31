#include<bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;

void solve(int);
int findLocalMin(vector<int>&,int,int);
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
    int res=findLocalMin(a,0,n-1);
    if(res==-1){
        if(a[0]<a[1]) res=0;
        else res=n-1;
    }
    cout<<res<<"\n";
    //
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time Taken for TC "<<t<<": "<<(float)(duration.count())/1000000 << endl;
    return;
}

int findLocalMin(vector<int> &a,int l,int r){
    if(r-l<2) return -1;
    int mid=(l+r)/2;
    if(a[l]<a[mid]) return findLocalMin(a,l,mid);
    else{
        if(a[mid]>a[r]) return findLocalMin(a,mid+1,r);
        else{
            if(a[r]>a[mid]){
                if(a[mid]<a[mid-1]&&a[mid]<a[mid+1]) return mid;
                else{
                    if(a[mid-1]<a[mid]) return findLocalMin(a,l,mid);
                    else return findLocalMin(a,mid+1,r);
                }
            }
        }
    }
    return -1;
}