#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"
#include "profile.h"

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