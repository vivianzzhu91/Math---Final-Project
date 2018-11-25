#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;


int main(int argc, char* argv[]){

	string filename(argv[1]);
	ifstream inputf (filename);
	string num;
	inputf >> num;

	int n1 = 0;
	int n2 = 0;
	int run = 1;

	for(size_t i = 0; i < num.length(); i ++){
		if(i >0 && num[i] != num[i-1]){
			run ++;
		}
		if(num[i] == '1'){
			n1 ++;
		}
		else{
			n2 ++;
		}
	}

	double mean = ((double)(2*n1*n2) / (double)(n1+n2) )+1;
	double variance = (double) (2*n1*n2) * (double)(2*n1*n2 - n1 - n2) /( (double) (pow(n1+n2,2)) * (double)(n1+n2-1));
	double zvalue = (double)(run - mean + 0.5) / (double) (pow(variance, 0.5));

	ofstream outputf("result.txt");
	// cout<<n1<<" "<<n2<endl;
	outputf << mean;
	outputf << endl;
	outputf << variance;
	outputf << endl;
	outputf << run;
	outputf << endl;
	outputf << zvalue;
	outputf << endl;
	outputf << n1;
	outputf << endl;
	outputf << n2;
	outputf << endl;



	return 0;
}
