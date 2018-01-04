#include "testAVL.h"
#include <memory>


using namespace std;

// empty list

TEST(AVLTest, Insert1_Element) {
    avlTree *tree= new avlTree();
    tree->insert(5);
    EXPECT_TRUE(tree->contains(5));
    EXPECT_FALSE(tree->contains(1));
}

TEST(AVLTest, Insert2_Elements) {
    avlTree *tree= new avlTree();
    tree->insert(5);
    tree->insert(7);
    EXPECT_TRUE(tree->contains(5));
    EXPECT_TRUE(tree->contains(7));
    EXPECT_FALSE(tree->contains(1));
}

TEST(AVLTest, Insert3_Elements) {
    avlTree *tree= new avlTree();
    tree->insert(5);
    tree->insert(7);
    tree->insert(4);
    EXPECT_TRUE(tree->contains(5));
    EXPECT_TRUE(tree->contains(7));
    EXPECT_TRUE(tree->contains(4));
    EXPECT_FALSE(tree->contains(1));
}

TEST(AVLTest, Insert3_Elements_rising) {
    avlTree *tree= new avlTree();
    tree->insert(4);
    tree->insert(5);
    tree->insert(7);
    EXPECT_TRUE(tree->contains(5));
    EXPECT_TRUE(tree->contains(7));
    EXPECT_TRUE(tree->contains(4));
    EXPECT_FALSE(tree->contains(1));
}

TEST(AVLTest, Insert3_Elements_falling) {
    avlTree *tree= new avlTree();
    tree->insert(7);
    tree->insert(5);
    tree->insert(4);
    EXPECT_TRUE(tree->contains(5));
    EXPECT_TRUE(tree->contains(7));
    EXPECT_TRUE(tree->contains(4));
    EXPECT_FALSE(tree->contains(1));
}

TEST(AVLTest, Remove1_Element) {
    avlTree *tree= new avlTree();
    tree->insert(5);
    tree->contains(5);
    EXPECT_TRUE(tree->contains(5));
    EXPECT_FALSE(tree->remove(1));
    EXPECT_TRUE(tree->remove(5));
    EXPECT_FALSE(tree->contains(5));
}

// for following testcases visualisation see: https://stackoverflow.com/a/13843966

TEST(AVLTest, Left_Right) {
    avlTree *tree= new avlTree();
    tree->insert(20);
    tree->insert(4);
    tree->insert(15);
    EXPECT_TRUE(tree->root->val==15);
    EXPECT_TRUE(tree->root->left->val==4);
    EXPECT_TRUE(tree->root->right->val==20);
}

TEST(AVLTest, Triple_Rotate_Right) {
    avlTree *tree= new avlTree();
    tree->insert(20);
    tree->insert(4);
    tree->insert(26);
    tree->insert(3);
    tree->insert(9);
    tree->insert(15);
    EXPECT_TRUE(tree->root->val==9);
    EXPECT_TRUE(tree->root->left->val==4);
    EXPECT_TRUE(tree->root->left->left->val==3);
    EXPECT_TRUE(tree->root->right->val==20);
    EXPECT_TRUE(tree->root->right->right->val==26);
    EXPECT_TRUE(tree->root->right->left->val==15);
}

TEST(AVLTest, Triple_Rotate_Left) {
    avlTree *tree= new avlTree();
    tree->insert(20);
    tree->insert(4);
    tree->insert(26);
    tree->insert(3);
    tree->insert(9);
    tree->insert(8);
    EXPECT_TRUE(tree->root->val==9);
    EXPECT_TRUE(tree->root->left->val==4);
    EXPECT_TRUE(tree->root->left->left->val==3);
    EXPECT_TRUE(tree->root->left->right->val==8);
    EXPECT_TRUE(tree->root->right->val==20);
    EXPECT_TRUE(tree->root->right->right->val==26);
}

TEST(AVLTest, Remove_Rotate) {
    avlTree *tree= new avlTree();
    tree->insert(2);
    tree->insert(4);
    tree->insert(1);
    tree->insert(3);
    tree->insert(5);
    tree->remove(1);
    EXPECT_TRUE(tree->root->val==4);
    EXPECT_TRUE(tree->root->left->val==2);
    EXPECT_TRUE(tree->root->left->right->val==3);
    EXPECT_TRUE(tree->root->right->val==5);
}

TEST(AVLTest, Remove_Multi_Rotate) {
    avlTree *tree= new avlTree();
    tree->insert(5);
    tree->insert(2);
    tree->insert(8);
    tree->insert(1);
    tree->insert(3);
    tree->insert(7);
    tree->insert(10);
    tree->insert(4);
    tree->insert(6);
    tree->insert(9);
    tree->insert(11);
    tree->insert(12);
    tree->remove(1);
    EXPECT_TRUE(tree->root->val==8);
    EXPECT_TRUE(tree->root->left->val==5);
    EXPECT_TRUE(tree->root->left->left->val==3);
    EXPECT_TRUE(tree->root->left->left->left->val==2);
    EXPECT_TRUE(tree->root->left->left->right->val==4);
    EXPECT_TRUE(tree->root->left->right->val==7);
    EXPECT_TRUE(tree->root->left->right->left->val==6);

    EXPECT_TRUE(tree->root->right->val==10);
    EXPECT_TRUE(tree->root->right->left->val==9);
    EXPECT_TRUE(tree->root->right->right->val==11);
    EXPECT_TRUE(tree->root->right->right->right->val==12);
}