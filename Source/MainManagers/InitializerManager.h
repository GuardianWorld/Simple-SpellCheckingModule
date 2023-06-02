#pragma once
#include <fstream>
#include <list>
#include <vector>
#include <iostream>
#include <time.h>
#include <algorithm>
#include "../LangModules/Word.h"
#include "../SYS_Module/IOSystem/FileSystem.h"
#include "../SYS_Module/IOSystem/FormatOperators.h"

class DictManager{
    public:
    static std::vector<Word> obtainWordVector(std::string dictFile);
    static std::vector<std::pair<std::string, float>> obtainWeightPairVector(std::string weightFile);
};

