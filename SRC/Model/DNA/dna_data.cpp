#include "dna_data.h"

size_t DNAData::idCounter = 1;

std::vector<bool> DNAData::idsTaken(1000000, false);
