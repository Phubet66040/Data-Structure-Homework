#include <iostream>
using namespace std;
class Heap{
	public:
		int Heapsize = 1;
		int*arr;
		int data;
		Heap(){
			arr = new int[1000];
		}
		void insert(int value){
			int index = Heapsize++;
			arr[index] = value;
			while(index>1&&arr[index]>arr[index/2]){
				int temp = arr[index];
				arr[index] = arr[index/2];
				arr[index/2] = temp;
				index = index/2;
			}
			
		}
		int erase() {
    		int last = Heapsize - 1;
    		int root = arr[1];  
    		arr[1] = arr[last];     
    		Heapsize--;             
    		int index = 1;
			while(index <= Heapsize) {
        		int left = index * 2;
        		int right = index * 2 + 1;
        		int last = index;
        		if (left <= Heapsize && arr[left] > arr[last]) {
            		last = left;
        		}
        		if (right <= Heapsize && arr[right] > arr[last]) {
            		last= right;
        		}
        		if (last == index) {
            		break;
        		}
        		int temp = arr[index];
        		arr[index] = arr[last];
        		arr[last] = temp;
        		index = last;
    		}
    		return root;  
		}

		void print(){
			for(int index = 1;index<Heapsize;index++){
				cout<<arr[index]<<" "; 
			}
			cout<<"\n";
		}
};

int main(){
	Heap* h = new Heap();
	char cmd;
	int com;
	do{
		cin>>cmd;
		if(cmd == 'a'){
			cin>>com;
			h->insert(com);
		}else if(cmd == 'p'){
			h->print();
		}else if(cmd == 'd'){
			cout<<h->erase()<<endl;
		}
	}while(cmd != 'e');
}