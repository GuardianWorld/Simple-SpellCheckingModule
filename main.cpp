#include "Source/SYS_Module/def/defClassDefines.h"
#include "Source/MainManagers/InitializerManager.h"
#include "Source/SYS_Module/IOSystem/FileSystem.h"
#include "Source/LangModules/SpellChecker.h"

#include "Source/Managers/SpellCheckerManager.h"

int main()
{
	Dictionary dict(DictManager::obtainWordVector("./Language/EnglishWords.txt"), 0);
	dict.setWordsWeightData(DictManager::obtainWeightPairVector("./Language/trainingValues_English.txt"));

	SpellChecker* spc = new SpellChecker(dict, 2);

	while(true){
		std::cout << "Type a word to check if its in the dictionary and the spell checking, type break to quit.\n >> ";
		std::string word;
		std::cin >> word;
		std::vector<std::string> results = SCManager::callSpellChecker(spc, word);
		for(std::string word : results){
			std::cout << word << std::endl;
		}
		std::cout << std::endl;
		if(word == "break"){
			break;
		}
	}
	
	delete spc;
}