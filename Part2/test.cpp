#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;


int main(int argc, char *argv[]) {
	
	string filename(argv[1]);
	ifstream inputf(filename);
	string num;
	inputf >> num;
	
	int n1 = 0;
	int n2 = 0;
	int run = 1;
	
	for (size_t i = 0; i < num.length(); i++) {
		if (i > 0 && num[i] != num[i - 1]) {
			run++;
		}
		if (num[i] == '1') {
			n1++;
		} else {
			n2++;
		}
	}
	
	auto mean = static_cast<long long>(((double) (2 * n1 * n2) / (double) (n1 + n2)) + 1);
	auto step1=static_cast<double>(2 * n1 * n2);
	auto step2=static_cast<double>(2 * n1 * n2 - n1 - n2);
	auto step3= pow(n1 + n2, 2);
	auto step4=static_cast<double>((n1 + n2 - 1));
	auto result=step1/step3/step4*step2;
	// auto variance = static_cast<double>(2 * n1 * n2) * static_cast<double>((2 * n1 * n2 - n1 - n2))
	//                        / pow(n1 + n2, 2) / static_cast<double>((n1 + n2 - 1));
	auto variance = result;
	double zvalue = (run - mean + 0.5) / (pow(variance, 0.5));
	
	ofstream outputf("result.txt");
	// cout<<n1<<" "<<n2<endl;
	outputf << "n1:\t" << n1 << endl;
	outputf << "n2:\t" << n2 << endl;
	outputf << "Mean:\t" << mean << endl;
	outputf << "Variance:\t" << variance << endl;
	outputf << "Run Num:\t" << run << endl;
	outputf << "Z-Value:\t" << zvalue << endl;
	if (zvalue > 1.96) {
		outputf << "Reject" << endl;
	}
	
	
	return 0;
}
