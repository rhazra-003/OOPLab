#include <iostream>
using namespace std; 
class BST 
{
	int data;
	BST *left,*right;
public:
    BST();
    BST(int);
    BST* Insert(BST*, int);
    BST* search(BST*,int);
    int findheight(BST*);
    BST* deletenode(BST*,int);
    void displayinorder(BST*);
    void displaybfs(BST*);
    void displayLevel(BST* , int ); 
    void displayPreorder(BST* );
    void displayPostorder(BST* );
};
BST ::BST()
    : data(0)
    , left(NULL)
    , right(NULL)
{
}
BST ::BST(int value)
{
    data = value;
    left = right = NULL;
}
BST* BST ::Insert(BST* root, int value)
{
    if (!root) 
    {
        return new BST(value);
    }
    if (value > root->data) 
    {
        root->right = Insert(root->right, value);
    }
    else
    {
        root->left = Insert(root->left, value);
    }
    return root;
}
BST* BST ::search(BST* root, int key)
{
    if (root == NULL || root->data == key)
       return root;
    if (root->data < key)
       return search(root->right, key);
       
    return search(root->left, key);
}
int BST ::findheight(BST* root) 
{ 
    if (root == NULL) 
        return 0; 
    else
    {
        int lheight = findheight(root->left); 
        int rheight = findheight(root->right); 
        if (lheight > rheight) 
            return(lheight + 1); 
        else return(rheight + 1); 
    } 
} 
void BST ::displayinorder(BST* root)
{
    if (!root) {
        return;
    }
    displayinorder(root->left);
    cout << root->data <<" ";
    displayinorder(root->right);
}
BST* BST::deletenode(BST* root,int k)
{
    if (root == NULL)
        return root;
    if (root->data > k) {
        root->left = deletenode(root->left, k);
        return root;
    }
    else if (root->data < k) {
        root->right = deletenode(root->right, k);
        return root;
    }
    if (root->left == NULL) {
        BST* temp = root->right;
        delete root;
        return temp;
    }
    else if (root->right == NULL) {
        BST* temp = root->left;
        delete root;
        return temp;
    }
    else {
 
        BST* succParent = root;
        BST* succ = root->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }
        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;
        root->data = succ->data;
        delete succ;
        return root;
    }
}
void BST::displaybfs(BST* root) 
{ 
    int h = findheight(root); 
    int i; 
    for (i = 1; i <= h; i++) 
        displayLevel(root, i); 
} 
void BST::displayLevel(BST* root, int level) 
{ 
    if (root == NULL) 
        return; 
    if (level == 1) 
        cout << root->data << " "; 
    else if (level > 1) 
    { 
        displayLevel(root->left, level-1); 
        displayLevel(root->right, level-1); 
    } 
} 
void BST::displayPreorder(BST* root) 
{ 
    if (root == NULL) 
        return; 
    cout << root->data << " "; 
    displayPreorder(root->left);  
    displayPreorder(root->right); 
}  
void BST::displayPostorder(BST* root) 
{ 
    if (root == NULL) 
        return; 
    displayPostorder(root->left); 
    displayPostorder(root->right); 
    cout << root->data << " "; 
} 
int main()
{
    BST b, *root = NULL;
    int n,i,k,t=1,ch;
    cout<<"Enter the number of elements: ";
    cin>>n;
    cout<<"Enter the values: "<<endl;
    for(i=0;i<n;i++){
    	cin>>k;
    	root=b.Insert(root,k);
	}
	cout<<"Choices :\n";
    cout<<"1.To Insert\n"<<"2.To delete\n"<<"3.To display\n"<<"4.To search\n";
    cout<<"5.To find height\n"<<"6.To Display bfs\n"<<"7.To Display dfs\n"<<"8.To terminate\n";
    while(t){
    	cout<<"Enter your choice: ";
    	cin>>ch;
    	switch(ch){
    		case 1:cout<<"Enter the number: ";cin>>k;root=b.Insert(root,k);
    				break;
    		case 2:cout<<"Enter the number: ";cin>>k;root=b.deletenode(root,k);
    				break;
    		case 3:cout<<"Displaying Inorder traversal: ";b.displayinorder(root);
    				break;
    		case 4:cout<<"Enter the key: ";cin>>k;
					if(b.search(root,k))
					cout<<"It is present";
					else
					cout<<"It is not present";
					break;
			case 5:cout<<"Height of the tree is: "<<b.findheight(root);
					break;
			case 6:cout<<"Displaying bfs :";b.displaybfs(root);
					break;
			case 7:cout<<"Displaying Preorder traversal: ";b.displayPreorder(root);cout<<endl;
				   cout<<"Displaying Inorder traversal: ";b.displayinorder(root);cout<<endl;
				   cout<<"Displaying Postorder traversal: ";b.displayPreorder(root);
				   break;
			case 8:t=0;
					break;
			default: cout<<"Invaid choice try again";
		}
		cout<<endl;
	}
    return 0;
}