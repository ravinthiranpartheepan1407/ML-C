#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

vector<double> dexposmooth(vector<double> x, double alpha, double beta){
    // SES_t = α * Y_t + (1 - α) * SES_(t-1)
    for(size_t elements = 0; elements < x.size(); elements++){

    }
    // DES_t = Beta * (SES_t * SES_t-1) + (1 - Beta) * DES_(t-1)
    
    // Forecast = ( (SES_t-1) - (DES_t-1) )
}

int main(){
    vector<double> x = {10,20,30,40};
    double alpha = 0.2;
    double beta = 0.2;
    vector<double> res = dexposmooth(x, alpha, beta);
    for(size_t elements = 0; elements < res.size(); elements++){
        cout<<"The Double Exponential Smoothing Values are: "<<res[elements]<<endl;
    }
}