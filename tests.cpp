#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"
#include "profile.h"
#include "network.h"
#include <string>
TEST_CASE("TASK A")
{

    Profile p1("marco", "Marco");
    p1.setDisplayName("different from Marco");
    CHECK (p1.getUsername() == "marco");
    CHECK(p1.getFullName() == "different from Marco (@marco)");
    Profile p0;
    CHECK(p0.getUsername() == "");
    CHECK(p0.getFullName() == " (@)");
}

TEST_CASE("TASK B"){
    Network nw;
    CHECK(nw.addUser("mario", "Mario")); // true (1)
    CHECK(nw.addUser("luigi", "Luigi")); // true (1)

    CHECK(!nw.addUser("mario", "Mario2"));   // false (0)
    CHECK(!nw.addUser("mario 2", "Mario2")); // false (0)
    CHECK(!nw.addUser("mario-2", "Mario2")); // false (0)

    for (int i = 2; i < 20; i++){
        nw.addUser("mario" + std::to_string(i),
                   "Mario" + std::to_string(i));
    }

    CHECK(!nw.addUser("yoshi", "Yoshi")); // false (0)
}

TEST_CASE("TASK C"){
    Network nw;
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");
    CHECK(nw.follow("mario", "luigi"));

    CHECK(nw.follow("mario", "yoshi"));
    CHECK(nw.follow("luigi", "mario"));
    CHECK(nw.follow("luigi", "yoshi"));
    CHECK(nw.follow("yoshi", "mario"));
    CHECK(nw.follow("yoshi", "luigi"));
    CHECK(!nw.follow("WARIO", "yoshi"));
    CHECK(!nw.follow("yoshi", "WARIO"));
    CHECK(!nw.follow("WARIO", "ZARIO"));
}