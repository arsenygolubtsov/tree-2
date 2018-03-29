#include <catch.hpp>
#include <sstream>

#include "tree.hpp"

TEST_CASE("creating tree")
{
    tree_t tree;
    REQUIRE(tree.root() == nullptr);
}

TEST_CASE("insert and print")
{
    tree_t tree;
    tree.insert(2);
    tree.insert(4);
    tree.insert(0);
    tree.insert(1);

    std::string output
    {
        "----4/n"
        "--2/n"
        "------1/n"
        "----0/n"
    }
    std::ostringstream ostream;
    tree.print(ostream, tree.root());
    REQUIRE(ostream.str() == output);
}

TEST_CASE("find")
{
    tree_t tree;
    tree.insert(2);
    tree.insert(4);
    tree.insert(0);
    tree.insert(1);
    tree.insert(9);
    tree.insert(8);
    tree.insert(6);
    tree.insert(7);

    REQUIRE(tree.find(6) == true);
    REQUIRE(tree.find(7) == true);
    REQUIRE(tree.find(5) == false);
    REQUIRE(tree.find(0) == true);
    REQUIRE(tree.find(3) == false);
}
