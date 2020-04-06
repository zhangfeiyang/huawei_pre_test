{

	int N1 = 100;
	int N2 = 300;
	int N3 = 50;
	for(int i=0;i<N1;i++){
		for(int j=i+1;j<N1;j++){
			for(int k=j+1;k<N1;k++){
				if(k==20) break;
			}
		}
		cout << i << "\n";
	}

}
