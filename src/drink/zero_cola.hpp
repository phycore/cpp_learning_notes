#ifndef _ZERO_COLA_HPP
#define _ZERO_COLA_HPP

#include <coke.hpp>

class zero_cola : public coke {
   protected:
    void set_basic_recipi(void) override;

   public:
    zero_cola();
    ~zero_cola() = default;

    void pack(void) override;
    void taste(void) override;
    void setPrice(size_t set_value) override;
    void setCodeName(std::string& code_name) override;
};

#endif