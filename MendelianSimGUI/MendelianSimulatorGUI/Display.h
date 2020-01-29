//====================================================================
// Display.h
// Declaration file for the display class
// Author: Houston Calvert
//====================================================================

#ifndef DISPLAY_H
#define DISPLAY_H
#ifndef UNICODE
#define ACSII
#include "MasterGene.h"

class Display
{
	private:
		char *pStrand1;
		char *pStrand2;
		int place1;
		int place2;
		int placement;
		int instanceNumber;
		Display();

	public:
		~Display();
		int getInstanceNumber();
		static Display *getInstance();
		void MasterGenesDisplay(std::vector<MasterGene> geneticsData, std::vector<ParentData> parentData);
		void DisplayResults(std::vector<MasterGene> geneticsData, int hetDomCount, int homDomCount, int homRecCount, int callCount);
};
#endif
#endif