#include "Ribosome.h"
#include "AminoAcid.h"
#include <iostream>

/*
The function will return the amino acid chain
input:
an RNA transcript
output:
the protein that fits the RNA transcript
*/
Protein* Ribosome::create_protein(std::string &RNA_transcript) const {
	int flag = 1;
	AminoAcidNode* head = new AminoAcidNode();
	Protein* protein = new Protein();
	std::string rnaTranscript = RNA_transcript;
	protein->init();
	if (rnaTranscript.length() >= NUC_NEEDED) {
		if (get_amino_acid(rnaTranscript.substr(0, NUC_NEEDED)) != UNKNOWN) {
			// takes the first amino acid
			head->set_data(get_amino_acid(rnaTranscript.substr(0, NUC_NEEDED)));
			protein->set_first(head);
			rnaTranscript = rnaTranscript.substr(NUC_NEEDED , rnaTranscript.length() - NUC_NEEDED); // offset of 1 cause string starts from index 0
		}
		else {
			flag = 0; // amino acid is UNKNOWN
		}
		
	}
	while (rnaTranscript.length() >= NUC_NEEDED && flag != 0) {
		// goes over the rest of the RNA transcript
		if (get_amino_acid(rnaTranscript.substr(0, NUC_NEEDED)) != UNKNOWN) {
			protein->add(get_amino_acid(rnaTranscript.substr(0, NUC_NEEDED)));
			rnaTranscript = rnaTranscript.substr(NUC_NEEDED, rnaTranscript.length() - NUC_NEEDED);
		}
		else {
			flag = 0;
		}
	}
	if (flag == 0) {
		delete(protein);
		protein = nullptr;
	}
	return protein;
}