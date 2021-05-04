//
// Created by mavros on 3/5/21.
//

#ifndef C_TEXT_EDITOR_READER_H
#define C_TEXT_EDITOR_READER_H


#include <string>

class Reader {

private:

    const std::string dataArray[5] = {"int", "long", "char", "float", "double"};

public:
    virtual ~Reader();

    std::vector<std::string::size_type> find_type(std::string &readInput);
};


#endif //C_TEXT_EDITOR_READER_H
