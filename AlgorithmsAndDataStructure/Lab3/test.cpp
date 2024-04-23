#include "pch.h"
#include "../AlgorithmTable/Table.cpp"

TEST(TestAddingToTable, Test1) {
	Table table;

	table.addElement("key1", 1);
	table.addElement("key2", 2);

	EXPECT_EQ(table.findValue("key1"), 1);
	EXPECT_EQ(table.findValue("key2"), 2);
}

TEST(TestAddingToTable, Test2) {
	std::stringstream output;
	std::streambuf* old_cout = std::cout.rdbuf(output.rdbuf());

	Table table;

	table.addElement("key1", 1);
	table.addElement("key2", 2);
	table.addElement("key3", 3);
	table.addElement("key4", 4);
	table.addElement("key5", 5);

	table.addElement("key6", 6);
	std::string expected_output = "Table Owerflow!\n";
	EXPECT_EQ(output.str(), expected_output);

	std::cout.rdbuf(old_cout);
}

TEST(TestRemovingFromTable, Test1) {
	std::stringstream output;
	std::streambuf* old_cout = std::cout.rdbuf(output.rdbuf());

	Table table;

	table.addElement("key1", 1);
	table.addElement("key2", 2);
	table.addElement("key3", 3);

	EXPECT_EQ(table.findValue("key2"), 2);

	table.removeElement("key2");
	table.findValue("key2"), 2;
	std::string expected_output = "Element with a key key2 not found!\n";
	EXPECT_EQ(output.str(), expected_output);

	std::cout.rdbuf(old_cout);
}

TEST(TestRemovingFromTable, Test2) {
	std::stringstream output;
	std::streambuf* old_cout = std::cout.rdbuf(output.rdbuf());

	Table table;

	table.addElement("key1", 1);
	table.addElement("key2", 2);
	table.addElement("key3", 3);
	table.addElement("key4", 4);
	table.addElement("key5", 5);

	table.addElement("key6", 6);
	std::string expected_output = "Table Owerflow!\n";
	EXPECT_EQ(output.str(), expected_output);

	table.removeElement("key5");
	table.addElement("key6", 6);
	EXPECT_EQ(table.findValue("key6"), 6);

	std::cout.rdbuf(old_cout);
}
