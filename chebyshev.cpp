// Chebyshev Distance
#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int chebyshev(vector<double> xData, vector<double> yData){
    vector<double> stack;
    int iterate = 0;
    for(size_t elements = 0; elements < xData.size(); elements++){
        double calc = abs(xData[elements] - yData[elements]);
        stack.push_back(calc);
        cout<<stack[elements]<<endl;
    }

    for(size_t elements = 0; elements < stack.size(); elements++){
        if(stack[elements] > iterate){
            iterate = stack[elements];   
        }
    }
    cout<<"The max value is: ";  
    return iterate;
}

int main(){
    vector<double> xData = {1,2,3,4,5};
    vector<double> yData = {2,9,8,7,6};
    cout<<chebyshev(xData, yData);
}