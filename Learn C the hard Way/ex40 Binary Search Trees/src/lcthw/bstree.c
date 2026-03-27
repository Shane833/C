#include <lcthw/dbg.h>
#include <lcthw/bstree.h>
#include <stdlib.h>
#include <lcthw/bstrlib.h>

static int default_compare(void* a, void* b)
{
	return bstrcmp((bstring) a, (bstring) b);
}

// Allocates a new tree
BSTree* BSTree_create(BSTree_compare compare)
{
	BSTree* map = calloc(1, sizeof(BSTree));
	check_mem(map);
	
	map->compare = compare == NULL ? default_compare : compare;
	
	return map;

// Destroys
error:
	if(map){
		BSTree_destroy(map);
	}
	return NULL;
}

// Node destroy callbacks
static int BSTree_destroy_cb(BSTreeNode* node)
{
	free(node);
	return 0;
}

void BSTree_destroy(BSTree* map)
{
	if(map){
        // Using the node destroy callback to destroy 
		BSTree_traverse(map, BSTree_destroy_cb);
		free(map);
	}
}

// Helper function for creating the nodes
static inline BSTreeNode* BSTreeNode_create(BSTreeNode* parent, void* key, void* data)
{
	BSTreeNode* node = calloc(1, sizeof(BSTreeNode));
	check_mem(node);
	
	node->key = key;
	node->data = data;
	node->parent = parent;
	return node;

error:
	return NULL;
}

// Recursively compares and adds the nodes to the trees
static inline void BSTree_setnode(BSTree* map, BSTreeNode* node, void* key, void* data)
{
	int cmp = map->compare(node->key, key);
	
	if(cmp <= 0){
		if(node->left){
			BSTree_setnode(map, node->left, key, data);
		} 
		else{
			node->left = BSTreeNode_create(node, key, data);
		}
	}
	else{
		if (node->right){
			BSTree_setnode(map, node->right, key, data);
		}
		else{
			node->right = BSTreeNode_create(node, key, data);
		}
	}
}

int BSTree_set(BSTree* map, void* key, void* data)
{
	if(map->root == NULL){
		// first node, so just make it and get out
		map->root = BSTreeNode_create(NULL, key, data);
		check_mem(map->root);
	}
	else{
        // We start with the root node and sets by recursively comparing it
		BSTree_setnode(map, map->root, key, data);
	}
	
	return 0;
error:
	return -1;
}

// Searching using the binary search 
static inline BSTreeNode* BSTree_getnode(BSTree* map, BSTreeNode* node, void* key)
{
	int cmp = map->compare(node->key, key);
	
	if(cmp == 0){
		return node;
	}
	else if(cmp < 0){
		if(node->left){
			return BSTree_getnode(map, node->left, key);
		}
		else{
			return NULL;
		}
	}
	else{
		if(node->right){
			return BSTree_getnode(map, node->right, key);
		}
		else{
			return NULL;
		}
	}
}

// Searching on the root node
void* BSTree_get(BSTree* map, void* key)
{
	if(map->root == NULL){
		return NULL;
	}
	else{
		BSTreeNode* node = BSTree_getnode(map, map->root, key);
		return node == NULL ? NULL : node->data;
	}
}

// Traverses the tree using the provided callback
static inline int BSTree_traverse_nodes(BSTreeNode* node, BSTree_traverse_cb traverse_cb)
{
	int rc = 0; // returns 0 on success
	
	if(node->left){
		rc = BSTree_traverse_nodes(node->left, traverse_cb);
		if(rc != 0)
			return rc;
	}
	
	if (node->right){
		rc = BSTree_traverse_nodes(node->right, traverse_cb);
		if(rc != 0)
			return rc;
	}
	
	return traverse_cb(node);
}

int BSTree_traverse(BSTree* map, BSTree_traverse_cb traverse_cb)
{
	if(map->root){
		return BSTree_traverse_nodes(map->root, traverse_cb);
	}
	
	return 0;
}

// Traverse to the left most node to find the minimum node
static inline BSTreeNode* BSTree_find_min(BSTreeNode* node)
{
	while(node->left){
		node = node->left;
	}
	
	return node;
}

static inline void BSTree_replace_node_in_parent(BSTree* map, BSTreeNode* node, BSTreeNode* new_value)
{
	if(node->parent){
        // Replacing the node of a parent, be it a left child or a right child
		if(node == node->parent->left){
			node->parent->left = new_value;
		}
		else{
			node->parent->right = new_value;
		}
	}
	else{
		// this is the root so gotta change it
		map->root = new_value;
	}

    // If the new_value node is not null then we can set its parent as the parent of previous node	
	if(new_value){
		new_value->parent = node->parent;
	}
}

// Simple util function for swapping two nodes
static inline void BSTree_swap(BSTreeNode* a, BSTreeNode* b)
{
	void* temp = NULL;
	
	temp = b->key;
	b->key = a->key;
	a->key = temp;
	
	temp = b->data;
	b->data = a->data;
	a->data = temp;
}


static inline BSTreeNode* BSTree_node_delete(BSTree* map, BSTreeNode* node, void* key)
{
	int cmp = map->compare(node->key, key);
	
	if(cmp < 0){
		if(node->left){
			return BSTree_node_delete(map, node->left, key);
		}
		else{
			// not found
			return NULL;
		}
	}
	else if(cmp > 0){
		if(node->right){
			return BSTree_node_delete(map, node->right, key);
		}
		else{
			// not found
			return NULL;
		}
	}
	else{
		if(node->left && node->right){
            // In case, where the node to be deleted have both childs
            // we can replace this node with the max child in the left sub tree
            // or the smallest child in right subtree
            
            // In this case we are finding the minimum node in the right sub tree
            // to replace it with the node to be deleted
			BSTreeNode* successor = BSTree_find_min(node->right);
			BSTree_swap(successor, node);
			
			// this leaves the old successor with possible a right child
			// so replace it with that right child
			BSTree_replace_node_in_parent(map, successor, successor->right);
			
			// finally its swapped, so return successor instead of node
            // as the values of the node have been swapped with the successor
			return successor;
		} // If there is only one child then we can simply replace the current node with its child
		else if(node->left){
			BSTree_replace_node_in_parent(map, node, node->left);
		}
		else if(node->right){
			BSTree_replace_node_in_parent(map, node, node->right);
		}
		else{ // In case of root
			BSTree_replace_node_in_parent(map, node, NULL);
		}
		// In this case, we can simply return the node itself
		return node;
	}
}

void* BSTree_delete(BSTree* map, void* key)
{
	void* data = NULL;
	
	if(map->root){
		BSTreeNode* node = BSTree_node_delete(map, map->root, key);
		
		if(node){
			data = node->data;
			free(node);
		}
	}
	
	return data;
}
