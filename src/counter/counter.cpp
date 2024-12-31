#include <counter.hpp>

void counter::write_counts(int32_t write_value) { this->counts_number = write_value; }

int32_t counter::read_counts(void) { return this->counts_number; }

void counter::reset(void) { write_counts(0); }

void counter::accumulate(void) { this->counts_number++; }

void counter::depreciate(void) { this->counts_number--; }

int32_t counter::getCounts(void) { return read_counts(); }