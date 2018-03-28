// This is start of the header guard.  ADD_H can be any unique name.
// By convention, we use the name of the header file.
#ifndef DISJOINT_SET_H
#define DISJOINT_SET_H

#include <vector>

#include "../../interfaces/disjoint_set/disjoint_set_interface.h"

// This is the content of the .h file, which is where the declarations go
class disjoint_set : public disjoint_set_interface
{
private:
    std::vector<int> vector;
    int componentsCount;

    int trace(int element)
    {
        if(this->vector.at(element) ==  element)
        {
            // representative found
            return element;
        }
        else
        {
            // not initialized yet
            return trace(this->vector.at(element));
        }
    }

public:
    disjoint_set(int n)
    {
        // initialize all values of the vector to be -1
        this->vector.assign(n, -1);

        this->componentsCount = n;
    }

    void make_set(int element)
    {
        this->vector.at(element) = element;
    }

    void union_sets_based_on_representative(int element1, int element2)
    {
        // check for whether elements recieved are representatives is not
        // implemented. implement later.

        if(this->find(element1) == this->find(element2))
        {
            // belong to the same set
        }
        else
        {
            this->vector.at(this->find(element2)) = this->find(element1);
            this->componentsCount--;
        }
    }

    int find(int element)
    {
        // find index within vector
        // if set trace back to representative and return representative
        // else return -1
        if(this->vector.at(element) == -1)
        {
            // not initalized yet
            return -1;
        }
        else
        {
            return this->trace(element);
        }
    }

    int returnComponentsCount()
    {
        return componentsCount;
    }
};

// This is the end of the header guard
#endif
