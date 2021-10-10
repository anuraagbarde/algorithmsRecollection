#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    unordered_map<char, TrieNode *> child;

    bool isWord;
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        this->root = new TrieNode();
    }

    TrieNode *newNode(bool isWord)
    {
        TrieNode *novel = new TrieNode();
        novel->isWord = isWord;

        return novel;
    }

    void printHelper(TrieNode *root)
    {
        auto &child = root->child;
        // if(root->isWord)
        // {
        //     cout<<"|";
        // }
        if (child.size() == 0)
        {
            cout << endl;
            return;
        }

        for (auto i : child)
        {
            cout << i.first;
            printHelper(i.second);
        }
    }
    void print()
    {
        printHelper(this->root);
    }

    void insert(string s)
    {
        TrieNode *curr = this->root;
        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            // cout << s[i];

            // try to find the child
            if (curr->child.find(s[i]) == curr->child.end())
            { //if child not found, create

                // cout<<s[i];
                // check wether this is the end of the word

                curr->child[s[i]] = newNode(false);
            }
            // else
            { // child already exists

                // select that child and make that curr and go to next letter
                // basically dfs

                // curr = child[s[i]];
                // continue;
            }
            curr = curr->child[s[i]];

            // also mark isWord if applicable
            if (i == n - 1)
            {
                curr->isWord = true;
            }
        }
    }

    bool search(string s)
    {
        TrieNode *curr = this->root;
        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            auto &child = curr->child;

            // try to find the child
            if (child.find(s[i]) == child.end())
            { //if child not found, return false, string not found
                return false;
            }
            else
            { // child already exists

                // select that child and make that curr and go to next letter
                // basically dfs
                // cout<<curr->isWord;
                if (i == n - 1 && curr->isWord == true)
                {
                    return true;
                }

                curr = child[s[i]];
                continue;
            }
        }

        return false;
    }
};

class Solution
{
    bool solve(Trie &T, string &s, int i, vector<int> &dp)
    {
        TrieNode *curr = T.root;
        int n = s.size();
        while (curr != NULL && i < n)
        {
            // cout << endl
            //      << s[i];
            if (curr->isWord == true)
            {
                // cout << "branching off: ";
                bool c1 = false;
                if (dp[i] != -1)
                {
                    c1 = dp[i];
                }
                else
                {
                    c1 = dp[i] = solve(T, s, i, dp);
                }

                // cout << c1 << endl;
                if (c1)
                    return true;
            }

            if (curr->child.find(s[i]) == curr->child.end())
            {
                // cout << "not found: " << s[i] << endl;
                return false;
            }
            else
            {
                curr = curr->child[s[i]];
                // printf("i:%d s[i]:%c isWord: %d , i==n-1: %d \n", i, s[i], curr->isWord, (i == n - 1));
                if (curr->isWord && i == n - 1)
                {
                    return true;
                }
                i++;
            }
        }

        return false;
    }

public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        Trie T = Trie();
        for (string s : wordDict)
            T.insert(s);

        // T.print();
        // cout<<T.search("leet");
        // cout<<T.search("lee");
        vector<int> dp(s.size() + 1, -1);
        return solve(T, s, 0, dp);

        // return false;
    }
};

int main()
{
    Solution S = Solution();

    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};

    cout << S.wordBreak(s, wordDict);
}