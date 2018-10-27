#pragma once
#include "AminoAcid.h"
#include "Protein.h"

/*A class that represents the mitochondrion*/
class Mitochondrion 
{
public:
	// init
	void init();

	// setters
	void insert_glucose_receptor(const Protein & protein);
	void set_glucose(const unsigned int glocuse_units);


private:
	unsigned int _glocuse_level;
	bool _has_glocuse_receptor;
};