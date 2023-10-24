#include<vector>
#include<cmath>
#include<iostream>

using namespace std;

vector<double> maxpool1D(vector<double> x, int pool_size, int stride, string option){
    vector<double> result;
    vector<double> none;
    double out;
    if (option == "accept"){
        for(size_t elements = stride; elements < x.size(); elements++){
            double res = ((x.size() - pool_size) + 1) / stride;
            result.push_back(x[elements]);
            out = res;
        }
    }else if(option == "equal"){
        // Stride: 2
        // index[0] + 2 = index[2]
        // index[2] + 2 = index[4]
        int start = stride - 1; // [1], 
        int stop = x.size(); // [4]
        int stack = start;
        double res = x.size() / stride;
        for(int elements = start; elements < stop; elements++){
            if(stack < stop){
                result.push_back(x[stack]);
                stack = stack + stride;
            }else{
                break;
            }
        }
        out = res;
    }else{
        return none;
    }
    return result;
}

int main(){
    vector<double> x = {-20, -1.0, 0.0, 5.0, 20, -21.7, 43, 57.8, -111.8};
    int stride = 3;
    string option = "accept";
    int pool_size = 2;
    vector<double> maxpool = maxpool1D(x, pool_size, stride, option);
    for(size_t elements = 0; elements < maxpool.size(); elements++){
        cout<<"Max Pooling 1D Values: "<<maxpool[elements]<<endl;
    }
}