#ifndef BIT_ARRAY_H_INCLUDED
#define BIT_ARRAY_H_INCLUDED

#include <stddef.h>
#include <stdlib.h>

typedef int _bundle;

typedef _bundle * _bit_array;

_bit_array bit_array_new(int bit_count);

_bit_array bit_array_clone(_bit_array b);

int bit_array_bundle_count(_bit_array b);

int bit_array_size(_bit_array b);

int bit_array_is_compressed(_bit_array b);

_bit_array bit_array_compress(_bit_array b);

_bit_array bit_array_decompress(_bit_array b);

int bit_array_set_bit(_bit_array b, int index);






#endif // BIT_ARRAY_H_INCLUDED
