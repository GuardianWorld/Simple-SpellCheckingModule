#include "SpellChecker.h"


int SpellChecker::calculateLevenshteinDistance(const std::string& s1, const std::string& s2)
{
    //Get the size of the Strings.
    const int len1 = s1.size();
    const int len2 = s2.size();

    // Create a 2D matrix to store the distances between all pairs of prefixes
    std::vector<std::vector<int>> d(len1 + 1, std::vector<int>(len2 + 1));

    // Initialize the first row and column of the matrix
    for (int i = 0; i <= len1; i++)
        d[i][0] = i;
    for (int j = 0; j <= len2; j++)
        d[0][j] = j;

    // Calculate the distance between all pairs of prefixes
    for (int j = 1; j <= len2; j++){
        for (int i = 1; i <= len1; i++){
            if (s1[i - 1] == s2[j - 1]){ 
                // The characters match, so the cost is 0
                d[i][j] = d[i - 1][j - 1];
            }
            else{
                // The characters don't match, so we need to choose the minimum
                // of three operations: insert, delete, or substitute
                d[i][j] = std::min({ d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + 1 });
            }
        }
    }
    return d[len1][len2];
}

std::vector<std::string> SpellChecker::search(std::string word){
    std::vector<std::pair<float, std::string>> suggestions;
    std::vector<std::string> resultStack;

    std::transform(word.begin(), word.end(), word.begin(), ::tolower);
    
    //If word is already in array, just shove it on the array and return;
    if(dictionary.containsWord(word)){
        dictionary.incrementSingleWordUsage(word);
        dictionary.incrementUsedWords();
        std::cout << dictionary.getWordObject(word).getWordUsageByUser() << std::endl;
        resultStack.push_back(word);
        return resultStack;
    }
    //Check just in case it exists in the cached Dictionary;
    if(containsCachedWord(word)){
        std::string cachedWord = cachedMispelledWords[word];
        resultStack.push_back(cachedWord);
        return resultStack;
    }

    int wordSize = word.size();
    // Iterate through the dictionary and calculate Levenshtein distance for each word
    int wordsPassed = 0;
    for (const auto& entry : dictionary.getDictionary()) {
        if(isInMaxRange(wordSize, (entry.second).getSize())){
            const std::string& dictWord = entry.first;
            int levenshteinCalculatedDistance = calculateLevenshteinDistance(word, dictWord);
            if(levenshteinCalculatedDistance <= levenshteinMaxDistance){
                suggestions.emplace_back(entry.second.getWordWeight(levenshteinCalculatedDistance, dictionary.getUsedWords()), dictWord);
            };
        }
    }

    if(suggestions.size() == 0){
        throw NoSuggestionsException("ERROR");
    }
    
    std::sort(suggestions.begin(), suggestions.end());

    int numb = 0;
    for(const auto s : suggestions){
        std::cout << "Word Suggestion [" << numb << "]:" << s.second << " Weight: " << s.first << std::endl;
        numb++;
    }

    float mainWeight = suggestions[suggestions.size() - 1].first;
    int y = suggestions.size() - 1;

    while(y>= 0){
        if(mainWeight != suggestions[y].first && resultStack.size() >= 5){
            break;
        }
        resultStack.push_back(suggestions[y].second);
        y--;
    }

    return resultStack;
}