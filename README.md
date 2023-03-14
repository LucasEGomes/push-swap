# Push_swap
Push swap goal is to sort data on a stack, with limited set of instructions, using the lowest possible number of actions.

# Summary
- [Push\_swap](#push_swap)
- [Summary](#summary)
- [Intro](#intro)
- [Operations](#operations)


# Intro
This project have a set of integer values, 2 stacks, and a set of instructions to manipulate both stacks.  
The set of integer values cannot have a duplicated value.  
The stacks are called A and B.  
The stack A ends with the sorted set of integer values.

# Operations
 - **sa (swap a)**  
  Swap the first 2 elements at the top of **stack A**.  
  Do nothing if there is only one or no elements.
  - **sb (swap b)**  
  Swap the first 2 elements at the top of **stack B**.  
  Do nothing if there is only one or no elements.
  - **ss**  
  **sa** and **sb** at the same time.
  - **pa (push a)**  
  Take the first element at the top of **stack B** and put it at the top of **stack A**
  Do nothing if **stack B** is empty.
  - **pb (push b)**  
  Take the first element at the top of **stack A** and put it at the top of **stack B**
  Do nothing if **stack A** is empty.
  - **ra (rotate a)**  
  Shift up all elements of **stack A** by 1.
  The first element becomes the last one.
  - **rb (rotate b)**  
  Shift up all elements of **stack A** by 1.
  The first element becomes the last one.
  Do nothing if **stack A** is empty.
  - **rr**  
  **ra** and **rb** at the same time.
  - **rra (reverse rotate a)**  
  Shift down all elements of **stack A** by 1.
  The last element becomes the first one.
  - **rrb (reverse rotate b)**  
  Shift down all elements of **stack A** by 1.
  The last element becomes the first one.
  Do nothing if **stack A** is empty.
  - **rrr**  
  **rra** and **rrb** at the same time.