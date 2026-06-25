#include "utilFile.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

// Read a file that contains only '0' and '1'. Whitespace (space, tab, newline,
// ...) is skipped. Each digit is appended to tt as a heap-allocated int, so the
// caller owns tt and must release it with clearEachEntryArray.
// Returns 0 on success. On any other byte (or NULL argument) the array is left
// empty and a non-zero value is returned.
int fileToTruth(FILE* file, ziArray* tt) {
    if (file == NULL || tt == NULL) {
        return 1;
    }
    if (initArray(tt, 8) != 0) {
        return 1;
    }
    int c;
    while ((c = fgetc(file)) != EOF) {
        if (isspace((unsigned char)c)) {
            continue;
        }
        if (c != '0' && c != '1') {
            clearEachEntryArray(tt);
            return 1;
        }
        int* val = (int*)malloc(sizeof(int));
        if (val == NULL) {
            clearEachEntryArray(tt);
            return 1;
        }
        *val = c - '0';
        if (pushArray(tt, val) != 0) {
            free(val);
            clearEachEntryArray(tt);
            return 1;
        }
    }
    return 0;
}
