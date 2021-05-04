//
// Created by mauro on 4/24/21.
//

#include<iostream>
# include "../Header/node.h"

void* operator new(size_t size){
    //std::cout << "ellolove";
    s_AllocationMetrics.TotalAllocated += size;

    return malloc(size);
}


void operator delete(void * memory, size_t size){
    //std::cout << "baibailove";
    s_AllocationMetrics.TotalFreed += size;

    free(memory);
}

node::node() {std::cout << "[Constr.] empty node\n";}

node::node(int number){
    data = number;
    next = NULL;
}

void node::set_data(int info){
    data = info;
}

void node::set_next(node* node){
    next = node;
}

int node::get_data(){return data;}

node node::get_next(){return *next;}

