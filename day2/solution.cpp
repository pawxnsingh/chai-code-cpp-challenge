#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

string mostCommonWord(const string& document){
    // brute-force solution that is coming to my head is tokenize it and use a unordered_map<string, int> and parse through it and calculate the frequency
    // but heres the catch our string can fail if we've two words with same frequency
    // little optimized: is that ki keep the track of the words
    unordered_map<string, int>wordCount;
    vector<string> wordOrder;

    string word = "";
    // traverse through the document
    for(char ch:document){
        if(ch == ' '){
            if(!word.empty()){
                // now before storing make it lowercase
                for(char &w:word){
                    w = tolower(w);
                }
                // track the first occurence
                // if(wordCount[word] == 0){
                    wordOrder.push_back(word);
                // }
                // then do the operation like puting the wording the hashmap
                wordCount[word]++;
                word = "";
            }
        }else{
            word += ch;
        }
    }

    // this is for the last word
    if(!word.empty()){
        // make it lowercase
        for(char &ch:word){
            ch = tolower(ch);
        }
        // if(wordCount[word] == 0){
            wordOrder.push_back(word);
        // }
        wordCount[word]++;
    }

    string most_CommonWord;
    int maxFrequency = 0;

    for(string word: wordOrder){
        if(wordCount[word] > maxFrequency){
            maxFrequency = wordCount[word];
            most_CommonWord = word;
        }
    }

    return most_CommonWord;
}

int main(){
    string document;
    getline(cin, document);

    cout << mostCommonWord(document) << endl;
}
