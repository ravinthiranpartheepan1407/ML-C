#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

void momentum(vector<double> x, vector<double> y, double input, double learning_rate, double momentCoe, int itr){
    // y= mx+ b
    // y isthe predicted value
    // x is the number of input,
    // m i sthe slope
    // b is the intercept

    vector<double> slopeRes, interRes;
    double xMean, yMean;

      // Calculate Mean of Feature 1
    for(size_t elements = 0; elements < x.size(); elements++){
         xMean += x[elements] / x.size();
    }

    // Calculate Mean of Feature 2
    for(size_t elements = 0; elements < y.size(); elements++){
        yMean += y[elements] / y.size();
    }

    for(int iteration = 0; iteration < itr; iteration++){
        double prodXY, xyProd, slope, intercept, lsq, mseVal, pdSlope, pdIntercept, slopeNew, interceptNew;
        double momentSlopeT = 0;
        double momentInterT = 0;
        vector<double> predict;

        // Find Slope 'm'
        for(size_t elements = 0; elements < x.size(); elements++){
            prodXY += (x[elements] - xMean) * (y[elements] - yMean);
            xyProd += pow((x[elements] - xMean),2);
            slope = prodXY / xyProd;
        }

        // Find Intercept 'b
        intercept = yMean - ((slope) * xMean);

        // Least Square Metric
        lsq = (slope * input) + intercept;

        // Iteration
        for(size_t elements = 0; elements < x.size(); elements++){
            double predictVal = (slope * x[elements]) + intercept;
            predict.push_back(predictVal);
        }

        for(size_t elements = 0; elements < predict.size(); elements++){
            cout<<"Predicted Iteration: "<<predict[elements]<<endl;
        }

        // Calculate Gradient Descent with respect to slope and intercept
        // Slope Evaluation
        // Partial Derivatives of 'm' Slope
        for(size_t elements = 0; elements < x.size(); elements++){
            pdSlope = -2 * x[elements] * (y[elements] - 0);
        }

        // Partial Derivatives of 'b' Intercept
        for(size_t elements = 0; elements < x.size(); elements++){
            pdIntercept = -2 * (y[elements] - 0);
        }

        // Update Momentum for Slope and Intercept
        for(int elements = 0; elements < itr; elements++){
            slopeRes.push_back(momentSlopeT);
            double momentSlope = momentCoe * momentSlopeT - learning_rate * (pdSlope);
            double momentInter = momentCoe * momentInterT - learning_rate * (pdIntercept);
            double momentSlopeTRes = slope + momentSlope;
            double momentInterRes = intercept + momentInter;
            momentSlopeT = momentSlopeTRes;
            momentInterT = momentInterRes;
        }         
        
        cout<<"Mean of X: "<<xMean<<endl;
        cout<<"Mean of Y: "<<yMean<<endl;
        cout<<"Slope: "<<slope<<endl;
        cout<<"Intercept: "<<intercept<<endl;
        cout<<"The Predicted values is: "<<lsq<<endl;
        cout<<"Partial Derivative of Slope: "<<pdSlope<<endl;
        cout<<"Partial Derivative of Intercept: "<<pdIntercept<<endl;
        cout<<"Updated Slope Moment: "<<momentSlopeT<<endl;
        cout<<"-------- End of Iteration: "<<itr<<" --------"<<endl;
    }
    // return slopeRes;
}

int main(){
    vector<double> x = {1,2,3,4,5};
    vector<double> y = {300,500,700,900,1100};
    double learningRate = 0.01;
    double input = 7;
    int itr = 2;
    double momentCoe = 0.9;
    // vector<double> momentumInter = momentum(x,y,input,learningRate,momentCoe,itr);
    // for(size_t elements = 0; elements < momentumInter.size(); elements++){
    //     cout<<momentumInter[elements]<<endl;
    // }
    momentum(x,y,input,learningRate,momentCoe,itr);
}