#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "counter.h"
#include "plat_memory.h"

// clang-format off

#define COUNTS_FAIL (int32_t)(-1)

typedef struct counts {
    int32_t counts_number;
} counts_t;

private counts_t* create_counts(void);
private void destroy_counts(counts_t* p_counts);

private void write_counts(counter_obj_t* p_this, int32_t write_value);
private int32_t read_counts(counter_obj_t* p_this);

private void reset_impl(counter_obj_t* p_this);
private void accumulate_impl(counter_obj_t* p_this);
private void depreciate_impl(counter_obj_t* p_this);
private int32_t get_counts_impl(counter_obj_t* p_this);

private counts_t* create_counts(void) {
    size_t alloc_size = sizeof(counts_t);
    counts_t* p_counts = plat_allocate(alloc_size);

    return p_counts;
}

private void destroy_counts(counts_t* p_counts) {
        PLAT_FREE(p_counts);
}

private void write_counts(counter_obj_t* p_this, int32_t write_value) {
    counts_t* p_counts = NULL;
    if (NULL != p_this) {
        if (NULL != p_this->data)
        p_counts = (counts_t*)p_this->data;
        p_counts->counts_number = write_value;
    }
}

private int32_t read_counts(counter_obj_t* p_this) {
    int32_t retval = COUNTS_FAIL;
    counts_t* p_counts = NULL;

    if (NULL != p_this) {
        if (NULL != p_this->data)
            p_counts = (counts_t*)p_this->data;
            retval = p_counts->counts_number;
    }

    return retval;
}

private void reset_impl(counter_obj_t* p_this) {
    write_counts(p_this, 0);
}

private void accumulate_impl(counter_obj_t* p_this) {
    counts_t* p_counts = NULL;
    if (NULL != p_this) {
        if (NULL != p_this->data) {
            p_counts = (counts_t*)p_this->data;
            p_counts->counts_number++;
        }
    }
}

private void depreciate_impl(counter_obj_t* p_this) {
    counts_t* p_counts = NULL;
    if (NULL != p_this) {
        if (NULL != p_this->data) {
            p_counts = (counts_t*)p_this->data;
            p_counts->counts_number--;
        }
    }
}

private int32_t get_counts_impl(counter_obj_t* p_this) {
    int32_t read_value = COUNTS_FAIL;
    read_value = read_counts(p_this);

    return read_value;
}

// NEW_OBJECT(counter_obj) {
struct counter_obj* new_counter_obj(void) {
    size_t alloc_size = sizeof(struct counter_obj);
    struct counter_obj* p_counter = (struct counter_obj*)plat_allocate(alloc_size);

    if (NULL == p_counter) {
        goto EXIT;
    }

    p_counter->data = create_counts();
    if (NULL == p_counter->data) {
        delete_counter_obj(p_counter);
        p_counter = NULL;
        goto EXIT;
    }

    write_counts(p_counter, 0);

    p_counter->reset = reset_impl;
    p_counter->accumulate = accumulate_impl;
    p_counter->depreciate = depreciate_impl;
    p_counter->get_counts = get_counts_impl;

EXIT:
    return p_counter;
}

// DELETE_OBJECT(counter_obj) {
void delete_counter_obj(struct counter_obj* p_obj) {
    if (NULL != p_obj) {
        destroy_counts(p_obj->data);
        PLAT_FREE(p_obj);
    }
}
// clang-format on