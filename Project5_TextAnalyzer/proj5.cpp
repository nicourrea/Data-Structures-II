#include <iostream>
#include <iomanip>
#include <string>
#include <map>

using namespace std;

//create functions

void characters(map<char, pair<int,int>> &characterMap);
void words(map<string, pair<int,int>> &wordMap);
void numbers(map<string, pair<int,int>> &numberMap);

// main function

int main(){
    string word;
    string number;
    char character;
    // create maps
    map<string, pair<int,int>> wordMap;
    map<string, pair<int,int>> numberMap;
    map<char, pair<int,int>> characterMap;

    // read input

    while(cin.good()) {
        // read character        
        cin.get(character);
        if(isalpha(character)){ 
            word += tolower(character); 
            // if number is not empty
            if(!number.empty()){ 
                ++numberMap[number].first; 
                if(numberMap[number].first == 1) { 
                    numberMap[number].second = numberMap.size();
                }
                number = ""; 
            }
        }else if(isdigit(character)){ 
            number += character; 
            // if word is not empty
            if(!word.empty()){ 
                ++wordMap[word].first; 
                if(wordMap[word].first == 1) { 
                    wordMap[word].second = wordMap.size();
                }
                word = ""; 
            }
        }else{ 
            if(!word.empty()){ 
                ++wordMap[word].first; 
                if(wordMap[word].first == 1) { 
                    wordMap[word].second = wordMap.size();
                }
                word = ""; 
            }
            if(!number.empty()){ 
                ++numberMap[number].first; 
                if(numberMap[number].first == 1){ 
                    numberMap[number].second = numberMap.size();
                }
                number = ""; 
            }
        }
        ++characterMap[character].first;
        characterMap[character].second = (int)character;
    }
    // if word is not empty
    if(!word.empty()){ 
        ++wordMap[word].first; 
        if(wordMap[word].first == 1) { 
            wordMap[word].second = wordMap.size();
        }
    }
    if(!number.empty()){ 
        ++numberMap[number].first; 
        if(numberMap[number].first == 1){ 
            numberMap[number].second = numberMap.size();
        }
    }
    // print results
    words(wordMap);
    numbers(numberMap);
    characters(characterMap);

    return 0;
}
// create functions
void words(map<string, pair<int,int>> &wordMap){
    int numberOfWords;
  
    if(wordMap.size() <= 10){
        numberOfWords = wordMap.size();
    }else{
        numberOfWords = 10;
    }
    
    // print results
    cout << endl;
    cout << "There are " << wordMap.size() << " Different Words, The Most Repeated " << numberOfWords << " Words:" << endl;
    cout << endl;
    cout << "Index       Item   Number    Priority" << endl;
    
    // create iterator
    map<string, pair<int,int>>::iterator it;
    
    for(int i = 0; i<numberOfWords; i++){
        
        auto best = wordMap.begin(); 
        for(it = wordMap.begin(); it != wordMap.end(); it++){ 
            
            if(best->second.first < it->second.first){
                best = it;
            }else if(best->second.first == it->second.first){ 
                if(it->second.second < best->second.second){
                    best = it;
                }
            }
        }
        // print results    
        cout << "[  " << i << "] " << setw(12) << best->first << setw(5) << best->second.first << setw(12) << best->second.second << endl;
        wordMap.erase(best); 
    }
}

// create functions
void numbers(map<string, pair<int,int>> &numberMap){
    int numberOfNumbers;
   
    if(numberMap.size() <= 10){
        numberOfNumbers = numberMap.size();
    }else{
        numberOfNumbers = 10;
    }
    cout << endl;
    cout << "There are " << numberMap.size() << " Different Numbers, The Most Repeated " << numberOfNumbers << " Numbers:" << endl;
    cout << endl;
    cout << "Index       Item   Number    Priority" << endl;

    map<string, pair<int,int>>::iterator it;
    for(int i = 0; i<numberOfNumbers; i++){
    
        auto best = numberMap.begin(); 
        for(it = numberMap.begin(); it != numberMap.end(); it++){ 
            if(best->second.first < it->second.first){
                best = it;
            }else if(best->second.first == it->second.first){ 
                if(it->second.second < best->second.second){
                    best = it;
                }
            }
        }
  
        cout << "[  " << i << "] " << setw(12) << best->first << setw(5) << best->second.first << setw(12) << best->second.second << endl;
        numberMap.erase(best); 
    }
}

void characters(map<char, pair<int,int>> &characterMap){
    int numberOfCharacters;
   
    if(characterMap.size() <= 10){
        numberOfCharacters = characterMap.size();
    }else{
        numberOfCharacters = 10;
    }
    cout << endl;
    cout << "There are " << characterMap.size() << " Different Characters, The Most Repeated " << numberOfCharacters << " Characters:" << endl;
    cout << endl;
    cout << "Index       Item   Number    Priority" << endl;

    map<char, pair<int,int>>::iterator it;
   
    for(int i = 0; i<numberOfCharacters; i++){
        
        auto best = characterMap.begin();
        for(it = characterMap.begin(); it != characterMap.end(); it++){ 
          
            if(best->second.first < it->second.first){
                best = it;
            }else if(best->second.first == it->second.first){ 
                
                if(it->second.second < best->second.second){
                    best = it;
                }
            }
        }
       
        if(best->first == '\n'){ 
            cout << "[  " << i << "] " << setw(12) << "Newline" << setw(5) << best->second.first << setw(12) << best->second.second << endl;
        }else if(best->first == '\t'){ 
            cout << "[  " << i << "] " << setw(12) << "Tab" << setw(5) << best->second.first << setw(12) << best->second.second << endl;
        }else if(best->first == ' '){ 
            cout << "[  " << i << "] " << setw(12) << "Space" << setw(5) << best->second.first << setw(12) << best->second.second << endl;
        }else{ 
            cout << "[  " << i << "] " << setw(12) <<best->first << setw(5) << best->second.first << setw(12) << best->second.second << endl;
        }
        characterMap.erase(best); 
    }
}