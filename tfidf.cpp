#include<iostream>
#include<vector>
#include<map>
#include<tuple>
#include<cstring>
#include<cctype>
#include<cmath>

using namespace std;

// Split words into hashtables
vector<double> tfidf(char doc[][100], int docCount, string word) {
    vector<double> tfidfRes;
    for (int docIndex = 0; docIndex < docCount; docIndex++) {
        char *docId;
        vector<string> out;
        int frequency = 0;
        docId = strtok(doc[docIndex], " "); //doc[docIndex] -> doc[0,1,2][100]
        
        while(docId != NULL) {
            out.push_back(docId);
            docId = strtok(NULL, " ");
        }
        int totalWords = out.size();
        for (size_t elements = 0; elements < out.size(); elements++) {
            if (word == out[elements]) {
                frequency++;
            }
        }

        // Finding Term Frequency
        // TF = no.of repeat words / total no.of words
        double tf = static_cast<double>(frequency) / totalWords; // Type Conversion: static_cast

        // cout << "Frequency of the word '" << word << "' in document " << docIndex + 1 << ": " << frequency << endl;
        cout<<"The Term frequency is: "<<tf<<endl;

        // Calculating IDF
        // Log(no.of documents) / (no.of doc containing word)
        double idf = log(docCount / static_cast<double>(frequency));

        cout<<"The Inverse Document frequency is: "<<idf<<endl;

        // TF-IDF Score Calculation
        // TF-IDF = TF * IDF
        double tfidfCalc = tf*idf;
        tfidfRes.push_back(tfidfCalc);
    }
    return tfidfRes;
}

int main() {
    char doc[][100] = {"It is going to rain today .", "Today I am not going outside .", "I am going to watch the season premiere ."};
    int docCount = sizeof(doc) / sizeof(doc[0]);
    string word = "rain";
    vector<double> res = tfidf(doc, docCount, word);
    for(size_t elements = 0; elements < res.size(); elements++){
        cout<<"The TF-IDF Score is: "<<res[elements]<<endl;
    }
    return 0;
}