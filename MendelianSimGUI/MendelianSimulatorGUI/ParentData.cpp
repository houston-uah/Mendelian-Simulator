//====================================================================
// ParentData.cpp
// Implementation file for the parent data class.
// Author: Houston Calvert
//====================================================================
#pragma warning(disable:4996)
#include "ParentData.h"
//====================================================================
// Constructor
//====================================================================
ParentData::ParentData(char *scientificName, char *strand1, char *strand2)
{
	
}

//====================================================================
// Destructor
//====================================================================
ParentData::~ParentData()
{

}

char *ParentData::getScientificName()
{
	return scientificName;
}

//====================================================================
// When called, returns strand1 of parent chromosome for that parent
//====================================================================
char *ParentData::getStrand1()
{
	return strand1;
}

//====================================================================
// When called, returns strand2 of parent chromosome for that parent
//====================================================================
char *ParentData::getStrand2()
{
	return strand2;
}