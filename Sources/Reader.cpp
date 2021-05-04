//
// Created by mavros on 3/5/21.
//

#include <vector>
#include "../Headers/Reader.h"

Reader::~Reader() = default;


std::vector<std::string::size_type> Reader::find_type(std::string &readInput){
        std::vector<std::string::size_type> stringPos;
        for (const std::string& i : dataArray) {
            std::string::size_type pos = readInput.find(i);
            while (pos != std::string::npos) {
                stringPos.push_back(pos);
                pos = readInput.find(i, pos + 1);
            }
        }

}
