//====================================================================
// MasterGene.h
// Declaration file for the master gene class.
// Author: Houston Calvert
//====================================================================

#ifndef MASTERGENE_H
#define MASTERGENE_H

#include "ParentData.h"
#include <sstream>

class MasterGene
{
	public:
		char trait[64];
		char domAllele[64];
		char domSymbol;
		char recAllele[64];
		char recSymbol;
		char coChance[32];
		
		MasterGene(char *trait, char *domAllele, char *domSymbol, char *recAllele, char *recSymbol, char *coChance);
		~MasterGene();
		void CreateMasterGene(std::vector<MasterGene> &geneticsData);
		char *getTrait();
		char *getDomAllele();
		char &getDomSymbol();
		char *getRecAllele();
		char &getRecSymbol();
		char *getCOChance();
};

#endif