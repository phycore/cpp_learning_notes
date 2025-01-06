#ifndef _COUNTER_HPP
#define _COUNTER_HPP

#include <cstdint>

class counter {
   private:
    int32_t counts_number;
    void write_counts(int32_t write_value);
    int32_t read_counts(void);

   public:
    void reset(void);
    void accumulate(void);
    void depreciate(void);
    int32_t getCounts(void);
};

#endif  // _COUNTER_HPP