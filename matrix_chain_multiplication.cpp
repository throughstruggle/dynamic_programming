#include<bits/stdc++.h>
using namespace std;

void parenthesize(vector< vector<int> > s,int i,int j){
	if(i==j){
		cout<<"A"<<i;
		return;
	}
	cout<<"(";
	parenthesize(s,i,s[i][j]);
	parenthesize(s,s[i][j]+1,j);
	cout<<")";
}

int main(){
	int n;
	cin>>n;
	vector<int> chain(n);
	for(int i=0;i<n;++i)cin>>chain[i];
	
	int m[n][n];
	vector< vector<int> > s(n);
	for(int i=0;i<n;++i){
		vector<int> a(n);
		s[i]=a;
	}
	for(int i=1;i<n;++i){
		m[i][i]=0;
	}

int q;
for(int l=2;l<n;++l){
	for(int i=1;i<n-l+1;++i){
		int j =i+l-1;
		m[i][j]=numeric_limits<int>::max();
		for(int k=i;k<j;++k){
			q=m[i][k]+m[k+1][j]+chain[i-1]*chain[j]*chain[k];
			if(q<m[i][j]){
				m[i][j]=q;
				s[i][j]=k;
			}
		}
	}
}
parenthesize(s,1,n-1);
cout<<endl;
cout<<m[1][n-1];

}
