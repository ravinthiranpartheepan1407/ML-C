#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

vector<double> matmul(vector<double> x, vector<double> y){
    vector<double> out;

    return out;
}

int main(){
    vector<double> x = {2,4,6,8};
    vector<double> y = {1,3,6,9};
    vector<double> res = matmul(x,y);
    for(size_t elements = 0; elements < res.size(); elements++){
        cout<<res[elements];
    }
}