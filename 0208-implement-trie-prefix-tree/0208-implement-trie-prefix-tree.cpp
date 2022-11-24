struct Node{
    Node *links[26];
    bool flag = false;
    
    bool containKey(char ch){
        return (links[ch - 'a'] != NULL);
    }
    void put(char ch,Node *dummy_node){
        links[ch - 'a'] = dummy_node;
    }
    Node *get(char ch){
        return links[ch - 'a'];
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
        
};


class Trie {
private: 
    Node* root;
public:
    Trie() {
        // creating new onject
        root = new Node();
    }
    
    void insert(string word) {
        //initializing dummy node pointing to root initially
        Node *dummy_node = root;
        for(int i = 0; i < word.size();i++){
            if(!dummy_node->containKey(word[i])){
                dummy_node->put(word[i],new Node());
            }
            // move to reference trie
            dummy_node = dummy_node->get(word[i]);
        }
        dummy_node->setEnd();
        
    }
    
    bool search(string word) {
        Node *dummy_node = root;
        for(int i = 0; i < word.size();i++){
            if(!dummy_node->containKey(word[i])){
                return false;
            }
            // move to reference trie
            dummy_node = dummy_node->get(word[i]);
        }
        return dummy_node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node *dummy_node = root;
        for(int i = 0; i < prefix.size();i++){
            if(!dummy_node->containKey(prefix[i])){
                return false;
            }
            // move to reference trie
            dummy_node = dummy_node->get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */