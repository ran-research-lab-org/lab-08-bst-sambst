#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "BinarySearchTree.hpp"
#include "doctest.h"
#include <sstream>
#include <stdexcept>


using namespace std;

TEST_CASE("BinarySearchTree basic operations") {
    BinarySearchTree<int> bst;

    // ----- Insert -----
    bst.insert(10);
    bst.insert(4);
    bst.insert(15);
    bst.insert(2);
    bst.insert(31);
    bst.insert(1);
    bst.insert(56);

    // The in-order traversal of a BST should always be sorted
    CHECK(bst.toInorderStr() == "1,2,4,10,15,31,56");
    CHECK(bst.contains(10) == true);
    CHECK(bst.contains(31) == true);
    CHECK(bst.contains(99) == false);

    // ----- Remove leaf node -----
    bst.remove(1); // leaf
    CHECK(bst.toInorderStr() == "2,4,10,15,31,56");
    CHECK_FALSE(bst.contains(1));

    // ----- Remove node with one child -----
    bst.remove(2); // has one child (4)
    CHECK(bst.toInorderStr() == "4,10,15,31,56");
    CHECK_FALSE(bst.contains(2));

    // ----- Remove node with two children -----
    bst.remove(10); // 10 has left=4, right=15
    CHECK(bst.toInorderStr() == "4,15,31,56");
    CHECK_FALSE(bst.contains(10));

    // ----- Reinsert new elements -----
    bst.insert(7);
    bst.insert(20);
    CHECK(bst.toInorderStr() == "4,7,15,20,31,56");

    // ----- Check that contains still works -----
    CHECK(bst.contains(7));
    CHECK(bst.contains(20));
    CHECK_FALSE(bst.contains(10));

    // ----- Check findMin and findMax -----
    CHECK(bst.findMin() == 4);
    CHECK(bst.findMax() == 56);
}

TEST_CASE("BinarySearchTree basic operations") {
  BinarySearchTree<int> B;
  B.insert(10);

  B.insert(4);
  B.insert(2);
  B.insert(15);
  B.insert(31);
  B.insert(1);
  B.insert(56);
  CHECK(B.toInorderStr() == "1,2,4,10,15,31,56");
  auto result = B.BFT();
INFO("BFT() returned: " << result);
  CHECK(B.BFT() == "[[10],[4,15],[2,31],[1,56]]");
 
  BinarySearchTree<int> C;
  for (auto e :
       {16, 8, 24, 28, 20, 12, 4, 2, 6, 10, 14, 18, 22, 26, 30, 15, 7, 3}) {
    C.insert(e);
  }

  CHECK(C.toInorderStr() == "2,3,4,6,7,8,10,12,14,15,16,18,20,22,24,26,28,30");
  CHECK(C.BFT() ==
        "[[16],[8,24],[4,12,20,28],[2,6,10,14,18,22,26,30],[3,7,15]]");
}
