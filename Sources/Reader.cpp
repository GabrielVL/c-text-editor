//
// Created by mavros on 3/5/21.
//

#include <vector>
#include <iostream>
#include "../Headers/Reader.h"

Reader::~Reader() = default;



void Reader::strSplitter(std::string inStr) {
    int strLength = inStr.length();
    int firstSepPos = inStr.find(" ");
    int secSepPos = inStr.rfind(" ");

    std::string s1 = inStr.substr(0, firstSepPos);
    std::string s2 = inStr.substr(firstSepPos+1, (secSepPos - (firstSepPos+1)));
    std::string s3 = inStr.substr(secSepPos+1,strLength-1);

    stringVector.push_back(s1);
    stringVector.push_back(s2);
    stringVector.push_back(s3);
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
    } else {
        stringVector.insert(stringVector.begin(), "Error");
    }
}

const std::vector<std::string> &Reader::getStringVector() const {
    return stringVector;
}
