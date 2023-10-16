#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

void anova(vector<double> x, vector<double> y, vector<double> z){
    // Each Groups: SSW
        // Sum
        double sumX, sumY, sumZ, meanXVal, meanYVal, meanZVal, sampXMean, sampYMean, sampZMean, xSSWG, ySSWG, zSSWG, xMeanTot, yMeanTot, zMeanTot, xObsVal, yObsVal, zObsVal;
        vector<double> obs;
        for(size_t elements = 0; elements < x.size(); elements++){
            sumX += x[elements];
            sumY += y[elements];
            sumZ += y[elements];
        }
        // Mean
        meanXVal = sumX / x.size();
        meanYVal = sumY / y.size();
        meanZVal = sumZ / z.size();
        // Sum(Sample - Mean)
        for(size_t elements = 0; elements < x.size(); elements++){
            double diff = x[elements] - meanXVal;
            sampXMean += diff;
        }
        for(size_t elements = 0; elements < y.size(); elements++){
            double diff = y[elements] - meanYVal;
            sampYMean += diff;
        }
          for(size_t elements = 0; elements < z.size(); elements++){
            double diff = z[elements] - meanZVal;
            sampZMean += diff;
        }
        // SSW (Sum of Squares within groups) = Sum(Square(Sample - Mean))
        for(size_t elements = 0; elements < x.size(); elements++){
            double diff = x[elements] - meanXVal;
            double sqr = pow(diff, 2);
            xSSWG += sqr;
        }
        for(size_t elements = 0; elements < y.size(); elements++){
            double diff = y[elements] - meanYVal;
            double sqr = pow(diff, 2);
            ySSWG += sqr;
        }
        for(size_t elements = 0; elements < z.size(); elements++){
            double diff = z[elements] - meanZVal;
            double sqr = pow(diff, 2);
            zSSWG += sqr;
        }
        double sswg = xSSWG + ySSWG + zSSWG;
        cout<<"The Sum of Square within group: "<<sswg<<endl;

    // Each Groups: TSS (Total Sum of Squares):
        // Mean of all observations
        for(size_t elements = 0; elements < x.size(); elements++){
            xMeanTot += x[elements];
            yMeanTot += y[elements];
            zMeanTot += z[elements];
        }
        double sizeXYZ = x.size() + y.size() + z.size();
        double meanTotObs = (xMeanTot + yMeanTot + zMeanTot) / sizeXYZ;
        cout<<"TSS Mean: "<<meanTotObs<<endl;
        // observation[index] - mean, Square (observation[index] - mean), and Sum(Square(Observation[index] - mean))
        for(size_t elements = 0; elements < x.size(); elements++){
            double xObs = x[elements] - meanTotObs;
            double sqr = pow(xObs, 2);
            xObsVal += sqr;
        }
        for(size_t elements = 0; elements < y.size(); elements++){
            double yObs = y[elements] - meanTotObs;
            double sqr = pow(yObs, 2);
            yObsVal += sqr;
        }
        for(size_t elements = 0; elements < z.size(); elements++){
            double yObs = z[elements] - meanTotObs;
            double sqr = pow(yObs, 2);
            zObsVal += sqr;
        }
        double tss = xObsVal + yObsVal + zObsVal;
        cout<<"The total sum of squares is: "<<tss<<endl;

    // Calculate Sum of Squares between groups
        // Sum of Squares between groups = Total sum of squares - Sum of squares within groups
        double xMeanSSBG = meanXVal - meanTotObs;
        double yMeanSSBG = meanYVal - meanTotObs;
        double zMeanSSBG = meanZVal - meanTotObs;
        double ssBG = xMeanSSBG + yMeanSSBG + zMeanSSBG;
        cout<<"The Sum of Squares between groups: "<<ssBG<<endl;
        // Total sum of squares = Sum of Squares between groups + Sum of squares within groups

    // Final Calculations
        // degress of freedom - 1 which is (total no.of groups) - 1
        // a = Sum of Squares between group / degrees of freedom 

        // degrees of freedom = total observations - total no.of groups
        // b = Sum of squares within groups / degrees of freedom

        // F = a / b
}

int main(){
    vector<double> x = {2,3,7,2,6};
    vector<double> y = {10,8,7,5,10};
    vector<double> z = {10,13,14,13,15};
    anova(x,y,z);
}