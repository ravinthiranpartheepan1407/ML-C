#include<iostream>
#include<vector>
#include<cctype>
#include<cstring>

using namespace std;

string casefold(char x[]){
    string caseout;
    for(size_t elements = 0; elements < strlen(x); elements++){
        char convLow = tolower(x[elements]);
        caseout += convLow;
    }
    return caseout;
}

int main(){
    char x[] = "Tokenization is The PROCESS of splitTing text intO words Or subword uNits.";
    string res = casefold(x);
    cout<<res;
}