#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

vector<double> sigmoid(vector<double> x){
    vector<double> sigmoidOut;
    for(size_t elements = 0; elements < x.size(); elements++){
        double sigmoidDenom = 1 + exp(-x[elements]);
        double sigmoidNom = 1 / sigmoidDenom;
        sigmoidOut.push_back(sigmoidNom);
    }
    return sigmoidOut;
}

int main(){
    vector<double> x = {0.10, 0.25, 0.27, 0.42, 21};
    vector<double> sigmoidRes = sigmoid(x);
    for(size_t elements = 0; elements < x.size(); elements++){
        cout<<sigmoidRes[elements]<<endl;
    }
}