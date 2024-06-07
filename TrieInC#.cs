
public class TrieNode {
	public TrieNode[] child ;
	public bool isLeaf;

	public TrieNode() {

		child = new TrieNode[26];
		isLeaf = false;

	}

};

public class Trie{

    private TrieNode root;

    public Trie(){
        root = new();
    }

    public void Insert(string str){
        insert(str,root);
    }

    public bool WordExist(string str){
        return wordExist(str,root);
    }

    public bool PrefixExist (string str){
        return prefixExist(str , root);
    }

    private void insert(string str,TrieNode node ,int i = 0 ) {
		if(i == str.Length){
			node.isLeaf = true;
            return;
        }

        int cur = str[i] - 'a';

        if(node.child[cur] is null )
            node.child[cur] = new TrieNode();
    

        insert( str , node.child[cur] , i+1 );

	}

	private bool wordExist(string str, TrieNode node  , int i = 0 ) {
		if(i == str.Length)
			return node.isLeaf;

		int cur = str[i] - 'a';
		if(node.child[cur] is null )
			return false;	 

		return wordExist( str ,node.child[cur] , i+1);
	}

	private bool prefixExist(string str , TrieNode node , int i = 0 ) {
		if(i == str.Length)
			return true;

		int cur = str[i] - 'a';
		if(node.child[cur] is null )
			return false;	 

		return prefixExist( str , node.child[cur] , i+1 );
	}

   

}

