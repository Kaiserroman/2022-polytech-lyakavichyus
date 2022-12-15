#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "hash.h"
#include <string>
#include "doctest.h"

TEST_CASE("SIZE") {

    HashTable* ht = create_table(CAPACITY);
    ht_insert(ht, "1", "First address");
    ht_insert(ht, "2", "Second address");

    CHECK_EQ(ht->count, 2);
}

TEST_CASE("INSERT") {

    HashTable* ht = create_table(CAPACITY);
    ht_insert(ht, "1", "First address");
    ht_insert(ht, "2", "Second address");
    ht_insert(ht, "3", "Third address");
    CHECK(ht->count > 2);
}

TEST_CASE("GET") {

    HashTable* ht = create_table(CAPACITY);
    ht_insert(ht, "1", "First address");
    ht_insert(ht, "2", "Second address");
    CHECK(ht->count > 2);
}