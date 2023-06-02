#pragma once
#include "Dictionary.h"
#include <unordered_map>
#include <vector>
#include <algorithm>

class NoSuggestionsException : public std::exception {
public:
    NoSuggestionsException(const std::string& errorMessage) : errorMessage_(errorMessage) {}
    const char* what() const noexcept override {
        return errorMessage_.c_str();
    }
private:
    std::string errorMessage_;
};

typedef struct cacheStack{
	int wordSize;
	std::vector<Word*> wordCache;	
	cacheStack* nextStack;
}cacheStack;

class SpellChecker {
	private:
		Dictionary dictionary;
		std::unordered_map<std::string, std::string> cachedMispelledWords;
		int levenshteinMaxDistance;
		
		bool isInMaxRange(int inputSize, int dictWordSize){ //DictWordSize = 10, inputSize >= DictWordSize - 2 && inputSize <= DictWordSize + 2 
			return (inputSize >= dictWordSize - levenshteinMaxDistance) && (inputSize <= dictWordSize + levenshteinMaxDistance);
		}

	public:
		SpellChecker(const Dictionary& dict, int maxDistance) : dictionary(dict) {
			levenshteinMaxDistance = maxDistance;
		}

		void addCachedWord(std::string mispelledWord, std::string correctWord){
			cachedMispelledWords.emplace(mispelledWord, correctWord);
		}

		bool containsCachedWord(const std::string& word) const {
            std::string wordCopy = word;
            transform(wordCopy.begin(), wordCopy.end(), wordCopy.begin(), ::tolower);
            auto iter = cachedMispelledWords.find(wordCopy);
            return iter != cachedMispelledWords.end();
        }

		int calculateLevenshteinDistance(const std::string& s1, const std::string& s2);
		std::vector<std::string> search(std::string word);
		void setMaxDistance(int maxDistance){
			if(maxDistance > 0){
				levenshteinMaxDistance = maxDistance;
			}
		}

};