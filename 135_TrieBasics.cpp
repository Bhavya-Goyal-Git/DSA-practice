#include <iostream>
using namespace std;

// Trie is a non-linear Data Structure. It is a n-ary Tree, generally used to store strings. A trie has a root node that has no data (some garbage value we won't use) but has a array of n-pointers (here, 26 to represent 26 letters of alphabet). Each node has these values, a char data, an array of 26 pointers of similar kind, and a bool variable -isTerminal. (this variable is necessary during search operation, for example we added "army" into the trie, and search whether "arm" is inside trie, we would not be able to judge, but we can if we have a terminal boolean value).

// All 3 basic functions like searching, insertion, deletion are divided into 2 here, one in the interface that recieves the word to be processed from outside, and other is the actual function that recursively does the processing. To the recursive function we pass index (current letter of word being processed) and length of word to make better use of space and time (not copying string again, not calculating size of string at every call etc.)

// Insertion algo : Base case is when index == length, then we make the root a terminal node (root->isterminal = true) to mark end of string. Else, we first calculate index of letter we want, that is word[index] - 'A' (Assuming only uppercase words). Then we check if that is present at root's children (if root->children[letterIndex] exists), if it does not exists, create one, then make a recursive call with this root->children[letterIndex] as root, and index as index+1 and rest same. If it already existed, directly make that same recursive call.

// Search algo : Code is same to insertion, just at base case we know we have found the entire word, but it may be possible it is not actually there, we return root->isTerminal.. (it contains info whether a word actually ends there). And another change is when a child did not exist, then simply return false, only if it exists make a recursive call with root->children[letterindex] ahead.

// Deletion algo: Code is entirely same, the naive way is not to remove pointer and such, just reach the last node you want (if exists) and at that position, set the value of isTerminal to false. It will act as removing the word from trie.

// Trie's Node
class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;
    TrieNode(char c)
    {
        data = c;
        // initializing all children pointers to NULL at construction (Necessary, or functions wouldn't work properly)
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

// Actual trie class
class Trie
{
    TrieNode *rootNode; // only data is root node of the trie

public:
    Trie() // at construction, we make a root node with some absurd data
    {
        rootNode = new TrieNode('\0');
    }

    // recursive function that actually inserts a word into trie
    void insertUtil(TrieNode *root, string &word, int index, int &length)
    {
        if (index >= length)
        {
            root->isTerminal = true;
            return;
        }
        int letterIndex = word[index] - 'A';
        if (root->children[letterIndex] == NULL)
        {
            // if node does not exist, create it!
            root->children[letterIndex] = new TrieNode(word[index]);
        }
        insertUtil(root->children[letterIndex], word, index + 1, length);
    }

    // insertion function called from outside to insert a word.
    void insert(string word)
    {
        int len = word.size();
        insertUtil(rootNode, word, 0, len);
    }

    // recursive function that actually searches the word in trie
    bool searchUtil(TrieNode *root, string &word, int index, int &length)
    {
        if (index >= length)
        {
            return root->isTerminal;
        }
        int letterIndex = word[index] - 'A';
        if (root->children[letterIndex] == NULL)
        {
            return false;
        }
        return searchUtil(root->children[letterIndex], word, index + 1, length);
    }

    // function called from outside to search a word's presence in the trie
    bool search(string word)
    {
        int len = word.size();
        return searchUtil(rootNode, word, 0, len);
    }

    // recursive function that actually removes a word from the trie, ignores if word is not present
    void removeUtil(TrieNode *root, string &word, int index, int &length)
    {
        if (index >= length)
        {
            root->isTerminal = false;
            return;
        }
        int letterIndex = word[index] - 'A';
        if (root->children[letterIndex] == NULL)
            return; // agar hai hee nahi toh kya remove karna?
        removeUtil(root->children[letterIndex], word, index + 1, length);
    }

    // function called from outside to remove a word from the trie
    void remove(string word)
    {
        int len = word.size();
        removeUtil(rootNode, word, 0, len);
    }
};

int main()
{
    Trie *t = new Trie();
    t->insert("AABRA");
    t->insert("DAABRA");
    cout << "Is AABRA present : " << (t->search("AABRA") ? "YES" : "NO") << "\n";
    cout << "Is DAABRA present : " << (t->search("DAABRA") ? "YES" : "NO") << "\n";
    cout << "Is KAM present : " << (t->search("KAM") ? "YES" : "NO") << "\n";
    t->remove("AABRA");
    cout << "Is AABRA present after deletion : " << (t->search("AABRA") ? "YES" : "NO") << "\n";
    return 0;
}