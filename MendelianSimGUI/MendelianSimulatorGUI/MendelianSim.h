//====================================================================
// MendelianSim.h
// Declaration file for the simulation.
// Author: Houston Calvert
//====================================================================

#ifndef MENDELIANSIM_H
#define MENDELIANSIM_H

#pragma comment(lib, "shlwapi.lib")

#include "Display.h"
#include "ParentFactory.h"
#include "Gene.h"
#include <conio.h>
#include <Shlwapi.h>

class MendelianSim
{
	private:
		std::vector<MasterGene> geneticsData;
		std::vector<ParentData> parentData;
		std::vector<std::vector<std::string> > parentTypes;
		std::vector<std::vector<std::string> > offspring;
		std::vector<char> parentGenotypes;
		std::string userInput;
		std::string fileInput;
		std::string nameOfFile;
		std::string file1;
		std::string file2;
		std::string file3;
		std::string file4;
		char *pStrand1;
		char *pStrand2;
		char file[64];
		char newFileResponse;
		char continueInput;
		MasterGene *theTrait;
		bool done;
		bool fileExists;
		bool newFile;
		bool isNumber;
		int totalGenes;
		int totalOffspring;
		int totalAttempts;
		int fileNum;
		int heterozygousDom;
		int homozygousDom;
		int homozygousRec;
		int totalFiles;
		int parentNum;
		int place;
		int instanceNumber;
		int totalCrossovers;
		MendelianSim();

	public:
		~MendelianSim();
		int getInstanceNumber();
		static MendelianSim *getInstance();
		char DataFilePrompt(char *file);
		bool CheckFile(char *fileName);
		int UserOffspringPrompt();
		void RunSimulation(char *file);
};
#endif