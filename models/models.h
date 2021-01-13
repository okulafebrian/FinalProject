struct data{
  char title[255];
  char desc[255];
  char ingr[100][255];
  char inst[100][255];
  char prepTime[100];
  char cookTime[100];
  int count1, count2;
};

struct Node1{
  char name[255];
  Node1 *next, *prev;
};

struct Node{
  char title[255];
  char desc[255];
  char prepTime[100];
  char cookTime[100];
  Node *next, *prev;
  Node1 *list1, *head1, *tail1, *list2, *head2, *tail2;   // 1: Ingredients   2: Instructions
} *headA, *tailA, *headB, *tailB, *curr;    // A: Recipe    B: Queue

