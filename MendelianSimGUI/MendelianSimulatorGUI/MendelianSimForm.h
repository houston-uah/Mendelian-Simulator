#pragma once
#pragma comment(lib, "Shlwapi.lib")
#include "shlwapi.h"
#include "MendelianSim.h"
#include "Parent.h"
#include <cmath>
#define BUFSIZE 4096

namespace MendelianSimGUI {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	using namespace System::Collections::Generic;
	/// <summary>
	/// Summary for MendelianSimForm
	/// </summary>

	public ref class MendelianSimForm : public System::Windows::Forms::Form
	{
	
	public:

		MendelianSimForm(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MendelianSimForm()
		{
			if (components)
			{
				delete components;
			}
		}
		
	public:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		char *filename;
		char *fullFilePath;
		int totalOffspring;
		bool nonNumberEntered;
		bool charNotAllowed;
		List<String^> traits;
		List<String^> domAlleles;
		List<String^> domSymbols;
		List<String^> recAlleles;
		List<String^> recSymbols;
		List<String^> coChances;
		
		List<String^> scientificName;
		List<String^> strand1;
		List<String^> strand2;

		System::ComponentModel::Container^ components;
		System::Windows::Forms::GroupBox^ initializeSimGroupBox;
		System::Windows::Forms::GroupBox^ testOrganismGroupBox;
		System::Windows::Forms::GroupBox^ experimentGroupBox;
		System::Windows::Forms::Label^ dataFileLabel;
		System::Windows::Forms::Label^ genusSpeciesLabel;
		System::Windows::Forms::Label^ commonNameLabel;
		System::Windows::Forms::Label^ numChromosomesLabel;
		System::Windows::Forms::Label^ includeStudyLabel;
		System::Windows::Forms::Label^ p1GenotypeLabel;
		System::Windows::Forms::Label^ p2GenotypeLabel;
		System::Windows::Forms::Label^ numOffspringLabel;
		System::Windows::Forms::Label^ outputFileLabel;
		System::Windows::Forms::TextBox^ dataFileTextBox;
		System::Windows::Forms::TextBox^ genusSpeciesTextBox;
		System::Windows::Forms::TextBox^ commonNameTextBox;
		System::Windows::Forms::TextBox^ numChromosomesTextBox;
		System::Windows::Forms::TextBox^ numOffspringTextBox;
		System::Windows::Forms::TextBox^ outputFileTextBox;
		System::Windows::Forms::ListBox^ includeStudyListBox;
		System::Windows::Forms::ListBox^ p1GenotypeListBox;
		System::Windows::Forms::ListBox^ p2GenotypeListBox;
		System::Windows::Forms::ListBox^ resultsListBox;
		System::Windows::Forms::Button^ initializeSimButton;
		System::Windows::Forms::Button^ endSimButton;
		System::Windows::Forms::Button^ runExperimentButton;
		System::Windows::Forms::Button^ saveResultsButton;
		System::Windows::Forms::Button^ findFileButton;
		System::Windows::Forms::Button^ browseFileButton;
		System::Windows::Forms::ProgressBar^ pBar;
		System::Windows::Forms::Label^ pBarLabel;
		System::Windows::Forms::TextBox^ redTextBox;
		System::Windows::Forms::FolderBrowserDialog^ browseFileDialog;
		System::Windows::Forms::OpenFileDialog^ openFileDialog;
		System::Windows::Forms::SaveFileDialog^ saveFileDialog;
		System::Windows::Forms::ToolTip^ toolTip;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->initializeSimGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->dataFileLabel = (gcnew System::Windows::Forms::Label());
			this->dataFileTextBox = (gcnew System::Windows::Forms::TextBox());
			this->initializeSimButton = (gcnew System::Windows::Forms::Button());
			this->endSimButton = (gcnew System::Windows::Forms::Button());
			this->findFileButton = (gcnew System::Windows::Forms::Button());
			this->testOrganismGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->genusSpeciesLabel = (gcnew System::Windows::Forms::Label());
			this->genusSpeciesTextBox = (gcnew System::Windows::Forms::TextBox());
			this->commonNameLabel = (gcnew System::Windows::Forms::Label());
			this->commonNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->numChromosomesLabel = (gcnew System::Windows::Forms::Label());
			this->numChromosomesTextBox = (gcnew System::Windows::Forms::TextBox());
			this->includeStudyLabel = (gcnew System::Windows::Forms::Label());
			this->includeStudyListBox = (gcnew System::Windows::Forms::ListBox());
			this->p1GenotypeLabel = (gcnew System::Windows::Forms::Label());
			this->p1GenotypeListBox = (gcnew System::Windows::Forms::ListBox());
			this->p2GenotypeLabel = (gcnew System::Windows::Forms::Label());
			this->p2GenotypeListBox = (gcnew System::Windows::Forms::ListBox());
			this->experimentGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->numOffspringLabel = (gcnew System::Windows::Forms::Label());
			this->numOffspringTextBox = (gcnew System::Windows::Forms::TextBox());
			this->runExperimentButton = (gcnew System::Windows::Forms::Button());
			this->outputFileLabel = (gcnew System::Windows::Forms::Label());
			this->outputFileTextBox = (gcnew System::Windows::Forms::TextBox());
			this->saveResultsButton = (gcnew System::Windows::Forms::Button());
			this->resultsListBox = (gcnew System::Windows::Forms::ListBox());
			this->pBar = (gcnew System::Windows::Forms::ProgressBar());
			this->pBarLabel = (gcnew System::Windows::Forms::Label());
			this->browseFileButton = (gcnew System::Windows::Forms::Button());
			this->redTextBox = (gcnew System::Windows::Forms::TextBox());
			this->browseFileDialog = gcnew System::Windows::Forms::FolderBrowserDialog();
			this->openFileDialog = gcnew System::Windows::Forms::OpenFileDialog();
			this->saveFileDialog = gcnew System::Windows::Forms::SaveFileDialog();
			this->toolTip = gcnew System::Windows::Forms::ToolTip();
			this->initializeSimGroupBox->SuspendLayout();
			this->testOrganismGroupBox->SuspendLayout();
			this->experimentGroupBox->SuspendLayout();
			this->SuspendLayout();
			// 
			// initializeSimGroupBox
			// 
			this->initializeSimGroupBox->Controls->Add(this->dataFileLabel);
			this->initializeSimGroupBox->Controls->Add(this->dataFileTextBox);
			this->initializeSimGroupBox->Controls->Add(this->initializeSimButton);
			this->initializeSimGroupBox->Controls->Add(this->endSimButton);
			this->initializeSimGroupBox->Controls->Add(this->findFileButton);
			this->initializeSimGroupBox->Location = System::Drawing::Point(10, 5);
			this->initializeSimGroupBox->Name = L"initializeSimGroupBox";
			this->initializeSimGroupBox->Size = System::Drawing::Size(790, 40);
			this->initializeSimGroupBox->TabIndex = 0;
			this->initializeSimGroupBox->TabStop = false;
			// 
			// dataFileLabel
			// 
			this->dataFileLabel->Location = System::Drawing::Point(50, 15);
			this->dataFileLabel->Name = L"dataFileLabel";
			this->dataFileLabel->Size = System::Drawing::Size(52, 15);
			this->dataFileLabel->TabIndex = 0;
			this->dataFileLabel->Text = L"Data File:";
			// 
			// dataFileTextBox
			// 
			this->dataFileTextBox->Location = System::Drawing::Point(105, 13);
			this->dataFileTextBox->Name = L"dataFileTextBox";
			this->dataFileTextBox->Size = System::Drawing::Size(200, 20);
			this->dataFileTextBox->TabIndex = 1;
			this->dataFileTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->dataFileTextBox->TextChanged += gcnew System::EventHandler(this, &MendelianSimForm::dataFileTextBox_TextChanged);
			// 
			// initializeSimButton
			// 
			this->initializeSimButton->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->initializeSimButton->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->initializeSimButton->Location = System::Drawing::Point(375, 13);
			this->initializeSimButton->Name = L"initializeSimButton";
			this->initializeSimButton->Size = System::Drawing::Size(150, 20);
			this->initializeSimButton->TabIndex = 2;
			this->initializeSimButton->Text = L"Initialize Simulation";
			this->initializeSimButton->Click += gcnew System::EventHandler(this, &MendelianSimForm::initializeSimButton_Click);
			// 
			// endSimButton
			// 
			this->endSimButton->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->endSimButton->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->endSimButton->Location = System::Drawing::Point(575, 13);
			this->endSimButton->Name = L"endSimButton";
			this->endSimButton->Size = System::Drawing::Size(150, 20);
			this->endSimButton->TabIndex = 3;
			this->endSimButton->Text = L"End Simulation";
			this->endSimButton->Click += gcnew System::EventHandler(this, &MendelianSimForm::endSimButton_Click);
			// 
			// findFileButton
			// 
			this->findFileButton->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->findFileButton->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->findFileButton->Location = System::Drawing::Point(305, 13);
			this->findFileButton->Name = L"findFileButton";
			this->findFileButton->Size = System::Drawing::Size(25, 20);
			this->findFileButton->TabIndex = 4;
			this->findFileButton->Text = L"...";
			this->findFileButton->Click += gcnew System::EventHandler(this, &MendelianSimForm::findFileButton_Click);
			// 
			// testOrganismGroupBox
			// 
			this->testOrganismGroupBox->Controls->Add(this->genusSpeciesLabel);
			this->testOrganismGroupBox->Controls->Add(this->genusSpeciesTextBox);
			this->testOrganismGroupBox->Controls->Add(this->commonNameLabel);
			this->testOrganismGroupBox->Controls->Add(this->commonNameTextBox);
			this->testOrganismGroupBox->Controls->Add(this->numChromosomesLabel);
			this->testOrganismGroupBox->Controls->Add(this->numChromosomesTextBox);
			this->testOrganismGroupBox->Controls->Add(this->includeStudyLabel);
			this->testOrganismGroupBox->Controls->Add(this->includeStudyListBox);
			this->testOrganismGroupBox->Controls->Add(this->p1GenotypeLabel);
			this->testOrganismGroupBox->Controls->Add(this->p1GenotypeListBox);
			this->testOrganismGroupBox->Controls->Add(this->p2GenotypeLabel);
			this->testOrganismGroupBox->Controls->Add(this->p2GenotypeListBox);
			this->testOrganismGroupBox->Location = System::Drawing::Point(10, 55);
			this->testOrganismGroupBox->Name = L"testOrganismGroupBox";
			this->testOrganismGroupBox->Size = System::Drawing::Size(790, 330);
			this->testOrganismGroupBox->TabIndex = 1;
			this->testOrganismGroupBox->TabStop = false;
			this->testOrganismGroupBox->Text = L"Test Organism";
			// 
			// genusSpeciesLabel
			// 
			this->genusSpeciesLabel->Location = System::Drawing::Point(10, 20);
			this->genusSpeciesLabel->Name = L"genusSpeciesLabel";
			this->genusSpeciesLabel->Size = System::Drawing::Size(82, 15);
			this->genusSpeciesLabel->TabIndex = 0;
			this->genusSpeciesLabel->Text = L"Genus-Species:";
			// 
			// genusSpeciesTextBox
			// 
			this->genusSpeciesTextBox->BackColor = System::Drawing::SystemColors::Window;
			this->genusSpeciesTextBox->Location = System::Drawing::Point(95, 18);
			this->genusSpeciesTextBox->Name = L"genusSpeciesTextBox";
			this->genusSpeciesTextBox->ReadOnly = true;
			this->genusSpeciesTextBox->Size = System::Drawing::Size(150, 20);
			this->genusSpeciesTextBox->TabIndex = 1;
			// 
			// commonNameLabel
			// 
			this->commonNameLabel->Location = System::Drawing::Point(315, 20);
			this->commonNameLabel->Name = L"commonNameLabel";
			this->commonNameLabel->Size = System::Drawing::Size(82, 15);
			this->commonNameLabel->TabIndex = 2;
			this->commonNameLabel->Text = L"Common Name:";
			// 
			// commonNameTextBox
			// 
			this->commonNameTextBox->BackColor = System::Drawing::SystemColors::Window;
			this->commonNameTextBox->Location = System::Drawing::Point(400, 18);
			this->commonNameTextBox->Name = L"commonNameTextBox";
			this->commonNameTextBox->ReadOnly = true;
			this->commonNameTextBox->Size = System::Drawing::Size(100, 20);
			this->commonNameTextBox->TabIndex = 3;
			// 
			// numChromosomesLabel
			// 
			this->numChromosomesLabel->Location = System::Drawing::Point(580, 20);
			this->numChromosomesLabel->Name = L"numChromosomesLabel";
			this->numChromosomesLabel->Size = System::Drawing::Size(86, 15);
			this->numChromosomesLabel->TabIndex = 4;
			this->numChromosomesLabel->Text = L"# Chromosomes:";
			// 
			// numChromosomesTextBox
			// 
			this->numChromosomesTextBox->BackColor = System::Drawing::SystemColors::Window;
			this->numChromosomesTextBox->Location = System::Drawing::Point(670, 18);
			this->numChromosomesTextBox->Name = L"numChromosomesTextBox";
			this->numChromosomesTextBox->ReadOnly = true;
			this->numChromosomesTextBox->Size = System::Drawing::Size(50, 20);
			this->numChromosomesTextBox->TabIndex = 5;
			// 
			// includeStudyLabel
			// 
			this->includeStudyLabel->Location = System::Drawing::Point(60, 50);
			this->includeStudyLabel->Name = L"includeStudyLabel";
			this->includeStudyLabel->Size = System::Drawing::Size(195, 18);
			this->includeStudyLabel->TabIndex = 6;
			this->includeStudyLabel->Text = L"Genes/Chromosomes Included In Study";
			// 
			// includeStudyListBox
			// 
			this->includeStudyListBox->Location = System::Drawing::Point(10, 70);
			this->includeStudyListBox->Name = L"includeStudyListBox";
			this->includeStudyListBox->SelectionMode = System::Windows::Forms::SelectionMode::None;
			this->includeStudyListBox->Size = System::Drawing::Size(355, 255);
			this->includeStudyListBox->TabIndex = 7;
			// 
			// p1GenotypeLabel
			// 
			this->p1GenotypeLabel->Location = System::Drawing::Point(525, 50);
			this->p1GenotypeLabel->Name = L"p1GenotypeLabel";
			this->p1GenotypeLabel->Size = System::Drawing::Size(96, 18);
			this->p1GenotypeLabel->TabIndex = 8;
			this->p1GenotypeLabel->Text = L"Parent 1 Genotype";
			// 
			// p1GenotypeListBox
			// 
			this->p1GenotypeListBox->FormattingEnabled = true;
			this->p1GenotypeListBox->Location = System::Drawing::Point(375, 70);
			this->p1GenotypeListBox->Name = L"p1GenotypeListBox";
			this->p1GenotypeListBox->SelectionMode = System::Windows::Forms::SelectionMode::None;
			this->p1GenotypeListBox->Size = System::Drawing::Size(400, 110);
			this->p1GenotypeListBox->TabIndex = 9;
			// 
			// p2GenotypeLabel
			// 
			this->p2GenotypeLabel->Location = System::Drawing::Point(525, 190);
			this->p2GenotypeLabel->Name = L"p2GenotypeLabel";
			this->p2GenotypeLabel->Size = System::Drawing::Size(96, 18);
			this->p2GenotypeLabel->TabIndex = 10;
			this->p2GenotypeLabel->Text = L"Parent 2 Genotype";
			// 
			// p2GenotypeListBox
			// 
			this->p2GenotypeListBox->Location = System::Drawing::Point(375, 210);
			this->p2GenotypeListBox->Name = L"p2GenotypeListBox";
			this->p2GenotypeListBox->SelectionMode = System::Windows::Forms::SelectionMode::None;
			this->p2GenotypeListBox->Size = System::Drawing::Size(400, 110);
			this->p2GenotypeListBox->TabIndex = 11;
			// 
			// experimentGroupBox
			// 
			this->experimentGroupBox->Controls->Add(this->numOffspringLabel);
			this->experimentGroupBox->Controls->Add(this->numOffspringTextBox);
			this->experimentGroupBox->Controls->Add(this->runExperimentButton);
			this->experimentGroupBox->Controls->Add(this->outputFileLabel);
			this->experimentGroupBox->Controls->Add(this->outputFileTextBox);
			this->experimentGroupBox->Controls->Add(this->saveResultsButton);
			this->experimentGroupBox->Controls->Add(this->browseFileButton);
			this->experimentGroupBox->Controls->Add(this->resultsListBox);
			this->experimentGroupBox->Location = System::Drawing::Point(10, 395);
			this->experimentGroupBox->Name = L"experimentGroupBox";
			this->experimentGroupBox->Size = System::Drawing::Size(790, 310);
			this->experimentGroupBox->TabIndex = 2;
			this->experimentGroupBox->TabStop = false;
			this->experimentGroupBox->Text = L"Experiment";
			// 
			// numOffspringLabel
			// 
			this->numOffspringLabel->Location = System::Drawing::Point(10, 75);
			this->numOffspringLabel->Name = L"numOffspringLabel";
			this->numOffspringLabel->Size = System::Drawing::Size(121, 18);
			this->numOffspringLabel->TabIndex = 0;
			this->numOffspringLabel->Text = L"# Offspring to Generate:";
			this->numOffspringTextBox->KeyDown += gcnew KeyEventHandler(this, &MendelianSimForm::numOffspringTextBox_KeyDown);
			this->numOffspringTextBox->KeyPress += gcnew KeyPressEventHandler(this, &MendelianSimForm::numOffspringTextBox_KeyPress);
			// 
			// numOffspringTextBox
			// 
			this->numOffspringTextBox->Location = System::Drawing::Point(30, 95);
			this->numOffspringTextBox->MaxLength = 6;
			this->numOffspringTextBox->Name = L"numOffspringTextBox";
			this->numOffspringTextBox->Size = System::Drawing::Size(75, 20);
			this->numOffspringTextBox->TabIndex = 1;
			this->numOffspringTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// runExperimentButton
			// 
			this->runExperimentButton->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->runExperimentButton->Location = System::Drawing::Point(10, 125);
			this->runExperimentButton->Name = L"runExperimentButton";
			this->runExperimentButton->Size = System::Drawing::Size(121, 20);
			this->runExperimentButton->TabIndex = 2;
			this->runExperimentButton->Text = L"Run Experiment";
			this->runExperimentButton->Click += gcnew System::EventHandler(this, &MendelianSimForm::runExperimentButton_Click);
			// 
			// outputFileLabel
			// 
			this->outputFileLabel->Location = System::Drawing::Point(25, 160);
			this->outputFileLabel->Name = L"outputFileLabel";
			this->outputFileLabel->Size = System::Drawing::Size(92, 18);
			this->outputFileLabel->TabIndex = 3;
			this->outputFileLabel->Text = L"Output File Name:";
			// 
			// outputFileTextBox
			// 
			this->outputFileTextBox->Location = System::Drawing::Point(10, 180);
			this->outputFileTextBox->Name = L"outputFileTextBox";
			this->outputFileTextBox->Size = System::Drawing::Size(121, 20);
			this->outputFileTextBox->TabIndex = 4;
			this->outputFileTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->outputFileTextBox->KeyPress += gcnew KeyPressEventHandler(this, &MendelianSimForm::outputFileTextBox_KeyPress);
			this->outputFileTextBox->TextChanged += gcnew System::EventHandler(this, &MendelianSimForm::outputFileTextBox_TextChanged);
			// 
			// saveResultsButton
			// 
			this->saveResultsButton->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->saveResultsButton->Location = System::Drawing::Point(10, 210);
			this->saveResultsButton->Name = L"saveResultsButton";
			this->saveResultsButton->Size = System::Drawing::Size(121, 20);
			this->saveResultsButton->TabIndex = 8;
			this->saveResultsButton->Text = L"Save Results";
			this->saveResultsButton->Click += gcnew System::EventHandler(this, &MendelianSimForm::saveResultsButton_Click);
			// 
			// browseFileButton
			// 
			this->browseFileButton->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->browseFileButton->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->browseFileButton->Location = System::Drawing::Point(133, 180);
			this->browseFileButton->Name = L"saveFileButton";
			this->browseFileButton->Size = System::Drawing::Size(25, 20);
			this->browseFileButton->TabIndex = 5;
			this->browseFileButton->Text = L"...";
			//this->toolTip->SetToolTip(browseFileButton, "Default path is: ..\\Results Output Files");
			//this->toolTip->ToolTipTitle = "Change file path location or choose a file. ";
			//this->toolTip->AutoPopDelay = 30000;
			this->browseFileButton->Click += gcnew System::EventHandler(this, &MendelianSimForm::browseFileButton_Click);
			// 
			// resultsListBox
			// 
			this->resultsListBox->Location = System::Drawing::Point(205, 13);
			this->resultsListBox->Name = L"resultsListBox";
			this->resultsListBox->SelectionMode = System::Windows::Forms::SelectionMode::None;
			this->resultsListBox->Size = System::Drawing::Size(570, 290);
			this->resultsListBox->TabIndex = 6;
			// 
			// pBar
			// 
			this->pBar->Location = System::Drawing::Point(10, 715);
			this->pBar->Name = L"pBar";
			this->pBar->Size = System::Drawing::Size(790, 20);
			this->pBar->TabIndex = 3;
			// 
			// pBarLabel
			// 
			this->pBarLabel->Location = System::Drawing::Point(355, 740);
			this->pBarLabel->Name = L"pBarLabel";
			this->pBarLabel->Size = System::Drawing::Size(100, 15);
			this->pBarLabel->TabIndex = 4;
			this->pBarLabel->Text = L"Progress: 0%";
			// 
			// redTextBox
			// 
			this->redTextBox->Location = System::Drawing::Point(10, 715);
			this->redTextBox->Name = L"redTextBox";
			this->redTextBox->Size = System::Drawing::Size(790, 20);
			this->redTextBox->TabIndex = 5;
			this->redTextBox->Visible = false;
			// 
			// MendelianSimForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(810, 765);
			this->Controls->Add(this->initializeSimGroupBox);
			this->Controls->Add(this->testOrganismGroupBox);
			this->Controls->Add(this->experimentGroupBox);
			this->Controls->Add(this->pBar);
			this->Controls->Add(this->pBarLabel);
			this->Controls->Add(this->redTextBox);
			this->Name = L"MendelianSimForm";
			this->Text = L"Mendelian Genetics Simulator";
			this->Load += gcnew System::EventHandler(this, &MendelianSimForm::MendelianSimForm_Load);
			this->initializeSimGroupBox->ResumeLayout(false);
			this->initializeSimGroupBox->PerformLayout();
			this->testOrganismGroupBox->ResumeLayout(false);
			this->testOrganismGroupBox->PerformLayout();
			this->experimentGroupBox->ResumeLayout(false);
			this->experimentGroupBox->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		System::Void MendelianSimForm_Load(System::Object^  sender, System::EventArgs^  e) 
		{
			this->initializeSimButton->Enabled = false;
			this->endSimButton->Enabled = false;
			this->runExperimentButton->Enabled = false;
			this->saveResultsButton->Enabled = false;
			this->numOffspringTextBox->Enabled = false;
			this->outputFileTextBox->Enabled = false;
			this->browseFileButton->Enabled = false;
			this->ActiveControl = dataFileTextBox;
			//this->dataFileTextBox->Text = "GeneticsSim2a.xml";
		}

		System::Void dataFileTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) 
		{
			filename = (char*)Marshal::StringToCoTaskMemAnsi(this->dataFileTextBox->Text->ToString()).ToPointer();
			bool pathCheck = false;
			pathCheck = PathFileExists(filename);
			if (pathCheck)
			{
				this->initializeSimButton->Enabled = true;
				this->ActiveControl = initializeSimButton;
			}
			else
			{
				this->initializeSimButton->Enabled = false;
			}
		}

		System::Void findFileButton_Click(System::Object^  sender, System::EventArgs^  e)
		{
			System::Windows::Forms::OpenFileDialog^ findFileDialog = gcnew System::Windows::Forms::OpenFileDialog();
			char buffer[BUFSIZE] = TEXT("");
			GetCurrentDirectory(BUFSIZE, buffer);
			String^ path = gcnew String(buffer);
			findFileDialog->InitialDirectory = path;
			findFileDialog->Filter = "xml files (*.xml)| *.xml";//|All files (*.*)|*.*";
			findFileDialog->FilterIndex = 2;
			findFileDialog->RestoreDirectory = true;
			
			if (findFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				std::string file = (char*)Marshal::StringToCoTaskMemAnsi(findFileDialog->FileName->ToString()).ToPointer();
				std::string fileName = "";
				int totalSlashes = 0;
				int slashNum = 0;
				for (int i = 0; i < file.length(); i++)
				{
					if (file[i] == '/' || file[i] == '\\')
					{
						totalSlashes++;
					}
				}

				for (int j = 0; j < file.length(); j++)
				{
					if (file[j] == '/' || file[j] == '\\')
					{
						slashNum++;
					}
					if (slashNum == totalSlashes)
					{
						for (int k = j + 1; k < file.length(); k++)
						{
							fileName += file[k];
						}
						break;
					}
				}
				String^ fName = gcnew String(fileName.c_str());
				dataFileTextBox->Text = fName;
			}
		}
		
		System::Void initializeSimButton_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			this->dataFileTextBox->BackColor = System::Drawing::SystemColors::Window;
			this->dataFileTextBox->ReadOnly = true;
			this->initializeSimButton->Enabled = false;
			this->endSimButton->Enabled = true;
			this->findFileButton->Enabled = true;
			this->numOffspringTextBox->Enabled = true;
			this->ActiveControl = numOffspringTextBox;
			
			std::vector<MasterGene> geneticsData;
			std::vector<ParentData> parentData;
			int totalGenes = 0;
			int totalChromosomes = 0;
			int geneLoops = 0;
			int chromosomeLoops = 0;
			int totFuncNIL = 3;
			int totalUpdates = 0;
			int prog = 9;
			double coChance = 0;
			long double progMult = 0.000;
			String^ trait;
			String^ dAllele;
			String^ dSymbol;
			String^ rAllele;
			String^ rSymbol;
			String^ crossChance;
			String^ gsNameStr;
			std::string dataFile;
			std::string domAllele;
			std::string recAllele;
			std::string dsSymbol;
			std::string rsSymbol;
			std::string co;
			std::string gsName;
			char domSymbol;
			char recSymbol;

			dataFile = (char*)Marshal::StringToCoTaskMemAnsi(this->dataFileTextBox->Text->ToString()).ToPointer();
			std::cout << "\n\nFile Name: " << dataFile << std::endl;

			DataParser *parser = DataParser::getInstance();
			parser->initDataFile(filename);
			pBar->Value = 3;
			pBarLabel->Text = "Progress: " + pBar->Value.ToString() + "%";

			DataParser *dParser = DataParser::getInstance();
			totalGenes = dParser->getGeneCount();
			totalChromosomes = dParser->getChromosomeCount();

			totFuncNIL = 5;
			geneLoops = (3 * totalGenes);
			chromosomeLoops = totalChromosomes;
			totalUpdates = totFuncNIL + geneLoops + chromosomeLoops;

			progMult = (47.000 / totalUpdates);
			int progAddAmount = 0;
			int extraAdd = 0;
			int roundDown = progMult;
			int addInterval = 0;
			double decimal = (progMult - roundDown);
			int i = 0;
			int intervalCount = 0;
			progAddAmount = progMult;
			while (true)
			{
				if (decimal >= 1)
				{
					addInterval = i;
					break;
				}
				decimal = (decimal * 2);
				i++;
			}

			if (intervalCount == addInterval)
			{
				prog += progAddAmount + 1;
				intervalCount = 0;
			}
			else
			{
				prog += progAddAmount;
				intervalCount++;
			}
			pBar->Value = prog;
			pBarLabel->Text = "Progress: " + pBar->Value.ToString() + "%";

			for (int i = 0; i < totalGenes; i++)
			{
				MasterGeneFactory *mgf = MasterGeneFactory::getInstance();
				mgf->CreateMasterGene(geneticsData);

				if (intervalCount == addInterval)
				{
					prog += progAddAmount + 1;
					intervalCount = 0;
				}
				else
				{
					prog += progAddAmount;
					intervalCount++;
				}
				pBar->Value = prog;
				pBarLabel->Text = "Progress: " + pBar->Value.ToString() + "%";
			}
		
			// Get an instance of the parent data class
			ParentFactory *pf = ParentFactory::getInstance();
			pf->CreateParent(parentData, geneticsData);

			if (intervalCount == addInterval)
			{
				prog += progAddAmount + 1;
				intervalCount = 0;
			}
			else
			{
				prog += progAddAmount;
				intervalCount++;
			}
			pBar->Value = prog;
			pBarLabel->Text = "Progress: " + pBar->Value.ToString() + "%";

			printf("\n\nRunning Simulation...\n");
			printf("\nMaster Genes:\n");
			includeStudyListBox->Items->Add("Master Genes:");
			
			for (int i = 0; i < geneticsData.size(); i++)
			{
				printf("\tTrait Name: %s\n", geneticsData[i].getTrait());
				trait = gcnew String(geneticsData[i].getTrait());
				traits.Add(trait);
				includeStudyListBox->Items->Add("\tTrait Name: " + trait);

				domAllele = geneticsData[i].getDomAllele();
				domSymbol = geneticsData[i].getDomSymbol();
				recAllele = geneticsData[i].getRecAllele();
				recSymbol = geneticsData[i].getRecSymbol();
				std::stringstream convert1, convert2;
				convert1 << domSymbol;
				convert2 << recSymbol;
				dsSymbol = convert1.str();
				rsSymbol = convert2.str();

				std::cout << "\t\tDominant Name: " << domAllele << " (" << domSymbol << ")" << std::endl;
				dAllele = gcnew String(domAllele.c_str());
				domAlleles.Add(dAllele);
				dSymbol = gcnew String(dsSymbol.c_str());
				domSymbols.Add(dSymbol);
				includeStudyListBox->Items->Add("\t\tDominant Name: " + dAllele + " ( " + dSymbol + " )");

				std::cout << "\t\tRecessive Name: " << recAllele << "(" << recSymbol << ")" << std::endl;
				rAllele = gcnew String(recAllele.c_str());
				recAlleles.Add(rAllele);
				rSymbol = gcnew String(rsSymbol.c_str());
				recSymbols.Add(rSymbol);
				includeStudyListBox->Items->Add("\t\tRecessive Name: " + rAllele + " ( " + rSymbol + " )");

				co = "";
				co = geneticsData[i].getCOChance();
				coChance = atof(co.c_str());
				std::cout << "\t\tChance of Crossover: " << coChance << std::endl;
				crossChance = gcnew String(coChance.ToString());
				coChances.Add(crossChance);
				includeStudyListBox->Items->Add("\t\tChance of Crossover: " + crossChance);

				if (intervalCount == addInterval)
				{
					prog += progAddAmount + 1;
					intervalCount = 0;
				}
				else
				{
					prog += progAddAmount;
					intervalCount++;
				}
				pBar->Value = prog;
				pBarLabel->Text = "Progress: " + pBar->Value.ToString() + "%";
			}
	
			for (int j = 0; j < 2; j++)
			{
				printf("\n\nSim Parent %i\n", (j + 1));
				printf("\tOrganism Genus-Species: %s\n", parentData[j].getScientificName());
				//genusSpeciesTextBox = gcnew TextBox();
				gsName = parentData[j].getScientificName();
				gsNameStr = gcnew String(gsName.c_str());
				scientificName.Add(gsNameStr);
				genusSpeciesTextBox->Text = gsNameStr;

				// Get an instance of the parser class
				DataParser *parserData = DataParser::getInstance();
				printf("\tCommon Name: %s\n", parserData->getCommonName());
				std::string cName = parserData->getCommonName();
				System::String^ cNameStr = gcnew String(cName.c_str());
				commonNameTextBox->Text = cNameStr;
				printf("\tChromosomes:\n");
				//numChromosomesTextBox = gcnew TextBox();
				int chromosomeCount = parserData->getChromosomeCount();
				std::stringstream convert;
				convert << chromosomeCount;
				std::string cCount = convert.str();
				System::String^ cCountStr = gcnew String(cCount.c_str());
				numChromosomesTextBox->Text = cCountStr;
				int b = 0;
				for (int m = 0; m < chromosomeCount; m++)
				{
					printf("\t\tChromosome %i\n", (m + 1));
					if (j == 0)
					{
						p1GenotypeListBox->Items->Add("Chromosome " + (m + 1));
					}
					else
					{
						p2GenotypeListBox->Items->Add("Chromosome " + (m + 1));
					}

					char *pStrand1 = parentData[b].getStrand1();
					char *pStrand2 = parentData[b].getStrand2();
					std::string s1F = pStrand1;
					std::string s2F = pStrand2;
					System::String^ strand1F = gcnew String(s1F.c_str());
					strand1.Add(strand1F);
					System::String^ strand2F = gcnew String(s2F.c_str());
					strand2.Add(strand2F);
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
										std::stringstream converts1, converts2;
										converts1 << pStrand1[k];
										converts2 << pStrand2[k];
										std::string strand1 = converts1.str();
										std::string strand2 = converts2.str();
										System::String^ symbol1 = gcnew String(strand1.c_str());
										System::String^ symbol2 = gcnew String(strand2.c_str());

										if (j == 0)
										{
											p1GenotypeListBox->Items->Add("\tGene Type = " + gType);
											p1GenotypeListBox->Items->Add("\t\tAllele 1: " + allele1 + " ( " + symbol1 + " )");
											p1GenotypeListBox->Items->Add("\t\tAllele 2: " + allele2 + " ( " + symbol2 + " )");
										}
										else
										{
											p2GenotypeListBox->Items->Add("\tGene Type = " + gType);
											p2GenotypeListBox->Items->Add("\t\tAllele 1: " + allele1 + " ( " + symbol1 + " )");
											p2GenotypeListBox->Items->Add("\t\tAllele 2: " + allele2 + " ( " + symbol2 + " )");
										}
										done = true;
										std::string progPercent = (char*)Marshal::StringToCoTaskMemAnsi(pBar->Value.ToString()).ToPointer();

										if (intervalCount == addInterval)
										{
											int percentP1 = (atoi(progPercent.c_str()) + progAddAmount + 1);
											if (percentP1 <= 50)
											{
												prog += progAddAmount + 1;
												intervalCount = 0;
											}
											else
											{
												prog = 50;
											}
										}
										else
										{
											int percent = (atoi(progPercent.c_str()) + progAddAmount);
											if (percent <= 50)
											{
												prog += progAddAmount;
												intervalCount++;
											}
											else
											{
												prog = 50;
											}
										}
										pBar->Value = prog;
										pBarLabel->Text = "Progress: " + pBar->Value.ToString() + "%";
									}
								}
							}
						}
					}
					b++;
				}
			}
			pBar->Value = 50;
			pBar->Value = prog;
			pBarLabel->Text = "Progress: " + pBar->Value.ToString() + "%";
		}

		System::Void endSimButton_Click(System::Object^  sender, System::EventArgs^  e)
		{
			Application::Exit();
		}

		System::Void numOffspringTextBox_KeyDown(System::Object^ sender, KeyEventArgs^ e)
		{
			
			//this->numOffspringTextBox->KeyDown += gcnew KeyEventHandler(this, &MendelianSimForm::numOffspringTextBox_KeyDown);
			//this->numOffspringTextBox->KeyPress += gcnew KeyPressEventHandler(this, &MendelianSimForm::numOffspringTextBox_KeyPress);
			
			// Initialize the flag to false.
			nonNumberEntered = false;

			// Determine whether the keystroke is a number from the top of the keyboard.
			if ( e->KeyCode < Keys::D0 || e->KeyCode > Keys::D9 )
			{
				// Determine whether the keystroke is a number from the keypad.
				if ( e->KeyCode < Keys::NumPad0 || e->KeyCode > Keys::NumPad9 )
				{
					// Determine whether the keystroke is a backspace.
					if ( e->KeyCode != Keys::Back )
					{
						// A non-numerical keystroke was pressed.
						// Set the flag to true and evaluate in KeyPress event.
						nonNumberEntered = true;
					}
				}
			}
			else
			{
				runExperimentButton->Enabled = true;
				if ((numOffspringTextBox->TextLength + 1) == 6)
				{
					this->ActiveControl = runExperimentButton;
				}
			}

			// Determine whether the keystroke is a backspace.
			if ((!nonNumberEntered) && (e->KeyCode == Keys::Back))
			{
				//MessageBox::Show("TotChars: " + numOffspringTextBox->TextLength.ToString() + " - |" + e->KeyCode.ToString() + "|");
				if ((numOffspringTextBox->TextLength - 1) > 0)
				{
					runExperimentButton->Enabled = true;
				}
				else
				{
					runExperimentButton->Enabled = false;
				}
			}
			// Determine whether the keystroke is a number from the keypad.
			else if ((!nonNumberEntered) && ( e->KeyCode > Keys::NumPad0 || e->KeyCode < Keys::NumPad9 ))
			{
					runExperimentButton->Enabled = true;
			}
			//If shift key was pressed, it's not a number.
			else if ((!nonNumberEntered) && (Control::ModifierKeys == Keys::Shift))
			{
				nonNumberEntered = true;
			}
			else if (e->KeyCode == Keys::Enter)
			{
				this->ActiveControl = runExperimentButton;
			}
		}

		System::Void numOffspringTextBox_KeyPress(System::Object^ sender, KeyPressEventArgs^ e)
		{
			// Check for the flag being set in the KeyDown event.
			if ( nonNumberEntered == true )
			{   
				// Stop the character from being entered into the control since it is non-numerical.
				e->Handled = true;
			}
		}

		System::Void runExperimentButton_Click(System::Object^  sender, System::EventArgs^  e)
		{
			std::string totalOS = (char*)Marshal::StringToCoTaskMemAnsi(this->numOffspringTextBox->Text->ToString()).ToPointer();
			totalOffspring = atoi(totalOS.c_str());
			numOffspringTextBox->BackColor = System::Drawing::SystemColors::Window;
			numOffspringTextBox->ReadOnly = true;
			this->outputFileTextBox->Enabled = true;
			this->runExperimentButton->Enabled = false;
			this->outputFileTextBox->Text = L"Type File Name Here";
			this->outputFileTextBox->SelectAll();
			this->browseFileButton->Enabled = true;
			// Get a new instance of the parent class
			std::vector<MasterGene> geneticsData;
			std::vector<ParentData> parentData;
			std::vector<char> parentGenotypes;
			std::vector<std::vector<std::string> > parentTypes;
			std::vector<std::vector<std::string> > offspring;
			std::vector<int> genesInChromosome;
			int totalCrossovers = 0;

			DataParser *parser = DataParser::getInstance();
			parser->initDataFile(filename);
			int prog = 51;
			pBar->Value = prog;
			pBarLabel->Text = "Progress: " + pBar->Value.ToString() + "%";

			int totalChromosomes = parser->getChromosomeCount();
			prog = prog + 1;
			pBar->Value = prog;
			pBarLabel->Text = "Progress: " + pBar->Value.ToString() + "%";

			int totalGenes = parser->getGeneCount();
			prog = prog + 1;
			pBar->Value = prog;
			pBarLabel->Text = "Progress: " + pBar->Value.ToString() + "%";

			int totalLoops = 3;
			for (int i = 0; i < strand1.Count; i++)
			{
				char *pStrand1 = (char*)Marshal::StringToCoTaskMemAnsi(strand1[i]).ToPointer();
				std::string strand1Str = pStrand1;
				for (int j = 0; j < strlen(strand1Str.c_str()); j++)
				{
					totalLoops++;
				}
			}

			int totFuncNIL = 1;
			int loops145 = (3 * totalGenes);
			int loops2 = (totalChromosomes * totalLoops);
			int loops3 = (2 * totalGenes);
			int totalUpdates = loops145 + loops2 + loops3;

			double progMult = (47.000 / totalUpdates);
			int progAddAmount = 0;
			int roundDown = progMult;
			int addInterval = 0;
			double decimal = (progMult - roundDown);
			int i = 0;
			int intervalCount = 0;
			progAddAmount = progMult;

			while (true)
			{
				if (decimal >= 1)
				{
					addInterval = i;
					break;
				}
				decimal = (decimal * 2);
				i++;
			}

			if (intervalCount == addInterval)
			{
				prog += progAddAmount + 1;
				intervalCount = 0;
			}
			else
			{
				prog += progAddAmount;
				intervalCount++;
			}
			pBar->Value = prog;
			pBarLabel->Text = "Progress: " + pBar->Value.ToString() + "%";

			for (int i = 0; i < totalGenes; i++)
			{
				MasterGeneFactory *mgf = MasterGeneFactory::getInstance();
				mgf->CreateMasterGene(geneticsData);

				if (intervalCount == addInterval)
				{
					prog += progAddAmount + 1;
					intervalCount = 0;
				}
				else
				{
					prog += progAddAmount;
					intervalCount++;
				}
				pBar->Value = prog;
				pBarLabel->Text = "Progress: " + pBar->Value.ToString() + "%";
			}
			
			CParent *parent = new CParent();
			for (int i = 0; i < totalChromosomes; i++)
			{
				int totalGenesInChromosome = 0;
				char *pStrand1 = (char*)Marshal::StringToCoTaskMemAnsi(strand1[i]).ToPointer();
				char *pStrand2 = (char*)Marshal::StringToCoTaskMemAnsi(strand2[i]).ToPointer();
				std::string strand1Str = pStrand1;
				std::string strand2Str = pStrand2;

				for (int j = 0; j < strlen(strand1Str.c_str()); j++)
				{
					parentGenotypes.push_back(strand1Str[j]);
					parentGenotypes.push_back(strand2Str[j]);
					totalGenesInChromosome++;

					if (intervalCount == addInterval)
					{
						prog += progAddAmount + 1;
						intervalCount = 0;
					}
					else
					{
						prog += progAddAmount;
						intervalCount++;
					}
					pBar->Value = prog;
					pBarLabel->Text = "Progress: " + pBar->Value.ToString() + "%";
				}
				genesInChromosome.push_back(totalGenesInChromosome);
			}

			for (int i = 0; i < 2; i++)
			{
				parentTypes.push_back(std::vector<std::string> ());
				for (int j = 0; j < genesInChromosome.size(); j++)
				{
					for (int k = 0; k < (genesInChromosome[j] * 2); k++)
					{
						char pgs1 = parentGenotypes[k];
						char pgs2 = parentGenotypes[k + 1];
						// Cast each allele to either a dominant or recessive allele to compare the parent data with
						char dominant = static_cast<char>(toupper(static_cast<unsigned char>(parentGenotypes[k])));
						char recessive = static_cast<char>(tolower(static_cast<unsigned char>(parentGenotypes[k])));
						if ((pgs1 == dominant) && (pgs2 == recessive))
						{
							parentTypes[i].push_back("HeterozygousDominant");
						}
						else if ((pgs1 == dominant) && (pgs2 == dominant))
						{
							parentTypes[i].push_back("HomozygousDominant");
						}
						else if ((pgs1 == recessive) && (pgs2 == recessive))
						{
							parentTypes[i].push_back("HomozygousRecessive");
						}

						if (intervalCount == addInterval)
						{
							prog += progAddAmount + 1;
							intervalCount = 0;
						}
						else
						{
							prog += progAddAmount;
							intervalCount++;
						}
						pBar->Value = prog;
						pBarLabel->Text = "Progress: " + pBar->Value.ToString() + "%";
						k++;
					}
				}
			}
			int pNum = 0;
			
			for(int j = 0; j < traits.Count; j++)
			{
				int hetDomCount = 0;
				int homDomCount = 0;
				int homRecCount = 0;

				// Depending on the the two parents, call the function to get the offspring data
				if ((parentTypes[pNum][j] == "HeterozygousDominant") && (parentTypes[pNum + 1][j] == "HeterozygousDominant"))
				{
					offspring = parent->GenerateOffspring(j, totalOffspring, hetDomCount, homDomCount, homRecCount, 0.50, 1);
				}
				else if (((parentTypes[pNum][j] == "HeterozygousDominant") && (parentTypes[pNum + 1][j] == "HomozygousDominant")) || ((parentTypes[pNum][j] == "HomozygousDominant") && (parentTypes[pNum + 1][j] == "HeterozygousDominant")))
				{
					offspring = parent->GenerateOffspring(j, totalOffspring, hetDomCount, homDomCount, homRecCount, 0.50, 2);
				}
				else if (((parentTypes[pNum][j] == "HeterozygousDominant") && (parentTypes[pNum + 1][j] == "HomozygousRecessive")) || ((parentTypes[pNum][j] == "HomozygousRecessive") && (parentTypes[pNum + 1][j] == "HeterozygousDominant")))
				{
					offspring = parent->GenerateOffspring(j, totalOffspring, hetDomCount, homDomCount, homRecCount, 0.50, 3);
				}
				else if (((parentTypes[pNum][j] == "HomozygousDominant") && (parentTypes[pNum + 1][j] == "HomozygousRecessive")) || ((parentTypes[pNum][j] == "HomozygousRecessive") && (parentTypes[pNum + 1][j] == "HomozygousDominant")))
				{
					offspring = parent->GenerateOffspring(j, totalOffspring, hetDomCount, homDomCount, homRecCount, 0.50, 4);
				}
				else if (((parentTypes[pNum][j] == "HomozygousDominant") && (parentTypes[pNum + 1][j] == "HomozygousDominant")) || ((parentTypes[pNum][j] == "HomozygousDominant") && (parentTypes[pNum + 1][j] == "HomozygousDominant")))
				{
					offspring = parent->GenerateOffspring(j, totalOffspring, hetDomCount, homDomCount, homRecCount, 1.00, 5);
				}
				else if (((parentTypes[pNum][j] == "HomozygousRecessive") && (parentTypes[pNum + 1][j] == "HomozygousRecessive")) || ((parentTypes[pNum][j] == "HomozygousRecessive") && (parentTypes[pNum + 1][j] == "HomozygousRecessive")))
				{
					offspring = parent->GenerateOffspring(j, totalOffspring, hetDomCount, homDomCount, homRecCount, 1.00, 6);
				}
				// Only display this bar the first time to separate this data from the data above it
				if (j == 0)
				{
					std::cout << "\n======================================= Results of this Run =========================================" << std::endl;
				}
				std::string gsTrait = (char*)Marshal::StringToCoTaskMemAnsi(traits[j]->ToString()).ToPointer();
				std::string gsDomAllele = (char*)Marshal::StringToCoTaskMemAnsi(domAlleles[j]->ToString()).ToPointer();
				std::string gsDomSymbol = (char*)Marshal::StringToCoTaskMemAnsi(domSymbols[j]->ToString()).ToPointer();
				std::string gsRecAllele = (char*)Marshal::StringToCoTaskMemAnsi(recAlleles[j]->ToString()).ToPointer();
				std::string gsRecSymbol = (char*)Marshal::StringToCoTaskMemAnsi(recSymbols[j]->ToString()).ToPointer();
				std::cout << "Gene: " << gsTrait << std::endl;
				std::cout << "\t" << homDomCount << " Homozygous Dominant (" << gsDomAllele << " " << gsDomSymbol << gsDomSymbol << ")" << std::endl;
				std::cout << "\t" << hetDomCount << " Heterozygous Dominant (" << gsDomAllele << " " << gsDomSymbol << gsRecSymbol << ")" << std::endl;
				std::cout << "\t" << homRecCount << " Homozygous Recessive (" << gsRecAllele << " " << gsRecSymbol << gsRecSymbol << ")" << std::endl;

				System::String^ gTrait = gcnew String(traits[j]);
				System::String^ gDomAllele = gcnew String(domAlleles[j]);
				System::String^ gRecAllele = gcnew String(recAlleles[j]);
				System::String^ gDomSymbol = gcnew String(domSymbols[j]);
				System::String^ gRecSymbol = gcnew String(recSymbols[j]);

				resultsListBox->Items->Add("Gene: " + gTrait);
				resultsListBox->Items->Add("\t" + homDomCount + " Homozygous Dominant ( " + gDomAllele + " " + gDomSymbol + gDomSymbol + " )");
				resultsListBox->Items->Add("\t" + hetDomCount + " Heterozygous Dominant ( " + gDomAllele + " " + gDomSymbol + gRecSymbol + " )");
				resultsListBox->Items->Add("\t" + homRecCount + " Homozygous Recessive ( " + gRecAllele + " " + gRecSymbol + gRecSymbol + " )");
				
				if (intervalCount == addInterval)
				{
					prog += progAddAmount + 1;
					intervalCount = 0;
				}
				else
				{
					prog += progAddAmount;
					intervalCount++;
				}
				pBar->Value = prog;
				pBarLabel->Text = "Progress: " + pBar->Value.ToString() + "%";
			}
			std::vector<std::string> coChancesStr;
			Gene *gene = new Gene();
			for (int i = 0; i < coChances.Count; i++)
			{
				std::string gsCoChance = (char*)Marshal::StringToCoTaskMemAnsi(coChances[i]->ToString()).ToPointer();
				coChancesStr.push_back(gsCoChance);

				std::string progPercent = (char*)Marshal::StringToCoTaskMemAnsi(pBar->Value.ToString()).ToPointer();

				if (intervalCount == addInterval)
				{
					int percentP1 = (atoi(progPercent.c_str()) + progAddAmount + 1);
					if (percentP1 <= 50)
					{
						prog += progAddAmount + 1;
						intervalCount = 0;
					}
					else
					{
						prog = 100;
					}
				}
				else
				{
					int percent = (atoi(progPercent.c_str()) + progAddAmount);
					if (percent <= 50)
					{
						prog += progAddAmount;
						intervalCount++;
					}
					else
					{
						prog = 100;
					}
				}
				pBar->Value = prog;
				pBarLabel->Text = "Progress: " + pBar->Value.ToString() + "%";
			}
			totalCrossovers = gene->GetCrossovers(coChancesStr, totalOffspring);
			printf("\n\nA total of %i offspring had at least one crossover gene.\n\n", totalCrossovers);
			resultsListBox->Items->Add("");
			resultsListBox->Items->Add("");
			resultsListBox->Items->Add("A total of " + totalCrossovers + " offspring had at least one crossover gene.");
			prog = 100;
			pBar->Value = prog;
			pBarLabel->Text = "Progress: " + pBar->Value.ToString() + "%";
		}

		System::Void outputFileTextBox_KeyPress(System::Object^  sender, KeyPressEventArgs^  e)
		{
			char unacceptedChars[27] = {'\'', '+', '=', '>', '<', ';', ':', ',', '?', '!', '@', '#', '$', '%', '^', '&', '*', '`', '"', '~', '/', '\\', '[', ']', '{', '}', '|'};
			charNotAllowed = false;
			// Check for the flag being set in the KeyDown event.
			for (int i = 0; i < sizeof(unacceptedChars); i++)
			{
				if (unacceptedChars[i] == e->KeyChar)
				{
					charNotAllowed = true;
					break;
				}
			}

			if (charNotAllowed == true)
			{   
				// Stop the character from being entered into the control since it is non-numerical.
				e->Handled = true;
			}
		}

		System::Void outputFileTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) 
		{
			std::string file = (char*)Marshal::StringToCoTaskMemAnsi(outputFileTextBox->Text->ToString()).ToPointer();
			std::string extension = "";
			bool isFile = false;
			int extCharNum = 0;
			for (int i = 0; i < file.length(); i++)
			{
				if (file[i] == '.')
				{
					for (int j = i; j < file.length(); j++)
					{
						extension += file[j];
						extCharNum++;
					}
					if (extCharNum > 3)
					{
						isFile = true;
					}
				}
			}

			if ((isFile) && (extension == ".txt"))
			{
				saveResultsButton->Enabled = true;
			}
			else if ((isFile) && (extension != ".txt"))
			{
				MessageBox::Show("File must be a .txt");
				saveResultsButton->Enabled = false;
				std::string newText = "";
				for (int i = 0; i < file.length(); i++)
				{
					if (file[i] == '.')
					{
						break;
					}
					else
					{
						newText += file[i];
					}
				}
				newText += ".txt";
				String^ text = gcnew String(newText.c_str());
				outputFileTextBox->Text = text;
			}
			else
			{
				saveResultsButton->Enabled = false;
			}
		}

		System::Void saveResultsButton_Click(System::Object^  sender, System::EventArgs^  e)
		{
			//outputFileTextBox->Enabled = false;
			outputFileTextBox->BackColor = System::Drawing::SystemColors::Window;
			outputFileTextBox->ReadOnly = true;
			browseFileButton->Enabled = false;
			saveResultsButton->Enabled = false;

			std::string file = (char*)Marshal::StringToCoTaskMemAnsi(openFileDialog->FileName->ToString()).ToPointer();
			int totalSlashes = 0;
			int slashNum = 0;
			for (int i = 0; i < file.length(); i++)
			{
				if (file[i] == '/' || file[i] == '\\')
				{
					totalSlashes++;
				}
			}
			std::string fName = "";
			for (int j = 0; j < file.length(); j++)
			{
				if (file[j] == '/' || file[j] == '\\')
				{
					slashNum++;
				}
				if (slashNum == totalSlashes)
				{
					fName += file[j];
					break;
				}
				else
				{
					fName += file[j];
				}
			}

			if (totalSlashes == 0)
			{
				char buffer[BUFSIZE] = TEXT("");
				GetFullPathName("..\\", BUFSIZE, buffer, NULL);
				std::string outputFolder = "Result Output Files\\";
				fName = buffer + outputFolder;
			}
			std::string fileName = (char*)Marshal::StringToCoTaskMemAnsi(outputFileTextBox->Text->ToString()).ToPointer();
			std::string fullPath = fName + fileName;
			char fullFPath[BUFSIZE];
			strcpy(fullFPath, fullPath.c_str());
			String^ path2 = gcnew String(fullFPath);
			MessageBox::Show("Text File was outputted to: " + path2);
			std::ofstream outFile;

			bool fExists = PathFileExists(fullFilePath);
			outFile.open(fullFPath, std::ios::out | std::ios::trunc);
			outFile << "================================================================" << std::endl;
			outFile << "|     EXPERIMENTAL RESULTS - PROGRAM 3 GENETICS SIMULATION     |" << std::endl;
			outFile << "================================================================" << std::endl << std::endl;
			for (int i = 0; i < resultsListBox->Items->Count; i++)
			{
				std::string line = (char*)Marshal::StringToCoTaskMemAnsi(resultsListBox->Items[i]->ToString()).ToPointer();
				if ((i + 1) == resultsListBox->Items->Count)
				{
					outFile << line;
				}
				else
				{
					outFile << line << std::endl;
				}
			}
			outFile.close();
		}

		System::Void browseFileButton_Click(System::Object^  sender, System::EventArgs^  e)
		{
			openFileDialog->ValidateNames = false;
			openFileDialog->CheckFileExists = false;
			openFileDialog->CheckPathExists = true;
			char buffer[BUFSIZE] = TEXT("");
			GetFullPathName("..\\", BUFSIZE, buffer, NULL);
			String^ path = gcnew String(buffer);
			std::string tbText = (char*)Marshal::StringToCoTaskMemAnsi(outputFileTextBox->Text->ToString()).ToPointer();
			if (tbText == "")
			{
				outputFileTextBox->Text = L"Type File Name Here";
				openFileDialog->FileName = "FileName.txt";
			}
			else if (tbText == "Type File Name Here")
			{
				openFileDialog->FileName = "FileName.txt";
			}
			else
			{
				openFileDialog->FileName = outputFileTextBox->Text;
			}

			
			openFileDialog->InitialDirectory = path + "Result Output Files";
			openFileDialog->Filter = "txt Files (*.txt)|*.txt";
			openFileDialog->FilterIndex = 2;
			openFileDialog->RestoreDirectory = true;
			
			if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				std::string file = (char*)Marshal::StringToCoTaskMemAnsi(openFileDialog->FileName->ToString()).ToPointer();
				std::string fileName = "";
				int totalSlashes = 0;
				int slashNum = 0;
				for (int i = 0; i < file.length(); i++)
				{
					if (file[i] == '/' || file[i] == '\\')
					{
						totalSlashes++;
					}
				}
				std::string fName = "";
				for (int j = 0; j < file.length(); j++)
				{
					if (file[j] == '/' || file[j] == '\\')
					{
						slashNum++;
					}
					if (slashNum == totalSlashes)
					{
						for (int k = j + 1; k < file.length(); k++)
						{
							fName += file[k];
						}

						if (fName == "FileName.txt")
						{
							outputFileTextBox->Text = L"Type File Name Here";
							this->ActiveControl = outputFileTextBox;
							outputFileTextBox->SelectAll();
						}
						else
						{
							String^ fullPath = gcnew String(fName.c_str());
							outputFileTextBox->Text = fullPath;
							std::string file = (char*)Marshal::StringToCoTaskMemAnsi(outputFileTextBox->Text->ToString()).ToPointer();
							std::string extension = "";
							bool isFile = false;
							int extCharNum = 0;
							for (int i = 0; i < file.length(); i++)
							{
								if (file[i] == '.')
								{
									for (int j = i; j < file.length(); j++)
									{
										extension += file[j];
										extCharNum++;
									}
					
									if (extCharNum < 3)
									{
										isFile = true;
									}
								}
							}

							if ((isFile) && (extension != ".txt"))
							{
								MessageBox::Show("File must be a .txt");
							}
							else
							{
								saveResultsButton->Enabled = true;
							}
						}
						break;
					}
				}
			}
		}
};
}
