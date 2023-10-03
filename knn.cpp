// Pseudo Code: 
    // 1. Load Training and Testing Data
    // 2. Choose the K value
    // 3. For each point in the data
        // 3.1  Choose the distance metric - Euclidean, Manhattan, and Minkowski
        // 3.2  Find the distance between each data points in the training dataset
        // 3.3  Choose the first K points
        // 3.4  Assign class label to the test point based on the majority of the classes present in the K values.

#include <iostream>
#include <cmath>

using namespace std;

int sqftCalc(int sqft[], int ipSqft){
    for(int elements=0; elements < (sizeof(sqft)/sizeof(sqft[0])); elements++){
        cout << "Comparing sqft from data: " << sqft[elements] << " " << "with" << " " << ipSqft<< endl;
        int distCalc =  pow((ipSqft - sqft[elements]), 2);
        cout<< "The calculated distance between each sqft: "<< sqft[elements] << " " << "and" << " " << ipSqft << " " << "is" << " " << distCalc <<endl;
        return distCalc;
    }
}

int bedCalc(int bedroom[], int ipBed){
    for(int elements = 0; elements < (sizeof(bedroom)/sizeof(bedroom[0])); elements++){
        cout << "Comparing Bedroom Freq from dataset: " << bedroom[elements] << " " << "with" << " " << "Requested Freq:" << " " << ipBed<< endl;
        int bedDistCalc = pow((ipBed - bedroom[elements]), 2);
        cout<< "The calculated distance between each bedroom: "<< bedroom[elements] << " " << "and" << " " << ipBed << " " << "is" << " " << bedDistCalc <<endl;
        return bedDistCalc;
    }
}

int bathCalc(int bathroom[], int ipBath){
    for(int elements = 0; elements < (sizeof(bathroom)/sizeof(bathroom[0])); elements++){
        cout << "Comparing bathroom Freq from dataset: " << bathroom[elements] << " " << "with" << " " << "Requested Freq:" << " " << ipBath<< endl;
        int bedDistCalc = pow((ipBath - bathroom[elements]), 2);
        cout<< "The calculated distance between each bathroom: "<< bathroom[elements] << " " << "and" << " " << ipBath << " " << "is" << " " << bedDistCalc <<endl;
        return bedDistCalc;
    }
}

void eculideanDist(int k, int sqft[], int bedroom[], int bathroom[], int ipSqft, int ipBed, int ipBath){
    int calcDist = sqftCalc(sqft, ipSqft) + bedCalc(bedroom, ipBed) + bathCalc(bathroom, ipBath);
    float out = sqrt(calcDist);
    cout<< "The distance is: " << out;
}

int main(){
    int k, ipSqft, ipBed, ipBath;
    
    cout << "Enter K Value: "<<endl;
    cin >> k;
    cout << "Enter Sqft Value: "<<endl;
    cin >> ipSqft;
    cout << "Enter Bedroom Frequency: "<<endl;
    cin >> ipBed;
    cout << "Enter Bathroom Frequency: "<<endl;
    cin >> ipBath;

    int sqft[5] = {1500,2000,1800,2100,1600}; 
    int bedroom[5] = {3,4,3,4,3};
    int bathroom[5] = {2,2,2,3,2};
    int price[5] = {250000, 320000, 300000, 350000, 270000};
    cout << sqftCalc(sqft, ipSqft);
    eculideanDist(k, sqft, bedroom, bathroom, ipSqft, ipBed, ipBath);
}
