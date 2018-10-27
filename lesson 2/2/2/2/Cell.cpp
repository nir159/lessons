#include "Cell.h"
#include <iostream>

// init
void Cell::init(const std::string dna_sequence, const Gene glucose_receptor_gene) {
	this->_nucleus.init(dna_sequence);
	this->_mitochondrion.init();
	this->_glocus_receptor_gene.init(glucose_receptor_gene.getStart(), glucose_receptor_gene.getEnd(), glucose_receptor_gene.is_on_complementary_dna_strand());
	this->_atp_units = 0;
}

/*

*/
bool Cell::get_ATP() {
	std::string transcript = "";
	Protein* protein = NULL;
	bool flag = true;
	protein = this->_ribosome.create_protein(this->_nucleus.get_RNA_transcript(this->_glocus_receptor_gene));
	if (protein->get_first() == NULL) {
		std::cerr << "Couldn't make the protein needed";
		_exit(1);
	}
	this->_mitochondrion.insert_glucose_receptor(*protein);
	this->_mitochondrion.set_glucose(50);
	if (this->_mitochondrion.produceATP(0) == false) {
		flag = false;
	}
	else {
		this->_mitochondrion.set_glucose(100);
	}
	delete(protein->get_first());
	delete(protein);
	return flag;
}