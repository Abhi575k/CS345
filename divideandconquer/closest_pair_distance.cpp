#include<bits/stdc++.h>
using namespace std;

void solve();
int divideMin(vector<int>&,vector<int>&,int,int);
int dist(int,int,int,int);
bool comp(pair<int,int>&,pair<int,int>&);

int main(){
	int t=1;
	// cin>>t;
	while(t--) solve();
	return 0;
}

void solve(){
	int n;
	cin>>n;
	vector<int> x(n),y(n);
	for(int i=0;i<n;i++) cin>>x[i]>>y[i];
	int res=divideMin(x,y,0,n-1);
	cout<<res<<"\n";
	return;
}

int divideMin(vector<int> &x,vector<int> &y,int l,int r){
	if(r-l<=4){
		int res=(int)1e9;
		for(int i=l;i<=r;i++){
			for(int j=l;j<=r;j++){
				if(i!=j)
				res=min(res,dist(x[i],y[i],x[j],y[j]));
			}
		}
		return res;
	}
	int mid=(l+r)/2;
	int l_min=divideMin(x,y,l,mid-1);
	int r_min=divideMin(x,y,mid+1,r);
	int delta=min(l_min,r_min);
	vector<pair<int,int>> points_l,points_r;
	for(int i=l;i<=r;i++){
		if(abs(x[i]-x[mid])<delta){
			if(x[i]<=x[mid]){
				points_l.push_back({x[i],y[i]});
			}else{
				points_r.push_back({x[i],y[i]});
			}
		}
	}
	sort(points_l.begin(),points_l.end(),comp);
	sort(points_r.begin(),points_r.end(),comp);
	int size_l=points_l.size(),size_r=points_r.size();
	int idxl=0,idxr=0;
	while(idxl<size_l&&idxr<size_r){
		if(points_l[idxl].second<=points_r[idxr].second){
			for(int i=idxr;i<min(idxr+4,size_r-1);i++) delta=min(delta,dist(points_l[idxl].first,points_l[idxl].second,points_r[i].first,points_r[i].second));
			idxl++;
		}else{
			for(int i=idxl;i<min(idxl+4,size_l-1);i++) delta=min(delta,dist(points_l[i].first,points_l[i].second,points_r[idxr].first,points_r[idxr].second));
			idxr++;
		}
	}
	return delta;
}

int dist(int x1,int y1,int x2,int y2){
	int x=x1-x2,y=y1-y2;
	return (x*x+y*y);
}

bool comp(pair<int,int>& a,pair<int,int>& b){
	return a.second>b.second;
}