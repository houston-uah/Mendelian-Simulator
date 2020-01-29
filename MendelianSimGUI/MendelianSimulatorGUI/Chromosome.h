//====================================================================
// Chromosome.h
// Declaration file for the chromosome class
// Author: Houston Calvert
//====================================================================

#ifndef CHROMOSOME_H
#define CHROMOSOME_H

#include "Gene.h"

class Chromosome
{
	public:
		Chromosome();
		~Chromosome();
		void AddGene(Gene *gene);

};
#endif