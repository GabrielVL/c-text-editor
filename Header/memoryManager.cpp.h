//
// Created by mauro on 4/24/21.
//

#ifndef C_TEXT_EDITOR_MEMORYMANAGER_CPP_H
#define C_TEXT_EDITOR_MEMORYMANAGER_CPP_H

class memoryManager
{
public:
    uint32_t TotalAllocated;
    uint32_t TotalFreed;

    memoryManager();
    uint32_t CurrentUsage();


};

#endif //C_TEXT_EDITOR_MEMORYMANAGER_CPP_H
