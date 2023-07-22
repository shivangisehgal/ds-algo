//not on LC
//TC: O(H) + O(H)
//SC: O(1)

	//predecessor -> value that is just less than key
	//successor -> value just greater than key

vector<int> findPreSuc(binaryTreeNode *root, int key)
{

	binaryTreeNode* temp = root;

	int succ = -1;
	int pred = -1;

	//successor
	while(temp)
	{
		if(temp->data <= key)
			temp = temp->right;
		
		else
		{
			succ = temp->data;
			temp = temp->left;
		}
	}

	temp = root;

	//predecessor
	while(temp)
	{
		if(temp->data >= key)
			temp = temp->left;
		
		else
		{
			pred = temp->data;
			temp = temp->right;
		}
	}

	return {pred, succ};
}
