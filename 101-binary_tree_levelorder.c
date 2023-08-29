#include "binary_trees.h"


/**
 * createQueue - Create a new queue
 *
 * This function allocates memory for a new queue.
 *
 * Return: A pointer to the newly created queue, or NULL on failure.
 */
queue_t *createQueue()
{
	queue_t *queue = (queue_t *)malloc(sizeof(queue_t));

	queue->head = NULL;
	queue->tail = NULL;
	return (queue);
}

/**
 * enqueue - Add a node to the end of the queue
 * @queue: Pointer to the queue
 * @node: Pointer to the binary tree node to be enqueued
 *
 * This function adds a new node containing the given binary
 * tree node to the end of the queue.
 */
void enqueue(queue_t *queue, binary_tree_t *node)
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
 * dequeue - Remove and return the front node from the queue
 * @queue: Pointer to the queue
 * Return: A pointer to the binary tree node.
 */
binary_tree_t *dequeue(queue_t *queue)
{
	queueNode_t *tmp;
	binary_tree_t *node;

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
 * binary_tree_levelorder - function that goes through a binary
 * tree using level-order traversal
 * @tree: tree
 * @func: prit function
 * Return: height
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t *queue;
	binary_tree_t *current;

	if (tree == NULL)
		return;

	queue = createQueue();
	enqueue(queue, (binary_tree_t *)tree);

	while (queue->head != NULL)
	{
		current = dequeue(queue);
		func(current->n);

		if (current->left != NULL)
			enqueue(queue, current->left);
		if (current->right != NULL)
			enqueue(queue, current->right);
	}

	free(queue);
}
