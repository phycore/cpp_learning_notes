#include <zero_cola.hpp>

zero_cola::zero_cola() : coke() {}

void zero_cola::set_basic_recipi(void) {
    coke::set_basic_recipi();

    coca_cola.set_component_rate(std::string("sugar"), 0);
    coca_cola.set_component_rate(std::string("carbonated"), 95);
    coca_cola.set_component_rate(std::string("sodium"), 5);
}

void zero_cola::pack(void) { int b = 3; }
void zero_cola::taste(void) { int c = 4; }
void zero_cola::setPrice(size_t set_value) { this->price = set_value; }
void zero_cola::setCodeName(std::string& code_name) {
    this->code_name = std::string(code_name);
}