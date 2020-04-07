#include <iostream>
#include <thread>
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
		}
		l1_chains.push_back(dataV);
	}

	
	size = l1_chains.size();
	vector<int*> l2_chains;
	for(int i=0;i<size;i++){
		for(int j=i+1;j<size;j++){
			if(l1_chains[i][1] == l1_chains[j][0]){
				int *dataV2 = new int[3];
				dataV2[0] = l1_chains[i][0];
				dataV2[1] = l1_chains[i][1];
				dataV2[2] = l1_chains[j][1];
				l2_chains.push_back(dataV2);
				continue;
			}
			if(l1_chains[i][0] == l1_chains[j][1]){
				int *dataV2 = new int[3];
				dataV2[0] = l1_chains[j][0];
				dataV2[1] = l1_chains[j][1];
				dataV2[2] = l1_chains[i][1];
				l2_chains.push_back(dataV2);
			}
		}
	}

	size = l2_chains.size();
	vector<int*> l3_chains;
	const int nl3 = 4;
	for(int i=0;i<size;i++){
                if(l2_chains[i][0] == l2_chains[i][nl3-2]){
                        continue;
                }

		for(int j=i+1;j<size;j++){
                	if(l2_chains[j][0] == l2_chains[j][nl3-2]){
                	        continue;
                	}

			chain = true;
			for(int k=0;k<nl3-2;k++){
				if(l2_chains[i][k+1] != l2_chains[j][k]) {
					chain = false;
					break;
				}	
			}
			if(chain){
				int *dataV2 = new int[nl3];
				for(int k=0;k<nl3-1;k++){
					dataV2[k] = l2_chains[i][k];
				}
				dataV2[nl3-1] = l2_chains[j][nl3-2];
				l3_chains.push_back(dataV2);
				continue;
			}

			chain = true;
			for(int k=0;k<nl3-2;k++){
				if(l2_chains[i][k] != l2_chains[j][k+1]) {
					chain = false;
					break;
				}	
			}
			if(chain){
				int *dataV2 = new int[nl3];
				for(int k=0;k<nl3-1;k++){
					dataV2[k] = l2_chains[j][k];
				}
				dataV2[nl3-1] = l2_chains[i][nl3-2];
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
			if(l3_chains[j][0] == l3_chains[j][nl4-2]){
				continue;
			}
			chain = true;
			for(int k=0;k<nl4-2;k++){
				if(l3_chains[i][k+1] != l3_chains[j][k]) {
					chain = false;
					break;
				}	
			}
			if(chain){
				int *dataV2 = new int[nl4];
				for(int k=0;k<nl4-1;k++){
					dataV2[k] = l3_chains[i][k];
				}
				dataV2[nl4-1] = l3_chains[j][nl4-2];
				l4_chains.push_back(dataV2);
				continue;
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
				for(int k=0;k<nl4-1;k++){
					dataV2[k] = l3_chains[j][k];
				}
				dataV2[nl4-1] = l3_chains[i][nl4-2];
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
			if(l4_chains[j][0] == l4_chains[j][nl5-2]){
				continue;
			}
			chain = true;
			for(int k=0;k<nl5-2;k++){
				if(l4_chains[i][k+1] != l4_chains[j][k]) {
					chain = false;
					break;
				}	
			}
			if(chain){
				int *dataV2 = new int[nl5];
				for(int k=0;k<nl5-1;k++){
					dataV2[k] = l4_chains[i][k];
				}
				dataV2[nl5-1] = l4_chains[j][nl5-2];
				l5_chains.push_back(dataV2);
				continue;
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
				for(int k=0;k<nl5-1;k++){
					dataV2[k] = l4_chains[j][k];
				}
				dataV2[nl5-1] = l4_chains[i][nl5-2];
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
			if(l5_chains[j][0] == l5_chains[j][nl6-2]){
				continue;
			}
			chain = true;
			for(int k=0;k<nl6-2;k++){
				if(l5_chains[i][k+1] != l5_chains[j][k]) {
					chain = false;
					break;
				}	
			}
			if(chain){
				int *dataV2 = new int[nl6];
				for(int k=0;k<nl6-1;k++){
					dataV2[k] = l5_chains[i][k];
				}
				dataV2[nl6-1] = l5_chains[j][nl6-2];
				l6_chains.push_back(dataV2);
				continue;
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
				for(int k=0;k<nl6-1;k++){
					dataV2[k] = l5_chains[j][k];
				}
				dataV2[nl6-1] = l5_chains[i][nl6-2];
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
			if(l6_chains[j][0] == l6_chains[j][nl7-2]){
				continue;
			}
			chain = true;
			for(int k=0;k<nl7-2;k++){
				if(l6_chains[i][k+1] != l6_chains[j][k]) {
					chain = false;
					break;
				}	
			}
			if(chain){
				int *dataV2 = new int[nl7];
				for(int k=0;k<nl7-1;k++){
					dataV2[k] = l6_chains[i][k];
				}
				dataV2[nl7-1] = l6_chains[j][nl7-2];
				l7_chains.push_back(dataV2);
				continue;
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
				for(int k=0;k<nl7-1;k++){
					dataV2[k] = l6_chains[j][k];
				}
				dataV2[nl7-1] = l6_chains[i][nl7-2];
				l7_chains.push_back(dataV2);
			}
		}
	}
	
	vector<int*> loop_chains7;
	size = l7_chains.size();
	for(int i=0;i<size;i++){
		if(l7_chains[i][0] == l7_chains[i][nl7-1]){
			loop_chains7.push_back(l7_chains[i]);	
		}
	}

        clock_t mid = clock();

	cout << "mid time is : " << (mid - start)/1e6 << "s\n";


	size = loop_chains3.size();
	vector<int*> Loop_chains3;

	for(int i=0;i<size;i++){
		int index = distance(loop_chains3[i],min_element(loop_chains3[i],loop_chains3[i]+nl3-1));
		int *dataV3 = new int[nl3-1];
		for(int j=index;j<nl3-1;j++)
			dataV3[j-index] = loop_chains3[i][j];
		for(int j=0;j<index;j++)
			dataV3[nl3-1 - index + j] = loop_chains3[i][j];
		Loop_chains3.push_back(dataV3);
	}


	vector<char*> result;
	int nloops = 0;
	for(int i=0;i<size-1;i++){
		for(int j=0;j<size-1-i;j++){
			if(Loop_chains3[j][0] > Loop_chains3[j+1][0]){	
				int *tmp_arr = new int[nl3-1];
				for(int k=0;k<nl3-1;k++){
					tmp_arr[k] = Loop_chains3[j+1][k];
				}
				for(int k=0;k<nl3-1;k++){
					Loop_chains3[j+1][k] = Loop_chains3[j][k];
				}
				for(int k=0;k<nl3-1;k++){
					Loop_chains3[j][k] = tmp_arr[k];
				}
			}
		}
	}
	for(int i=0;i<size;i++){
		if(i>0){
			if(Loop_chains3[i][0] == Loop_chains3[i-1][0] && Loop_chains3[i][1] == Loop_chains3[i-1][1]) continue;
		}
		nloops++;
		for(int j=0;j<nl3-1;j++){
			char *strs = new char[100];
			if(j < nl3-2) sprintf(strs,"%i,",Loop_chains3[i][j]);
			else sprintf(strs,"%i\n",Loop_chains3[i][j]);
			result.push_back(strs);
		}
	}

	size = loop_chains4.size();
	vector<int*> Loop_chains4;

	for(int i=0;i<size;i++){
		int index = distance(loop_chains4[i],min_element(loop_chains4[i],loop_chains4[i]+nl4-1));
		int *dataV3 = new int[nl4-1];
		for(int j=index;j<nl4-1;j++)
			dataV3[j-index] = loop_chains4[i][j];
		for(int j=0;j<index;j++)
			dataV3[nl4-1 - index + j] = loop_chains4[i][j];
		Loop_chains4.push_back(dataV3);
	}


	for(int i=0;i<size-1;i++){
		for(int j=0;j<size-1-i;j++){
			if(Loop_chains4[j][0] > Loop_chains4[j+1][0]){	
				int *tmp_arr = new int[nl4-1];
				for(int k=0;k<nl4-1;k++){
					tmp_arr[k] = Loop_chains4[j+1][k];
				}
				for(int k=0;k<nl4-1;k++){
					Loop_chains4[j+1][k] = Loop_chains4[j][k];
				}
				for(int k=0;k<nl4-1;k++){
					Loop_chains4[j][k] = tmp_arr[k];
				}
			}
		}
	}
	for(int i=0;i<size;i=i+1){
		if(i>0){
			if(Loop_chains4[i][0] == Loop_chains4[i-1][0] && Loop_chains4[i][1] == Loop_chains4[i-1][1]) continue;
		}
		nloops++;
		for(int j=0;j<nl4-1;j++){
			//if(j < nl4-2) cout << Loop_chains4[i][j] << ",";
			//else cout << Loop_chains4[i][j] << "\n";
			char *strs = new char[100];
			if(j < nl4-2) sprintf(strs,"%i,",Loop_chains4[i][j]);
			else sprintf(strs,"%i\n",Loop_chains4[i][j]);
			result.push_back(strs);
		}
	}



	size = loop_chains5.size();
	vector<int*> Loop_chains5;

	for(int i=0;i<size;i++){
		int index = distance(loop_chains5[i],min_element(loop_chains5[i],loop_chains5[i]+nl5-1));
		int *dataV3 = new int[nl5-1];
		for(int j=index;j<nl5-1;j++)
			dataV3[j-index] = loop_chains5[i][j];
		for(int j=0;j<index;j++)
			dataV3[nl5-1 - index + j] = loop_chains5[i][j];
		Loop_chains5.push_back(dataV3);
	}


	for(int i=0;i<size-1;i++){
		for(int j=0;j<size-1-i;j++){
			if(Loop_chains5[j][0] > Loop_chains5[j+1][0]){	
				int *tmp_arr = new int[nl5-1];
				for(int k=0;k<nl5-1;k++){
					tmp_arr[k] = Loop_chains5[j+1][k];
				}
				for(int k=0;k<nl5-1;k++){
					Loop_chains5[j+1][k] = Loop_chains5[j][k];
				}
				for(int k=0;k<nl5-1;k++){
					Loop_chains5[j][k] = tmp_arr[k];
				}
			}
		}
	}
	for(int i=0;i<size;i=i+1){
		if(i>0){
			if(Loop_chains5[i][0] == Loop_chains5[i-1][0] && Loop_chains5[i][1] == Loop_chains5[i-1][1]) continue;
		}
		nloops++;
		for(int j=0;j<nl5-1;j++){
			//if(j < nl5-2) cout << Loop_chains5[i][j] << ",";
			//else cout << Loop_chains5[i][j] << "\n";
			char *strs = new char[100];
			if(j < nl5-2) sprintf(strs,"%i,",Loop_chains5[i][j]);
			else sprintf(strs,"%i\n",Loop_chains5[i][j]);
			result.push_back(strs);
		}
	}


	size = loop_chains6.size();
	vector<int*> Loop_chains6;

	for(int i=0;i<size;i++){
		int index = distance(loop_chains6[i],min_element(loop_chains6[i],loop_chains6[i]+nl6-1));
		int *dataV3 = new int[nl6-1];
		for(int j=index;j<nl6-1;j++)
			dataV3[j-index] = loop_chains6[i][j];
		for(int j=0;j<index;j++)
			dataV3[nl6-1 - index + j] = loop_chains6[i][j];
		Loop_chains6.push_back(dataV3);
	}


	for(int i=0;i<size-1;i++){
		for(int j=0;j<size-1-i;j++){
			if(Loop_chains6[j][0] > Loop_chains6[j+1][0]){	
				int *tmp_arr = new int[nl6-1];
				for(int k=0;k<nl6-1;k++){
					tmp_arr[k] = Loop_chains6[j+1][k];
				}
				for(int k=0;k<nl6-1;k++){
					Loop_chains6[j+1][k] = Loop_chains6[j][k];
				}
				for(int k=0;k<nl6-1;k++){
					Loop_chains6[j][k] = tmp_arr[k];
				}
			}
		}
	}

	for(int i=0;i<size;i=i+1){
		if(i>0){
			if(Loop_chains6[i][0] == Loop_chains6[i-1][0] && Loop_chains6[i][1] == Loop_chains6[i-1][1]) continue;
		}
		nloops++;
		for(int j=0;j<nl6-1;j++){
			//if(j < nl6-2) cout << Loop_chains6[i][j] << ",";
			//else cout << Loop_chains6[i][j] << "\n";
			char *strs = new char[100];
			if(j < nl6-2) sprintf(strs,"%i,",Loop_chains6[i][j]);
			else sprintf(strs,"%i\n",Loop_chains6[i][j]);
			result.push_back(strs);
		}
	}





	size = loop_chains7.size();
	vector<int*> Loop_chains7;

	for(int i=0;i<size;i++){
		int index = distance(loop_chains7[i],min_element(loop_chains7[i],loop_chains7[i]+nl7-1));
		int *dataV3 = new int[nl7-1];
		for(int j=index;j<nl7-1;j++)
			dataV3[j-index] = loop_chains7[i][j];
		for(int j=0;j<index;j++)
			dataV3[nl7-1 - index + j] = loop_chains7[i][j];
		Loop_chains7.push_back(dataV3);
	}


	for(int i=0;i<size-1;i++){
		for(int j=0;j<size-1-i;j++){
			if(Loop_chains7[j][0] > Loop_chains7[j+1][0]){	
				int *tmp_arr = new int[nl7-1];
				for(int k=0;k<nl7-1;k++){
					tmp_arr[k] = Loop_chains7[j+1][k];
				}
				for(int k=0;k<nl7-1;k++){
					Loop_chains7[j+1][k] = Loop_chains7[j][k];
				}
				for(int k=0;k<nl7-1;k++){
					Loop_chains7[j][k] = tmp_arr[k];
				}
			}
		}
	}
	for(int i=0;i<size;i=i+1){
		if(i>0){
			if(Loop_chains7[i][0] == Loop_chains7[i-1][0] && Loop_chains7[i][1] == Loop_chains7[i-1][1]) continue;
		}
		nloops++;
		for(int j=0;j<nl7-1;j++){
			//if(j < nl7-2) cout << Loop_chains7[i][j] << ",";
			//else cout << Loop_chains7[i][j] << "\n";
			char *strs = new char[100];
			if(j < nl7-2) sprintf(strs,"%i,",Loop_chains7[i][j]);
			else sprintf(strs,"%i\n",Loop_chains7[i][j]);
			result.push_back(strs);
		}
	}

	cout << nloops << "\n";
	size = result.size();
	for(int i=0;i<size;i++){
		cout << result[i];
	}
	

	clock_t end = clock();

	cout << "total time is : " << (end - start)/1e6 << "s\n"; 

	return 0;
}
