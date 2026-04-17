#include "binary_trees.h"
#include <string.h>

/**
 * get_size - counts the number of nodes in a binary tree
 * @tree: pointer to the root node
 *
 * Return: number of nodes
 */
size_t get_size(binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + get_size(tree->left) + get_size(tree->right));
}

/**
 * find_insert_parent - finds the parent where the new node should be inserted
 * @root: pointer to the root node
 * @node_count: current number of nodes in the tree
 *
 * Return: pointer to the parent node, or NULL on error
 */
binary_tree_t *find_insert_parent(binary_tree_t *root, size_t node_count)
{
	binary_tree_t **queue;
	size_t front, rear;

	if (root == NULL)
		return (NULL);

	queue = malloc(sizeof(binary_tree_t *) * (node_count + 1));
	if (queue == NULL)
		return (NULL);

	front = 0;
	rear = 0;
	queue[rear++] = root;

	while (front < rear)
	{
		binary_tree_t *current = queue[front++];

		if (current->left == NULL || current->right == NULL)
		{
			free(queue);
			return (current);
		}

		if (current->left != NULL)
			queue[rear++] = current->left;
		if (current->right != NULL)
			queue[rear++] = current->right;
	}

	free(queue);
	return (NULL);
}

/**
 * bubble_up - bubbles a node up to maintain max heap property
 * @node: pointer to the node to bubble up
 *
 * Return: pointer to the node after bubbling
 */
binary_tree_t *bubble_up(binary_tree_t *node)
{
	binary_tree_t *current = node;

	while (current->parent && current->n > current->parent->n)
	{
		int temp = current->n;

		current->n = current->parent->n;
		current->parent->n = temp;
		current = current->parent;
	}

	return (current);
}

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the heap
 * @value: the value to store in the node to be inserted
 *
 * Return: pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new;
	heap_t *parent;
	size_t node_count;

	if (root == NULL)
		return (NULL);

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	node_count = get_size(*root);
	parent = find_insert_parent(*root, node_count);

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent->left == NULL)
		parent->left = new;
	else
		parent->right = new;

	return (bubble_up(new));
}
