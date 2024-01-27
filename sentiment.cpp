#include<iostream>
#include<cmath>
#include<sstream>
#include<vector>
#include<algorithm>
#include <map>

using namespace std;

struct sentenceFreq
{   
    string text;
    int frequency;
};


void sentiment(vector<string> sentence, vector<string> cluster, string data){
    int elements;
    double sentimentScore;
    vector<string> posWords;
    vector<string> negWords;
    // sentence.push_back(sentimentData.text);
    // cluster.push_back(sentimentData.group);
    for(elements = 0; elements < cluster.size(); elements++){
        if(cluster[elements] == "positive"){
            cout<<"Positive Sentence: "<<" "<<sentence[elements]<<endl;
            stringstream splitWords(sentence[elements]);
            string words;
            while(splitWords >> words){
                posWords.push_back(words);
            }
        }else if (cluster[elements] == "negative")
        {
            cout<<"Negative Sentence: "<<" "<<sentence[elements]<<endl;
            stringstream splitwords(sentence[elements]);
            string words;
            while(splitwords >> words){
                negWords.push_back(words);
            }
        }else{
            cout<<"No Sentence Provided"<<endl;
        }
    }

    // Mapping frequencies of each words in positive clusters
    map<string, int> posMap;
    for(size_t element = 0; element < posWords.size(); element++){
        if(posMap.find(posWords[element]) != posMap.end()){
            posMap[posWords[element]]++;
        }else{
            posMap[posWords[element]] = 1;
        }
    }

    // Mapping frequencies of each words in negative clusters
    map<string, int> negMap;
    for(size_t element = 0; element < negWords.size(); element++){
        if(negMap.find(negWords[element]) != negMap.end()){
            negMap[negWords[element]]++;
        }else{
            negMap[negWords[element]] = 1;
        }
    }
    
    // Priting frequency of words in positive sentence
    for(const auto& pair: posMap){
        // cout<<"Frequency of Positive word: "<<pair.first<<": "<<pair.second<<endl;
    }

    // Printing frequency of words in negative sentence
    for(const auto& pair: negMap){
        // cout<<"Frequency of negative words: "<<pair.first<<": "<<pair.second<<endl;
    }

    // Using Naive Bayes approach (Log-Likelihood)
    for(const auto& pair: posMap){
        for(const auto& pairs: negMap){
            if(pair.first == pairs.first){
                cout<<"Similar Instances: "<<pair.first<<" | "<<pairs.second<<endl;
                double logLikelihood = log((pair.second) / (pairs.second));
                // cout<<"Log Likelihood: "<<logLikelihood<<endl;
            }else{
                cout<<"Individual Instances: "<<pairs.first<<" | "<<pairs.second<<endl;
                double logLikelihood = log((pair.second) / (pairs.second));
                // cout<<"Log Likelihood: "<<logLikelihood<<endl;
                break;
            }
        }
    }
    // return sentimentScore;
}

int main(){
    // // First Data
    // sentimentData.text = "I am happy because I am learning NLP";
    // sentimentData.group = "positive";
    // // Second Data
    // sentimentData.text = "I am sad, I am not learning NLP";
    // sentimentData.group = "negative";

    // Call the sentiment function
    vector<string> text = {"I am happy because I am learning NLP", "I am sad I am not learning NLP", "I am so happy", "I am so sad"};
    vector<string> clusters = {"positive", "negative", "positive", "negative"};
    string data = "I am okay to learn NLP";
    sentiment(text, clusters, data);
}
