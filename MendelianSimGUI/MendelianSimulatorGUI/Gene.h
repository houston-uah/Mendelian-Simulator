//====================================================================
// Gene.h
// Declaration file for the gene class
// Author: Houston Calvert
//====================================================================

#ifndef GENE_H
#define GENE_H

#include "DataParser.h"
#include "Parent.h"
#include <sstream>

class Gene
{
	public:
		Gene();
		~Gene();
		//int GetCrossovers(std::vector<MasterGene> geneticsData, int totalOffspring);
		int GetCrossovers(std::vector<std::string> coChances, int totalOffspring);
};

#endif