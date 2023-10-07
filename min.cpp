#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

double min(vector<double> x){
    int minValue = x[0];
    for(size_t elements = 0; elements < x.size(); elements++){
        if(x[elements] < minValue){
            minValue = x[elements];
        }
    }
    cout<<"The min value: ";
    return minValue;
}

int main(){
    vector<double> x = {15,7,45,49};
    cout<<min(x);
}