#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

// Earth Mover or Wasserstein Distance
void chamfer(vector<double> x, vector<double> y){
    // A to B Calculation
    double sumAB, sumBA;
    for(size_t elements = 0; elements < x.size(); elements++){
        double calcABDist = sqrt((x[elements] - y[elements]));
        cout<<"The Distance between Point A: "<<x[elements]<< " + "<<y[elements]<<" is: "<<calcABDist<<endl;
        double powAB = pow(calcABDist, 2);
        sumAB += powAB;
    }
    cout<<"Total Distance between A to B: "<<sumAB<<endl;

    // B to A Calculation
    for(size_t elements = 0; elements < x.size(); elements++){
        double calcBADist = sqrt((y[elements] - x[elements]));
        cout<<"The Distance between Point A: "<<x[elements]<< " + "<<y[elements]<<" is: "<<calcBADist<<endl;
        double powBA = pow(calcBADist, 2);
        sumBA += powBA;
    }

    // Total Distance Calculation
}

int main(){
    vector<double> x = {7,8,9};
    vector<double> y = {9,10,11};
    chamfer(x,y);
    // vector<double> res = chamfer(x,y);
    // for(size_t elements = 0; elements < res.size(); elements++){
    //     cout<<res[elements]<<endl;
    // }
}