#include "pch.h"

#include <sstream>

#include "../AVLTree/AVLTree.h"

TEST(AVLTreeTest, Insert_Method) {
    AVLTree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(15);

    EXPECT_TRUE(tree.search(10) != nullptr);
    EXPECT_TRUE(tree.search(20) != nullptr);
    EXPECT_TRUE(tree.search(5) != nullptr);
    EXPECT_TRUE(tree.search(25) == nullptr);
}

TEST(AVLTreeTest, Remove_Method) {
    AVLTree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(15);

    tree.remove(20);
    tree.remove(5);

    EXPECT_TRUE(tree.search(20) == nullptr);
    EXPECT_TRUE(tree.search(5) == nullptr);
    EXPECT_TRUE(tree.search(10) != nullptr);
    EXPECT_TRUE(tree.search(15) != nullptr);
}

TEST(AVLTreeTest, Complex_Insert_And_Remove) {
    AVLTree tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    tree.remove(20);
    tree.remove(70);
    tree.remove(30);

    EXPECT_TRUE(tree.search(50) != nullptr);
    EXPECT_TRUE(tree.search(40) != nullptr);
    EXPECT_TRUE(tree.search(60) != nullptr);
    EXPECT_TRUE(tree.search(80) != nullptr);

    EXPECT_TRUE(tree.search(20) == nullptr);
    EXPECT_TRUE(tree.search(70) == nullptr);
    EXPECT_TRUE(tree.search(30) == nullptr);
}

TEST(AVLTreeTest, InorderTraversal_Method) {
    AVLTree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(15);

    std::stringstream output;
    std::streambuf* oldCout = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());

    tree.inorderTraversal();

    std::cout.rdbuf(oldCout);

    EXPECT_EQ(output.str(), "5 10 15 20 ");
}

TEST(AVLTreeTest, Clear_Method) {
    AVLTree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(15);

    tree.clear();

    tree.insert(10);

    EXPECT_TRUE(tree.search(10) != nullptr);
    EXPECT_TRUE(tree.search(20) == nullptr);
    EXPECT_TRUE(tree.search(5) == nullptr);
    EXPECT_TRUE(tree.search(15) == nullptr);
}

TEST(AVLTreeTest, All_Methods) {
    AVLTree tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    testing::internal::CaptureStdout();
    tree.inorderTraversal();
    std::string traversal_output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(traversal_output, "20 30 40 50 60 70 80 ");

    tree.remove(20);
    tree.remove(70);
    tree.remove(30);

    EXPECT_TRUE(tree.search(50) != nullptr);
    EXPECT_TRUE(tree.search(40) != nullptr);
    EXPECT_TRUE(tree.search(60) != nullptr);
    EXPECT_TRUE(tree.search(80) != nullptr);
    EXPECT_TRUE(tree.search(20) == nullptr);
    EXPECT_TRUE(tree.search(70) == nullptr);
    EXPECT_TRUE(tree.search(30) == nullptr);

    tree.clear();

    EXPECT_TRUE(tree.search(50) == nullptr);
    EXPECT_TRUE(tree.search(40) == nullptr);
    EXPECT_TRUE(tree.search(60) == nullptr);
    EXPECT_TRUE(tree.search(80) == nullptr);
}
