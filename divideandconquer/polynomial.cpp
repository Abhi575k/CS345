#include<bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;

void findPolynomial(vector<int>&,vector<int>&,int,int);
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
    vector<int> a(n),p(n,1);
    for(int i=0;i<n;i++) cin>>a[i];
    findPolynomial(a,p,0,n-1);
    for(int i=0;i<n;i++) cout<<p[i]<<" ";
    cout<<"\n";
    //
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time Taken for TC "<<t<<": "<<(float)(duration.count())/1000000 << endl;
    return;
}

void findPolynomial(vector<int> &a,vector<int> &p,vector<int> &temp,int l,int r){
    if(l>r) return;
    if(l==r){
        temp.push_back({1,a[l]});
        return;
    }
    int mid=(l+r)/2;
    vector<int> L,R;
    findPolynomial(a,p,L,l,mid);
    findPolynomial(a,p,R,mid+1,r);
    
    return;
}