#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include "Word.h"

class InvalidWordException : public std::exception {
public:
    InvalidWordException(const std::string& errorMessage) : errorMessage_(errorMessage) {}
    const char* what() const noexcept override {
        return errorMessage_.c_str();
    }
private:
    std::string errorMessage_;
};


class Dictionary{
    private:
        std::unordered_map<std::string, Word> dictionary;
        int usedWords;

        Word& getWordReference(std::string word);

    public:
        Dictionary(const std::vector<Word> dictWords, int usedWordsReload);

        std::unordered_map<std::string, Word> getDictionary();

        void insertWordInDictionary(Word word);

        void incrementSingleWordUsage(std::string word);

        int getDictionarySize();

        std::string getWordDefinition(std::string word);

        Word getWordObject(std::string word);

        bool containsWord(const std::string& word) const;

        void incrementUsedWords();

        int getUsedWords();

        void setWordsWeightData(const std::vector<std::pair<std::string, float>> wordWeights);

};
