#include "SpellCheckerManager.h"


std::vector<std::string> SCManager::callSpellChecker(SpellChecker* spc, string search){
    try{
        std::vector<std::string> searchResult = spc->search(search);
        return searchResult;
	}catch(NoSuggestionsException){
        std::cerr << "no suggestions\n";
    }
    return std::vector<std::string>();
}

