#include<bits/stdc++.h>
#include <chrono>

#define INF 1e9

using namespace std::chrono;
using namespace std;

class Job{
    public:
    int start,end;
    int profit;
    
    Job(int s,int f,int p){
        start=s;
        end=f;
        profit=p;
    }
};

int createDP(vector<int>&,vector<int>&,int,vector<Job>&, Job);
bool comp(Job&,Job&);
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
bool comp(Job &a,Job &b){
    return (a.end<b.end);
}
void solve(int t){
    auto start = high_resolution_clock::now();
    //  Your code here
    int n;
    cin>>n;
    vector<Job> a;
    for(int i=0;i<n;i++){
        int s,f,p;
        cin>>s>>f>>p;
        a.push_back(Job(s,f,p));
    }
    a.push_back(Job((int)INF,(int)INF,0));
    sort(a.begin(),a.end(),comp);
    for(auto u:a){
        cout<<u.start<<" "<<u.end<<" "<<u.profit<<"\n";
    }
    vector<int> dp_incl(n,-1),dp_excl(n,-1);
    createDP(dp_incl,dp_excl,n-1,a,a[n]);
    cout<<max(dp_incl[n-1],dp_excl[n-1])<<"\n";
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time Taken for TC "<<t<<": "<<(float)(duration.count())/1000000 << endl;
    return;
}
int createDP(vector<int> &dp_incl,vector<int> &dp_excl,int x,vector<Job> &a, Job prev){
    if(a[x].end>prev.start){
        if(x==0) return 0;
        else{
            if(dp_excl[x]==-1) dp_excl[x]=createDP(dp_incl,dp_excl,x-1,a,prev);
            return dp_excl[x];
        }
    }
    if(x==0){
        if(dp_incl[x]==-1) dp_incl[x]=a[x].profit;
        return dp_incl[x];
    }
    if(dp_incl[x]==-1) dp_incl[x]=max(a[x].profit+createDP(dp_incl,dp_excl,x-1,a,a[x]),createDP(dp_incl,dp_excl,x-1,a,prev));
    return dp_incl[x];
}