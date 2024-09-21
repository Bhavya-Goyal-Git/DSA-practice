#include <iostream>
#include <vector>
using namespace std;

// Problem link : https://www.naukri.com/code360/problems/implement-a-phone-directory_1062666?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

// Problem : You are given a list/array of strings which denotes the contacts that exist in your phone directory. The search query on a string ‘str’ which is a query string displays all the contacts which are present in the given directory with the prefix as ‘str’. One special property of the search function is that when a user searches for a contact from the contact list then suggestions (contacts with prefix as the string entered so for) are shown after the user enters each character. Return a vector of vector of strings. (1st vector when user types 1st letter of query, all the suggestions, 2nd when 2 letters have been typed and so on..)

// Approach : For the storage of strings and prefix kind manipulation, we create a trie data structure. We add all the given strings into the trie. Now comes the processing part. We firstly get the root of our trie and assign it to a pointer 'prev'. We also make a string called prefix and a char called lastChar, and obviously a vect of vect of strings 'ans' to store the ans. Then we can run a loop across letters of queryString given. We firstly assign the character to lastChar, and append it to prefix string. Then we check whether this character is present in the children of 'prev' if not, we break out. If yes, we make a temp vector of strings, and send it along with prefix as reference vars along with pointer to that children to another recursive function getAllWords, which returns a vector of strings, from the trie, containing all words starting with given prefix. We append the result into ans vector. Then we update prev to the child pointer we just made a call to.
// Working of getAllWords: if root is a terminal node, we simply append prefix to the vector. Then we check if this node has any more children, if yes add thier data to the prefix and make a recursive call with them. After the call pop back from prefix for backtracking. This recursively gets all values and pushes into the temp vector.
// Space comp is O(n*m) and time is O(n*m2), where n is number of strings and m is average len of string.

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;
    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
    TrieNode *rootNode;

public:
    Trie()
    {
        rootNode = new TrieNode('\0');
    }
    void insertUtil(TrieNode *root, string &word, int index, int &length)
    {
        if (index >= length)
        {
            root->isTerminal = true;
            return;
        }
        int letterIndex = word[index] - 'a';
        if (root->children[letterIndex] == NULL)
        {
            root->children[letterIndex] = new TrieNode(word[index]);
        }
        insertUtil(root->children[letterIndex], word, index + 1, length);
    }
    void insert(string word)
    {
        int len = word.size();
        insertUtil(rootNode, word, 0, len);
    }
    TrieNode *getRoot()
    {
        return rootNode;
    }
};

void getAllWords(TrieNode *root, vector<string> &temp, string &prefix)
{
    if (root->isTerminal)
    {
        temp.push_back(prefix);
    }
    for (int i = 0; i < 26; i++)
    {
        if (root->children[i] != NULL)
        {
            prefix.push_back('a' + i);
            getAllWords(root->children[i], temp, prefix);
            prefix.pop_back();
        }
    }
}

vector<vector<string>> phoneDirectory(vector<string> &contactList, string &queryStr)
{
    Trie *t = new Trie();
    // add all the words to a Trie
    int numofstrings = contactList.size();
    for (int i = 0; i < numofstrings; i++)
    {
        t->insert(contactList[i]);
    }
    vector<vector<string>> ans;
    TrieNode *prev = t->getRoot();
    string prefix = "";
    char lastChar;
    int lenOfQuery = queryStr.size();
    for (int i = 0; i < lenOfQuery; i++)
    {
        lastChar = queryStr[i];
        prefix.push_back(lastChar);
        if (prev->children[lastChar - 'a'] == NULL)
            break;
        TrieNode *curr = prev->children[lastChar - 'a'];
        vector<string> temp;
        getAllWords(curr, temp, prefix);
        ans.push_back(temp);
        prev = curr;
    }
    return ans;
}
