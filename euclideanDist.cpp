#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

double euclidean(vector<double> xData, vector<double> yData){
    double sum = 0.0;
    for(size_t elements = 0; elements < xData.size(); elements++){
        double distCalc = pow((xData[elements] - yData[elements]), 2);
        sum += distCalc;
        cout<<distCalc<<endl;
    }
    double out = sqrt(sum);
    return out;
}

int main(){
    vector<double> xData = {1,3,5,7};
    vector<double> yData = {2,4,6,8};
    cout<<euclidean(xData, yData);
}