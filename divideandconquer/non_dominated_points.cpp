#include<bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;

void solve(int);
bool comp(pair<int,int>&,pair<int,int>&);
void NDPoints(vector<pair<int,int>>&,int,int,vector<pair<int,int>>&);

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
	vector<pair<int,int>> P(n);
	for(int i=0;i<n;i++) cin>>P[i].first>>P[i].second;
	vector<pair<int,int>> res;
	sort(P.begin(),P.end(),comp);
	NDPoints(P,0,n-1,res);
	int m=res.size();
	// cout<<m<<"\n";
	// for(int i=0;i<m;i++) cout<<res[i].first<<" "<<res[i].second<<"\n";
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Time Taken for TC "<<t<<": "<<(float)(duration.count())/1000000 << endl;
	return;
}
void NDPoints(vector<pair<int,int>> &P,int l,int r,vector<pair<int,int>> &res){
	if(l>=r){
		for(int i=l;i<=r;i++) res.push_back(P[i]);
		return;
	}
	int mid=(l+r)/2;
	vector<pair<int,int>> res_l,res_r;
	NDPoints(P,l,mid,res_l);
	NDPoints(P,mid+1,r,res_r);
	while(res_r[0].second>=res_l[res_l.size()-1].second && res_l.size()>0) res_l.pop_back();
	for(int i=0;i<res_l.size();i++) res.push_back(res_l[i]);
	for(int i=0;i<res_r.size();i++) res.push_back(res_r[i]);
	return;
}
bool comp(pair<int,int> &a,pair<int,int> &b){
	if(a.first==b.first) return a.second<b.second;
	return a.first<b.first;
}