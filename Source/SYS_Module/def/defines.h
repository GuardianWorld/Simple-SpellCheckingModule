#pragma once
#ifndef defines_H
#define defines_H

//Memory Defines

//System Commands Defines
#define OVRLOG	2

//FileSystem Defines
//#define append "a"
//#define write  "w"
//#define read   "r"

#pragma region LogModule_Defines
//Log Defines
//000 to 099= Normal
//100 up to 299 = Warning
//300 up to 500 = Error
//500 Up to 600 = Critical Error

#define NORMAL 			000 //All Running norma
#define ENDOFFILE		001 //End Of File
#define STOP			-2	//Stops the program

//TextSystemWarning
#define File_already_open	101 //File already open, just a observation, not an error
#define Empty_File			102 //Empty file warning.
#define FILE_TOO_BIG        103 //File too big to be opened.
//TextSystemError
#define NO_FILE_OPEN		300 //No file opened in SavingSystem.c module.
#define ERROR_PRT_TOFILE	301 //Could not print to file.
//TextSystemCritical
#define FILE_ERROR			501 //File Error
//Memory_Critical_Errors
#define FULL_MEMORY			502 //Full memory to allocate more words...
#define FULL_DISK			503 //Full disk to save stuff.


#define FORCECRASH		-1//ForceCrashes the program just in case.

#pragma endregion

#define true 1
#define false 0

//StringManip Defines
#define MAXSIZE 4000
#define BUFSIZE	4000

//LanguageSystem Defines
#define USER	0
#define ACT	    1
#define PERS	2

#endif

