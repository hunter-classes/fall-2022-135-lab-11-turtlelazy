#include <iostream>
#include "funcs.h"
#include "profile.h"
#include "network.h"
#include <string>
int main(){

    Profile p1("marco", "Marco");
    std::cout << p1.getUsername() << std::endl; // marco
    p1.setDisplayName("different from Marco");
    std::cout << p1.getFullName() << std::endl; // Marco (@marco)
   
    Network nw;
    std::cout << "User, mario, was added:" << nw.addUser("mario", "Mario") << std::endl; // true (1)

    //nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");

    // make them follow each other
    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");

    // add a user who does not follow others
    nw.addUser("wario", "Wario");

    // add clone users who follow @mario
    for (int i = 2; i < 6; i++)
    {
        std::string usrn = "mario" + std::to_string(i);
        std::string dspn = "Mario " + std::to_string(i);
        nw.addUser(usrn, dspn);
        nw.follow(usrn, "mario");
    }
    // additionally, make @mario2 follow @luigi
    nw.follow("mario2", "luigi");

    nw.printDot();
    return 0;
}