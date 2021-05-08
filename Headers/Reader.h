//
// Created by mavros on 3/5/21.
//

#ifndef C_TEXT_EDITOR_READER_H
#define C_TEXT_EDITOR_READER_H


#include <string>

class Reader {

private:

    std::string type;
    std::string name;
    std::string value;
    int scope;
    int references;

    std::vector<std::string> TextEditorLine;
    const std::string typeArray[5] = {"char", "int", "long", "float", "double"};

public:
    Reader();

    virtual ~Reader();

    void strSplitter(std::string inStr);

    void confirmType();

    const std::vector<std::string> &getStringVector() const;
};


#endif //C_TEXT_EDITOR_READER_H
