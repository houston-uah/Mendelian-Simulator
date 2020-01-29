//====================================================================
// MasterGeneFactory.h
// Declaration file for the master gene factory class
// Author: Houston Calvert
//====================================================================

#ifndef MASTERGENEFACTORY_H
#define MASTERGENEFACTORY_H

#include "MasterGene.h"

class MasterGeneFactory
{
	private:
		int instanceNumber;
		char trait[64];
		char domAllele[64];
		char domSymbol;
		char recAllele[64];
		char recSymbol;
		char coChance;
		std::vector<MasterGene> geneticsData;
		MasterGene *masterGene;
		MasterGeneFactory();

	public:
		~MasterGeneFactory();
		int getInstanceNumber();
		static MasterGeneFactory *getInstance();
		void CreateMasterGene(std::vector<MasterGene> &geneticsData);
};
#endif