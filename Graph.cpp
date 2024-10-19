#include <iostream>
#include <vector>
using namespace std;
class graph{
	public:
		int s_v;
		vector<vector<int> > edges;
		graph(int n){
			s_v = n;
			edges = vector<vector<int> >(s_v,vector<int>(s_v,0));
		}
		
		void add(int x,int y,int w){
			edges[x][y] = w;
		}
		void print(){
			if(!edges.empty()){
				for(int i =0;i<s_v;i++){
					cout<<i<<" : ";
					for(int j =0;j<s_v;j++){
						cout<<edges[i][j]<<" ";
					}
					cout<<endl;
				}
			}
		}
		
		bool visitD[100];
		
		void sub(int start){
			cout<<start<<" ";
			visitD[start] = 1;
			for(int i =0;i<s_v;i++){
				if(visitD[i] == 0 && edges[start][i] >0){
					sub(i);
				}
			}
		}
		
		void dft(int start){
			for(int i =0;i<100;i++){
				visitD[i] = 0;
			}
			sub(start);
		}
		
		void bft(int start){
			bool visitB[100];
			for(int i =0;i<100;i++){
				visitB[i] = 0;
			}
			visitB[start] = 1;
			vector<int> q;
			q.push_back(start);	
			while(q.empty() == 0){
				start = q.front();
				cout<<start<<" ";
				q.erase(q.begin());
				for(int i =0;i<s_v;i++){
					if(visitB[i] == 0 && edges[start][i] >0){
						visitB[i] = 1;
						q.push_back(i);
					}
				}
			}
		}
};

int main(){
	int n,x,y,w,v;
	char cmd;
	cin>>n;
	graph g(n);
	do{
		cin>>cmd;
		if(cmd == 'e'){
			cin>>x>>y>>w;
			g.add(x,y,w);
		}else if(cmd == 'p'){
			g.print();
		}else if(cmd == 'd'){
			cin>>v;
			g.dft(v);
			cout<<endl;
		}else if(cmd == 'b'){
			cin>>v;
			g.bft(v);
			cout<<endl;
		}
	}while(cmd != 'q');
}




