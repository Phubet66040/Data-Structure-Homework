#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

bool isSimple(const vector<int>& degree,int n){
	for(size_t i =0;i<degree.size();++i){
		if(degree[i]>=n){
			return false;
		}
	}
	
	int sum = accumulate(degree.begin(), degree.end(),0);
	return (sum % 2 == 0); 
}

int main(){
	int q;
	cin>>q;
	while(q--){
		int n;
		cin>>n;
		
		vector<int> degree(n);
		for(int i =0;i<n;i++){
			cin>> degree[i];
		}
		if(isSimple(degree,n)){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
}
