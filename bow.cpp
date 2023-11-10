#include<iostream>
#include<map>
#include<cstring>
#include<vector>

using namespace std;

void bow(char x[]){
    string combine;
    map<string, string> dict; // Typename, Format
    for(int elements = 0; elements < strlen(x); elements++){
        combine += x[elements];
        dict.insert({combine, to_string(elements)});
    }
    // for(int elements = 0; elements < strlen(x); elements++){
    //     dict.insert({combine, to_string(elements)});
    // }
    for(auto elements = dict.begin(); elements != dict.end(); ++elements){
        cout<<elements->first<<" : "<<elements->second<<endl;
    }
}

int main(){
    char x[] = "Tokenization is the process of splitting text into words or subword units.";
    bow(x);
}