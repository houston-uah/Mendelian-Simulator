//====================================================================
// MasterGeneFactory.cpp
// Implementation file for the master gene class.
// Author: Houston Calvert
//====================================================================
#pragma warning(disable:4996)
#include "MasterGeneFactory.h"
//====================================================================
// Constructor
//====================================================================
MasterGeneFactory::MasterGeneFactory()
{
	
}

//====================================================================
// Destructor
//====================================================================
MasterGeneFactory::~MasterGeneFactory()
{
	
}

//====================================================================
// Return the instance number (This will always be 1)
//====================================================================
int MasterGeneFactory::getInstanceNumber()
{
    return this->instanceNumber;
}

//====================================================================
// Return the singleton instance
//====================================================================
MasterGeneFactory *MasterGeneFactory::getInstance()
{
    MasterGeneFactory *theInstance = NULL;
    static int counter = 1; 
    if (theInstance == NULL)
    {
        theInstance = new MasterGeneFactory();
        theInstance->instanceNumber = counter;
        counter++; 
    }
    return theInstance;
}

//====================================================================
// Calls the functions from the parser to get the gene data
//====================================================================
void MasterGeneFactory::CreateMasterGene(std::vector<MasterGene> &geneticsData)
{
	
		// Get an instance of the parser class
		DataParser *parser = DataParser::getInstance();
		// Get an instance of the Master Gene class to collect all the data for each variable
		// and place it into a vector to give the data out later to whoever needs it.
		MasterGene *mg = new MasterGene(trait, domAllele, &domSymbol, recAllele, &recSymbol, &coChance);
		parser->getGeneData(mg->trait, mg->domAllele, &mg->domSymbol, mg->recAllele, &mg->recSymbol, mg->coChance);
		geneticsData.push_back(*mg);
}