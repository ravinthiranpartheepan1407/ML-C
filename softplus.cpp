#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<double> softplus(vector<double> x){
    // log(exp(x) + 1)
    vector<double> result;
    for(size_t elements = 0; elements < x.size(); elements++){
        double expRes = log(1 + exp(x[elements]));
        result.push_back(expRes);
    }
    return result;
}

int main(){
    vector<double> x = {-20, -1.0, 0.0, 1.0, 20};
    vector<double> res = softplus(x);
    for(size_t elements = 0; elements < res.size(); elements++){
        cout<<"Softplus values: "<<res[elements]<<endl;
    }
}