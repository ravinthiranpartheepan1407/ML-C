#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

double entropy(vector<double> xData, vector<double> yData){
    double deltaS = 0;
    vector<double> xCalcHS, yCalcHS;
    double sizeX = xData.size();
    double sizeY = yData.size();
    double partX = sizeX/(sizeX+sizeY);
    double partY = sizeY/(sizeX+sizeY);
    double xCalc = -((partX) * log2(partX));
    double yCalc = (partY) * log2(partY);
    double hS = xCalc - yCalc;
    deltaS += hS;    
    return deltaS;
}

int main(){
    vector<double> xData = {2.4, 3.7};
    vector<double> yData = {1.1, 2.5, 3.4, 6.7, 8.9};
    cout<<entropy(xData, yData);
}