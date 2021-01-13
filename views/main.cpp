#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../controllers/controllers.h"

void mainMenu(){
  printf("========== WELCOME TO WHISK ==========\n");
  printf("           The Cooking App\n");
  printf("======================================\n");
  puts("");
  
  printf("[1] Home Page\n");
  printf("[2] Cookbook\n");
  printf("[3] Kitchen\n");
  printf("[4] Pantry\n");
  printf("[5] Profile\n");
  printf("[6] Exit\n");
  puts("");

  printf("----------------------------------------\n");
	printf("Press 0 and enter to abort an operation\n");
	printf("----------------------------------------\n");
}

void homePage(){
  puts("");
  printf("==== HOME ==============================\n");
  
  puts("");
} 

void createNewRecipe(){
  puts("");
  printf("----------------------------------------\n");
  printf("Add Recipe\n");
  printf("----------------------------------------\n");
  puts("");

  printf("Press 0 and enter to abort an operation\n");
  puts("");

  bool flag = true;
  while(flag){
    data input;
    char temp[255];

    printf("Title :\n");
    printf(">>");
    scanf("%[^\n]", input.title); getchar();
    if(strcmp(input.title,"0") == 0) return;
    puts("");

    printf("Description :\n");
    printf(">>");
    scanf("%[^\n]", input.desc); getchar();
    if(strcmp(input.desc,"0") == 0) return;
    puts("");

    int count = 0;
    printf("Ingredients :\n");
    printf("* Press 1 and enter to skip an operation\n");
    for(int i=0; i<=100; i++){
      if(i == 100){
        printf("Reach Maximum Input!\n");
        break;
      }
      
      printf(">>");
      scanf("%[^\n]", temp); getchar();
      if(strcmp(temp,"0") == 0) return;

      if(strcmp(temp,"1") == 0){
        input.count1 = count;
        break;
      } else{
        strcpy(input.ingr[i],temp);
        count++;
      }
    }
    puts("");

    count = 0;
    printf("Instructions :\n");
    printf("* Press 1 and enter to skip an operation\n");
    for(int i=0; i<=100; i++){
      if(i == 100){
        printf("Reach Maximum Input!\n");
        break;
      }

      printf("Step %d\n", i+1);
      printf(">>");
      scanf("%[^\n]", temp); getchar();
      if(strcmp(temp,"0") == 0) return;

      if(strcmp(temp,"1") == 0){
        input.count2 = count;
        break;
      } else{
        strcpy(input.inst[i],temp);
        count++;
      }
    }
    puts("");

    printf("Preparation Time :\n");
    printf(">>");
    scanf("%[^\n]", input.prepTime); getchar();
    if(strcmp(temp,"0") == 0) return;
    puts("");

    printf("Cook Time :\n");
    printf(">>");
    scanf("%[^\n]", input.cookTime); getchar();
    if(strcmp(temp,"0") == 0) return;
    puts("");

    printf("Save?  [YES/NO]\n");
    printf(">>");
    scanf("%[^\n]", temp); getchar();
    if(strcmp(temp,"0") == 0) return;

    if(strcmp(temp,"YES") == 0){
      pushRecipe(&input);
      printf("** Saved Successfully **\n");
      puts("");
      return;
    }
  }
}

int main(){
  bool flag = true;

  while(flag){
    mainMenu();

    int select;
    printf(">>");
  	scanf("%d", &select); getchar();

    switch(select){
      case 1:
        //homePage();
        puts("");

        printf("==== HOME ==============================\n");
        puts("");
        break;
      case 2:
        int n;
        while(n != 3){
          puts("");

          printf("==== COOKBOOK ==========================\n");
          puts("");
  
          printf("My Recipes\n");
          displayMyRecipe();
          puts("");

          printf("[1] Create new recipe\n");
          printf("[2] Open the recipe\n");
          printf("[3] Back\n");
          puts("");

          printf(">>");
          scanf("%d", &n); getchar();
          puts("");

          if(n == 1){
            createNewRecipe();
          } else if(n == 2){
            char temp[255];

            printf("Choose the recipe :\n");
            printf(">>");
            scanf("%[^\n]", temp); getchar();
    
            recipePage(temp);
          }
        }
        break;
      case 3:
        puts("");
        printf("==== KITCHEN ===========================\n");
        puts("");

        printf("Cooking List\n");
        displayCookingList();
        puts("");

        char cook[100];
        printf("What're you going to cook today?\n");
        printf(">>");
        scanf("%[^\n]", cook); getchar();
        if(strcmp(cook,"0") == 0) break;

        cookPage(cook);

        break;
      case 4:
        //pantry();
        break;
      case 5:
        return 0;  
    }
  }

  return 0;
}