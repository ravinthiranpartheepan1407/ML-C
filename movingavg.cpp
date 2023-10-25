#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

vector<double> movingavg(vector<double> x, int criteria){

   vector<double> result;
    
    for (int elementX = criteria - 1; elementX < x.size(); elementX++) {
        double mvCalc = 0.0;
        
        // Calculate the moving average for the current window
        for (int elementY = 0; elementY < criteria; elementY++) {
            mvCalc += x[elementX - elementY];
            cout<<"MV cacl: "<<x[elementX]<<" "<<" - "<<x[elementY]<<endl;
        }
        
        // Calculate the average and add it to the result vector
        double out = mvCalc / criteria;
        result.push_back(out);
    }
    return result;
}

int main(){
    vector<double> x = {75,78,82,79,83,88,87};
    int criteria = 3;
    // int key = criteria;
    movingavg(x, criteria);
    vector<double> out = movingavg(x, criteria);
    for(size_t elements = 0; elements < out.size(); elements++){
        cout<<"Moving Averages are: "<<out[elements]<<endl;
    }
}