
#include "hashtable.h"
using namespace std;  

//Constructor
template <typename K, typename V>
HashTable<K, V>::HashTable(size_t size) {
    theList.resize(prime_below(size));  // Initialize to prime number 
    currentSize = 0;
}

// Destructor
template <typename K, typename V>
HashTable<K, V>::~HashTable() {
    clear();  // Clear the hashtable
}

//checks if key is in hashtable
template <typename K, typename V>
bool HashTable<K,V>::contains(const K &k) const {
    //Get the given chainlinked list at the hashvalue location
    auto & possibleList = theList[myhash(k)];
    //Loop through the chainlinked list to check if value is in the hashtable
    for(auto & thisList : possibleList)
        if(thisList.first == k)
            return true;    //Key is in table
    return false;
}

//checks if key-value pair is in table
template <typename K, typename V>
bool HashTable<K,V>::match(const pair<K,V> &kv) const {
    //Get the given chainlinked list at the hashvalue location
    auto & possibleList = theList[myhash(kv.first)];
    if(possibleList.size() > 0){
        for(auto & thisList : possibleList){
            if(thisList.first == kv.first)
                if(thisList.second == kv.second)
                    return true;    //Key & Value are both in table
        }
        return false;
    }
    else return false;
}

//adds the key value pair into the hash table
template <typename K, typename V>
bool HashTable<K,V>::insert(const pair<K,V> &kv){
    //Get the given chainlinked list at the hashvalue location
    auto & possibleList = theList[myhash(kv.first)];
    //Checks to see if KV pair is in table, updates it with proper values
    if(possibleList.size() > 0){
        for(auto & thisList : possibleList){
            if(thisList.first == kv.first)
                if(thisList.second == kv.second)
                    return false;
                else{ thisList.second = kv.second; break;}
            else{ possibleList.push_back(kv);break;}
        }
    }
    else possibleList.push_back(kv);

    //Increment current size 
    currentSize++;
    if(currentSize > theList.size())
        rehash();   //Increase size of hashtable
    return true;
}

//Move version of insert()
template <typename K, typename V>
bool HashTable<K,V>::insert(pair<K,V> &&kv){
    //Get the given chainlinked list at the hashvalue location
    auto & possibleList = theList[myhash(kv.first)];
    //Loop through list calling swap and move 
    if(possibleList.size() > 0){
        for(auto & thisList : possibleList){
            if(thisList.first == kv.first)
                if(thisList.second == kv.second)
                    return false;
                else{ swap(thisList.second,kv.second); break;}
            else{ possibleList.push_back(move(kv));break;}
        }
    }
    else possibleList.push_back(move(kv));

    //Increment current size 
    currentSize++;
    if(currentSize > theList.size())
        rehash();   //Increase size of hashtable
    return true;
}

//deltes the key and the corresponding value from the table
template <typename K, typename V>
bool HashTable<K,V>::remove(const K &k){
    //Get the given chainlinked list at the hashvalue location
    auto & possibleList = theList[myhash(k)];
    bool flag = false;
    unsigned int index = 0;
    //Loop through the nested list
    for(auto & thisList : possibleList){
        if(thisList.first == k){    
            flag = true;
            auto itr = possibleList.begin();
            advance(itr,index);
            possibleList.erase(itr);
            --currentSize;  //decrement cSize
            break;
        }
        index++;
    }
    return flag;
}

//calls private makeEmtpy()
template <typename K, typename V>
void HashTable<K,V>::clear(){
    makeEmpty();
}

//loads data from a filename
template <typename K, typename V>
bool HashTable<K,V>::load(const char *filename){
    
    ifstream infile;
    infile.open(filename);

    
    string line;
    while(getline(infile,line)){
        istringstream iss(line);
        string user, pass;
        iss >> user >> pass;    
        pair<string, string> p = make_pair (user,pass);
        insert(p);
    }
    infile.close();
    return true;
}

//sends the hash table
template <typename K, typename V>
void HashTable<K,V>::dump() const {
    int gIndex = 0;
    //Loop through each chainlinked list
    for(auto & thisList : theList){
        int index = 0;
        cout << "v[" << gIndex++ << "]: ";
        for(auto & x : thisList){
            
            if(++index > 1)
                cout << ":";
            cout << x.first << " " << x.second;
        }
        cout << "\n";
    }
}

//outputs the hash table 
template <typename K, typename V>
bool HashTable<K,V>::write_to_file(const char *filename) const {
    //Local variable
    ofstream ofile;
    ofile.open(filename);
    //Loop through and output
    for(auto & thisList : theList)
        for(auto & x : thisList)
            ofile << x.first << " " << x.second << "\n";
     ofile.close();
     return true;
}

//clears the hash table
template <typename K, typename V>
void HashTable<K,V>::makeEmpty(){
    for(auto & thisList : theList)
        thisList.clear();
    currentSize = 0;
}

template <typename K, typename V>
void HashTable<K, V>::rehash() {
    auto oldLists = theList; //
    theList.resize(prime_below(2 * theList.size()));
    for (auto &list : theList) { // clear each list
        list.clear();
    }
    currentSize = 0; // Reset current size

    for (auto &thisList : oldLists) {
        for (auto &x : thisList) {
            insert(std::move(x));
        }
    }
}


//My hash computes a given hash 
template <typename K, typename V>
size_t HashTable<K,V>::myhash(const K &k) const {
    size_t val = 0;
    for(auto ch : k)
        val = 37 * val + ch;
    return val % theList.size();
}

// returns largest prime number <= n or zero if input is too large
template <typename K, typename V>
unsigned long HashTable<K, V>::prime_below (unsigned long n) const
{
  if (n > max_prime)
    {
      cerr << "** input too large for prime_below()\n";
      return 0;
    }
  if (n == max_prime)
    {
      return max_prime;
    }
  if (n <= 1)
    {
		cerr << "** input too small \n";
      return 0;
    }

  // 2 <= n < max_prime
  vector <unsigned long> v (n+1);
  setPrimes(v);
  while (n > 2)
    {
      if (v[n] == 1)
	return n;
      --n;
    }

  return 2;
}

//Sets all prime number indexes to 1
template <typename K, typename V>
void HashTable<K, V>::setPrimes(vector<unsigned long>& vprimes) const
{
  int i = 0;
  int j = 0;

  vprimes[0] = 0;
  vprimes[1] = 0;
  int n = vprimes.capacity();

  for (i = 2; i < n; ++i)
    vprimes[i] = 1;

  for( i = 2; i*i < n; ++i)
    {
      if (vprimes[i] == 1)
        for(j = i + i ; j < n; j += i)
          vprimes[j] = 0;
    }
}