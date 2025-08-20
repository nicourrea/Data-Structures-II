#include "passserver.h"
#include <fstream>
#include <sstream>
#include "base64.h"

using namespace std;
using namespace cop4530;

// Constructor
PassServer::PassServer(size_t size) : table(size) {}

// Destructor
PassServer::~PassServer() {}

// Load file
bool PassServer::load(const char* filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Cannot open file " << filename << endl;
        return false;
    }

    string user, pass;
    while (file >> user >> pass) {
        addUser(make_pair(user, encrypt(pass)));
    }

    file.close();
    return true;
}

// Add a user with a password
bool PassServer::addUser(const pair<string, string>& kv) {
    return table.insert(make_pair(kv.first, encrypt(kv.second)));
}

// addUser
bool PassServer::addUser(pair<string, string>&& kv) {
    return table.insert(make_pair(move(kv.first), encrypt(move(kv.second))));
}

// Remove a user
bool PassServer::removeUser(const string& k) {
    return table.remove(k);
}

// Change a user's password
bool PassServer::changePassword(const pair<string, string>& p, const string& newpassword) {
    if (!find(p.first) || newpassword.empty() || p.second == newpassword) {
        return false;
    }

    auto currentEncryptedPass = table.match(make_pair(p.first, encrypt(p.second)));
    if (!currentEncryptedPass) {
        return false;
    }

    return table.insert(make_pair(p.first, encrypt(newpassword)));
}

// Find a user
bool PassServer::find(const string& user) const {
    return table.contains(user);
}

// Dump the hash table
void PassServer::dump() const {
    table.dump();
}

// Write user and password data to a file
bool PassServer::write_to_file(const char* filename) const {
    return table.write_to_file(filename);
}

// Encrypt the password
string PassServer::encrypt(const string& str) const {
    const size_t MAXSIZE = 1024;  //
    BYTE charIn[MAXSIZE];         // Input character array.
    BYTE charOut[MAXSIZE];        // Output character array.

    // Ensure the input string doesn't exceed MAXSIZE
    strncpy(reinterpret_cast<char*>(charIn), str.c_str(), min(str.size(), MAXSIZE-1));
    charIn[min(str.size(), MAXSIZE-1)] = '\0'; //  null-termination

    // perform base64 encoding
    base64_encode(charIn, charOut, strlen(reinterpret_cast<char*>(charIn)), 1);

    // Convert the outpur back to string
    return string(reinterpret_cast<char*>(charOut));
}

// Size of the hash table
size_t PassServer::size() const {
    return table.getSize();
}
