#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//set up node struct
struct node { 
  int i; 
  struct node *next; 
};


//function headers
void print_list(struct node *);
struct node* insert_front(struct node *, int);
struct node* free_list(struct node *);

//main function
int main(){
  //make new node and set values
  struct node * nums = malloc(sizeof(struct node));;
  nums->i = 1;
  nums->next = NULL;

  //test node functions
  print_list(nums);
  printf("\n");
  nums = insert_front(nums, 2);
  print_list(nums);
  printf("\n");
  nums = insert_front(nums, 3);
  print_list(nums);
  printf("\n");
  nums = insert_front(nums, 4);
  print_list(nums);
  printf("\n");
  nums = free_list(nums);
  print_list(nums);
}

//other functions
void print_list(struct node * n){
  struct node * temp = n; //make copy of given list/node

  if(temp == NULL)
    printf("NULL\n");
  
  while (temp) { 
    printf("%d\n", temp->i); //print out the int in the current node
    temp = temp->next; //set current node to the next
  }
}

struct node* insert_front(struct node * n, int i){
  struct node * front = malloc( sizeof(struct node) ); //make new front node
  front->i = i; //set the int val for front
  front->next = n; //set the next node to the original node
  return front;  
}

struct node* free_list(struct node * n){
  struct node * temp = n;
  while(temp){ //while temp != NULL
    free(temp);
    temp = temp->next;
  }
  return temp;
}
