#pragma once
#include "AminoAcid.h"
#include "Protein.h"

/*A class that represents the mitochondrion*/
class Mitochondrion 
{
public:
	// init
	void init();

	// functions
	void insert_glucose_receptor(const Protein & protein);
private:
	unsigned int _glocuse_level;
	bool _has_glocuse_receptor;
};