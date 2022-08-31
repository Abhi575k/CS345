#include<bits/stdc++.h>
using namespace std;

void solve(int);
bool comp(pair<int,int>&,pair<int,int>&);
void findMinConvex(vector<pair<int,int>>&,int,int,vector<pair<int,int>>&);
void transformHull(vector<pair<int,int>>&);

int main(){
	int t=1;
	cin>>t;
	for(int i=1;i<=t;i++) solve(i);
		return 0;
}

void solve(int t){
	int n;
	cin>>n;
	vector<pair<int,int>> P(n);
	for(int i=0;i<n;i++) cin>>P[i].first>>P[i].second;
	sort(P.begin(),P.end(),comp);
	transformHull(P);
	vector<pair<int,int>> res;
	// findMinConvex(P,0,n-1,res);
	int m=res.size();
	cout<<m<<"\n";
	for(int i=0;i<m;i++){
		cout<<res[i].first<<" "<<res[i].second<<"\n";
	}

	for(int i=0;i<n;i++){
		cout<<P[i].first<<" "<<P[i].second<<"\n";
	}
	return;
}

void findMinConvex(vector<pair<int,int>>& P,int l,int r,vector<pair<int,int>>& res){
	if(l+2>=r){
		for(int i=l;i<=r;i++) res.push_back(P[i]);
		return;
	}
	int mid=(l+r)/2;
	vector<pair<int,int>> res_l,res_r;
	findMinConvex(P,l,mid,res_l);
	findMinConvex(P,mid+1,r,res_r);
	transformHull(res_l);
	transformHull(res_r);
	pair<int,int> temp,p=res_l[0],q=res_l[1];
	for(int i=0;i<res_r.size();i++){
		if(p.first==q.first) continue;
	}
	return;
}

bool comp(pair<int,int>& A,pair<int,int>& B){
	if(A.first==B.first) return A.second<B.second;
	return A.first<B.first;
}

void transformHull(vector<pair<int,int>> &res){
	int x=res[0].first,y=res[0].second;
	int n=res.size();
	vector<pair<int,int>> temp;
	for(int i=0;i<n;i++) temp.push_back(res[i]);
	res.clear();
	for(int i=0;i<n;i++){
		if(temp[i].second>=y){
			res.push_back(temp[i]);
		}
	}
	for(int i=n-1;i>=0;i--){
		if(temp[i].second<y){
			res.push_back(temp[i]);
		}
	}
	return;
}