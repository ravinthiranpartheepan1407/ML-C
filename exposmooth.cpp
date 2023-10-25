#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

vector<double> exposmooth(vector<double> x, double alpha){
    // SES_t = α * Y_t + (1 - α) * SES_(t-1)
    vector<double> result;
    int fStep = 0;
    int bStep = 1;
    for(size_t elements = 0; elements < x.size(); elements++){
        double alphAct = alpha * x[fStep];
        double smooth = (1-alpha) * x[bStep];
        // cout<<"AplhaAct: "<<alphAct<<" + "<<smooth<<endl;
        double out = alphAct + smooth;
        result.push_back(out);
        fStep = fStep + 1;
        bStep = bStep - 1;
    }
    return result;
}

int main(){
    vector<double> x = {10,20,30,40,50};
    double alpha = 0.2;
    vector<double> res = exposmooth(x, alpha);
    for(size_t elements = 0; elements < res.size(); elements++){
        cout<<"Exponential Smoothin Values: "<<res[elements]<<endl;
    }
}