#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool checkPrime(int num){
    if(num <= 1) return false;

    for(int i=2;i*i<=num;i++){
        if(num % i == 0){
            return false;
        }
    }

    return true;
}

int main()
{
    int num = 98;
    return 0;
}