#include "Dictionary.h"


Dictionary::Dictionary(const std::vector<Word> dictWords, int usedWordsReload) {
    for(Word word : dictWords){
        std::string wordSTR = word.getWord();
        transform(wordSTR.begin(), wordSTR.end(), wordSTR.begin(), ::tolower);
        dictionary.emplace(wordSTR, word);
    } 
    usedWords = usedWordsReload;
}

Word& Dictionary::getWordReference(std::string word){
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    auto iter = dictionary.find(word);
    if(iter != dictionary.end()){
        return iter->second;
    }
    else throw InvalidWordException("Error, Invalid Word");
}

void Dictionary::setWordsWeightData(const std::vector<std::pair<std::string, float>> wordWeights){
    
    int x = 0;
    for (const auto& pair : wordWeights) {
        //std::cout << "Word: " << pair.first << ", Weight: " << pair.second << std::endl;
        std::string word = pair.first;
        double weight = pair.second;
        try{
            Word& wordRef = getWordReference(word);
            wordRef.setWordUsageTrainingData(weight);
        }catch(InvalidWordException){
            //std::cout << "[" << word << "] ";
            Word wordOBJ(word, "-", "-");
            wordOBJ.setWordUsageTrainingData(weight);
            this->insertWordInDictionary(wordOBJ);
        }
    }
}


void Dictionary::insertWordInDictionary(Word word){
    dictionary.emplace(word.getWord(),word);
}

bool Dictionary::containsWord(const std::string& word) const {
    std::string wordCopy = word;
    transform(wordCopy.begin(), wordCopy.end(), wordCopy.begin(), ::tolower);
    auto iter = dictionary.find(wordCopy);
    return iter != dictionary.end();
}

void Dictionary::incrementUsedWords(){
    usedWords++;
}

void Dictionary::incrementSingleWordUsage(std::string word){
    auto iter = dictionary.find(word);
    if(iter != dictionary.end()){
        iter->second.incrementWordUsageByUser();
    }
}

Word Dictionary::getWordObject(std::string word){
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    auto iter = dictionary.find(word);
    if(iter != dictionary.end()){
        return iter->second;
    }
    else throw InvalidWordException("Error, Invalid Word");
}

int Dictionary::getDictionarySize(){
    return dictionary.size();
}

std::string Dictionary::getWordDefinition(std::string word){
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    auto iter = dictionary.find(word);
    if(iter != dictionary.end()){
        return iter->second.getDefinition();
    }
    return "N/A";
}

std::unordered_map<std::string, Word> Dictionary::getDictionary(){
    return dictionary;
}

int Dictionary::getUsedWords(){
    return usedWords;
}