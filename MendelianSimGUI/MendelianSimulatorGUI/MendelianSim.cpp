//====================================================================
// MendelianSim.cpp
// Implementation file for the simulation program.
// Author: Houston Calvert
//====================================================================
#pragma warning(disable:4996)
#include "MendelianSim.h"

//====================================================================
// Constructor
//====================================================================
MendelianSim::MendelianSim()
{
	done = false;
	fileExists = false;
	newFile = false;
}

//====================================================================
// Destructor
//====================================================================
MendelianSim::~MendelianSim()
{

}

//====================================================================
// Return the instance number (This will always be 1)
//====================================================================
int MendelianSim::getInstanceNumber()
{
    return this->instanceNumber;
}

//====================================================================
// Return the singleton instance
//====================================================================
MendelianSim *MendelianSim::getInstance()
{
    static MendelianSim *theInstance = NULL;
    static int counter = 1; 
    if (theInstance == NULL)
    {
        theInstance = new MendelianSim();
        theInstance->instanceNumber = counter;
        counter++; 
    }
    return theInstance;
}

//====================================================================
// Prompts user to type in file name to retrive the data from
//====================================================================
char MendelianSim::DataFilePrompt(char *file)
{
	while (!done)
	{
		printf("Name of file: ");
		std::cin >> fileInput;
		strcpy(file, fileInput.c_str());
		/*std::string fileName = "GeneticsSim2";
		fileName += getch();
		fileName += ".xml";
		strcpy(file, fileName.c_str());*/
		bool fileCheck = CheckFile(file);

		if (fileCheck)
		{
			done = true;
		}
	}
	return *file;
}

//====================================================================
// Checks to make sure the file inputted exists
//====================================================================
bool MendelianSim::CheckFile(char *fileName)
{
	fileExists = false;
	//Built in function to check path to file
	fileExists = PathFileExists(fileName);
	// If the file exists return true
	if (fileExists)
	{
		return true;
	}
	else
	{
		// Else if user has typed in a wrong file more than once
		if (totalAttempts < 1)
		{
			std::cout << "File does not exist. Try Again." << std::endl;
			return false;
		}
		else
		{
			// Tell user to double check manually if file inputted is correct
			std::cout << "File does not exist. Try typing an exact path to the file." << std::endl;
			return false;
		}
	}
}

//====================================================================
// Function that prompts the user for the amount of offspring
// they want to generate
//====================================================================
int MendelianSim::UserOffspringPrompt()
{
	totalOffspring = 0;
	done = false;
	// I could not seem to create a char array without declaring and intitializing it in the function itself
	char numbers[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	// Check to make sure the user input does not contain non-numeric characters
	while(!done)
	{
		std::cout << "\nHow many offspring do you want to generate? (Type the number then press 'Enter')" << std::endl;
		std::cout << "==>";
		std::cin >> userInput;
		for (int i = 0; i < userInput.length(); i++)
		{
			isNumber = false;
			for (int j = 0; j < sizeof(numbers); j++)
			{
				if (userInput[i] == numbers[j])
				{
					isNumber = true;
				}
			}
			if (!isNumber)
			{
				std::cout << "Incorrect Input. Try Again." << std::endl;
				break;
			}
			if ((i == (userInput.length() - 1)) && (isNumber))
			{
				totalOffspring = atoi(userInput.c_str());
				done = true;
			}
		}
	}
	// Return the total offspring the user wants to generate
	return totalOffspring;
}

//====================================================================
// The main function of the MendelianSim class that calls all
// necessary functions to get all the data
//====================================================================
void MendelianSim::RunSimulation(char *file)
{
	// Clear all the data in the vectors
	// I tried placing this info in the constructor and destructor and it gave me too 
	// many problems, so I hope this isn't breaking any OOP principles
	offspring.clear();
	parentTypes.clear();
	parentGenotypes.clear();

	// Prompt the user for the file name
	//DataFilePrompt(file);

	// Clear the data in these two vectors at this point to prepare to get new data
	parentData.clear();
	geneticsData.clear();

	// Get an instance of the parser and initialize the file that is being used
	DataParser *parser = DataParser::getInstance();
	parser->initDataFile(file);
	
	// Call this function of the parent data class to get the parent data 
	//parentData = pf->CreateParent();

	// Get an instance of the master gene class
	DataParser *dParser = DataParser::getInstance();
	totalGenes = 0;
	totalGenes = dParser->getGeneCount();
	for (int i = 0; i < totalGenes; i++)
	{
		MasterGeneFactory *mgf = MasterGeneFactory::getInstance();
		mgf->CreateMasterGene(geneticsData);
	}

	DataParser *dParser1 = DataParser::getInstance();
	ParentData *pData;
		
	// Get an instance of the parent data class
	ParentFactory *pf = ParentFactory::getInstance();
	pf->CreateParent(parentData, geneticsData);

	// Get a new instance of the display class
	Display *display = Display::getInstance();

	// Display the master gene data
	display->MasterGenesDisplay(geneticsData, parentData);

	// Prompt the user for the amount of offspring they want to generate
	/*UserOffspringPrompt();

	// Get a new instance of the parent class
	Parent *parent = new Parent();

	// Remove the spaces from the line retrieved by the parser
	parentGenotypes = parent->RemoveData(parentData);

	// Determine what type each parent's traits are
	parentTypes = parent->GetParentTypes(parentData);

	// Get the offspring based on the parent data found from the parser data
	offspring = parent->GetOffspring(parentData, geneticsData, totalOffspring);

	Gene *gene = new Gene();
	totalCrossovers = gene->GetCrossovers(geneticsData, totalOffspring);
	printf("\n\nA total of %i offspring had at least one crossover gene.\n\n", totalCrossovers);
	system("pause");*/
}