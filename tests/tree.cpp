#include <catch.hpp>
#include <sstream>

#include "tree.hpp"

TEST_CASE("creating tree")
{
    tree_t <int> tree;
    REQUIRE(tree.root() == nullptr);
}

TEST_CASE("insert and print tree int")
{
    tree_t <int> tree;

    std::string input1{ "+3\n" };
    std::string input2{ "+4\n" };
    std::string input3{ "+2\n" };
    std::string input4{ "+1\n" };
    std::string input5{ "+5\n" };
    std::string result{ "------5\n"
                        "----4\n"
                        "--3\n"
                        "----2\n"
                        "------1\n" };

    std::istringstream inp1{ input1 };
    std::istringstream inp2{ input2 };
    std::istringstream inp3{ input3 };
    std::istringstream inp4{ input4 };
    std::istringstream inp5{ input5 };

    REQUIRE(read(tree, inp1));
    REQUIRE(read(tree, inp2));
    REQUIRE(read(tree, inp3));
    REQUIRE(read(tree, inp4));
    REQUIRE(read(tree, inp5));

    std::ostringstream ostream;
    tree.print(ostream, tree.root(), 1);
    REQUIRE(ostream.str() == result);
}

TEST_CASE("insert and print tree double")
{
    tree_t <double> tree;

    std::string input1{ "+3.3\n" };
    std::string input2{ "+4.4\n" };
    std::string input3{ "+2.2\n" };
    std::string input4{ "+1.1\n" };
    std::string input5{ "+5.5\n" };
    std::string result{ "------5.5\n"
                        "----4.4\n"
                        "--3.3\n"
                        "----2.2\n"
                        "------1.1\n" };

    std::istringstream inp1{ input1 };
    std::istringstream inp2{ input2 };
    std::istringstream inp3{ input3 };
    std::istringstream inp4{ input4 };
    std::istringstream inp5{ input5 };

    REQUIRE(read(tree, inp1));
    REQUIRE(read(tree, inp2));
    REQUIRE(read(tree, inp3));
    REQUIRE(read(tree, inp4));
    REQUIRE(read(tree, inp5));

    std::ostringstream ostream;
    tree.print(ostream, tree.root(), 1);
    REQUIRE(ostream.str() == result);
}

TEST_CASE("find tree int")
{
    tree_t <int> tree;

    std::string input1{ "+3\n" };
    std::string input2{ "+4\n" };
    std::string input3{ "+2\n" };
    std::string input4{ "+1\n" };
    std::string input5{ "+5\n" };

    std::istringstream inp1{ input1 };
    std::istringstream inp2{ input2 };
    std::istringstream inp3{ input3 };
    std::istringstream inp4{ input4 };
    std::istringstream inp5{ input5 };

    REQUIRE(read(tree, inp1));
    REQUIRE(read(tree, inp2));
    REQUIRE(read(tree, inp3));
    REQUIRE(read(tree, inp4));
    REQUIRE(read(tree, inp5));

    REQUIRE(tree.find(1) == true);
    REQUIRE(tree.find(2) == true);
    REQUIRE(tree.find(5) == true);
    REQUIRE(tree.find(7) == false);
    REQUIRE(tree.find(0) == false);
}

TEST_CASE("find tree double")
{
    tree_t <double> tree;

    std::string input1{ "+3.3\n" };
    std::string input2{ "+4.4\n" };
    std::string input3{ "+2.2\n" };
    std::string input4{ "+1.1\n" };
    std::string input5{ "+5.5\n" };

    std::istringstream inp1{ input1 };
    std::istringstream inp2{ input2 };
    std::istringstream inp3{ input3 };
    std::istringstream inp4{ input4 };
    std::istringstream inp5{ input5 };

    REQUIRE(read(tree, inp1));
    REQUIRE(read(tree, inp2));
    REQUIRE(read(tree, inp3));
    REQUIRE(read(tree, inp4));
    REQUIRE(read(tree, inp5));

    REQUIRE(tree.find(1.1) == true);
    REQUIRE(tree.find(2.2) == true);
    REQUIRE(tree.find(5.5) == true);
    REQUIRE(tree.find(7.7) == false);
    REQUIRE(tree.find(0) == false);
}

TEST_CASE("deleting")
{
    	tree_t<int> tree{3, 4, 2, 1, 5, 10, 7, 8};
	    std::string result{ "--------10\n"
	                        "------------8\n"
                            "----------7\n"
                            "------5\n"
                            "----4\n"
                            "--3\n"
                            "----2\n"
                            "------1\n"};
    	
    	tree.remove(5);
    	std::string result5{"------10\n"
	                        "----------8\n"
                            "--------7\n"
                            "----4\n"
                            "--3\n"
                            "----2\n"
                            "------1\n"};
	    std::ostringstream ostream1;
	    tree.print(ostream1, tree.root(), 1);
	    REQUIRE( ostream1.str() == result5 );
	       
	    tree.remove(1);
    	std::string result1{"------10\n"
	                        "----------8\n"
                            "--------7\n"
                            "----4\n"
                            "--3\n"
                            "----2\n"};
	    std::ostringstream ostream2;
	    tree.print(ostream2, tree.root(), 1);
	    REQUIRE( ostream2.str() == result1 );
}
