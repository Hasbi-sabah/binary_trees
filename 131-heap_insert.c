#include "binary_trees.h"

/**
 * createQueue - create a queue
 * Return: queue
 */
queue_t *createQueue()
{
	queue_t *queue = (queue_t *)malloc(sizeof(queue_t));

	queue->head = NULL;
	queue->tail = NULL;
	return (queue);
}

/**
 * enqueue - add a new node to the queue
 * @queue: queue
 * @node: node to queue
 */
void enqueue(queue_t *queue, heap_t *node)
{
	queueNode_t *newNode = (queueNode_t *)malloc(sizeof(queueNode_t));

	newNode->node = node;
	newNode->next = NULL;

	if (queue->tail == NULL)
	{
		queue->head = newNode;
		queue->tail = newNode;
		return;
	}
	queue->tail->next = newNode;
	queue->tail = newNode;
}


/**
 * dequeue - pop the head of the queue
 * @queue: queue
 * Return: node poped
 */
heap_t *dequeue(queue_t *queue)
{
	queueNode_t *tmp;
	heap_t *node;

	if (queue->head == NULL)
		return (NULL);

	tmp = queue->head;
	node = tmp->node;
	queue->head = queue->head->next;

	if (queue->head == NULL)
		queue->tail = NULL;

	free(tmp);
	return (node);
}

/**
 * levelorder - traverse a binary tree level by level
 * @tree: tree
 * Return: height
 */
heap_t *levelorder(const heap_t *tree)
{
	queue_t *queue;
	heap_t *current;

	if (tree == NULL)
		return (NULL);

	queue = createQueue();
	enqueue(queue, (binary_tree_t *)tree);

	while (queue->head != NULL)
	{
		current = dequeue(queue);

		if (current->left != NULL)
			enqueue(queue, current->left);
		else
			return (current);
		if (current->right != NULL)
			enqueue(queue, current->right);
		else
			return (current);
	}
	free(queue);
	return (NULL);
}

/**
 * heappa_sort - fix position of inserted node to keep tree a Max Heap
 * @root: Max Heap tree
 * @node: new node
 */
void heappa_sort(heap_t **root, heap_t *node)
{
	heap_t *tmpParent, *tmpLeft = NULL, *tmpRight = NULL;

	if (node->parent == NULL)
	{
		(*root) = node;
		return;
	}
	if (node->parent->n > node->n || (*root)->left == NULL)
		return;
	tmpParent = node->parent, tmpLeft = node->left, tmpRight = node->right;
	if (tmpParent->parent)
	{
		node->parent = tmpParent->parent;
		if (node->parent->left == tmpParent)
			node->parent->left = node;
		else
			node->parent->right = node;
	}
	if (tmpParent->left == node)
	{
		node->left = tmpParent, node->right = tmpParent->right;
		if (tmpParent->right)
			tmpParent->right->parent = node;
	}
	else
	{
		node->right = tmpParent, node->left = tmpParent->left;
		if (tmpParent->left)
			tmpParent->left->parent = node;
	}
	tmpParent->left = NULL, tmpParent->right = NULL;
	if (tmpLeft)
		tmpParent->left = tmpLeft, tmpLeft->parent = tmpParent;
	if (tmpRight)
		tmpParent->right = tmpRight, tmpRight->parent = tmpParent;
	if (tmpParent == (*root))
		*root = node, (*root)->parent = NULL;
	tmpParent->parent = node;
	if (node->parent && node->parent->n < node->n)
		heappa_sort(root, node);
}

/**
 * heap_insert - insert a node in the Heap tree
 * @root: Heap tree
 * @value: value of the new node
 * Return: node to the created node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *pa = NULL, *newNode = NULL;

	if (*root == NULL)
		return (*root = binary_tree_node(NULL, value));

	pa = levelorder(*root);
	newNode = binary_tree_node(pa, value);
	if (pa->left == NULL)
		pa->left = newNode;
	else
		pa->right = newNode;

	heappa_sort(root, newNode);
	return (newNode);
}
