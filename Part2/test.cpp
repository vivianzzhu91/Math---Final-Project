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
	int run = 0;

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

	float mean = (float)(2*n1*n2) / (float)(n1+n2);
	float variance = (float) (2*n1*n2) * (2*n1*n2 - n1 - n2) / (float) (pow(n1+n2,2)) * float(n1+n2-1);
	float zvalue = (float)(run - mean + 0.5) / (float) (pow(variance, 0.5));

	ofstream outputf("result.txt");
	outputf << mean;
	outputf << endl;
	outputf << variance;
	outputf << endl;
	outputf << run;
	outputf << endl;
	outputf << zvalue;
	outputf << endl;



	return 0;
}
