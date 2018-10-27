#include "Mitochondrion.h"
#include "AminoAcid.h"

/*
Function  the initialize the mitochondrion
*/
void Mitochondrion::init() {
	this->_glocuse_level = 0;
	this->_has_glocuse_receptor = false;
}

/*
the function check if the protein is in the right order and sets has glocuse receptor
input:
protein to check
*/
void Mitochondrion::insert_glucose_receptor(const Protein & protein) {
	int aminoAcidList[] = {ALANINE, LEUCINE, GLYCINE, HISTIDINE, LEUCINE, PHENYLALANINE, AMINO_CHAIN_END};
	int flag = 0, i = 0;
	AminoAcidNode* curr = protein.get_first();
	while (flag == 0) {
		if (!(curr->get_data == aminoAcidList[i])) {
			flag = 1;
		}
		if (curr->get_next == NULL || curr->get_data == AMINO_CHAIN_END) {
			flag = 1;
		}
		else {
			curr = curr->get_next;
			i++;
		}
	}
	if (curr->get_data == AMINO_CHAIN_END) {
		this->_has_glocuse_receptor = true;
	}
}

/*
function sets glucose
input:
the amount of glucose to set
*/
void Mitochondrion::set_glucose(const unsigned int glocuse_units) {
	this->_glocuse_level = glocuse_units;
}