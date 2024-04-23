#include <iostream>
#include <string>

#include "Table.h"

using namespace std;



int main(int argc, char* argv[]) {
    Table table;

    table.addElement("one", 1);
    table.addElement("two", 2);
    table.addElement("three", 3);

    cout << "Element with key 'two': " << table.findValue("two") << endl;
    cout << "Element with key 'four': " << table.findValue("four") << endl;

    // testing::InitGoogleTest(&argc, argv);
    // return RUN_ALL_TESTS();
    return 0;
}
