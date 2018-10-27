#pragma once
#include "Protein.h"

#define NUC_NEEDED 3

/*A class that repreasents the ribosome*/
class Ribosome 
{
public:
	// functions
	Protein* create_protein(std::string &RNA_transcript) const;
};