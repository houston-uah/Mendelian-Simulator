//====================================================================
// MasterGene.cpp
// Implementation file for the master gene class.
// Author: Houston Calvert
//====================================================================
#pragma warning(disable:4996)
#include "MasterGene.h"
//====================================================================
// Constructor
//====================================================================
MasterGene::MasterGene(char *trait, char *domAllele, char *domSymbol, char *recAllele, char *recSymbol, char *coChance)
{
	
}

//====================================================================
// Destructor
//====================================================================
MasterGene::~MasterGene()
{

}

//====================================================================
// When called, returns the trait variable
//====================================================================
char *MasterGene::getTrait()
{
	return trait;
}

//====================================================================
// When called, returns the dominant allele name for that gene
//====================================================================
char *MasterGene::getDomAllele()
{
	return domAllele;
}

//====================================================================
// When called, returns the dominant symbol (character) for that gene
//====================================================================
char &MasterGene::getDomSymbol()
{
	return domSymbol;
}

//====================================================================
// When called, returns the recessive allele name for that gene
//====================================================================
char *MasterGene::getRecAllele()
{
	return recAllele;
}

//====================================================================
// When called, returns the recessive symbol (character) for that gene
//====================================================================
char &MasterGene::getRecSymbol()
{
	return recSymbol;
}

//====================================================================
// When called, returns the crossover chance for that gene
//====================================================================
char *MasterGene::getCOChance()
{
	return coChance;
}