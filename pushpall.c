#include "monty.h"
/**
 * f_push - add node to the stack
 * @head: stack head
 * @counter: line_number
 */
void f_push(stack_t **head, unsigned int counter)
{
	int number, index = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			index++;
		for (; bus.arg[index] != '\0'; index++)
		{
			if (bus.arg[index] > '9' || bus.arg[index] < '0')
				exitWithError(counter);
		}
	}
	else
		exitWithError(counter);

	number = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(head, number);
	else
		addqueue(head, number);
}

/**
 * exitWithError - prints the stack
 * @counter: stack head
 */
void exitWithError(unsigned int counter)
{
	fprintf(stderr, "L%d: usage: push integer\n", counter);
	fclose(bus.file);
	free(bus.content);
	freeStack(*head);
	exit(EXIT_FAILURE);
}

/**
 * f_pall - prints the stack
 * @head: stack head
 * @counter: no used
 */
void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *h = *head;
	(void)counter;

	if (h == NULL)
		return;
	while (h)
		printf("%d\n", h->n);
		h = h->next;
}