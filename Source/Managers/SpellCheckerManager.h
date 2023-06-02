#include "../LangModules/SpellChecker.h"

typedef std::string string;

class SCManager{
    public:
    static std::vector<std::string> callSpellChecker(SpellChecker* spc, string search);
};