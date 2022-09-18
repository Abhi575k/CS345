#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cout<<"Test Cases:";
	cin>>t;
	vector<int> n(t);
	for(int i=1;i<=t;i++){
		cout<<"Number of jobs "<<i<<" :";
		cin>>n[i-1];
	}
	freopen("input.txt", "w", stdout);
	cout<<t<<"\n";
	for(int i=0;i<t;i++){
		cout<<n[i]<<"\n";
		srand(7);
		for(int j=0;j<n[i];j++){
			int u=rand()%(n[i]+1);
			// if(u>=v||w<=0){
			// 	while(u>=v||w<=0){
			// 		u=rand()%(n[i]+1),v=rand()%(n[i]+1),w=rand()%(n[i]+1);
			// 	}
			// }
			cout<<u<<"\n";
		}
	}
	return 0;
}