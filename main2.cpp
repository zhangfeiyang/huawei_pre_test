#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <map>
#include <algorithm>
#include "time.h"

using namespace std;
int main(){

	clock_t start = clock();

	ifstream infile("test_data.txt");
	string line;
	int size;
	bool chain;

	vector<int *> l1_chains;
	int data_tmp;
	while (infile){
		getline(infile,line);
		stringstream sin(line);
		char ch;

		int *dataV = new int[2];
		if (line.size()>0){
			char c = sin.peek();
			sin >> dataV[0];
			sin>>ch;
			sin >> dataV[1];
			sin>>ch;
			sin >> data_tmp;

			//if(dataV[0] == 94 && dataV[1] == 91)
			//	cout << "hello\n";
			//if(dataV[0] == 91 && dataV[1] == 223)
			//	cout << "hello\n";
		}
		l1_chains.push_back(dataV);
	}

	
	size = l1_chains.size();
	vector<int*> l2_chains;
	for(int i=0;i<size;i++){
		for(int j=i+1;j<size;j++){
			if(l1_chains[i][1] == l1_chains[j][0]){
				//if(l1_chains[i][1] == 91 ){
//					cout << "hello\n";
				//}
				int *dataV2 = new int[3];
				dataV2[0] = l1_chains[i][0];
				dataV2[1] = l1_chains[i][1];
				dataV2[2] = l1_chains[j][1];
				l2_chains.push_back(dataV2);
				//cout << l1_chains[i][0] << "," << l1_chains[i][1] << "," << l1_chains[j][1] << "\n";
			}
			if(l1_chains[i][0] == l1_chains[j][1]){
				int *dataV2 = new int[3];
				dataV2[0] = l1_chains[j][0];
				dataV2[1] = l1_chains[j][1];
				dataV2[2] = l1_chains[i][1];
				l2_chains.push_back(dataV2);
				//cout << l1_chains[j][0] << "," << l1_chains[j][1] << "," << l1_chains[i][1] << "\n";
			}
		}
	}

	size = l2_chains.size();
	//cout << "size is "<< size << "\n";
	//for(int i=0;i<size;i++){
	//	cout << l2_chains[i][0] << "," << l2_chains[i][1] << "," << l2_chains[i][2] << "\n";
	//}
	vector<int*> l3_chains;
	const int nl3 = 4;
	for(int i=0;i<size;i++){
		for(int j=i+1;j<size;j++){
			chain = true;
			for(int k=0;k<nl3-2;k++){
				if(l2_chains[i][k+1] != l2_chains[j][k]) {
					chain = false;
					break;
				}	
			}
			if(chain){
				int *dataV2 = new int[nl3];
				for(int k=0;k<nl3;k++){
					if(k<nl3-1) dataV2[k] = l2_chains[i][k];
					else dataV2[k] = l2_chains[j][k-1];
				}
				l3_chains.push_back(dataV2);
			}

			chain = true;
			for(int k=0;k<nl3-2;k++){
				if(l2_chains[i][k] != l2_chains[j][k+1]) {
					chain = false;
					break;
				}	
			}
			if(chain){
				//cout << "hello\n";
				int *dataV2 = new int[nl3];
				for(int k=0;k<nl3;k++){
					if(k<nl3-1) dataV2[k] = l2_chains[j][k];
					else dataV2[k] = l2_chains[i][k-1];
				}
				l3_chains.push_back(dataV2);
			}
		}
	}


	vector<int*> loop_chains3;

	size = l3_chains.size();
	vector<int*> l4_chains;
	const int nl4 = 5;
	for(int i=0;i<size;i++){
		if(l3_chains[i][0] == l3_chains[i][nl4-2]){
			loop_chains3.push_back(l3_chains[i]);	
			continue;
		}
		for(int j=i+1;j<size;j++){
			chain = true;
			for(int k=0;k<nl4-2;k++){
				if(l3_chains[i][k+1] != l3_chains[j][k]) {
					chain = false;
					break;
				}	
			}
			if(chain){
				int *dataV2 = new int[nl4];
				for(int k=0;k<nl4;k++){
					if(k<nl4-1) dataV2[k] = l3_chains[i][k];
					else dataV2[k] = l3_chains[j][k-1];
				}
				l4_chains.push_back(dataV2);
			}

			chain = true;
			for(int k=0;k<nl4-2;k++){
				if(l3_chains[i][k] != l3_chains[j][k+1]) {
					chain = false;
					break;
				}	
			}
			if(chain){
				int *dataV2 = new int[nl4];
				for(int k=0;k<nl4;k++){
					if(k<nl4-1) dataV2[k] = l3_chains[j][k];
					else dataV2[k] = l3_chains[i][k-1];
				}
				l4_chains.push_back(dataV2);
			}
		}
	}
	


	size = l4_chains.size();
	vector<int*> l5_chains;
	vector<int*> loop_chains4;
	const int nl5 = 6;
	for(int i=0;i<size;i++){
		if(l4_chains[i][0] == l4_chains[i][nl5-2]){
			loop_chains4.push_back(l4_chains[i]);	
			continue;
		}

		for(int j=i+1;j<size;j++){
			chain = true;
			for(int k=0;k<nl5-2;k++){
				if(l4_chains[i][k+1] != l4_chains[j][k]) {
					chain = false;
					break;
				}	
				//cout << "hello" << "\n";
			}
			if(chain){
				int *dataV2 = new int[nl5];
				for(int k=0;k<nl5;k++){
					if(k<nl5-1) dataV2[k] = l4_chains[i][k];
					else dataV2[k] = l4_chains[j][k-1];
				}
				l5_chains.push_back(dataV2);
			}

			chain = true;
			for(int k=0;k<nl5-2;k++){
				if(l4_chains[i][k] != l4_chains[j][k+1]) {
					chain = false;
					break;
				}	
			}
			if(chain){
				int *dataV2 = new int[nl5];
				for(int k=0;k<nl5;k++){
					if(k<nl5-1) dataV2[k] = l4_chains[j][k];
					else dataV2[k] = l4_chains[i][k-1];
				}
				l5_chains.push_back(dataV2);
			}
		}
	}



	size = l5_chains.size();
	vector<int*> l6_chains;
	vector<int*> loop_chains5;
	const int nl6 = 7;
	for(int i=0;i<size;i++){
		if(l5_chains[i][0] == l5_chains[i][nl6-2]){
			loop_chains5.push_back(l5_chains[i]);	
			continue;
		}

		for(int j=i+1;j<size;j++){
			chain = true;
			for(int k=0;k<nl6-2;k++){
				if(l5_chains[i][k+1] != l5_chains[j][k]) {
					chain = false;
					break;
				}	
			}
			if(chain){
				int *dataV2 = new int[nl6];
				for(int k=0;k<nl6;k++){
					if(k<nl6-1) dataV2[k] = l5_chains[i][k];
					else dataV2[k] = l5_chains[j][k-1];
				}
				l6_chains.push_back(dataV2);
			}

			chain = true;
			for(int k=0;k<nl6-2;k++){
				if(l5_chains[i][k] != l5_chains[j][k+1]) {
					chain = false;
					break;
				}	
			}
			if(chain){
				int *dataV2 = new int[nl6];
				for(int k=0;k<nl6;k++){
					if(k<nl6-1) dataV2[k] = l5_chains[j][k];
					else dataV2[k] = l5_chains[i][k-1];
				}
				l6_chains.push_back(dataV2);
			}
		}
	}

	size = l6_chains.size();
	vector<int*> l7_chains;
	vector<int*> loop_chains6;
	const int nl7 = 8;
	for(int i=0;i<size;i++){
		if(l6_chains[i][0] == l6_chains[i][nl7-2]){
			loop_chains6.push_back(l6_chains[i]);	
			continue;
		}

		for(int j=i+1;j<size;j++){
			chain = true;
			for(int k=0;k<nl7-2;k++){
				if(l6_chains[i][k+1] != l6_chains[j][k]) {
					chain = false;
					break;
				}	
			}
			if(chain){
				int *dataV2 = new int[nl7];
				for(int k=0;k<nl7;k++){
					if(k<nl7-1) dataV2[k] = l6_chains[i][k];
					else dataV2[k] = l6_chains[j][k-1];
				}
				l7_chains.push_back(dataV2);
			}

			chain = true;
			for(int k=0;k<nl7-2;k++){
				if(l6_chains[i][k] != l6_chains[j][k+1]) {
					chain = false;
					break;
				}	
			}
			if(chain){
				int *dataV2 = new int[nl7];
				for(int k=0;k<nl7;k++){
					if(k<nl7-1) dataV2[k] = l6_chains[j][k];
					else dataV2[k] = l6_chains[i][k-1];
				}
				l7_chains.push_back(dataV2);
			}
		}
	}

	
	vector<int*> loop_chains7;
	size = l7_chains.size();
	for(int i=0;i<size;i++){
		if(l7_chains[i][0] == l7_chains[i][nl7-1]){
			loop_chains7.push_back(l7_chains[i]);	
			continue;
		}
	}


	size = loop_chains3.size();
	for(int i=0;i<size;i++){
		for(int j=0;j<3;j++)
			cout << loop_chains3[i][j] << ",";
		cout << "\n";
	}


	size = loop_chains4.size();
	for(int i=0;i<size;i++){
		for(int j=0;j<4;j++)
			cout << loop_chains4[i][j] << ",";
		cout << "\n";
	}

	size = loop_chains5.size();
	for(int i=0;i<size;i++){
		for(int j=0;j<5;j++)
			cout << loop_chains5[i][j] << ",";
		cout << "\n";
	}

	size = loop_chains6.size();
	for(int i=0;i<size;i++){
		for(int j=0;j<6;j++)
			cout << loop_chains6[i][j] << ",";
		cout << "\n";
	}

	size = loop_chains7.size();
	for(int i=0;i<size;i++){
		for(int j=0;j<7;j++)
			cout << loop_chains7[i][j] << ",";
		cout << "\n";
	}

	double tmpp[3] = {2,1,30};
	 cout << "mini is " << *min_element(tmpp,tmpp+3) << "\n";
	clock_t end = clock();

	cout << "total time is : " << (end - start)/1e6 << "s\n"; 

	return 0;
}
