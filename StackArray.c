#include <limits.h> 
#include <stdio.h> 
#include <stdlib.h>
/*The idea of stack is to store elements sequentially in LIFO(Last In First Out)
movement without iterating through elements*/

struct stack
{ // struct stack creation
    int top; //this is used to avoid iterations.. you'll see how..
    unsigned capacity; // we use this here else we will have to pass capacity
                       // in every functions which is tedious
    int* array; //initailly set to null 
}; 


struct stack *create(int a)
{
    //The idea is to create an array using the variable top to traverse through it 
    struct stack *stack = (struct stack*)malloc(sizeof(struct stack)); 
    //allocating *stack a memory in heap of sizeof struct stack 
    stack->top = -1; /*basic idea of stack is to traverse without a loop.. so initially
    top = -1 as array index starts from 0 .... you'll see how it's done....*/ 
    stack->capacity = a; 
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    //allocating complete array size
    return stack; 
}


int isfull(struct stack **stack)
{
    /*when stack is full top will be at n-1 index for array of n elements*/
    return (*stack)->top == (*stack)->capacity - 1;
}


int isempty(struct stack **stack)
{
    /*If stack is empty top will be -1.. that means no array is created yet*/
    return (*stack)->top == -1;
}


void push(struct stack **stack, int a)
{
    /*Checking if array is full or not.. Initially its not that useful to check this..
    But it does help in some error handling efficiently*/
    if(isfull(&(*stack)))
    {
        return;
    }
    else
    { 
        /*pre-increment of top... Well now you see why we did top=-1...
        But we can't use post-increment as then top would remain at -1... and array cannot have -1 */
        (*stack)->array[++(*stack)->top] = a;
        /*that's how we iterate through the array without loops ;)
        (technically speaking push isn't iteration but... for simplicity sake)*/
    }
}


int pop(struct stack **stack)
{
    if(isempty(&(*stack)))
    {
        return -45415454; //safety check
    }
    return (*stack)->array[(*stack)->top--]; 
    /* It's time to decrement top ...
    But here we use post decrement as we want to fetch the data first and then move top down...
    This not only sets top at -1 eventually with decrements... but it prevents the element in 
    stack from being deleted permanently*/
    /*In order to delete an element permanently we can use a pointer and then free()*/
}

int main()
{
    int n,i;
    printf("Enter no of elements \n");
    scanf("%d",&n);
    struct stack *stack = create(n); //Dynamic allocation of memory .. increases efficiency :)
    for(i=0;i<n;i++) /*PS this is iterations for accepting elements from user...You can't completely skip loops though*/
    {
        int element;
        scanf("%d",&element);
        push(&stack,element);
    }
    for(i=0;i<n;i++)
    {
        int element = pop(&stack);
        printf("%d ",element);
    }
    return 0;
}
//that's a lot of COMMENTS :)