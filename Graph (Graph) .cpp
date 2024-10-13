#include <iostream>
#include <vector>

using namespace std;

class graph{
	public:
		vector<vector<int> >matrix;
		int s_v;
		graph(int n){
			s_v = n;
			matrix = vector<vector<int> >(n,vector<int>(n,0));
		}
		void addedge(int x,int y,int w){
			matrix[x][y] = w;
		}
		
		void print(){
			if(!matrix.empty()){
				for(int i =0;i<s_v;i++){
					cout<<i<<": ";
					for(int j =0;j<s_v;j++){
						if(matrix[i][j] >0){
							cout<<j<<","<<matrix[i][j]<<" ";
						}
					}
					cout<<endl;
				}
			}
		}
		
		void bft(int start){
			bool visit[100];
			for(int i = 0;i<100;i++){
				visit[i] = 0;
			}
			visit[start] = 1;
			vector<int>q;
 			q.push_back(start);
 			while(q.empty() ==0){
 				start = q.front();
 				cout<<start<<" ";
 				q.erase(q.begin());
 				for(int y =0;y<s_v;y++){
 					if(visit[y] == 0 && matrix[start][y]>0){
 						visit[y] = 1;
 						q.push_back(y);
					}	
				}
			 }
 		}
 		bool visitt[100];
 		void sub(int start){
 			cout<<start<<" ";
 			visitt[start] = 1;
 			for(int y =0;y<s_v;y++){
 				if(visitt[y] ==0&& matrix[start][y] >0){
 					sub(y);
				 }
			 }
		}
		void dft(int start){
			for(int i =0;i<100;i++){
				visitt[i] = 0;
			}
			sub(start);
		}
		void sd(){
			int num_s = 1;
			for(int i=0;i<100;i++){
				visitt[i] = 0;
			}
			for(int y =0;y<s_v;y++){
				if(visitt[y] ==0){
					cout<<"\n sum "<<num_s+1;
				}
			}
		}
};

int main(){
	int n,x,y,w,value;
	char cmp;
	cin>>n;
	graph h(n);
	
	do{
		cin>>cmp;
		if(cmp =='e'){
			cin>>x>>y>>w;
			h.addedge(x,y,w);
		}else if(cmp =='p'){
			h.print();
		}else if( cmp == 'd'){
			cin>>value;
			h.dft(value);
			cout<<endl;
		}else if(cmp =='b'){
			cin>>value;
			h.bft(value);
			cout<<endl;
		}
		
	}while(cmp != 'q');
}