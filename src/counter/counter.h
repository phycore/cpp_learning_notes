#ifndef _COUNTER_H
#define _COUNTER_H

#include <stdint.h>

#include "c2cpp_adapter.h"

// clang-format off

// struct counter will be c++ class.
typedef struct counter_obj {
// private:
    private_t data;
// public:
    public void (*reset)(struct counter_obj* p_self);
    public void (*accumulate)(struct counter_obj* p_self);
    public void (*depreciate)(struct counter_obj* p_self);
    public int32_t (*get_counts)(struct counter_obj* p_self);
} counter_obj_t;

// new and delete operator for imitative class.
NEW_OBJECT(counter_obj);
DELETE_OBJECT(counter_obj);

// clang-format on
#endif  //  _COUNTER_H