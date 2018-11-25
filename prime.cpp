//
// Created by Vivian on 2018/Nov/25
//
#include <stdio.h>
#include <iostream>
#include <fstream>
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
    return r;
}
int main(){
    ofstream outputf("output_prime.txt");
    outputf << '0';
    for (int i =0;i<100;i++){
        if (isPrime(i) == true){
            string num;
            num = ConvertBinary(i);
            outputf << num;
        }
    }
    return 0;
}

