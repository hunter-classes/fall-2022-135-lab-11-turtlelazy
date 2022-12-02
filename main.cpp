#include <iostream>
#include "funcs.h"
#include "profile.h"
#include "network.h"
int main(){

    Profile p1("marco", "Marco");
    std::cout << p1.getUsername() << std::endl; // marco
    p1.setDisplayName("different from Marco");
    std::cout << p1.getFullName() << std::endl; // Marco (@marco)
   
    Network nw;
    std::cout << nw.addUser("mario", "Mario") << std::endl; // true (1)

    return 0;
}