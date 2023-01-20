#include "cookie_analyser.cpp"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"


// Testing:
TEST_CASE("Test most frequent cookie is printed.") {
    CHECK(findMostActiveCookies("cookie_log.csv", "2018-12-09") == std::vector<std::string>{"AtY0laUfhglK3lC7"});
}

TEST_CASE("Test no cookie is printed when unexistent date is given") {
    CHECK(findMostActiveCookies("cookie_log.csv", "2050-12-12") == std::vector<std::string>{});
}

TEST_CASE("Test cannot read from unexistent file") {
    CHECK_THROWS_WITH(findMostActiveCookies("notafile.csv", "2018-12-08"), "Could not open file: notafile.csv\n");
}

TEST_CASE("Test all most active cookies are printed") {
    CHECK(findMostActiveCookies("cookie_log.csv", "2018-12-07") == std::vector<std::string>{"SAZuXPGUrfbcn5UA", "4sMM2LxV07bPJzwf"});
}

TEST_CASE("Test date is formatted correctly") {
    CHECK(formatDate("2018-12-09T06:19:00+00:00") == "2018-12-09");
}

TEST_CASE("Test filterByDate filters correctly") {
    // This date is not in the file so the filter should return an empty vector
    CHECK(findMostActiveCookies("cookie_log.csv", "2029-12-12") == std::vector<std::string>{});
}