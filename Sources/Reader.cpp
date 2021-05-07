//
// Created by mavros on 3/5/21.
//

#include <vector>
#include <iostream>
#include "../Headers/Reader.h"
Reader::Reader() {
    stringVector.push_back("");
    stringVector.push_back("");
    stringVector.push_back("");
}

Reader::~Reader() = default;

void Reader::strSplitter(std::string inStr) {
    int strLength = inStr.length();
    int firstSepPos = inStr.find(" ");
    int secSepPos = inStr.rfind(" ");

    std::string s1 = inStr.substr(0, firstSepPos);
    std::string s2 = inStr.substr(firstSepPos+1, (secSepPos - (firstSepPos+1)));
    std::string s3 = inStr.substr(secSepPos+1,strLength-1);

    stringVector[0] = s1;
    stringVector[1] = s2;
    stringVector[2] = s3;
    confirmData();
}

void Reader::confirmData() {
    bool trueDataType = false;
    for (std::string data : dataArray) {
        if (data == stringVector[0]) {
            trueDataType = true;
        }
    }
    if (trueDataType) {
        stringVector[0] = "Tipo: " + stringVector[0];
        stringVector[1] = "Etiqueta: " + stringVector[1];
        stringVector[2] = "Valor: " + stringVector[2];
        while (stringVector.size() > 3) {
            stringVector.pop_back();
        }
    } else {
        stringVector.insert(stringVector.begin(), "Type Error");
        while (stringVector.size() > 4) {
            stringVector.pop_back();
        }
    }
}

const std::vector<std::string> &Reader::getStringVector() const {
    return stringVector;
}
