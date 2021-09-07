#include<vector>
#include<string>
using namespace std;

class TrieNode{
public:
	vector<TrieNode*> children;
	bool isword;
	
	TrirNode() : children(26, nullptr), isword(false){
	}
	
	~TrieNode() {
		for (int i = 0; i < 26; ++i) {
			if (children[i]) {
				delete children[i];
			}
		}
	}
};

class Trie{
	TrieNode* root;
public:
	Trie(){
		root = new TrieNode();
	}
	
	void insert(string word) {
		TrieNode* p = root;
		for (int i = 0; i < word.size(); ++i) {
			if (p->children[word[i] - 'a'] == nullptr) {
				p->children[word[i] - 'a'] = new TrieNode();
			}
			p = p->children[word[i] - 'a'];
		}
		p->isword = true;
	}
	
	bool search(string word) {
		TrieNode* p = root;
		for (int i = 0; i < word.size() && p; ++i) {
			p = p->children[word[i] - 'a'];
		}
		return p && p->isword;
	}
	
	bool startsWith(string prefix) {
		TrieNode* p = root;
		for (int i = 0; i < word.size() && p; ++i) {
			p = p->children[word[i] - 'a'];
		}
		return p;
	}
	
	~Trie() {
		delete root;
	}
};
