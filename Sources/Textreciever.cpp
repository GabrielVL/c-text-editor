//
// Created by mauro on 4/28/21.
//

#include "../Headers/Textreciever.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>

class storedData{
public:

    //Constructor
    storedData(){
        std::string clientsInfo = "int.numb.3";
    }

    //Analyzes de String that comes from the client in order to check if meets the requirements.
    void inputAnalyzer(){

    }

    //If the input meet the requirements it splits it to check what has been sent.
    std::string strSplitter(std::string inStr){
        int strLength = inStr.length();
        int firstSepPos = inStr.find("-");
        int secSepPos = inStr.rfind("-");

        std::string s1 = inStr.substr(0,firstSepPos);
        std::string s2 = inStr.substr(firstSepPos+1, (secSepPos - (firstSepPos+1)));
        std::string s3 = inStr.substr(secSepPos+1,strLength-1);

        std::cout << "Pos one: " << firstSepPos << ", Pos two: " << secSepPos << std::endl;
        std::cout << s1 << " " << s2 << " " << s3 << " \n";
    }

private:
};

//Manages the memory to send the info to the client.
class MemoryManager{
public:

private:
};

long get_mem_usage(){
    struct rusage myusage;

    getrusage(RUSAGE_SELF, &myusage);
    return myusage.ru_maxrss;
}

int main(){
    //printf("usage: %ld\n", get_mem_usage());

}
