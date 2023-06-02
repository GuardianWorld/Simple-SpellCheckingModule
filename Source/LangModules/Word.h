#pragma once
#include <vector>
#include <unordered_map>
#include <string>
#include <string.h>
#include <iostream>
#include <algorithm>

typedef unsigned char byteInt;
class Word{
    private:
        std::string word;
        byteInt size;
        std::string wordType;
        byteInt wordImportance;
        float wordUsageInTrainingDataNormalized;
        float wordUsageByUser;
        std::string definition;

        float calculateUsedWordWeight(int usedWordsInDict) const;

    public:
        Word(const std::string wordSTR, const std::string wordTypeSTR, const std::string definitionSTR);

        std::string getWord() const;
        std::string getDefinition() const;
        int getSize() const;
        std::string getWordType() const;
        int getWordUsageByUser();
        float getWordWeight(int LevanshtainDistance, int usedWordsInDict) const;

        void setWordUsageTrainingData(float data);
        void setWordUsageByUser(float data);
        void incrementWordUsageByUser();
};