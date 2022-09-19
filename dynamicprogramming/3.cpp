#include<bits/stdc++.h>
#include <chrono>

#define INF 1e9

using namespace std::chrono;
using namespace std;

class Box{
    public:
        int length;
        int breadth;
        int height;

        Box(int l,int b,int h){
            length=l;
            breadth=b;
            height=h;
        }
};

void solve(int);
bool comp(Box&,Box&);
bool isGreater(Box&,Box&);
int createDP(vector<int>&,vector<int>&,int,vector<Box>&,Box);
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
    vector<Box> box;
    for(int i=0;i<n;i++){
        vector<int> temp(3);
        for(int j=0;j<3;j++) cin>>temp[j];
        sort(temp.begin(),temp.end());
        box.push_back(Box(temp[0],temp[1],temp[2]));
        box.push_back(Box(temp[0],temp[2],temp[1]));
        box.push_back(Box(temp[1],temp[2],temp[0]));
    }
    box.push_back(Box((int)INF,(int)INF,(int)INF));
    sort(box.begin(),box.end(),comp);
    vector<int> dp_incl(3*n,-1),dp_excl(3*n,-1);
    createDP(dp_incl,dp_excl,3*n-1,box,box[3*n]);
    cout<<max(dp_incl[3*n-1],dp_excl[3*n-1])<<"\n";
    //
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time Taken for TC "<<t<<": "<<(float)(duration.count())/1000000 << endl;
    return;
}


bool comp(Box& a,Box& b){
    if(a.length==b.length){
        if(a.breadth==b.breadth) return a.height<b.height;
        return a.breadth<b.breadth;
    }
    return a.length<b.length;
}

int createDP(vector<int> &dp_incl,vector<int> &dp_excl,int x,vector<Box> &box,Box prev){
    if(x==0){
        if(isGreater(prev,box[x])){
            if(dp_incl[x]==-1) dp_incl[x]=box[x].height;
            return dp_incl[x];
        }else{
            if(dp_excl[x]==-1) dp_excl[x]=0;
            return dp_excl[x];
        }
    }else{
        if(isGreater(prev,box[x])){
            if(dp_incl[x]==-1) dp_incl[x]=box[x].height+createDP(dp_incl,dp_excl,x-1,box,box[x]);
        }else{
            if(dp_excl[x]==-1) dp_excl[x]=createDP(dp_incl,dp_excl,x-1,box,prev);
        }
        return max(dp_incl[x],dp_excl[x]);
    }
}

bool isGreater(Box& a,Box& b){
    return ((a.length>b.length&&a.breadth>b.breadth)||(a.length>b.breadth&&a.breadth>b.length));
}