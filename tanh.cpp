#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

vector<double> tanh(vector<double> x){
    vector<double> tanH;
    double expoVal;
    for(size_t elements = 0; elements < x.size(); elements++){
        double expoElements = 1 + exp(2*(-x[elements]));
        double expoDiv = (2 / expoElements) - 1;
        tanH.push_back(expoDiv);
    }
    return tanH;
}

int main(){
    vector<double> x = {0.10, 0.25, 0.27, 0.42, -0.21};
    vector<double> tanHOut = tanh(x);
    for(size_t elements = 0; elements < x.size(); elements++){
        cout<<"TanH Value: "<<tanHOut[elements]<<endl;
    }
}