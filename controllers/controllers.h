#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../models/models.h"

Node *createNode(data **input){
  Node *temp = (Node*)malloc(sizeof(Node));
  strcpy(temp->title, (*input)->title);
  strcpy(temp->desc, (*input)->desc);
  strcpy(temp->prepTime, (*input)->prepTime);
  strcpy(temp->cookTime, (*input)->cookTime);
  temp->next = temp->prev = NULL;
  return temp;
}

Node *createNode2A(Node **currTemp, const char *name){
  Node *temp = *currTemp;
  temp->list1 = (Node1*)malloc(sizeof(Node1));

  strcpy(temp->list1->name, name);
  temp->list1->next = temp->list1->prev = NULL;
  return temp;
}

Node *createNode2B(Node **currTemp, const char *name){
  Node *temp = *currTemp;
  temp->list2 = (Node1*)malloc(sizeof(Node1));

  strcpy(temp->list2->name, name);
  temp->list2->next = temp->list2->prev = NULL;
  return temp;
}

Node *createNode3(Node **currTemp){
  Node *temp = (Node*)malloc(sizeof(Node));
  temp = *currTemp;
  temp->next = temp->prev = NULL;
  return temp;
}


void push1(Node **temp1, data **input){
  for(int i=0; i<(*input)->count1; i++){
    Node *temp = createNode2A(&*temp1, (*input)->ingr[i]);

    if(!temp->head1){
      temp->head1 = temp->tail1 = temp->list1;
    } else{
      temp->tail1->next = temp->list1;
      temp->list1->prev = temp->tail1;
      temp->tail1 = temp->list1;
    }
  }
}

void push2(Node **temp1, data **input){
  for(int i=0; i<(*input)->count2; i++){
    Node *temp = createNode2B(&*temp1, (*input)->inst[i]);

    if(!temp->head2){
      temp->head2 = temp->tail2 = temp->list2;
    } else{
      temp->tail2->next = temp->list2;
      temp->list2->prev = temp->tail2;
      temp->tail2 = temp->list2;
    }
  }
} 

void pushRecipe(data *input){
  Node *temp = createNode(&input);

  if(!headA){
    headA = tailA = temp;
  } else{
    tailA->next = temp;
    temp->prev = tailA;
    tailA = temp;
  }

  push1(&temp,&input);
  push2(&temp,&input);
}

void pushQueue(Node **temp1){
  Node *temp = createNode3(&*temp1);

  if(!headB){
    headB = tailB = temp;
  } else{
    tailA->next = temp;
    temp->prev = tailA;
    tailA = temp;
  }
}

// void popHead(){
//   if(!head){
//     return;
//   } else if(head == tail){
//     free(head);
//     head = tail = NULL;
//   } else{
//     Node *temp = head->next;
//     head->next = temp->prev = NULL;
//     free(head);
//     head = temp;
//   }
// }

// void popTail(){
//   if(!head){
//     return;
//   } else if(head == tail){
//     free(head);
//     head = tail = NULL;
//   } else{
//     Node *temp = tail->prev;
//     tail->prev = temp->next = NULL;
//     free(tail);
//     tail = temp;
//   }
// }

// void popMid(int value){
//   if(!head){
//     return;
//   } else if(head->value == value){
//     popHead();
//   } else if(tail->value == value){
//     popTail();
//   } else{
//     curr = head;

//     while(curr && curr->value != value){
//       curr = curr->next;
//     }

//     curr->prev->next = curr->next;
//     curr->next->prev = curr->prev;
//     curr->next = curr->prev = NULL;
//     free(curr);
//     curr = NULL;
//   }
// }


void displayMyRecipe(){
  Node *curr = headA;
  
  int i = 1;
  while(curr){
    printf("  - %s\n", curr->title);
    curr = curr->next;
    i++;
  }
}

Node *openMyRecipe(const char **name){
  Node *curr = headA;

  while(curr){
    if(strcmp(curr->title, *name) == 0){
      return curr;
    }
    curr = curr->next;
  }
  return 0;
}

void printIngredients(Node *temp){
  Node1 *curr = temp->head1;

  int i = 1;
  while(curr){
    printf("%d. %s\n", i, curr->name);
    curr = curr->next;
    i++;
  }
}

void printInstructions(Node *temp){
  Node1 *curr = temp->head2;

  int i = 1;
  while(curr){
    printf("%d. %s\n", i, curr->name);
    curr = curr->next;
    i++;
  }
}

void recipePage(const char *name){
  Node *temp = openMyRecipe(&name);
  
  puts("");
  printf("%s\n", temp->title);
  printf("----------------------------------------\n");
  puts("");
  
  printf("## %s\n", temp->desc);
  puts("");

  printf("<< Ingredients >>\n");
  printIngredients(temp);
  puts("");

  printf("<< Instructions >>\n");
  printInstructions(temp);
  puts("");

  char input[100];
  printf("Cook this meal?   [YES/NO]\n");
  scanf("%[^\n]", input); getchar();

  if(strcmp(input,"YES") == 0){
    pushQueue(&temp);
    printf("** Add To Cooking List **\n");
    puts("");
    return;
  }
}

void displayCookingList(){
  Node *curr = headB;
  
  int i = 1;
  while(curr){
    printf("  - %s\n", curr->title);
    curr = curr->next;
    i++;
  }
}

Node *checkQueue(const char **name){
  Node *curr = headB;

  while(curr){
    if(strcmp(curr->title, *name) == 0){
      return curr;
    }
    curr = curr->next;
  }
  return 0;
}

void cookPage(const char *name){
  Node *temp = checkQueue(&name);

  printf("----------------------------------------\n");
  printf("Prep Time: %s\n", temp->prepTime);
  printf("Cook Time: %s\n", temp->cookTime);
  puts("");

  printf("Ingredients\n");
  printIngredients(temp);
  puts("");

  char input[100];
  printf("Start?    [YES/NO]\n");
  scanf("%[^\n]", input);

  if(strcmp(input,"YES") == 0){
    printf("======================================\n");
    puts("");
    
    Node1 *curr = temp->head2;

    int i=1;
    while(curr){
      printf("STEP %d\n", i++);
      printf("%s\n", curr->name);
      puts("");
      
      curr = curr->next;
      i++;
    }

    printf("FINISH\n");
  }

}