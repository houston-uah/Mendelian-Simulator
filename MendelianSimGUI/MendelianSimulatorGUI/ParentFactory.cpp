//====================================================================
// ParentFactory.cpp
// Implementation file for the master gene class.
// Author: Houston Calvert
//====================================================================
#pragma warning(disable:4996)
#include "ParentFactory.h"
//====================================================================
// Constructor
//====================================================================
ParentFactory::ParentFactory()
{
	
}

//====================================================================
// Destructor
//====================================================================
ParentFactory::~ParentFactory()
{

}

//====================================================================
// Return the instance number (This will always be 1)
//====================================================================
int ParentFactory::getInstanceNumber()
{
    return this->instanceNumber;
}

//====================================================================
// Return the singleton instance
//====================================================================
ParentFactory *ParentFactory::getInstance()
{
    ParentFactory *theInstance = NULL;
    static int counter = 1; 
    if (theInstance == NULL)
    {
        theInstance = new ParentFactory();
        theInstance->instanceNumber = counter;
        counter++; 
    }
    return theInstance;
}

//====================================================================
// Calls the functions from the parser to get the parent data
//====================================================================
void ParentFactory::CreateParent(std::vector<ParentData> &parentData, std::vector<MasterGene> geneticsData)
{
	parentData.clear();
	// Get an instance of the parser class
	DataParser *parser = DataParser::getInstance();
	ChromosomeFactory *cf = ChromosomeFactory::getInstance();
	ParentData *pData = new ParentData(scientificName, strand1, strand2);
	strcpy(scientificName, parser->getScientificName());
	strcpy(pData->scientificName, scientificName);

	chromosomeCount = parser->getChromosomeCount();
	for (int a = 0; a < 2; a++)
	{
		for (int i = 0; i < chromosomeCount; i++)
		{
			ch1 = "";
			ch2 = "";
			if (a == 0)
			{
				// Get the first parent's chromosome
				parser->getP1Chromosome(strand1, strand2);
				cf->BuildChromosome(strand1, strand2, ch1, ch2, geneticsData);
				strcpy(pData->strand1, ch1.c_str());
				strcpy(pData->strand2, ch2.c_str());
			}
			else
			{
				// Get the second parent's chromosome
				parser->getP2Chromosome(strand1, strand2);
				cf->BuildChromosome(strand1, strand2, ch1, ch2, geneticsData);
				strcpy(pData->strand1, ch1.c_str());
				strcpy(pData->strand2, ch2.c_str());
			}
			parentData.push_back(*pData);
		}
	}
}