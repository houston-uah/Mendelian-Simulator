//====================================================================
// Gene.cpp
// Implementation file for the gene class
// Author: Houston Calvert
//====================================================================

#include "Gene.h"

//====================================================================
// Constructor
//====================================================================
Gene::Gene()
{

}

//====================================================================
// Destructor
//====================================================================
Gene::~Gene()
{

}

/*int Gene::GetCrossovers(std::vector<MasterGene> geneticsData, int totalOffspring)
{
	DataParser *dParser = DataParser::getInstance();
	int totalGenes = dParser->getGeneCount();
	double totalCOChance = 0;
	for (int i = 0; i < totalGenes; i++)
	{
		std::string co = "";
		co = geneticsData[i].getCOChance();
		double coChance = atof(co.c_str());
		totalCOChance += coChance;
	}
	long double genes = totalGenes;
	long double error = (genes / 2500);
	long double percent = (0.02 - error);
	std::random_device rd;
	std::mt19937 e(rd());
	std::bernoulli_distribution d(totalCOChance * percent);
	int totalCrossovers = 0;
	for (int i = 0; i < totalOffspring; i++)
	{
		if (d(e))
		{
			totalCrossovers++;
		}
	}
	return totalCrossovers;
}*/

int Gene::GetCrossovers(std::vector<std::string> coChances, int totalOffspring)
{
	DataParser *dParser = DataParser::getInstance();
	int totalGenes = dParser->getGeneCount();
	double totalCOChance = 0;
	for (int i = 0; i < coChances.size(); i++)
	{
		std::string co = coChances[i];
		double coChance = atof(co.c_str());
		totalCOChance += coChance;
	}
	long double genes = totalGenes;
	long double error = (genes / 2500);
	long double percent = (0.02 - error);
	std::random_device rd;
	std::mt19937 e(rd());
	std::bernoulli_distribution d(totalCOChance * percent);
	int totalCrossovers = 0;
	for (int i = 0; i < totalOffspring; i++)
	{
		if (d(e))
		{
			totalCrossovers++;
		}
	}
	return totalCrossovers;
}