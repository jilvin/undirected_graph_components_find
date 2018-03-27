// This is start of the header guard.  ADD_H can be any unique name.
// By convention, we use the name of the header file.
#ifndef DISJOINT_SET_H
#define DISJOINT_SET_H

#include "../../interfaces/disjoint_set/disjoint_set_interface.h"

// This is the content of the .h file, which is where the declarations go
class disjoint_set : public disjoint_set_interface
{
public:
    void make_set(int element)
    {}

    void union_sets()
    {}

    int find(int element)
    {
        return 1;
    }
};

// This is the end of the header guard
#endif
