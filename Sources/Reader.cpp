//
// Created by mavros on 3/5/21.
//

#include <vector>
#include <iostream>
#include <sstream>
#include "../Headers/Reader.h"
Reader::Reader() {
    TextEditorLine.push_back("");
    TextEditorLine.push_back("");
    TextEditorLine.push_back("");
}

Reader::~Reader() = default;

void Reader::strSplitter(std::string inStr) {
    int strLength = inStr.length();
    int firstSepPos = inStr.find(" ");
    int secSepPos = inStr.rfind(" ");

    std::string s1 = inStr.substr(0, firstSepPos);
    std::string s2 = inStr.substr(firstSepPos+1, (secSepPos - (firstSepPos+1)));
    std::string s3 = inStr.substr(secSepPos+1,strLength-1);

    TextEditorLine[0] = s1;
    TextEditorLine[1] = s2;
    TextEditorLine[2] = s3;
    confirmType();
}

void Reader::confirmType() {
    bool isType = false;
    bool isOneDot = false;
    bool isNum = true;
    for (std::string data : typeArray) {
        if (data == TextEditorLine[0]) {
            if (data == "char") {
                if (TextEditorLine[2].length() == 1) {
                    isType = true;
                    break;
                }
            } else { // int, long, float & double
                for (char const &digit : TextEditorLine[2]) {
                    if (!std::isdigit(digit)) {
                        isNum = false;
                    }
                    if (digit == ',' && (data == "float" || data == "double")) {
                        isNum = true;
                        if (!isOneDot) {
                            isOneDot = true;
                        } else {
                            isNum = false;
                            break;
                        }
                    }
                }
                isType = deleteZeroes(isNum, data);
                break;
            }
        }
    }
    labelObject(isType);
}

bool Reader::deleteZeroes(bool isNum, const std::string &data) {
    if (isNum) {
        if (data == "float" || data == "double") {
            double deleteZeroesDouble = atof(TextEditorLine[2].c_str());
            TextEditorLine[2] = std::to_string(deleteZeroesDouble);
        } else {
            long deleteZeroesLong = std::stol(TextEditorLine[2]);
            TextEditorLine[2] = std::to_string(deleteZeroesLong);
        }
        return true;
    } else {
        return false;
    }
}

void Reader::labelObject(bool isType) {
    if (isType) {
        TextEditorLine[0] = "Tipo: " + TextEditorLine[0];
        TextEditorLine[1] = "Etiqueta: " + TextEditorLine[1];
        TextEditorLine[2] = "Valor: " + TextEditorLine[2];
        while (TextEditorLine.size() > 3) {
            TextEditorLine.pop_back();
        }
    } else {
        TextEditorLine.insert(TextEditorLine.begin(), "Type Error");
        while (TextEditorLine.size() > 4) {
            TextEditorLine.pop_back();
        }
    }
}

const std::vector<std::string> &Reader::getStringVector() const {
    return TextEditorLine;
}
