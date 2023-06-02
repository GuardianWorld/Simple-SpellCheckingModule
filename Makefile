ALL:
	g++ -g ./main.cpp \
	./Source/SYS_Module/IOSystem/FileSystem.cpp \
	./Source/SYS_Module/IOSystem/FormatOperators.cpp \
	./Source/MainManagers/InitializerManager.cpp \
	./Source/LangModules/Word.cpp \
	./Source/LangModules/Dictionary.cpp \
	./Source/Managers/SpellCheckerManager.cpp \
	./Source/LangModules/SpellChecker.cpp \
	-o main -pthread