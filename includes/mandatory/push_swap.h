/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:53:40 by roglopes          #+#    #+#             */
/*   Updated: 2024/03/15 18:48:54 by roglopes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/**
 * @brief Includes librarys for program.
 * 
 * @include stdbool -> To use bool flags, e.g, to print or not to print.
 * @include limits  -> To define MIN and MAX macros.
 * @include libft   -> Library Libft created at 42.
*/
# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include "../../libft/include/libft.h"

/**
 * @brief Used for some project definitions.
 * 
 * @param nbr The number to sort.
 * @param index The number's position in the stack.
 * @param push_cost How many commands in total.
 * @param above_median Used to calculate `push_cost`.
 * @param cheapest The node that is the cheapest to do commands.
 * @param target_node The target node of a node in the opposite stack.
 * @param next A pointer to the next node.
 * @param prev A pointer to previous node.
*/
typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}				t_stack_node;

/**
 * @brief Handles syntax errors in a string representing a number.
 * 
 * This function checks for syntax errors in the input string `str_n` 
 * representing a number. It returns `1` (error) if any of the following
 * conditions are met:
 * - The first character of the string does not contain a sign or a digit.
 * - The first character contains a sign, but the second character does not
 *   contain a digit.
 * - Any character in the string other than the first is not a digit.
 * 
 * @param str_n Input string representing a number.
 * @return `1` if a syntax error is detected, `0` otherwise.
 */
int				ft_error_syntax(char *str_n);

/**
 * @brief Checks for duplicate numbers in stack `a`.
 * 
 * This function iterates through each node in stack `a` and checks if
 * the value `n` already exists in the stack. If a node with the same value
 * as `n` is found, the function returns `1` (indicating a duplicate).
 * Otherwise, it returns `0`.
 * 
 * @param a Pointer to the start of stack `a`.
 * @param n The number to check for duplication.
 * @return `1` if a duplicate is found, `0` otherwise.
 */
int				ft_error_duplicate(t_stack_node *a, int n);

/**
 * @brief Frees all nodes in a stack to prevent memory leaks.
 * 
 * Iterates through the stack, freeing each node to release the memory
 * allocated to it.
 * This is typically used to clean up memory in case of errors or when
 * the program finishes using the stack.
 * It sets each node's value to `0` before freeing, which is a good 
 * practice for debugging purposes.
 * 
 * @param stack Pointer to the pointer of the first node in the stack.
 * The function sets the stack pointer to `NULL` after freeing all nodes.
 */
void			ft_free_stack(t_stack_node **stack);

/**
 * @brief Frees the stack and prints an error message before exiting 
 * the program.
 * 
 * This function is called when an unrecoverable error is encountered.
 * It ensures that any allocated memory for the stack is properly freed
 * to prevent memory leaks. After freeing the memory, it prints a generic
 * error message to the standard output and then terminates
 * the program with an exit status of `1`, indicating an error condition.
 * 
 * @param a Pointer to the pointer of the first node in the stack `a`.
 * This stack will be freed.
 */
void			ft_free_errors(t_stack_node **a, char **argv, bool argc_2);

/**
 * @brief Initializes a stack with values passed as arguments and checks 
 * for errors.
 * This function initializes a stack with integer values passed as 
 * arguments in the  provided array of strings. It checks for syntax 
 * errors, integer overflow, and duplicate values, freeing any errors 
 * encountered.
 * 
 * @param a Pointer to a pointer to the head of the stack.
 * @param argv Array of strings containing integer values to 
 * initialize the stack.
 */
void			ft_init_stack_a(t_stack_node **a, char **argv, bool argc_2);
/**
 * @brief Function to handle input of numbers as a string argument,
 *  e.g. enclosed in " "
 * @param s string for split.
 * @param c delimiter for split string.
 * 
 * @return Array from string.
*/
char			**ft_split_push_swap(char *s, char c);

/**
 * @brief Converts a string to a long integer value.
 * This function iterates over the input string, ignoring 
 * leading whitespace characters.
 * It supports positive and negative numbers by detecting a '+' or '-' sign. 
 * The function converts the sequence of digit characters in the string to 
 * a numerical long value, taking into account the sign. Non-digit characters 
 * at the beginning are ignored, and the conversion stops at the first non-digit 
 * character.
 * 
 * @param s Pointer to the string that is to be converted.
 * @return The long integer result of the conversion.
 */
long			ft_atol(const char *s);

/**
 * @brief Combines all functions needed to prepare stack `a` and `b`.
 * 
 * This function combines multiple functions required to prepare stack `a` and
 * `b` for pushing and sorting. These functions set the data inside the node's
 * structure and perform necessary analysis to optimize sorting.
 * 
 * @param a Pointer to the start of stack `a`.
 * @param b Pointer to the start of stack `b`.
 */
void			ft_init_nodes(t_stack_node *a, t_stack_node *b);

/**
 * @brief Updates the index and median position for each node in the stack.
 * 
 * This function iterates through each node in the stack, assigning an index
 * to each one, starting from 0. It also calculates the median position of the
 * stack and marks each node as being above or below this median based on their
 * position. This helps in decision-making for sorting algorithms that require
 * knowledge of a node's position relative to the median.
 * 
 * @param stack Pointer to the start of the stack.
 */
void			ft_current_index(t_stack_node *stack);

/**
 * @brief Sets the `cheapest` attribute for a node in the stack.
 * 
 * This function iterates through each node in the stack, comparing their
 * push costs to find the node with the lowest cost. It then sets the 
 * `cheapest` attribute of that node to `true` in the data structure. 
 * The `cheapest` attribute is used for optimization
 * purposes in sorting algorithms to identify the node with the lowest cost.
 * 
 * @param stack Pointer to the start of the stack.
 */
void			ft_set_cheapest(t_stack_node *stack);

/**
 * @brief Searches for and returns the cheapest node in the stack.
 * 
 * Iterates through the stack to find a node marked as the cheapest based 
 * on a predefined criterion (e.g., cost of operations).
 * The 'cheapest' flag is a boolean attribute of each node indicating 
 * whether it is the least costly option.
 * 
 * @param stack Pointer to the top node of the stack.
 * @return Pointer to the cheapest node if found, NULL otherwise.
 */
t_stack_node	*ft_get_cheapest(t_stack_node *stack);

/**
 * @brief Moves the required node to the top of the stack.
 * 
 * This function continuously rotates or reverse rotates the stack until 
 * the specified node is at the top. It checks whether the specified 
 * node is above or below the median and rotates the stack accordingly 
 * to ensure the node ends up at the top.
 * 
 * @param stack Pointer to the pointer of the top node in the stack.
 * @param top_node Pointer to the node that needs to be moved to the top.
 * @param stack_name Indicates the name of the stack ('a' or 'b').
 */
void			ft_prep_for_push(t_stack_node **s, t_stack_node *n, char c);

/**
 * @brief Finds the target node in stack `b` for each node in stack `a`.
 * 
 * This function iterates through each node in stack `a` and searches for
 * the closest smaller number in stack `b`. For each node in `a`, it finds
 * the node in `b` that is smaller than the current node in `a` but closest
 * to it in value. If no such node is found, it selects the largest node in
 * `b` as the target. The target node for each node in `a` is stored within
 * the node structure.
 * 
 * @param a Pointer to the start of stack `a`.
 * @param b Pointer to the start of stack `b`.
 */
void			ft_set_target(t_stack_node *a, t_stack_node *b);

/**
 * @brief Analyzes the cost of each node in stack `a` with its target
 * node in stack `b`.
 * 
 * This function calculates the cost of pushing each node in stack `a` to 
 * the top of its stack, taking into account the number of instructions
 * required for rotation. For each node in `a`, it calculates the push cost
 * based on its index and the position of its target node in stack `b`.
 * The push cost is the sum of the node's index and the number of instructions
 * needed for rotation to reach its target node. The analysis helps optimize 
 * sorting algorithms by considering the relative positions of nodes in both 
 * stacks.
 * 
 * @param a Pointer to the start of stack `a`.
 * @param b Pointer to the start of stack `b`.
 */
void			ft_cost_analysis(t_stack_node *a, t_stack_node *b);

/**
 * @brief Appends a new node with a given integer value to the end of a stack.
 * This function creates a new stack node with the specified integer value `n`
 * and appends it to the end of the stack pointed to by `stack`. If the stack 
 * is empty, the new node becomes the first element of the stack. Each new node
 * is dynamically allocated and initialized with `n` as its value and its `next`
 * pointer set to NULL.
 * If the stack already contains nodes, the function finds the last node and 
 * updates its `next` pointer to point to the new node, effectively appending 
 * it to the stack.
 * The new node's `prev` pointer is set to the last node of the stack,
 *  establishing a double-link between the last node and the new node.
 * 
 * @param stack Double pointer to the head of the stack.
 * @param n The integer value to store in the new node.
 */
void			ft_append_node(t_stack_node **stack, int n);

/**
 * @brief Calculates the length of a stack.
 * 
 * This function counts the number of nodes in the stack and returns 
 * the total length.
 * It iterates through each node in the stack, incrementing a counter until 
 * the end of the stack is reached. If the stack is empty, it returns `0`.
 * 
 * @param stack Pointer to the start of the stack.
 * @return `count` - The length of the stack.
 */
int				ft_stack_len(t_stack_node *stack);

/**
 * @brief Checks if a stack is sorted in ascending order.
 * 
 * This function takes a pointer to the head of a stack and iterates through 
 * its elements to determine if they are sorted in ascending order. It 
 * returns true if the stack is sorted in ascending order, indicating that
 * each element is less than or equal to the next element in the stack.
 * If the stack is empty  or if any element is greater than the next
 * element, the function returns false.
 * 
 * @param stack Pointer to the head of the stack to be checked.
 * @return True if the stack is sorted in ascending order, otherwise false.
 */
bool			ft_stack_sorted(t_stack_node *stack);

/**
 * @brief Finds and returns the last node in the stack.
 * 
 * This function iterates through the stack until it reaches the last node.
 * It checks if the stack is empty at the beginning; if so, it returns NULL.
 * Otherwise, it loops through the stack by following the `next` pointers
 * until it finds a node where `next` is NULL, indicating the last node in
 * the stack.
 * 
 * @param stack Pointer to the top node of the stack.
 * @return Pointer to the last node in the stack, or NULL if the stack is empty.
 */
t_stack_node	*ft_find_last(t_stack_node *stack);

/**
 * @brief Finds and returns the node with the minimum value in the stack.
 * 
 * This function iterates through the stack to find the node with the smallest
 * value. It initializes two variables, `min` with the maximum long integer
 * value to ensure any node's value will be smaller, and `min_node` to store the
 * pointer to the node with the minimum value found so far. It then compares each
 * node's value with `min` and updates `min` and `min_node` accordingly.
 * 
 * @param stack Pointer to the top node of the stack.
 * @return Pointer to the node with the minimum value found, or NULL
 * if the stack is empty.
 */
t_stack_node	*ft_find_min(t_stack_node *stack);

/**
 * @brief Finds and returns the node with the maximum value in the stack.
 * 
 * This function iterates through the stack to find the node with the highest
 * value. It initializes two variables, `max` with the minimum long integer
 * value to ensure any node's value will be greater, and `max_node` to store
 * the pointer to the node with the maximum value found so far. It then 
 * compares each node's value with `max` and updates `max` and `max_node`
 * accordingly.
 * 
 * @param stack Pointer to the top node of the stack.
 * @return Pointer to the node with the maximum value found, or 
 * NULL if the stack is empty.
 */
t_stack_node	*ft_find_max(t_stack_node *stack);

/**
 * @brief Rotates both the top nodes of stacks `a` and `b` to the 
 * bottom if it's the cheapest move.
 * 
 * This function continuously rotates the top nodes of stacks `a` and `b` 
 * to the bottom until the current top node of stack `b` matches the 
 * target node of the cheapest node in stack `a`, and the current top
 * node of stack `a` matches the cheapest node. This rotation is performed
 * if it's the cheapest move to reach the desired configuration, as 
 * determined by the `cheapest_node` parameter.
 * After rotation, it updates the indices of both stacks.
 * 
 * @param a Pointer to the pointer of the top node in stack `a`.
 * @param b Pointer to the pointer of the top node in stack `b`.
 * @param cheapest_node Pointer to the cheapest node in stack `a`.
 */
void			ft_rotate_both(t_stack_node **a, t_stack_node **b, \
								t_stack_node *cheapest_node);

/**
 * @brief Reverse rotates both the bottom nodes of stacks `a` and
 * `b` to the top if it's the cheapest move.
 * 
 * This function continuously reverse rotates the bottom nodes of stacks
 * `a` and `b` to the top until the current bottom node of stack `b`
 * matches the target node of the cheapest node in stack `a`, and the
 * current bottom node of stack `a` matches the cheapest node.
 * This reverse rotation is performed if it's determined to be the
 * cheapest move to reach the desired configuration, based on the 
 * `cheapest_node` parameter.
 * After reverse rotation, it updates the positions of nodes in both stacks.
 * 
 * @param a Pointer to the pointer of the top node in stack `a`
 * (since the stack is treated as circular, allowing bottom to top rotation).
 * @param b Pointer to the pointer of the top node in stack `b`
 * (same circular logic applies).
 * @param cheapest_node Pointer to the cheapest node in stack `a`, 
 * influencing the decision to reverse rotate.
 */
void			ft_rev_rotate_both(t_stack_node **a, t_stack_node **b, \
									t_stack_node *cheapest_node);

/**
 * @brief Prepares the cheapest nodes on top of stacks `a` and `b`
 * for pushing `a` nodes to stack `b`.
 * 
 * This function ensures that the cheapest nodes from stack `a` and 
 * their corresponding target nodes from stack `b` are positioned
 * at the top of their respective stacks. It determines the cheapest
 * node in stack `a`, rotates both stacks if necessary to optimize 
 * the push operation, and then pushes the cheapest
 * node from stack `a` to stack `b`.
 * It continues this process until only three nodes remain in stack `a`.
 * After each operation, it ensures the top nodes of both stacks are
 * prepared for pushing.
 * 
 * @param a Pointer to the pointer of the top node in stack `a`.
 * @param b Pointer to the pointer of the top node in stack `b`.
 */
void			ft_move_a_to_b(t_stack_node **a, t_stack_node **b);

/**
 * @brief Moves the smallest number to the top of stack `a`.
 * 
 * This function continuously rotates or reverse rotates stack `a` until
 * the smallest number is at the top. It checks the position of the
 * smallest number relative to the median and rotates accordingly to
 * ensure the smallest number ends up at the top of the stack.
 * 
 * @param a Pointer to the pointer of the top node in stack `a`.
 */
void			ft_min_on_top(t_stack_node **a);

/**
 * @brief Sorts a stack with three nodes.
 * 
 * This function handles the sorting of a stack when it contains three nodes.
 * It identifies the node with the highest value in stack `a` and performs
 * the necessary operations to sort the stack. If the node with the highest
 * value is at the top of the stack, it is rotated to the bottom. If it is at
 * the bottom, it is reverse-rotated to the top. If the node with the highest
 * value is in the middle of the stack, the function rearranges the nodes to
 * ensure the stack is in ascending order.
 * 
 * @param a Pointer to the pointer to the start of the stack to be sorted.
 */
void			ft_sort_three(t_stack_node **a);

/**
 * @brief ft_sort_five - Handles the sorting of a stack when its length
 * is exactly 5. It pushes the two smallest elements to stack `b` to simplify
 * the sorting of stack `a` to just 3 elements, which can be easily sorted
 * with minimal operations.
 * 
 * @param a Pointer to the top node of stack `a`, which contains the
 * elements to be sorted.
 * @param b Pointer to the top node of stack `b`, used temporarily to
 * hold elements during the sorting process.
 */
void			ft_sort_five(t_stack_node **a, t_stack_node **b);

/**
 * @brief Sorts stack `a` if it contains more than 3 nodes, 
 * using stack `b` as an intermediary.
 * 
 * This function orchestrates the sorting of stack `a` for cases where
 * it contains more than three nodes and they are not already sorted.
 * It employs a series of steps including transferring nodes from
 * stack `a` to `b` if `a` is not sorted and has more than three nodes.
 * The process involves initializing all nodes from both stacks, moving
 * the most cost-effective `a` nodes to a sorted stack `b` until only three 
 * nodes are left in `a`, sorting those three nodes, and then moving all
 * nodes from `b` back to `a` in a sorted manner. 
 * The function ensures the smallest number is on top of stack `a`
 * upon completion.
 * 
 * @param a Pointer to the pointer to the start of stack `a`.
 * @param b Pointer to the pointer to the start of stack `b`.
 */
void			ft_sort_stacks(t_stack_node **a, t_stack_node **b);

/**
 * @brief Frees memory allocated for an array of strings and
 * the array itself.
 * 
 * This function frees the memory allocated for each string
 * in the array pointed to by argv, and then frees the memory
 * allocated for the array itself.
 * 
 * @param argv A pointer to a pointer to the first element
 * of the array of strings.
 */
void			ft_free_argc(char **argv);

/**
 * @brief swap - Swaps the positions of the top two nodes in a stack.
 * If the stack has fewer than two nodes, no action is taken.
 *
 * @param head Pointer to the pointer of the top node of the stack.
 */
void			ft_swap(t_stack_node **head);

/**
 * @brief sa - Swaps the first two nodes at the top of stack `a`
 * and optionally prints the operation.
 *
 * @param a Pointer to the pointer of the top node of stack `a`.
 * @param print Boolean indicating whether to print the operation.
 */
void			ft_sa(t_stack_node **a, bool print);

/**
 * @brief sb - Swaps the first two nodes at the top of stack `b`
 * and optionally prints the operation.
 *
 * @param b Pointer to the pointer of the top node of stack `b`.
 * @param print Boolean indicating whether to print the operation.
 */
void			ft_sb(t_stack_node **b, bool print);

/**
 * @brief ss - Simultaneously swaps the first two nodes at the top of both
 * stack `a` and stack `b`, and optionally prints the operation.
 *
 * @param a Pointer to the pointer of the top node of stack `a`.
 * @param b Pointer to the pointer of the top node of stack `b`.
 * @param print Boolean indicating whether to print the operation.
 */
void			ft_ss(t_stack_node **a, t_stack_node **b, bool print);

/**
 * @brief rotate - Rotates the top node of the stack to the bottom.
 * If the stack has fewer than two nodes, no action is taken.
 *
 * @param stack Pointer to the pointer of the top node of the stack.
 */
void			ft_rotate(t_stack_node **stack);

/**
 * @brief ra - Rotates the top node of stack `a` to the bottom
 * and optionally prints the operation.
 *
 * @param a Pointer to the pointer of the top node of stack `a`.
 * @param print Boolean indicating whether to print the operation.
 */
void			ft_ra(t_stack_node **a, bool print);

/**
 * @brief rb - Rotates the top node of stack `b` to the bottom and
 * optionally prints the operation.
 *
 * @param b Pointer to the pointer of the top node of stack `b`.
 * @param print Boolean indicating whether to print the operation.
 */
void			ft_rb(t_stack_node **b, bool print);

/**
 * @brief rr - Simultaneously rotates the top nodes of both stack `a`
 * and `b` to the bottom and optionally prints the operation.
 *
 * @param a Pointer to the pointer of the top node of stack `a`.
 * @param b Pointer to the pointer of the top node of stack `b`.
 * @param print Boolean indicating whether to print the operation.
 */
void			ft_rr(t_stack_node **a, t_stack_node **b, bool print);

/**
 * @brief rev_rotate - Rotates the bottom node of the stack to the top.
 * If the stack has fewer than two nodes, no action is taken.
 *
 * @param stack Pointer to the pointer of the top node of the stack.
 */
void			ft_rev_rotate(t_stack_node **stack);

/**
 * @brief rra - Rotates the bottom node of stack `a` to the top and
 * optionally prints the operation.
 *
 * @param a Pointer to the pointer of the top node of stack `a`.
 * @param print Boolean indicating whether to print the operation.
 */
void			ft_rra(t_stack_node **a, bool print);

/**
 * @brief rrb - Rotates the bottom node of stack `b` to the top
 * and optionally prints the operation.
 *
 * @param b Pointer to the pointer of the top node of stack `b`.
 * @param print Boolean indicating whether to print the operation.
 */
void			ft_rrb(t_stack_node **b, bool print);

/**
 * @brief rrr - Simultaneously rotates the bottom nodes of both
 * stack `a` and `b` to the top and optionally prints the operation.
 *
 * @param a Pointer to the pointer of the top node of stack `a`.
 * @param b Pointer to the pointer of the top node of stack `b`.
 * @param print Boolean indicating whether to print the operation.
 */
void			ft_rrr(t_stack_node **a, t_stack_node **b, bool print);

/**
 * @brief push - Pushes the top node from one stack (src) to the top of
 * another stack (dst).
 * If the source stack is empty, no action is performed.
 *
 * @param dst Pointer to the pointer of the top node of the destination stack.
 * @param src Pointer to the pointer of the top node of the source stack.
 */
void			ft_push(t_stack_node **dst, t_stack_node **src);

/**
 * @brief pa - Transfers the top node from stack `b` to the top of stack `a`
 * and optionally prints the operation "pa".
 *
 * @param a Pointer to the pointer of the top node of stack `a`.
 * @param b Pointer to the pointer of the top node of stack `b`.
 * @param print Boolean indicating whether to print the operation.
 */
void			ft_pa(t_stack_node **a, t_stack_node **b, bool print);

/**
 * @brief pb - Transfers the top node from stack `a` to the top of stack `b`
 * and optionally prints the operation "pb".
 *
 * @param b Pointer to the pointer of the top node of stack `b`.
 * @param a Pointer to the pointer of the top node of stack `a`.
 * @param print Boolean indicating whether to print the operation.
 */
void			ft_pb(t_stack_node **b, t_stack_node **a, bool print);
#endif