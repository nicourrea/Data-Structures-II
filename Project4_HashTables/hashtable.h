#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <cstring>
#include <utility>
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>

namespace cop4530
{
template <typename K, typename V>
class HashTable{
public:
    HashTable(size_t size = 101); // Make a new hash table
    ~HashTable(); // Clean up

    bool contains(const K &k) const; // See if key's there
    bool match(const std::pair<K,V> &kv) const; // Find key-value pair
    bool insert(const std::pair<K,V> &kv); // Add key-value
    bool insert(std::pair<K,V> && kv); // Move version of add
    bool remove(const K &k); // Take key-value out

    void clear(); // Empty it
    bool load(const char *filename); // Fill from file
    void dump() const; // Show everything
    bool write_to_file(const char *filename) const; // Save to file

    size_t getSize() const {return currentSize;} 

    // Below are needed to resize
    static const unsigned int max_prime = 1301081;
    static const unsigned int default_capacity = 11;
private:
    void makeEmpty(); // Clear it all
    void rehash(); // Resize when full
    size_t myhash(const K &k) const; // Find where key goes
    unsigned long prime_below(unsigned long) const; // For resizing
    void setPrimes(std::vector<unsigned long> &) const; // Also for resizing

    std::vector<std::list<std::pair<K,V>>> theList; // The hash table
    size_t currentSize; 
};
#include "hashtable.hpp"
}
#endif 
