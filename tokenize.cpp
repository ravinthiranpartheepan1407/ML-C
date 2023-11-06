#include<iostream>
#include<vector>
#include<sstream>

using namespace std;

vector<string> tokenize(string x){
    vector<string> out;
    stringstream splitWords(x);
    string words;
    while(splitWords >> words){
        out.push_back(words);
    }
    return out;
}

int main(){
    string x = "Tokenization is the process of splitting text into words or subword units.";
    vector<string> res = tokenize(x);
    for(size_t chars = 0; chars < res.size(); chars++){
        cout<<res[chars]<<endl;
    }
}