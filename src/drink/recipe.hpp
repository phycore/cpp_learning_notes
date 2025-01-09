#ifndef _RECIPE_HPP
#define _RECIPE_HPP

#include <cstdint>
#include <map>
#include <string>

class recipe {
   private:
    std::map<std::string, int32_t> ingredient;

   public:
    recipe() = default;
    ~recipe() = default;
    /* getter() */
    int32_t get_component_rate(const std::string& component);
    /* setter() */
    void set_component_rate(const std::string& component, int32_t set_rate);
};

#endif