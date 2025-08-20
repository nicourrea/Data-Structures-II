#ifndef PASSSERVER_H
#define PASSSERVER_H

#include "hashtable.h"
#include <string>
#include <utility>

namespace cop4530 {
    class PassServer {
    public:
        PassServer(size_t size = 101); // Constructor
        ~PassServer(); // Destructor

        bool load(const char* filename); // Load password file 
        bool addUser(const std::pair<std::string, std::string>& kv); // Add a new user pass
        bool addUser(std::pair<std::string, std::string>&& kv); // Move  addUser
        bool removeUser(const std::string& k); // Delete user
        bool changePassword(const std::pair<std::string, std::string>& p, const std::string& newpassword); // Change password
        bool find(const std::string& user) const; // Check if user exists
        void dump() const; // Show the structure 
        bool write_to_file(const char* filename) const; // Save username/password 
        size_t size() const; // Return the size

    private:
        std::string encrypt(const std::string& str) const; // Encrypt the parameter
        HashTable<std::string, std::string> table; // HashTable object 
    };
}

#endif // PASSSERVER_H
