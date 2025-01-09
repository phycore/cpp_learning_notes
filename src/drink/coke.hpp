#ifndef _COKE_HPP
#define _COKE_HPP

#include <cstdint>
#include <recipe.hpp>
#include <string>

class coke {
   protected:
    std::string code_name;
    size_t price = 0;
    recipe coca_cola;
    virtual void set_basic_recipi(void);

   public:
    coke();
    virtual ~coke() = default;
    virtual void pack(void) = 0;
    virtual void taste(void) = 0;
    virtual void setPrice(size_t set_value) = 0;
    size_t getPrice(void) const;
    virtual void setCodeName(std::string& code_name) = 0;
    const std::string& getCodeName(void) const;
};

#endif  // _COKE_HPP