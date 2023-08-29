#include "binary_trees.h"

typedef struct queueNode
{
	binary_tree_t *node;
	struct queueNode *next;
} queueNode_t;

typedef struct queue_s
{
	struct queueNode *head;
	struct queueNode *tail;
} queue_t;

queue_t *createQueue()
{
	queue_t *queue = (queue_t*)malloc(sizeof(queue_t));

	queue->head = NULL;
	queue->tail = NULL;
	return queue;
}

void enqueue(queue_t *queue, binary_tree_t *node)
{
	queueNode_t *newNode = (queueNode_t*)malloc(sizeof(queueNode_t));
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

binary_tree_t *dequeue(queue_t *queue)
{
	queueNode_t *tmp;
	binary_tree_t *node;

	if (queue->head == NULL)
		return NULL;

	tmp = queue->head;
	node = tmp->node;
	queue->head = queue->head->next;

	if (queue->head == NULL)
		queue->tail = NULL;

	free(tmp);
	return (node);
}

/**
 * binary_tree_levelorder -
 * @tree: tree
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
