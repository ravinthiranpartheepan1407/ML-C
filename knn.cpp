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
#include <vector>
#include<ostream>

using namespace std;

void dataTable(int sqft[], int bedroom[], int bathroom[], int price[], int size){
    for(int elements = 0; elements < size; elements++){
        cout << "Sqft: " << " " << sqft[elements] << "|" <<  " " << "Bedroom: " << " " << bedroom[elements] << "|" <<  " " << "Bathroom: " << " " << bathroom[elements] << "|" <<  " " << "Price: " << " " << price[elements] << "|" <<  " " << endl;
    }
}


void eculideanDist(int k, int sqft[], int bedroom[], int bathroom[], int ipSqft, int ipBed, int ipBath, int size){
    float dist[5];

    for(int elements=0; elements < size; elements++){
        cout << "Comparing sqft: " << sqft[elements] << " " << "with" << " " << ipSqft<< endl;
        int sqftDistCalc =  pow((ipSqft - sqft[elements]), 2);
        cout<< "Sqft"<< " " << sqft[elements] << " " << "and" << " " << ipSqft << " " << "is" << " " << sqftDistCalc <<endl;

        cout << "Comparing Bedroom Freq: " << bedroom[elements] << " " << "with" << " " << "Requested Freq:" << " " << ipBed<< endl;
        int bedDistCalc = pow((ipBed - bedroom[elements]), 2);
        cout<< "Bedroom"<< " " << bedroom[elements] << " " << "and" << " " << ipBed << " " << "is" << " " << bedDistCalc <<endl;

        cout << "Comparing bathroom Freq: " << bathroom[elements] << " " << "with" << " " << "Requested Freq:" << " " << ipBath<< endl;
        int bathDistCalc = pow((ipBath - bathroom[elements]), 2);
        cout<< "Bathroom"<< " " << bathroom[elements] << " " << "and" << " " << ipBath << " " << "is" << " " << bathDistCalc <<endl;

        int calcDist = sqftDistCalc + bedDistCalc + bathDistCalc;
        float totalDist = sqrt(calcDist);

        cout<< totalDist<<endl;
    }
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
    int size = (sizeof(sqft)/sizeof(sqft[0]));
    dataTable(sqft, bedroom, bathroom, price, size);
    eculideanDist(k, sqft, bedroom, bathroom, ipSqft, ipBed, ipBath, size);
}
