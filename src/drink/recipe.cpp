#include <recipe.hpp>

int32_t recipe::get_component_rate(const std::string& component) {
    int32_t retval = 0;
    if (ingredient.count(component) > 0) {
        retval = ingredient[component];
    }

    return retval;
}

void recipe::set_component_rate(const std::string& component, int32_t set_rate) {
    ingredient[component] = set_rate;
}