#pragma once

/*A class that represents a gene*/
class Gene 
{
public:
	// init
	void init(const unsigned int start, const unsigned int end, const bool on_complementary_dna_strand);

	//getters
	unsigned int getStart() const;
	unsigned int getEnd() const;
	bool is_on_complementary_dna_strand() const;

	//setters
	void setStart(const unsigned int start);
	void setEnd(const unsigned int end);
	void setOnComplementaryDnaStrand(const bool onComplementaryDnaStrand);

private:
	unsigned int _start;
	unsigned int _end;
	bool _on_complementary_dna_strand;
};

/*A class that represents a Nucleus*/
class Nucleus
{
public:
	// init
	void init(const std::string dna_sequence);

	// functions
	std::string get_RNA_transcript(const Gene& gene) const;
	std::string get_reversed_DNA_strand() const;
	unsigned int get_num_of_codon_appearances(const std::string& codon) const;

private:
	std::string _DNA_strand;
	std::string _complementary_DNA_strand;
};