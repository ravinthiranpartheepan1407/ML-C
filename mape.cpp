#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

double mape(vector<double> actual, vector<double> predict){
    double absSum, sumActual;
    for(size_t elements = 0; elements < actual.size(); elements++){
        double diff = abs((actual[elements] - predict[elements]));
        cout<<"The difference between actual and predicted values: "<<diff<<endl;
        sumActual += actual[elements];
        absSum += (diff / sumActual);
    }
    double mapeOut = absSum / actual.size();
    return mapeOut;
}

int main(){
    vector<double> actual = {10.5,20.7,30.6};
    vector<double> predict = {11.12, 22.14, 33.16};
    cout<<mape(actual, predict);
}