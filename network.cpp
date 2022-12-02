#include "network.h"
#include <cctype>
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
