#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "../def/defines.h"


class FileOperations{
	public:
	static std::vector<std::string> obtainStringVector(const std::string filePath);
	void closeFile(std::fstream& file);
	static std::ifstream openFileReadingMode(const std::string& filePath);

};

//V1 -> Basic Saving, without much things, and that can work standalone most importantly!

/*typedef struct bitFieldcF
{
	unsigned closeFlag : 1;
}bitFieldcF;*/

/*
	@function savingSystem
	@discussion base function of the Saving Module.
	@param textBlock The block of text that is going to get placed inside the file.
	@param f The File Variable
	@param fname the file name.
	@param mode the mode, deffined above with the #defines.
	@param closeFile If the File in question is going to be closed or not.
	@result Returns if the operation was successful or an error occured.

*/
int savingSystem(char* textBlock, FILE* f, char* fname, char* mode, int closeFile);

int edit_file(FILE* fl, char* fname, char* text);

/*
	@function saveModule
	@discussion saves the text in a file or closes if set to.
	@param textBlock The block of text that is going to get placed inside the file.
	@param f The File Variable
	@param closeFile the tag that signalize if the file is going to be closed or not.
	@result Returns if the operation was successful or an error occured.

*/
int LoadingSystemCPP(char* fname, std::stringstream* buffer);
int LoadingSystemGeneric(char** buffer, char* fname, const char* mode);
