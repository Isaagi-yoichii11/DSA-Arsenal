#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> sieve_of_eratosthenes(int number){

    if(number <= 1) return {};

    vector<bool>prime(number+1,true);

    prime[0] = false;
    prime[1] = false;

    for(int i=2; i*i<=number;i++){
        if(prime[i] == true){
            for(int j=i*i;j<=number;j+=i){
                prime[j] = false;
            }
        }
    }

    vector<int>ans;

    for(int i=0;i<=number;i++){
        if(prime[i]){
            ans.push_back(i);
        }
    }

    return ans;
}

int main()
{
    int number = 35;
    vector<int>ans = sieve_of_eratosthenes(number);
    for(auto it:ans){
        cout<<it<<" ";
    }

    return 0;
}