// This is start of the header guard.  ADD_H can be any unique name.
// By convention, we use the name of the header file.
#ifndef DISJOINT_SET_INTERFACE_H
#define DISJOINT_SET_INTERFACE_H

// This is the content of the .h file, which is where the declarations go
class disjoint_set_interface
{
public:
    // function to create a new set containing element passed to it
    // the element should not belong to any other set already
    // if belong to a set already the input is rejected and error returned
    // if success return representative element of the set(element passed in)
    virtual void make_set(int element)=0;

    // function to create union of two sets with their representatives passed in
    // as parameters. the original two sets identified by the representatives
    // will be dropped.
    virtual void union_sets_based_on_representative(int element1, int element2)=0;

    // function to find representative to the set that contains the element
    // passed as parameter
    virtual int find(int element)=0;
};

// This is the end of the header guard
#endif
