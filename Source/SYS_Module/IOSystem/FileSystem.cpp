#include "FileSystem.h"

// File Operations

// Open a file in read mode
// Open a file in write mode
/*std::ofstream openFileForWriting(const std::string& filePath) {
    std::ofstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Failed to open file for writing: " << filePath << std::endl;
    }
    return file;
}*/

// Create a file
/*bool createFile(const std::string& filePath) {
    std::fstream file(filePath, std::ios::out);
    if (!file.is_open()) {
        std::cerr << "Failed to create file: " << filePath << std::endl;
        return false;
    }
    file.close();
    return true;
}

// Delete a file
bool deleteFile(const std::string& filePath) {
    if (std::remove(filePath.c_str()) != 0) {
        std::cerr << "Failed to delete file: " << filePath << std::endl;
        return false;
    }
    return true;
}

// Rename a file
bool renameFile(const std::string& oldFilePath, const std::string& newFilePath) {
    if (std::rename(oldFilePath.c_str(), newFilePath.c_str()) != 0) {
        std::cerr << "Failed to rename file: " << oldFilePath << " to " << newFilePath << std::endl;
        return false;
    }
    return true;
}

// Move a file
bool moveFile(const std::string& srcFilePath, const std::string& dstFilePath) {
    if (std::rename(srcFilePath.c_str(), dstFilePath.c_str()) != 0) {
        std::cerr << "Failed to move file: " << srcFilePath << " to " << dstFilePath << std::endl;
        return false;
    }
    return true;
}


// File Operations

// Open a file in read mode
/*FILE* openFileForReading(const char* filePath) {
    FILE* file = fopen(filePath, "r");
    if (file == NULL) {
        fprintf(stderr, "Failed to open file for reading: %s\n", filePath);
    }
    return file;
}

// Open a file in write mode
FILE* openFileForWriting(const char* filePath) {
    FILE* file = fopen(filePath, "w");
    if (file == NULL) {
        fprintf(stderr, "Failed to open file for writing: %s\n", filePath);
    }
    return file;
}

// Close a file
void closeFile(FILE* file) {
    if (file != NULL) {
        fclose(file);
    }
}

// Create a file
int createFile(const char* filePath) {
    FILE* file = fopen(filePath, "w");
    if (file == NULL) {
        fprintf(stderr, "Failed to create file: %s\n", filePath);
        return 0;
    }
    fclose(file);
    return 1;
}

// Delete a file
int deleteFile(const char* filePath) {
    if (remove(filePath) != 0) {
        fprintf(stderr, "Failed to delete file: %s\n", filePath);
        return 0;
    }
    return 1;
}

// Rename a file
int renameFile(const char* oldFilePath, const char* newFilePath) {
    if (rename(oldFilePath, newFilePath) != 0) {
        fprintf(stderr, "Failed to rename file: %s to %s\n", oldFilePath, newFilePath);
        return 0;
    }
    return 1;
}

// Move a file
int moveFile(const char* srcFilePath, const char* dstFilePath) {
    if (rename(srcFilePath, dstFilePath) != 0) {
        fprintf(stderr, "Failed to move file: %s to %s\n", srcFilePath, dstFilePath);
        return 0;
    }
    return 1;
}

int savingSystem(char* textBlock, FILE* f, char* fname, char* mode, int closeFile)
{
    if (f == NULL) //There is going to have cases where files are already open probably, so keep this here in mind.
    {
        f = fopen(fname, mode);
    }
    if (f != NULL)
    {
        if (fprintf(f, "%s", textBlock) < 0)
        {
            fclose(f);
            return ERROR_PRT_TOFILE;
        }
        if (closeFile) { fclose(f); }
        return NORMAL;
    }
   
    return NO_FILE_OPEN;
}
//https://github.com/mandreyel/mio/blob/master/README.md*/
/*
int LoadingSystemLine(char* fname, std::string* buffer)
{
    std::ifstream opf(fname);
    if (!opf) {
        return NO_FILE_OPEN;
    }
    return 0;
}

int LoadingSystemCPP(char* fname, std::stringstream *buffer)
{
    std::ifstream t(fname);;
    t.read(fname, 0);
    *buffer << t.rdbuf();
    return NORMAL;
}

int LoadingSystemGeneric(char** buffer, char* fname, const char* mode)
{
    FILE* f;
    unsigned long int numbytes;
    f = fopen(fname, mode);
    if (f != NULL){
        fseek(f, 0L, SEEK_END);  // Get the number of bytes 
        numbytes = ftell(f);
        if (!numbytes){
            fclose(f);
            return Empty_File;
        }
        if (numbytes > 1000000000){
            fclose(f);
            return FILE_TOO_BIG;
            /*
                Decidi fazer isso visto que acima de 1GB, e bem provavel que muitos sistemas n�o ir�o aguentar, ent�o, coloco essa barreira para impedir esse acontecimento.
                O limite do LONG INT e de 4GB, e essa e outra barreira q terai que mexer depois. Por enquanto, deixo assim.
                Para a ideia no Advanced File System, dividir o arquivo em peda�os de 512MB - 1024 MB e salvar um ponteiro de onde esta no arquivo no momento seria
                uma boa ideia, permitindo arquivos de tamanho "infintos" serem lidos e processados.
                Isso vai ser necessario quando o sistema de Memoria estiver funcionando, mas at� la, n�o.
            */
        //}
        /*
        fseek(f, 0L, SEEK_SET);  // reset the file position indicator to the beginning of the file 
        *buffer = (char*)calloc(numbytes, sizeof(char)); // grab sufficient memory for the buffer to hold the text 
        if (*buffer == NULL) { return FULL_MEMORY; }
        fread(*buffer, sizeof(char), numbytes, f); // copy all the text into the buffer 
        fclose(f);
        return NORMAL;
    }
    return NO_FILE_OPEN;
}

//========================================//
*/

std::ifstream FileOperations::openFileReadingMode(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        //Throw error later;
        std::cerr << "Failed to open file for reading: " << filePath << std::endl;
    }
    return file;
}

std::vector<std::string> FileOperations::obtainStringVector(const std::string filePath){
    std::ifstream file = FileOperations::openFileReadingMode(filePath);
    std::vector<std::string> fileAsString;
    std::string line;

    while (getline(file, line))
	{
		fileAsString.push_back(line);
	}

    file.close();

    return fileAsString;
}