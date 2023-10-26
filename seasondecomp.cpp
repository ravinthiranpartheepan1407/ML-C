#include<iostream>
#include<cmath>
#include<vector>


using namespace std;

vector<double> seasondecomp(vector<double> x){
    vector<double> timeSeriesComp, seasonIndex, seasonComponent, residualComponent;
    double mean = 0.0;

    // Calculating Mean Value
    for(size_t elements = 0; elements < x.size(); elements++){
        mean += x[elements];
    }
    double meanOut = mean / x.size();

    // Calculating the Seasonal Indices
    for(size_t elements = 0; elements < x.size(); elements++){
        double index = x[elements] / meanOut;
        seasonIndex.push_back(index);
    }

    // Calculating Seasonal Component
    for(size_t elements = 0; elements < seasonIndex.size(); elements++){
        double component = seasonIndex[elements] * meanOut;
        seasonComponent.push_back(component);
    }

    // Calculating Residual Component
    for(size_t elements = 0; elements < x.size(); elements++){
        double residual = x[elements] - seasonComponent[elements];
        residualComponent.push_back(residual);
    }

    // Re-Constructing Original Time Series
    for(size_t elements = 0; elements < x.size(); elements++){
        double timeSeries = meanOut + seasonComponent[elements] + residualComponent[elements];
        timeSeriesComp.push_back(timeSeries);
    }

    cout<<"Mean Value is: "<<meanOut<<endl;
    
    for(size_t elements = 0; elements < seasonIndex.size(); elements++){
        cout<<"Season Index: "<<seasonIndex[elements]<<endl;
    }

    for(size_t elements = 0; elements < seasonComponent.size(); elements++){
        cout<<"Season Component: "<<seasonComponent[elements]<<endl;
    }

    for(size_t elements = 0; elements < residualComponent.size(); elements++){
        cout<<"Residual Component: "<<residualComponent[elements]<<endl;
    }

    return timeSeriesComp;
}

int main(){
    vector<double> x = {100,110,120,105,115,125,130,135,140,150,160,155};
    vector<double> res = seasondecomp(x);
    for(size_t elements = 0; elements < res.size(); elements++){
        cout<<"Season Decomposition: "<<res[elements]<<endl;
    }
}