#include "array.h"

/*
Set method on bit level - Check for existence
1MegaBytes = 1024 KiloBytes = 1024 * 1024 Bytes = 1024 * 1024 * 8 Bits
1M could represent number upto 8388608, check position is 0 or 1

Internal limits of number of Bytes, 1G = 1024M

The process is like what signature in ABC does
*/

// Internal limits
static unsigned long INTERNAL_SETMEM_MAX = 1024;

typedef struct set_ set;

struct set_ {
    ziArray* s;
    unsigned long sSize;
};

int initSet(set* sData, ziArray* iData);
int clearSet(set* sData);