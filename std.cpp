#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

double popstd(vector<double> x){
    double mean, sqrdSum;
    // Mean calculation
    for(size_t elements = 0; elements < x.size(); elements++){
        // mean calculation
        double meanCalc = x[elements] / x.size();
        mean += meanCalc;
    }
    // Squared difference between elements and mean
    for(size_t elements = 0; elements < x.size(); elements++){
        double sqrdDiff = x[elements] - mean;
        double powSqrDiff = pow(sqrdDiff, 2);
        sqrdSum += powSqrDiff;
    }
    // Population data
    double popStd = x.size();
    
    // Calculate Population Standard Deviation
    double std = sqrt(sqrdSum / popStd);
    return std;
}

int main(){
    vector<double> x = {10,20,30,40,50, 60};
    cout<<popstd(x);
}