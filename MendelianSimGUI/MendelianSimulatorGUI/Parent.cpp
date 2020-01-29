//====================================================================
// Parent.cpp
// Implementation file for the parent class
// Author: Houston Calvert
//====================================================================

#include "Parent.h"
//====================================================================
// Constructor
//====================================================================
CParent::CParent()
{
	heterozygousDominant = "HeterozygousDominant";
	homozygousDominant = "HomozygousDominant";
	homozygousRecessive = "HomozygousRecessive";
}

//====================================================================
// Destructor
//====================================================================
CParent::~CParent()
{

}

//====================================================================
// Removes the spaces from the parent data to make it easier later
//====================================================================
std::vector<char> &CParent::RemoveData(std::vector<ParentData> parentData)
{
	DataParser *dParser = DataParser::getInstance();
	totalGenes = dParser->getGeneCount();
	for (int i = 0; i < parentData.size(); i++)
	{
		totalGenesInChromosome = 0;
		pStrand1 = parentData[i].getStrand1();
		pStrand2 = parentData[i].getStrand2();
		strand1Str = pStrand1;
		strand2Str = pStrand2;
		for (int j = 0; j < strlen(strand1Str.c_str()); j++)
		{
			if ((strand1Str[j] == '\0') || (isspace(strand1Str[j])))
			{
				totalGenesInChromosome++;
			}
			else
			{
				parentGenotypes.push_back(strand1Str[j]);
				parentGenotypes.push_back(strand2Str[j]);
			}
		}
		genesInChromosome.push_back(totalGenesInChromosome);
	}
	// Return the new vector containing the parent data for each parent
	return parentGenotypes;
}

//====================================================================
// Determines which of the three types the parents are for each trait
//====================================================================
std::vector<std::vector<std::string> > &CParent::GetParentTypes(std::vector<ParentData> parentData)
{
	for (int i = 0; i < 2; i++)
	{
		for (int k = 0; k < genesInChromosome.size(); k++)
		{
			parentTypes.push_back(std::vector<std::string> ());
		
			for (int j = 0; j < parentGenotypes.size(); j++)
			{
				char strand1 = parentGenotypes[j];
				char strand2 = parentGenotypes[j + 1];
				// Cast each allele to either a dominant or recessive allele to compare the parent data with
				dominant = static_cast<char>(toupper(static_cast<unsigned char>(parentGenotypes[i])));
				recessive = static_cast<char>(tolower(static_cast<unsigned char>(parentGenotypes[i])));
				if ((strand1 == dominant) && (strand2 == recessive))
				{
					parentTypes[i].push_back(heterozygousDominant);
				}
				else if ((strand1 == dominant) && (strand2 == dominant))
				{
					parentTypes[i].push_back(homozygousDominant);
				}
				else if ((strand1 == recessive) && (strand2 == recessive))
				{
					parentTypes[i].push_back(homozygousRecessive);
				}
				j++;
			}
		}
	}
	// Return the vector containing each of the parent types
	return parentTypes;
}

//====================================================================
// Gets all the offspring based on the parent types and displays all
// the general offspring data for all the traits
//====================================================================
std::vector<std::vector<std::string> > &CParent::GetOffspring(std::vector<ParentData> parentData, std::vector<MasterGene> geneticsData, int totalOffspring)
{
	pNum = 0;
	for (int j = 0; j < geneticsData.size(); j++)
	{
		hetDomCount = 0;
		homDomCount = 0;
		homRecCount = 0;

		// Depending on the the two parents, call the function to get the offspring data
		if ((parentTypes[pNum][j] == heterozygousDominant) && (parentTypes[pNum + 1][j] == heterozygousDominant))
		{
			offspring = GenerateOffspring(j, totalOffspring, hetDomCount, homDomCount, homRecCount, 0.50, 1);
		}
		else if (((parentTypes[pNum][j] == heterozygousDominant) && (parentTypes[pNum + 1][j] == homozygousDominant)) || ((parentTypes[pNum][j] == homozygousDominant) && (parentTypes[pNum + 1][j] == heterozygousDominant)))
		{
			offspring = GenerateOffspring(j, totalOffspring, hetDomCount, homDomCount, homRecCount, 0.50, 2);
		}
		else if (((parentTypes[pNum][j] == heterozygousDominant) && (parentTypes[pNum + 1][j] == homozygousRecessive)) || ((parentTypes[pNum][j] == homozygousRecessive) && (parentTypes[pNum + 1][j] == heterozygousDominant)))
		{
			offspring = GenerateOffspring(j, totalOffspring, hetDomCount, homDomCount, homRecCount, 0.50, 3);
		}
		else if (((parentTypes[pNum][j] == homozygousDominant) && (parentTypes[pNum + 1][j] == homozygousRecessive)) || ((parentTypes[pNum][j] == homozygousRecessive) && (parentTypes[pNum + 1][j] == homozygousDominant)))
		{
			offspring = GenerateOffspring(j, totalOffspring, hetDomCount, homDomCount, homRecCount, 0.50, 4);
		}
		else if (((parentTypes[pNum][j] == homozygousDominant) && (parentTypes[pNum + 1][j] == homozygousDominant)) || ((parentTypes[pNum][j] == homozygousDominant) && (parentTypes[pNum + 1][j] == homozygousDominant)))
		{
			offspring = GenerateOffspring(j, totalOffspring, hetDomCount, homDomCount, homRecCount, 1.00, 5);
		}
		else if (((parentTypes[pNum][j] == homozygousRecessive) && (parentTypes[pNum + 1][j] == homozygousRecessive)) || ((parentTypes[pNum][j] == homozygousRecessive) && (parentTypes[pNum + 1][j] == homozygousRecessive)))
		{
			offspring = GenerateOffspring(j, totalOffspring, hetDomCount, homDomCount, homRecCount, 1.00, 6);
		}

		// Get an instance of the display class
		Display *display = Display::getInstance();

		// Display all the data
		display->DisplayResults(geneticsData, hetDomCount, homDomCount, homRecCount, j);
	}
	// Return the vector constaining the offspring data
	return offspring;
}

//====================================================================
// Generates the three different genes for all offspring
//====================================================================
std::vector<std::vector<std::string> > &CParent::GenerateOffspring(int a, int totalOffspring, int &hetDomCount, int &homDomCount, int &homRecCount, double percent, int type)
{
	//Create the next row for the 2D vector
	offspring.push_back(std::vector<std::string> ());
	// Built in functions that can be used for probabilty/random generation
	// I know it's not good to declare a variable inside a function, but I tried everything like declaring it in the
	// header file class, but it for some reason would clear the data usless I declared it here.
	std::random_device rd;
	std::mt19937 e(rd());
	std::bernoulli_distribution d(percent);
	//Determines the gene for all offspring based on total amount of offspring inputted by the user.
	for (int i = 0; i < totalOffspring; i++)
	{
		// Type 1: Both parents are heterozygous dominant
		// Type 2: One parent is heterozygous dominant, the other is homozygous dominant
		// Type 3: One parent is heterozygous dominant, the other is homozygous recessive
		// Type 4: One parent is homozygous dominant, the other is homozygous recessive
		// Type 5: Both parents are homozygous dominant
		// Type 6: Both parents are homozygous recessive

		// If both parent are homozygous dominant (type 5) or both parents are homozygous 
		// recessive (type 6), 100% of the offspring will be of that same type
		if (type == 5)
		{
			offspring[a].push_back(homozygousDominant);
			homDomCount++;
		}
		else if (type == 6)
		{
			offspring[a].push_back(homozygousRecessive);
			homRecCount++;
		}
		else
		{
			// For the other types, the offspring will be heterozygous dominant half the time
			if (d(e))
			{
				offspring[a].push_back(heterozygousDominant);
				hetDomCount++;
			}
			else
			{
				// If parents are of types 1 or 4, they can produce offspring with any type the other half the time
				if ((type == 1) || (type == 4))
				{
					if (d(e))
					{
						offspring[a].push_back(homozygousDominant);
						homDomCount++;
					}
					else
					{
						offspring[a].push_back(homozygousRecessive);
						homRecCount++;
					}
				}
				else if (type == 2)
				{
					// Offspring can only be of this type for the other half
					offspring[a].push_back(homozygousDominant);
					homDomCount++;
				}
				else if (type == 3)
				{
					// Offspring can only be of this type for the other half
					offspring[a].push_back(homozygousRecessive);
					homRecCount++;
				}
			}
		}
	}
	// Return the vector containing the offspring data
	return offspring;
}