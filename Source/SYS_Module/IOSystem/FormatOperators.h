#pragma once
#include <string>
#include <string.h>
#include <vector>
#include <iostream>
#include <sstream>  

class FormatOperators{
    public:
    static std::vector<std::string> formatStringIntoPieces(char separator, std::string data);
    static std::vector<std::string> formatVectorIntoPieces(char separator, std::vector<std::string> data);

};