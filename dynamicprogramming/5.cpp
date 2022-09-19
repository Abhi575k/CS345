#include<bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;

void solve(int);
int transformString(vector<vector<int>>&,string,string,int,int,int);
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
    string a,b;
    cin>>a>>b;
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    cout<<transformString(dp,a,b,0,0,n)<<"\n";
    //
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time Taken for TC "<<t<<": "<<(float)(duration.count())/1000000 << endl;
    return;
}

int transformString(vector<vector<int>> &dp,string a,string b,int idxa,int idxb,int n){
    if(idxa==n){
        if(idxb==n){
            if(dp[idxa][idxb]==-1) dp[idxa][idxb]=0;
            return dp[idxa][idxb];
        }
        else{
            if(dp[idxa][idxb]==-1) dp[idxa][idxb]=n-idxb;
            return dp[idxa][idxb];
        }
    }else{
        if(idxb==n){
            if(dp[idxa][idxb]==-1) dp[idxa][idxb]=n-idxa;
            return dp[idxa][idxb];
        }else{
            if(a[idxa]==b[idxb]){
                if(dp[idxa][idxb]==-1) dp[idxa][idxb]=min(transformString(dp,a,b,idxa+1,idxb+1,n),min(1+transformString(dp,a,b,idxa+1,idxb,n),1+transformString(dp,a,b,idxa,idxb+1,n)));;
                return dp[idxa][idxb];
            }else{
                if(dp[idxa][idxb]==-1) dp[idxa][idxb]=min(1+transformString(dp,a,b,idxa+1,idxb+1,n),min(1+transformString(dp,a,b,idxa+1,idxb,n),1+transformString(dp,a,b,idxa,idxb+1,n)));;
                return dp[idxa][idxb];
            }
        }
    }
}