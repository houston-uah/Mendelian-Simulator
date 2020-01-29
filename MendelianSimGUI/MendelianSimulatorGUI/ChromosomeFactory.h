//====================================================================
// Chromosome.h
// Declaration file for the chromosome factory class
// Author: Houston Calvert
//====================================================================

#ifndef CHROMOSOMEFACTORY_H
#define CHROMOSOMEFACTORY_H

#include "MendelianSim.h"
#include <iostream>
#include <vector>
#include "Chromosome.h"

class ChromosomeFactory
{
	private:
		std::vector<Chromosome> chromosomeData;
		int instanceNumber;
		ChromosomeFactory();

	public:
		~ChromosomeFactory();
		int getInstanceNumber();
		static ChromosomeFactory *getInstance();
		void BuildChromosome(char *strand1, char *strand2, std::string &ch1, std::string &ch2, std::vector<MasterGene> geneticsData);
};
#endif