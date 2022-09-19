#include<bits/stdc++.h>
#include <chrono>

#define INF (int)1e9

using namespace std::chrono;
using namespace std;

class Matrix{
    public:
    int X,Y,op;
    bool vis;
    Matrix(int x,int y,int o){
        X=x;
        Y=y;
        op=o;
        vis=false;
    }
    Matrix(int x,int y,int o,bool v){
        X=x;
        Y=y;
        op=o;
        vis=true;
    }
};

void solve(int);
void createMatrix(vector<vector<Matrix>>&,int,int);
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
    vector<int> a(n+1);
    for(int i=0;i<=n;i++) cin>>a[i];
    vector<vector<Matrix>> matrices(n,vector<Matrix>(n,Matrix(0,0,INF)));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j<i) continue;
            else if(i==j){
                matrices[i][i]=Matrix(a[i],a[i+1],0,true);
            }
            else{
                if(!matrices[i][j].vis) createMatrix(matrices,i,j);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<matrices[i][j].X<<" "<<matrices[i][j].Y<<" "<<matrices[i][j].op<<"\t";
        }
        cout<<"\n";
    }
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time Taken for TC "<<t<<": "<<(float)(duration.count())/1000000 << endl;
    return;
}

void createMatrix(vector<vector<Matrix>> &matrices,int x,int y){
    for(int X=x,Y=x+1;X<y;X++,Y++){
        cout<<x<<" "<<X<<"\n"<<Y<<" "<<y<<"\n";
        // if(matrices[x][X].X==0) createMatrix(matrices,x,X);
        // if(matrices[Y][y].X==0) createMatrix(matrices,Y,y);
        matrices[x][y]=Matrix(matrices[x][X].X,matrices[Y][y].Y,min(matrices[x][y].op,matrices[x][X].X*matrices[Y][y].X*matrices[Y][y].Y+matrices[x][X].op+matrices[Y][y].op),true);
    }
    return;
}