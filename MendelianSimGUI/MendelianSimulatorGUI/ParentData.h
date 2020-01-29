//====================================================================
// ParentData.h
// Declaration file for the parent data class.
// Author: Houston Calvert
//====================================================================

#ifndef PARENTDATA_H
#define PARENTDATA_H

#include "DataParser.h"
#include <vector>

class ParentData
{
	public:
		char scientificName[64];
		char strand1[32];
		char strand2[32];
		std::vector<ParentData> parentData;

		ParentData(char *scientificName, char *strand1, char *strand2);
		~ParentData();
		std::vector<ParentData> &CreateParent();
		char *getStrand1();
		char *getStrand2();
		char *getScientificName();
};

#endif