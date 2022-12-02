#include "network.h"
#include <cctype>
#include <iostream>

int Network::findID(std::string usrn){
    for(int i = 0; i < numUsers; i++){
        if(profiles[i].getUsername() == usrn){
            return i;
        }
    }
    return -1;

}

Network::Network(){
    numUsers = 0;
    for(int r = 0; r < MAX_USERS; r++){
        for(int c = 0; c < MAX_USERS; c++){
            following[r][c] = false;
        }
    }
}

bool isAlphaNumeric(std::string string){
    for(int i = 0; i < string.length();i++){
        if(!std::isalpha(string[i]) && !std::isdigit(string[i])){
            return false;
        }
    }
    return true;
}

bool Network::addUser(std::string usrn, std::string dspn){
    if(usrn.length() > 0 && isAlphaNumeric(usrn) && 
    findID(usrn) == -1 && numUsers < MAX_USERS)
    {   
        Profile new_profile(usrn,dspn);
        profiles[numUsers] = new_profile;
        numUsers += 1;
        return true;
    }
    //std::cout << "Isalpha " << isAlphaNumeric(usrn) << "\n";
    return false;
}

bool Network::follow(std::string usrn1, std::string usrn2){
    int id1 = findID(usrn1);
    int id2 = findID(usrn2);

    if(id1 != -1 && id2 != -1){
        following[id1][id2] = true;
        return true;
    }

    return false;
}

std::string usernameFormatted(std::string usn){
    return "\"@" + usn + "\"";
}

std::string followVisual(std::string usn1, std::string usn2){
    return usernameFormatted(usn1) + " -> " + usernameFormatted(usn2);
}

void Network::printDot(){
    std::cout << "digraph {" << "\n";
    for(int user = 0; user < numUsers; user++){
        std::cout << "  " << usernameFormatted(profiles[user].getUsername()) << "\n";
    }
    std::cout << "\n";

    for (int r = 0; r < numUsers; r++)
    {
        for (int c = 0; c < numUsers; c++)
        {
            if(following[r][c]){
                std::cout << "  " << followVisual(profiles[r].getUsername(), profiles[c].getUsername()) << "\n";
            }
        }
    }
    std::cout << "}\n";
}