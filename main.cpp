#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <cmath>
#include <cstdlib>
using namespace std;

class client{

public:
	int id;
	vector<client> toClient;
	vector<client> fromClient;

	client(int Id){
		id = Id;
	}	
	//void setupTrans(client other,bool ToFrom){
	//	cout <<  other.id << "\n";
	//	other.fromClient.push_back(this);
	//	if(ToFrom){
	//		toClient.push_back(other);
	//		other.fromClient.push_back(*this);
	//	}
	//	else{
	//		other.toClient.push_back(*this);
	//		fromClient.push_back(other);
	//	}
	//}	
};


int main(){

	client A(10);
	client B(11);
	client C(12);
	client D(13);
	client E(14);

	A.toClient.push_back(B);
	A.toClient.push_back(C);
	A.toClient.push_back(D);

	int size = A.toClient.size();

	for(int i=0;i<size;i++){
		cout << A.toClient[i].id << "\n";
	}

	return 0;
}
