//====================================================================
// Display.cpp
// Implementation file for the display class
// Author: Houston Calvert
//====================================================================

#include "Display.h"
#include "MendelianSimForm.h"
using namespace MendelianSimGUI;
//====================================================================
// Constructor
//====================================================================
Display::Display()
{
	
}

//====================================================================
// Destructor
//====================================================================
Display::~Display()
{

}

//====================================================================
// Return the instance number (This will always be 1)
//====================================================================
int Display::getInstanceNumber()
{
    return this->instanceNumber;
}

//====================================================================
// Return the singleton instance
//====================================================================
Display *Display::getInstance()
{
    Display *theInstance = NULL;
    static int counter = 1; 
    if (theInstance == NULL)
    {
        theInstance = new Display();
        theInstance->instanceNumber = counter;
        counter++; 
    }
    return theInstance;
}

//====================================================================
// Displays the inital output with the gene data
//====================================================================
void Display::MasterGenesDisplay(std::vector<MasterGene> geneticsData, std::vector<ParentData> parentData)
{
	//MendelianSimForm^ msf = gcnew MendelianSimForm();
	//msf->MasterGenesDisplayForm(geneticsData, parentData);
}

//====================================================================
// Displays the general data of all the offspring for each trait
//====================================================================
/*void Display::DisplayResults(std::vector<MasterGene> geneticsData, int hetDomCount, int homDomCount, int homRecCount, int callCount)
{
	MendelianSimForm msf;
	msf.DisplayResultsForm(geneticsData, hetDomCount, homDomCount, homRecCount, callCount);
}*/

//====================================================================
// Displays the inital output with the gene data
//====================================================================
/*void Display::MasterGenesDisplay(std::vector<MasterGene> geneticsData, std::vector<ParentData> parentData)
{
	printf("\n\nRunning Simulation...\n");
	printf("\nMaster Genes:\n");
	MendelianSimForm msf;
	msf.includeStudyListBox->Items->Add("Master Genes:");
	for (int i = 0; i < geneticsData.size(); i++)
	{
		printf("\tTrait Name: %s\n", geneticsData[i].getTrait());
		msf.includeStudyListBox->Items->Add("Trait Name: ");
		printf("\t\tDominant Name: %s (%c)\n", geneticsData[i].getDomAllele(), geneticsData[i].getDomSymbol());
		msf.includeStudyListBox->Items->Add("Dominant Name: ");
		printf("\t\tRecessive Name: %s (%c)\n", geneticsData[i].getRecAllele(), geneticsData[i].getRecSymbol());
		msf.includeStudyListBox->Items->Add("Recessive Name: ");
		std::string co = "";
		co = geneticsData[i].getCOChance();
		double coChance = atof(co.c_str());
		std::cout << "\t\tChance of Crossover: " << coChance << std::endl;
		msf.includeStudyListBox->Items->Add("Chance of Crossover: ");
	}
	
	for (int j = 0; j < 2; j++)
	{
		printf("\n\nSim Parent %i\n", (j + 1));

		printf("\tOrganism Genus-Species: %s\n", parentData[j].getScientificName());
		std::string gsName = parentData[j].getScientificName();
		System::String^ gsNameStr = gcnew String(gsName.c_str());
		msf.genusSpeciesTextBox->Text = gsNameStr;
		// Get an instance of the parser class
		DataParser *parserData = DataParser::getInstance();
		printf("\tCommon Name: %s\n", parserData->getCommonName());
		std::string cName = parserData->getCommonName();
		System::String^ cNameStr = gcnew String(cName.c_str());
		msf.commonNameTextBox->Text = cNameStr;
		printf("\tChromosomes:\n");
		
		int chromosomeCount = parserData->getChromosomeCount();
		std::stringstream convert;
		convert << chromosomeCount;
		std::string cCount = convert.str();
		System::String^ cCountStr = gcnew String(cCount.c_str());
		msf.numChromosomesTextBox->Text = cCountStr;
		int b = 0;
		for (int m = 0; m < chromosomeCount; m++)
		{
			printf("\t\tChromosome %i\n", (m + 1));
			if (j == 0)
			{
				msf.p1GenotypeListBox->Items->Add("\t\tChromosome " + (m + 1));
			}
			else
			{
				msf.p2GenotypeListBox->Items->Add("\t\tChromosome " + (m + 1));
			}

			pStrand1 = parentData[b].getStrand1();
			pStrand2 = parentData[b].getStrand2();
			bool done = false;
			while (!done)
			{
				for (int k = 0; k < strlen(pStrand1); k++)
				{
					if ((pStrand1[k] == '\0') || (isspace(pStrand1[k])))
					{
					
					}
					else
					{
						for (int a = 0; a < geneticsData.size(); a++)
						{
							if ((pStrand1[k] == geneticsData[a].getDomSymbol()) || (pStrand1[k] == geneticsData[a].getRecSymbol()))
							{
								printf("\t\t\tGene Type = %s\n", geneticsData[a].getTrait());
								printf("\t\t\t\tAllele 1: %s (%c)\n", geneticsData[a].getDomAllele(), pStrand1[k]);
								printf("\t\t\t\tAllele 2: %s (%c)\n", geneticsData[a].getRecAllele(), pStrand2[k]);
								System::String^ gType = gcnew String(geneticsData[a].getTrait());
								System::String^ allele1 = gcnew String(geneticsData[a].getDomAllele());
								System::String^ allele2 = gcnew String(geneticsData[a].getRecAllele());
								System::String^ symbol1 = gcnew String(pStrand1[k].ToString());
								System::String^ symbol2 = gcnew String(pStrand2[k].ToString());

								if (j == 0)
								{
									msf.p1GenotypeListBox->Items->Add("\t\t\tGene Type = " + gType);
									msf.p1GenotypeListBox->Items->Add("\t\t\t\tAllele 1: " + allele1 + " (" + symbol1 + ")");
									msf.p1GenotypeListBox->Items->Add("\t\t\t\tAllele 2: " + allele2 + " (" + symbol2 + ")");
								}
								else
								{
									msf.p2GenotypeListBox->Items->Add("\t\t\tGene Type = " + gType);
									msf.p2GenotypeListBox->Items->Add("\t\t\t\tAllele 1: " + allele1 + " (" + symbol1 + ")");
									msf.p2GenotypeListBox->Items->Add("\t\t\t\tAllele 2: " + allele2 + " (" + symbol2 + ")");
								}
								done = true;
							}
						}
					}
				}
			}
			b++;
		}
	}
}*/

//====================================================================
// Displays the general data of all the offspring for each trait
//====================================================================
void Display::DisplayResults(std::vector<MasterGene> geneticsData, int hetDomCount, int homDomCount, int homRecCount, int callCount)
{
	// Only display this bar the first time to separate this data from the data above it
	if (callCount == 0)
	{
		std::cout << "\n======================================= Results of this Run =========================================" << std::endl;
	}
	std::cout << "Gene: " << geneticsData[callCount].getTrait() << std::endl;
	std::cout << "\t" << homDomCount << " Homozygous Dominant (" << geneticsData[callCount].getDomAllele() << " " << geneticsData[callCount].getDomSymbol() << geneticsData[callCount].getDomSymbol() << ")" << std::endl;
	std::cout << "\t" << hetDomCount << " Heterozygous Dominant (" << geneticsData[callCount].getDomAllele() << " " << geneticsData[callCount].getDomSymbol() << geneticsData[callCount].getRecSymbol() << ")" << std::endl;
	std::cout << "\t" << homRecCount << " Homozygous Recessive (" << geneticsData[callCount].getRecAllele() << " " << geneticsData[callCount].getRecSymbol() << geneticsData[callCount].getRecSymbol() << ")" << std::endl;
}