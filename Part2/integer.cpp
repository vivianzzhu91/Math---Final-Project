//
// Created by Vivian on 2018/Nov/25
//
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <cmath>
using namespace std;

string ConvertBinary(long long n)
{
    string r;
    while(n!=0) {
        if(n%2 == 0){
            r += "0";
        }
        else{
            r += "1";
        }
        n/=2;
    }
	std::reverse(r.begin(), r.end());
    return r;
}

void output_base2(int power){
	string filename="output_2^"+to_string(power)+".txt";
	ofstream outputfile(filename);
	outputfile << '0';
	for (int i =0;i<=pow(2,power);i++) {
		string line = ConvertBinary(i);
		outputfile << line;
	}
}

void output_base10(int power){
	string filename="output_10^"+to_string(power)+".txt";
	ofstream outputfile(filename);
	outputfile << '0';
	for (int i =0;i<=pow(10,power);i++) {
		string line = ConvertBinary(i);
		outputfile << line;
	}
}

int main(){
	for (int i = 0; i < 5; ++i) {
		output_base2(i);
	}
	
	// int power=4;
	// string filename="output_2^"+to_string(power)+".txt";
    // ofstream outputfile(filename);
    // outputfile << '0';
    // for (int i =0;i<=pow(2,power);i++) {
	//     string line = ConvertBinary(i);
	//     std::reverse(line.begin(), line.end());
    //     outputfile << line;
    // }
    return 0;
}