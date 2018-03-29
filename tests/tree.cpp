#include <catch.hpp>
#include <sstream>

#include "tree.hpp"

TEST_CASE("creating tree")
{
    tree_t tree;
    REQUIRE(tree.root() == nullptr);
}

TEST_CASE("insert and print tree")
{
	tree_t tree;
    
	std::string input1{"+3\n"};
	std::string input2{"+4\n"};
	std::string input3{"+2\n"};
    std::string input1{"+1\n"};
	std::string input2{"+5\n"};
	std::string result{"------5\n"
			   "----4\n"
			   "--3\n"
        "----2\n"
        "------1\n"
	};
	
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
	tree.print(ostream, tree.root());
	REQUIRE( ostream.str() == result );
} 

TEST_CASE("find tree")
{
	tree_t tree;
    
	std::string input1{"+3\n"};
	std::string input2{"+4\n"};
	std::string input3{"+2\n"};
    std::string input1{"+1\n"};
	std::string input2{"+5\n"};
	
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
    
	REQUIRE(tree.find(1) == true );
	REQUIRE(tree.find(2) == true );
    REQUIRE(tree.find(5) == true );
	REQUIRE(tree.find(7) == false );
    REQUIRE(tree.find(0) == false );
}
