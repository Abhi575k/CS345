#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cout<<"Test Cases:";
	cin>>t;
	vector<pair<int,int>> n(t);
	for(int i=1;i<=t;i++){
		cout<<"Number of nodes in graph "<<i<<" :";
		cin>>n[i-1].first;
		cout<<"Number of edges in graph "<<i<<" :";
		cin>>n[i-1].second;
	}
	freopen("input.txt", "w", stdout);
	cout<<t<<"\n";
	for(int i=0;i<t;i++){
		cout<<n[i].first<<" "<<n[i].second<<"\n";
		srand(7);
		for(int j=0;j<n[i].second;j++){
			int u=rand()%(n[i].first+1),v=rand()%(n[i].first+1),w=rand()%1000000;
			if(u==0||v==0){
				while(u==0||v==0){
					u=rand()%(n[i].first+1),v=rand()%(n[i].first+1);
				}
			}
			cout<<u<<" "<<v<<" "<<w<<"\n";
		}
		int s=rand()%(n[i].first+1),d=rand()%(n[i].first+1);
		if(s==0||d==0){
			while(s==0||d==0){
				s=rand()%(n[i].first+1),d=rand()%(n[i].first+1);
			}
		}
		cout<<s<<" "<<d<<"\n";
	}
	return 0;
}