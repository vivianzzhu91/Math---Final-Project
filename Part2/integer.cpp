//
// Created by Vivian on 2018/Nov/25
//
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <cmath>
using namespace std;

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
    return r;
}

int main(){
    ofstream outputfile("output_2^5.txt");
    outputfile << '0';
    for (int i =0;i<=pow(2,5);i++){
        string line;
        line = ConvertBinary(i);
        outputfile << line;
    }
    return 0;
}