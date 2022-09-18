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
        box.push_back(Box(temp[1],temp[0],temp[2]));
        box.push_back(Box(temp[0],temp[2],temp[1]));
        box.push_back(Box(temp[2],temp[0],temp[1]));
        box.push_back(Box(temp[1],temp[2],temp[0]));
        box.push_back(Box(temp[2],temp[1],temp[0]));
    }
    box.push_back(Box((int)INF,(int)INF,(int)INF));
    sort(box.begin(),box.end(),comp);

    vector<int> dp_incl(6*n,-1),dp_excl(6*n,-1);
    createDP(dp_incl,dp_excl,n-1,)
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