#include "Cell.h"
#include <iostream>

void Cell::init(const std::string dna_sequence, const Gene glucose_receptor_gene) {
	this->_nucleus.init(dna_sequence);
	this->_ribosome.create_protein(this->_nucleus.get_RNA_transcript);
	this->_mitochondrion.init();
	this->_glocus_receptor_gene.init(glucose_receptor_gene.getStart, glucose_receptor_gene.getEnd, glucose_receptor_gene.is_on_complementary_dna_strand);
	this->_atp_units = 0;
}