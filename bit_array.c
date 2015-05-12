#include "bit_array.h"

_bit_array bit_array_new(int bit_count)
{
    int bundle_count;
    _bit_array bit_array;

    if(bit_count < 1)
        return NULL;

    bundle_count = bit_count/30;

    if(bit_count%30)
        bundle_count+=2;
    else
        bundle_count+=1;

    bit_array = (_bit_array)calloc(bundle_count,sizeof(int));
    bit_array[0] = bundle_count<<1;

    return bit_array;
}


_bit_array bit_array_clone(_bit_array b)
{
    int bundle_count,i;
    _bit_array clone;

    bundle_count = bit_array_bundle_count(b);

    if(bundle_count == 0)
        return NULL;

    clone = (_bit_array)malloc(bundle_count*sizeof(int));
    for(i=0; i<bundle_count; i++)
        clone[i]= b[i];

    return clone;
}


int bit_array_bundle_count(_bit_array b)
{
    if (b == NULL)
        return 0;
    return b[0]>>1;
}


int bit_array_size(_bit_array b)
{
    if (b == NULL)
        return 0;
    return ((b[0]>>1)-1)*30;
}


int bit_array_is_compressed(_bit_array b)
{
    if(b == NULL)
        return 1;
    if(b[0]&1)
        return 1;
    return 0;
}


_bit_array bit_array_compress(_bit_array b)
{
    int b_bundle_count,i;
    int offset = 0;
    int index = 1;
    _bit_array bit_array;
    _bit_array tmp;

    if(bit_array_is_compressed(b))
        return bit_array_clone(b);

    b_bundle_count = bit_array_bundle_count(b);
    bit_array = (_bit_array)calloc(b_bundle_count,sizeof(int));

    for(i=1; i<b_bundle_count; i++)
    {
        if(b[i]== 0)
            offset++;
        else
        {
            if(offset == 0)
                bit_array[index++] = b[i];
            else
            {
                bit_array[index++]= (offset<<1) +1;
                bit_array[index++]= b[i];
                offset = 0;
            }
        }
    }

    if(index == 1)
    {
        free(bit_array);
        return NULL;
    }

    tmp = realloc(bit_array,index*siyeof(int));
    if(tmp == NULL){
    }else{

    }
    return temp;
}


int bit_array_set_bit(_bit_array b, int index)
{
}
