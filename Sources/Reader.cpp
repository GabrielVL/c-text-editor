//
// Created by mavros on 3/5/21.
//

#include <vector>
#include <iostream>
#include "../Headers/Reader.h"

Reader::Reader() {
    std::string clientsInfo = "int.numb.3";
}

Reader::~Reader() = default;

//std::vector<std::string::size_type> Reader::find_type(std::string &readInput){
//        std::vector<std::string::size_type> stringPos;
//        for (const std::string& i : dataArray) {
//            std::string::size_type pos = readInput.find(i);
//            while (pos != std::string::npos) {
//                stringPos.push_back(pos);
//                pos = readInput.find(i, pos + 1);
//            }
//        }
//}

std::vector<std::string> Reader::strSplitter(std::string inStr){
    int strLength = inStr.length();
    int firstSepPos = inStr.find(" ");
    int secSepPos = inStr.rfind(" ");
    std::vector<std::string> stringVector;

    std::string s1 = inStr.substr(0, firstSepPos);
    std::string s2 = inStr.substr(firstSepPos+1, (secSepPos - (firstSepPos+1)));
    std::string s3 = inStr.substr(secSepPos+1,strLength-1);

    stringVector.push_back(s1);
    stringVector.push_back(s2);
    stringVector.push_back(s3);
    return stringVector;
}