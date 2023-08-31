#include "binary_trees.h"


typedef struct queueNode
{
	heap_t *node;
	struct queueNode *next;
} queueNode_t;

typedef struct queue_s
{
	struct queueNode *head;
	struct queueNode *tail;
} queue_t;

/**
 *
 *
 */
queue_t *createQueue()
{
	queue_t *queue = (queue_t*)malloc(sizeof(queue_t));

	queue->head = NULL;
	queue->tail = NULL;
	return queue;
}

void enqueue(queue_t *queue, heap_t *node)
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
	heap_t *node;

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

heap_t *heappa_sort(heap_t **root, heap_t *node)
{
	int tmp;

	if (node->parent == NULL)
	{
		return ((*root) = node);
	}

	if (node->parent->n >= node->n)
		return (node);

	tmp = node->n;
	node->n = node->parent->n;
	node->parent->n = tmp;

	node = heappa_sort(root, node->parent);
	return (node);
}

/**
 *
 *
 *
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

	return (heappa_sort(root, newNode));
}
