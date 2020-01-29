//====================================================================
// ParentFactory.h
// Declaration file for the parent factory class
// Author: Houston Calvert
//====================================================================

#ifndef PARENTFACTORY_H
#define PARENTFACTORY_H
#include "ParentData.h"
#include "ChromosomeFactory.h"

class ParentFactory
{
	private:
		char scientificName[64];
		char strand1[32];
		char strand2[32];
		std::string ch1;
		std::string ch2;
		int totalGenes;
		int chromosomeCount;
		int instanceNumber;
		std::vector<ParentData> parentData;
		ParentFactory();

	public:
		~ParentFactory();
		int getInstanceNumber();
		static ParentFactory *getInstance();
		std::vector<ParentData> &CreateParent();
		void CreateParent(std::vector<ParentData> &parentData, std::vector<MasterGene> geneticsData);
};
#endif