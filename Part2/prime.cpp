//
// Created by Vivian on 2018/Nov/25
//
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


bool isPrime(int num){
    int i;

    if (num == 2)
        return true;
    else{
        for (i=2; i<num; i++) {
            if (num%i == 0){
                return false;
            }
        }
    }
    return true;
}

string ConvertBinary(int n)
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

void generate_prime_base10(int power){
	string filename="output_prime_10^"+to_string(power)+".txt";
	ofstream outputf(filename);
	outputf << '0';
	for (int i =0;i<pow(10,power);i++){
		if (isPrime(i)){
			string num;
			num = ConvertBinary(i);
			outputf << num;
		}
	}
}

void generate_prime_base2(int power){
	string filename="output_prime_2^"+to_string(power)+".txt";
	ofstream outputf(filename);
	outputf << '0';
	for (int i =0;i<pow(2,power);i++){
		if (isPrime(i)){
			string num;
			num = ConvertBinary(i);
			outputf << num;
		}
	}
}

int main(){
	for (int i = 0; i < 18; ++i) {
		generate_prime_base2(i);
	}
}

