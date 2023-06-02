#include "InitializerManager.h"

std::vector<Word> DictManager::obtainWordVector(std::string mainFilePath){
	std::vector<Word> wordVector;
	std::vector<std::string> dictWords = FileOperations::obtainStringVector(mainFilePath);
	std::vector<std::string> formattedDictWords = FormatOperators::formatVectorIntoPieces('|', dictWords);
	for(int x = 0; x < formattedDictWords.size(); x += 3){
		wordVector.emplace_back(formattedDictWords[x], formattedDictWords[x+1], formattedDictWords[x+2]);
	}
	return wordVector;
}

std::vector<std::pair<std::string, float>> DictManager::obtainWeightPairVector(std::string weightFile)
{
	std::vector<std::pair<std::string, float>> wordWeights;
	std::vector<std::string> formattedWords = FormatOperators::formatVectorIntoPieces(' ', FileOperations::obtainStringVector(weightFile));
	for(int x = 0; x < formattedWords.size(); x += 2){
		float tryWeight = 0;
		try{
			tryWeight = std::stod(formattedWords[x+1]);
		}catch(std::invalid_argument){
			tryWeight = 0;
		}
		wordWeights.emplace_back(formattedWords[x], tryWeight);
	}

    return wordWeights;
}
