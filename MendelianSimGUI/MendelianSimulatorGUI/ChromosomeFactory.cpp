//====================================================================
// ChromosomeFactory.cpp
// Implementation file for the master gene class.
// Author: Houston Calvert
//====================================================================
#pragma warning(disable:4996)
#include "ChromosomeFactory.h"
//====================================================================
// Constructor
//====================================================================
ChromosomeFactory::ChromosomeFactory()
{
	
}

//====================================================================
// Destructor
//====================================================================
ChromosomeFactory::~ChromosomeFactory()
{
	
}

//====================================================================
// Return the instance number (This will always be 1)
//====================================================================
int ChromosomeFactory::getInstanceNumber()
{
    return this->instanceNumber;
}

//====================================================================
// Return the singleton instance
//====================================================================
ChromosomeFactory *ChromosomeFactory::getInstance()
{
    ChromosomeFactory *theInstance = NULL;
    static int counter = 1; 
    if (theInstance == NULL)
    {
        theInstance = new ChromosomeFactory();
        theInstance->instanceNumber = counter;
        counter++; 
    }
    return theInstance;
}

void ChromosomeFactory::BuildChromosome(char *strand1, char *strand2, std::string &ch1, std::string &ch2, std::vector<MasterGene> geneticsData)
{
	Chromosome *theCh = NULL;
	theCh = new Chromosome();

	std::string strand1Str = strand1;
	std::string strand2Str = strand2;
	for (int i = 0; i < strlen(strand1Str.c_str()); i++)
	{
		if ((strand1[i] == '\0') || isspace((strand1[i])))
		{
			
		}
		else
		{
			for (int j = 0; j < geneticsData.size(); j++)
			{
				if ((strand1[i] == geneticsData[j].getDomSymbol()) || (strand1[i] == geneticsData[j].getRecSymbol()))
				{
					ch1 += strand1[i];
					ch2 += strand2[i];
				}
			}
		}
	}
}