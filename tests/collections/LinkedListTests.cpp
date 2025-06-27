#include "catch_amalgamated.hpp"
#include "Dast/collections/LinkedList.hpp"

using namespace Dast;

TEST_CASE("LinkedList", "[linkedlist]") {

    SECTION("push_back") {
        LinkedList<int> list;

        list.push_back(1);

        REQUIRE(list.size() == 1);
        REQUIRE(list.get_head() == 1);
        REQUIRE(list.get_tail() == 1);
        REQUIRE(list.at(0) == 1);
        REQUIRE(list.contains(1));

        list.push_back(2);

        REQUIRE(list.size() == 2);
        REQUIRE(list.get_head() == 1);
        REQUIRE(list.get_tail() == 2);
        REQUIRE(list.at(0) == 1);
        REQUIRE(list.at(1) == 2);
    }

    SECTION("push_front") {
        LinkedList<int> list;

        list.push_front(1);

        REQUIRE(list.size() == 1);
        REQUIRE(list.get_head() == 1);
        REQUIRE(list.get_tail() == 1);
        REQUIRE(list.at(0) == 1);
        REQUIRE(list.contains(1));

        list.push_front(5);

        REQUIRE(list.size() == 2);
        REQUIRE(list.get_head() == 5);
        REQUIRE(list.get_tail() == 1);
        REQUIRE(list.at(0) == 5);
        REQUIRE(list.at(1) == 1);
    }

    SECTION("init") {
        LinkedList list = {1, 2, 3, 4, 5};

        REQUIRE(list.size() == 5);
        REQUIRE(list.get_head() == 1);
        REQUIRE(list.get_tail() == 5);
        REQUIRE(list.at(0) == 1);
        REQUIRE(list.at(1) == 2);
        REQUIRE(list.at(2) == 3);
        REQUIRE(list.at(3) == 4);
        REQUIRE(list.at(4) == 5);
    }

    SECTION("iter") {
        LinkedList list = {1, 2, 3, 4, 5};

        int counter = 1;
        for (int item: list) {
            REQUIRE(item == counter);
            counter++;
        }
    }

    SECTION("remove") {
        LinkedList list = {'a', 'b', 'c', 'd', 'e'};

        list.remove(2);

        REQUIRE(list.size() == 4);
        REQUIRE(list[0] == 'a');
        REQUIRE(list[1] == 'b');
        REQUIRE(list[2] == 'd');
        REQUIRE(list[3] == 'e');

        list.remove(0);

        REQUIRE(list.size() == 3);
        REQUIRE(list[0] == 'b');
        REQUIRE(list[1] == 'd');
        REQUIRE(list[2] == 'e');

        list.remove(2);
        REQUIRE(list.size() == 2);
        REQUIRE(list[0] == 'b');
        REQUIRE(list[1] == 'd');

        REQUIRE_THROWS_AS(list.remove(2), std::out_of_range);
    }

    SECTION("clear") {
        LinkedList list = {4, 5 , 6};

        REQUIRE(list.size() == 3);
        REQUIRE(list.empty() == false);

        list.clear();

        REQUIRE(list.size() == 0);
        REQUIRE(list.empty() == true);
    }
}