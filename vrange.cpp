#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

vector<double> vrange(int start, int stop, int step){
    vector<double> vrangeContainer;
    int stack = start;
    for(int elements = start; elements < stop; elements++){
        if(stack < stop){
            vrangeContainer.push_back(stack);
            stack = stack + step;
        }else{
            break;
        }
    }
    return vrangeContainer;
}

int main(){
    int start = 3;
    int stop = 15;
    int step = 3;
    vector<double> vrangeItr = vrange(start, stop, step);
    for(size_t elements = 0; elements < vrangeItr.size(); elements++){
        cout<<"The values: "<<vrangeItr[elements]<<endl;
    }
}