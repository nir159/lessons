#include "Nucleus.h"
#include <iostream>


// initialize
void Gene::init(const unsigned int start, const unsigned int end, const bool on_complementary_dna_strand) {
	this->_start = start;
	this->_end = end;
	this->_on_complementary_dna_strand = on_complementary_dna_strand;
}

// getters
unsigned int Gene::getStart() const {
	return this->_start;
}

unsigned int Gene::getEnd() const {
	return this->_end;
}

bool Gene::is_on_complementary_dna_strand() const {
	return this->_on_complementary_dna_strand;
}

// setters
void Gene::setStart(const unsigned int start) {
	this->_start = start;
}

void Gene::setEnd(const unsigned int end) {
	this->_end = end;
}

void Gene::setOnComplementaryDnaStrand(const bool onComplementaryDnaStrand) {
	this->_on_complementary_dna_strand = onComplementaryDnaStrand;
}
