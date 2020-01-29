//====================================================================
// Parent.h
// Declaration file for the parent class.
// Author: Houston Calvert
//====================================================================

#ifndef PARENTORGANISMS_H
#define PARENTORGANISMS_H

#include "Display.h"
#include "ParentData.h"
#include "MasterGeneFactory.h"
#include <random> // for bernoulli_distribution()

class CParent
{
	public:
		std::vector<std::vector<std::string> > offspring;
		std::vector<std::vector<std::string> > parentTypes;
		std::vector<std::string> possibleCombos;
		std::vector<char> parentGenotypes;
		std::vector<int> genesInChromosome;
		std::string heterozygousDominant;
		std::string homozygousDominant;
		std::string homozygousRecessive;
		std::string binaryString;
		std::string strand1Str;
		std::string strand2Str;
		std::string newCombo;
		std::string combo;
		std::ifstream inFile;
		char *pStrand1;
		char *pStrand2;
		char dominant;
		char recessive;
		char uppercaseAllele;
		char lowercaseAllele;
		int totalGenes;
		int totalGenesInChromosome;
		int hetDomCount;
		int homDomCount;
		int homRecCount;
		int pNum;
		
		CParent();
		~CParent();
		std::vector<char> &RemoveData(std::vector<ParentData> parentData);
		std::vector<std::vector<std::string> > &GetParentTypes(std::vector<ParentData> parentData);
		std::vector<std::vector<std::string> > &GetOffspring(std::vector<ParentData> parentData, std::vector<MasterGene> geneticsData, int totalOffspring);
		std::vector<std::vector<std::string> > &GenerateOffspring(int a, int totalOffspring, int &hetDomCount, int &homDomCount, int &homRecCount, double percent, int type);
};
#endif