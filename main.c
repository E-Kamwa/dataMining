#include <stdio.h>
#include <stdlib.h>

#include "bit_array.h"
int main()
{
    _bit_array b = bit_array_new(45);
    _bit_array c = NULL;
    _bit_array clone = bit_array_clone(b);
    printf("\n bundle_count = %d, and size = %d and is compact %d",bit_array_bundle_count(b),bit_array_size(b),bit_array_is_compressed(b));
    printf("\n bitarray clone de b bundle_count = %d, and size = %d and is compact %d ",bit_array_bundle_count(clone),bit_array_size(clone),bit_array_is_compressed(clone));
    return 0;
}
