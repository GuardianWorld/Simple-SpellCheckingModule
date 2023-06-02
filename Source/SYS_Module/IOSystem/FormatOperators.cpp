#include "FormatOperators.h"

std::vector<std::string> FormatOperators::formatStringIntoPieces(char separator, std::string data){
    std::vector<std::string> formattedVector;
    std::stringstream lineStream(data);
    std::string separatedLine;
    while(getline(lineStream, separatedLine,separator)){
        std::cout << lineStream.str() << '\n';
        std::cout << separatedLine << std::endl;
        formattedVector.push_back(separatedLine);
    }
    
    return formattedVector;
}

std::vector<std::string> FormatOperators::formatVectorIntoPieces(char separator, std::vector<std::string> data){
    std::vector<std::string> formattedVector;
    for(auto x : data){
        std::stringstream lineStream(x);
        std::string separatedLine;
        while(getline(lineStream, separatedLine,separator)){
        //std::cout << lineStream.str() << '\n';
        //std::cout << separatedLine << std::endl;
        formattedVector.push_back(separatedLine);
        }
    }
    
    return formattedVector;
}