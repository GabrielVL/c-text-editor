//
// Created by mauro on 4/22/21.
//

#include<iostream>
#include "../Header/memoryManager.cpp.h"


memoryManager::memoryManager(){
       TotalAllocated = 0;
       TotalFreed = 0;
}

uint32_t memoryManager::CurrentUsage(){return TotalAllocated-TotalFreed;}

static memoryManager s_AllocationMetrics;

static void PrintMemoryUsage() {
    std::cout << "Mmemory Usage " << s_AllocationMetrics.CurrentUsage() << " bytes\n";
}

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

/*


struct linked_list{
    node *head, *tail;
    int size;

    linked_list(){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void add_value(int value){
        node* tmp = new node(value);

        if(head == NULL){
            head = tmp;
            tail = tmp;
            size += 1;
        }

        else{
            tail->set_next(tmp);
            tail = tmp;
            size += 1;
        }
    }

    int delete_last(){
        node* myPtr;

        *myPtr = *tail;

        return 0;
    }


    void show_list(){
        node* current = new node();

        current = head;

        if(head == NULL){
            std::cout << "No elements on the list" << std::endl;
        }

        else{
            for( int i = 0; i < size; i++){
                std :: string s = std::to_string(current->get_data());
                std::cout << s << std::endl;
                if((size - i) > 1){
                    *current = current->get_next();
                }
            }
        }


    }

    void show_size(){
        std::string s = std::to_string(size);
        std::cout << size;
    }
};*/
