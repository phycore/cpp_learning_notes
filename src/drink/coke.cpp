#include <coke.hpp>
#include <string>

coke::coke() { set_basic_recipi(); }

void coke::set_basic_recipi(void) {
    coca_cola.set_component_rate(std::string("carbonated"), 80);
    coca_cola.set_component_rate(std::string("sugar"), 15);
    coca_cola.set_component_rate(std::string("sodium"), 5);
}

size_t coke::getPrice(void) const { return this->price; }
const std::string& coke::getCodeName(void) const { return this->code_name; }