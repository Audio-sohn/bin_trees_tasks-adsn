#include <catch2/catch_test_macros.hpp>

#include "element.h"

TEST_CASE("new_element")
{
    Element element;
    element.left = nullptr;
    element.right = nullptr;

    REQUIRE(element.empty() == true);
}

TEST_CASE("insert")
{
    Element element;
    element.left = nullptr;
    element.right = nullptr;

    element.insert(1, true);

    REQUIRE(element.key == 1);
    REQUIRE(element.value == true);
    REQUIRE(element.left != nullptr);
    REQUIRE(element.right != nullptr);

    REQUIRE(element.empty() == false);
    REQUIRE(element.left->empty() == true);
    REQUIRE(element.right->empty() == true);
}

TEST_CASE("add")
{
    Element root;
    root.left = nullptr;
    root.right = nullptr;

    root.add(42, true);
    root.add(23, false);
    root.add(77, true);

    REQUIRE(!root.empty());
    REQUIRE(root.key == 42);
    REQUIRE(root.value == true);

    REQUIRE(!root.left->empty());
    REQUIRE(root.left->key == 23);
    REQUIRE(root.left->value == false);

    REQUIRE(!root.right->empty());
    REQUIRE(root.right->key == 77);
    REQUIRE(root.right->value == true);

    REQUIRE(root.left->left->empty());
    REQUIRE(root.left->right->empty());
    REQUIRE(root.right->left->empty());
    REQUIRE(root.right->right->empty());

    root.add(42, false);
    REQUIRE(root.key == 42);
    REQUIRE(root.value == false);
}

TEST_CASE("get")
{
    Element root;
    root.left = nullptr;
    root.right = nullptr;

    root.add(42, true);
    root.add(23, false);
    root.add(77, true);

    REQUIRE(root.get(42) == true);
    REQUIRE(root.get(23) == false);
    REQUIRE(root.get(77) == true);
    REQUIRE(root.get(100) == false);
}

TEST_CASE("height")
{
    Element root;
    root.left = nullptr;
    root.right = nullptr;

    root.add(42, true);
    root.add(23, false);
    root.add(77, true);

    REQUIRE(root.height() == 2);
    REQUIRE(root.left->height() == 1);
    REQUIRE(root.right->height() == 1);

    root.add(10, true);
    REQUIRE(root.height() == 3);
    REQUIRE(root.left->height() == 2);
    REQUIRE(root.right->height() == 1);
}
