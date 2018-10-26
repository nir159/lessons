#include "Nucleus.h"
#include <iostream>
#include <string.h>

// class Gene
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

// class Nucleus
// init
void Nucleus::init(const std::string dna_sequence) {
	int i = 0, reliable = 1;
	// checking if the input string is valid
	if (dna_sequence.empty()) {
		reliable = 0;
	}
	for (i = 0; i < dna_sequence.length(); i++) {
		// can only contain letters AGCT
		if (dna_sequence[i] != 'A' && dna_sequence[i] != 'G' && dna_sequence[i] != 'C' && dna_sequence[i] != 'T') {
			reliable = 0;
		}
	}
	if (reliable) {
		// initialize
		this->_DNA_strand = dna_sequence;
		// changing the string to the required complementary DNA strand
		this->_complementary_DNA_strand = "";
		for (i = 0; i < dna_sequence.length(); i++) {
			switch (dna_sequence[i]) {
			case 'A':
				this->_complementary_DNA_strand.push_back('T');
				break;
			case 'T':
				this->_complementary_DNA_strand.push_back('A');
				break;
			case 'C':
				this->_complementary_DNA_strand.push_back('G');
				break;
			case 'G':
				this->_complementary_DNA_strand.push_back('C');
			// No need for default we already know what the options are
			}
		}
	}
	else { // string is not valid
		std::cerr << "the string can only contain the letters: A, G, C, T" << std::endl;
		_exit(1);
	}
}

// methods
std::string Nucleus::get_RNA_transcript(const Gene& gene) const {
	int i = 0;
	std::string transcript = "";
	// copy the DNA transcript
	if (gene.is_on_complementary_dna_strand()) {
		transcript = this->_complementary_DNA_strand; // takes the complementary strand
		
	}
	else {
		transcript = this->_DNA_strand; // takes the strand
	}
	transcript = transcript.substr(gene.getStart, gene.getEnd - gene.getStart); // get rid of unnececery parts
	for (i = 0; i < transcript.length(); i++) {
		if (transcript[i] == 'T') {
			transcript[i] = 'U';
		}
	}
	return transcript;
}