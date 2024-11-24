#include <iostream>
#include <cstring>
using namespace std;

const int ALPHABET_SIZE = 26; 
const int MAX_NODES = 100000;

int trie[MAX_NODES][ALPHABET_SIZE]; 
bool isEndOfWord[MAX_NODES];        
int nodeCount = 1;             

void insert(string str){

int currentnode=0;

    for(char c:str){
        int index=c-'a';
        if(trie[currentnode][index]==0){
          trie[currentnode][index]=nodeCount++;
        }

        currentnode = trie[currentnode][index];

    }

    isEndOfWord[currentnode]=true;

}

bool search(string str){

      int currentnode=0;
      for(char c:str){
        int index=c-'a';
        if(trie[currentnode][index]==0)
            return false;
        currentnode=trie[currentnode][index];
      }

      return isEndOfWord[currentnode];

}

int main() {
    
    memset(trie,0,sizeof(trie));
    memset(isEndOfWord,false,sizeof(isEndOfWord));

    insert("app");
    insert("apple");
    insert("banana");

    cout << "Search 'apple': " << search("apple") << endl;    // true
    cout << "Search 'app': " << search("app") << endl;        // true
    cout << "Search 'appl': " << search("appl") << endl;      // false
    cout << "Search 'banana': " << search("banana") << endl;  // true
    cout << "Search 'ban': " << search("ban") << endl;        // false

    return 0;
}
