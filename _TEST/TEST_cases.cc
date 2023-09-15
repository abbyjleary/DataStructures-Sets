/*
 * Unit testing for the Book class for final CS 2400 project
 */
//#define CATCH_CONFIG_RUNNER
#define CATCH_CONFIG_MAIN  // Catch supplies a main program
#include "catch.hpp"
#include "../myset.h"

const int MAXSCORE = 32;
static int score = 0;

TEST_CASE("Testing  Set Class") {
    SECTION("Default Constructors") {
        MySet s;
        REQUIRE(0 == s.size());
        REQUIRE("{}" == s.toString());
        score += 1;
    }
    SECTION("Adding a single element at a time & toString") {
        MySet s;
        s = s + 10; //add an element to s
        REQUIRE(1 == s.size());
        REQUIRE("{10}" == s.toString());

	    s = s + 20;
	    s = s + 10;
        REQUIRE(2 == s.size());
        REQUIRE("{10, 20}" == s.toString());
        s = s + 30;
        s = s + 30;
        s = s + 5;
        REQUIRE("{5, 10, 20, 30}" == s.toString());
        score += 6;
    }

    SECTION("removing a single element at a time & toString") {
        MySet s;
        s = s + 10; //add an element to s
        s = s - 10;
        REQUIRE("{}" == s.toString());

	    s = s + 20;
	    s = s + 10;

        REQUIRE("{10, 20}" == s.toString());
        s = s + 30;
        s = s + 30;
        s = s + 5;
        REQUIRE("{5, 10, 20, 30}" == s.toString());
        s = s - 5; //remove the first element
        s = s - 30; // remove the last element
        REQUIRE("{10, 20}" == s.toString());
        score += 3;
    }
    SECTION("Set Membership") {
        MySet s;
        REQUIRE((10 ^ s) == false);
        s = s + 10;
        REQUIRE((10 ^ s) == true);
        s = s + 20;
        s = s + 30;
        REQUIRE((30 ^ s) == true);
        REQUIRE((40 ^ s) == false);
        
        score += 3;
    }

    SECTION("Set Union") {
        MySet s;
        s = s + 20;
        s = s + 10;
        s = s + 30;
        s = s + 40;

        MySet s2;
        s2 = s2 + 10;
        s2 = s2 + 50;
        s2 = s2 + 30;
        s2 = s2 + 60;

        MySet s3;
        s3 = s + s2;
        REQUIRE("{10, 20, 30, 40, 50, 60}" == s3.toString());

        score += 3;
    }
SECTION("Set Intersection") {
        MySet s;
        s = s + 20;
        s = s + 10;
        s = s + 30;
        s = s + 40;

        MySet s2;
        s2 = s2 + 10;
        s2 = s2 + 50;
        s2 = s2 + 30;
        s2 = s2 + 60;

        MySet s3;
        s3 = s * s2;
        REQUIRE("{10, 30}" == s3.toString());

        score += 3;
    }

SECTION("Set Difference") {
        MySet s;
        s = s + 20;
        s = s + 10;
        s = s + 30;
        s = s + 40;

        MySet s2;
        s2 = s2 + 10;
        s2 = s2 + 50;
        s2 = s2 + 30;
        s2 = s2 + 60;

        MySet s3;
        s3 = s - s2;
        REQUIRE("{20, 40}" == s3.toString());
        s3 = s2 - s;
        REQUIRE("{50, 60}" == s3.toString());

        MySet s4;
        s4 = s4 - s;
        REQUIRE("{}" == s4.toString());
        s4 = s - s4;
        REQUIRE("{10, 20, 30, 40}" == s4.toString());
        score += 3;
    }

    SECTION("Set Subset") {
        MySet s;
        s = s + 20;
        s = s + 10;
        s = s + 30;
        s = s + 40;

        MySet s2;
        s2 = s2 + 10;
        s2 = s2 + 40;
        s2 = s2 + 30;
        s2 = s2 + 20;
        s2 = s2 + 50;

        REQUIRE(true == (s <= s2));
        REQUIRE(false == (s2 <= s));

        MySet s3;
        REQUIRE(true == (s3 <= s));
        REQUIRE(false == (s <= s3));
        score += 3;
    }

        SECTION("Set Superset") {
        MySet s;
        s = s + 20;
        s = s + 10;
        s = s + 30;
        s = s + 40;

        MySet s2;
        s2 = s2 + 10;
        s2 = s2 + 40;
        s2 = s2 + 30;
        s2 = s2 + 20;
        s2 = s2 + 50;

        REQUIRE(true == (s2 >= s));
        REQUIRE(false == (s >= s2));

        MySet s3;
        REQUIRE(true == (s >= s3));
        REQUIRE(false == (s3 >= s));
        score += 3;
    }

    SECTION("Set Equal") {
        MySet s;
        s = s + 20;
        s = s + 10;
        s = s + 30;
        s = s + 40;

        MySet s2;
        s2 = s2 + 10;
        s2 = s2 + 40;
        s2 = s2 + 30;
        s2 = s2 + 20;
        s2 = s2 + 50;

        REQUIRE(false == (s2 == s));
        MySet s3;
        s3 = s3 + 10;
        s3 = s3 + 40;
        s3 = s3 + 30;
        s3 = s3 + 20;
     
        REQUIRE(true == (s >= s3));

        MySet s4;
        REQUIRE(false == (s == s4));
        REQUIRE(false == (s4 == s));

        MySet s5, s6;
        REQUIRE(true == (s5 == s6));
        s5 = s5 + 10;
        s6 = s6 + 10;
        REQUIRE(true == (s5 == s6));
        score += 3;
    }

    SECTION("Set Clear") {
        MySet s;
        s = s + 20;
        s = s + 10;
        s = s + 30;
        s = s + 40;
        REQUIRE(4 == s.size());
        s.clear();
        REQUIRE(0 == s.size());
        REQUIRE("{}" == s.toString());
        score += 1;
    }
   
    SECTION("Score"){
        cout << "\033[1;35m" << "\n==========================================" << endl;
        cout << "\033[1;33m" <<  " Score: " << score << "/" << MAXSCORE << "\033[1;35m" << endl;
        // << " (passed " << testsPassed <<  " out of " << NUMTESTS << " tests)" << "\033[0m" << endl;
        cout << "==========================================\n" << "\033[0m" << endl;
    }
}

