#include "Word.h"

Word::Word(const std::string wordSTR, const std::string wordTypeSTR, const std::string definitionSTR){
    word = wordSTR;
    std::transform(word.begin(), word.end(), word.begin(), ::tolower);
    wordType = wordTypeSTR;
    definition = definitionSTR;
    size = wordSTR.size();
    wordUsageInTrainingDataNormalized = 0;
    wordUsageByUser = 0;
}


std::string Word::getWord() const {
    return word;
}

std::string Word::getDefinition() const {
    return definition;
}

int Word::getSize() const {
    return size;
}

std::string Word::getWordType() const {
    return wordType;
}


void Word::setWordUsageTrainingData(float data) {
    if(wordUsageInTrainingDataNormalized == 0 && data > 0)
        wordUsageInTrainingDataNormalized = data;
}

void Word::setWordUsageByUser(float data){
    wordUsageByUser = data;
}

void Word::incrementWordUsageByUser(){
    wordUsageByUser++;
}


float Word::calculateUsedWordWeight(int usedWordsInDict) const{
    if(usedWordsInDict == 0){
        return 0;
    }
    else{
        return wordUsageByUser / usedWordsInDict;
    }
}

float Word::getWordWeight(int LevanshtainDistance, int usedWordsInDict) const{
    float penalty = -(LevanshtainDistance * 0.5);
    float wordUsageTrainingWeight = wordUsageInTrainingDataNormalized * 0.1;
    float wordUsageWeight = calculateUsedWordWeight(usedWordsInDict);
    return (penalty + wordUsageTrainingWeight + wordUsageWeight);
}

int Word::getWordUsageByUser(){
    return wordUsageByUser;
}