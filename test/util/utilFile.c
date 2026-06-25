#include "utilFile.h"

#include <assert.h>
#include <stdio.h>

int main() {
    // success: only 0/1 with mixed whitespace (space, tab, newline) skipped
    FILE* f = tmpfile();
    assert(f != NULL);
    fprintf(f, "0 1 1 0\n1\t0");
    rewind(f);
    ziArray tt;
    ziArray* ttPtr = &tt;
    assert(fileToTruth(f, ttPtr) == 0);
    assert(ttPtr->size == 6);
    int expected[6] = {0, 1, 1, 0, 1, 0};
    for (int i = 0; i < 6; i++) {
        assert(*(int*)fetchIndexArray(ttPtr, i) == expected[i]);
    }
    fclose(f);
    assert(clearEachEntryArray(ttPtr) == 0);

    // failure: invalid character 'a' -> read fails, array left empty
    FILE* f2 = tmpfile();
    assert(f2 != NULL);
    fprintf(f2, "010a");
    rewind(f2);
    ziArray tt2;
    ziArray* tt2Ptr = &tt2;
    assert(fileToTruth(f2, tt2Ptr) != 0);
    assert(tt2Ptr->c_ptr == NULL);
    assert(tt2Ptr->size == 0);
    fclose(f2);

    // empty file -> success with size 0
    FILE* f3 = tmpfile();
    assert(f3 != NULL);
    ziArray tt3;
    ziArray* tt3Ptr = &tt3;
    assert(fileToTruth(f3, tt3Ptr) == 0);
    assert(tt3Ptr->size == 0);
    assert(clearEachEntryArray(tt3Ptr) == 0);
    fclose(f3);

    // NULL arguments -> failure, no dereference
    assert(fileToTruth(NULL, tt3Ptr) != 0);

    return 0;
}
