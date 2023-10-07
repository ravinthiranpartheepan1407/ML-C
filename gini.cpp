#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

double gini(vector<double> xData, vector<double> yData){
    double sizeX = xData.size();
    double sizeY = yData.size();
    double partX = sizeX/(sizeX+sizeY);
    double partY = sizeY/(sizeX+sizeY);
    double giniXSquare = pow(partX, 2);
    double giniYSquare = pow(partY, 2);
    double ginIndex = 1 - (giniXSquare + giniYSquare);
    return ginIndex;
}

int main(){
    vector<double> xData = {0.2, 0.3, 0.1, 0.4};
    vector<double> yData = {0.1, 0.4, 0.2, 0.3, 0.8, 0.10};
    cout<<gini(xData, yData);
}