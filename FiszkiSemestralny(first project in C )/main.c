 //
 //  main.c
 //  TestProjektSemestralnyAngielski
 //
 //  Created by Patryk Piwowarczyk on 28/11/2019.
 //  Copyright © 2019 Patryk Piwowarczyk. All rights reserved.
 //
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #define PLword 50
 #define pusty 0
 #define ENGword 50
 #define INITSIZE 3
 #define MAXSIZE 100
 #include <stdio.h>
 #include <stdlib.h>
 
 #include <time.h>


 void options(void);
 void start(void);
 void score(void);
 void optionz(void);
 void author(void);
 void pexit(void);
 void menustructure(void);
 int submenuauthors(void);
 void howtoplay(void);
 int gamestartt(void);
 void game(void);
 void optionss(void);



     int main(void)
     {
         menustructure();
       return 0;
     }
        



 void menustructure()
 {
 char option;

 while (1) {
           printf("          ****Your English Learning Index Cards****\n\n");
           printf("Enter 1-5 of the following options: \n\n");
           options();
           scanf("%c", &option);
       
           switch (option) {
               case '1':
                   game();
                   break;
               case '2':
                   howtoplay();
                   break;
               case '3':
                   optionss();
                   
                   break;
               case '4':
                   author();
                   break;
               case '5':
                   pexit();
                   break;
               default:
                   printf("\n ============================================================ \n");
                   printf("\n Please insert number ranging from 1-5 though... No cheating! \n");
                   printf(" ============================================================ \n");
                   menustructure();
            
     }
     
     }
     }




     void options()
     {
         printf("1. Start Game \n");
         printf("2. How to play? \n");
         printf("3. Options \n");
         printf("4. Author \n");
         printf("5. Exit \n\n");
         
         printf("I choose: ");
     }

    void author()
    {
   
     char c;
     FILE *authorsFile;
     
     
     if ((authorsFile = fopen("/Users/patrykpiwowarczyk/Desktop/STUDIA/FoCP/Kodowanie/TestProjektSemestralnyAngielski/TestProjektSemestralnyAngielski/authors.txt","r")) == NULL)
     {
         printf("FAILED to read the file, maybe check directory?\n");
         exit(1);
     }

     while ((c = fgetc(authorsFile)) != EOF)
     {
         printf("%c", c);
     }
     
      fclose(authorsFile);
      submenuauthors();
             
     }
     
     
     void pexit()
     {
     
     puts("Your progress has been saved, see you next time.");
     exit(0);
     }


     int submenuauthors()
     {
     while (2) {
  
      printf("\n Press 1 to go back to the menu or 0 to quit the program \n");
         printf("\n I choose: ");
      getchar();
      char optionz;
      scanf("%c", &optionz);
      fflush(stdin);
      switch (optionz) {
      case '1':
          menustructure();
          return 1;
      break;
      case '0':
          
          pexit();
       break;
       default:
      printf("\n\n\n\n ============================================================ \n");
      printf("\n Please insert number ranging from 0-1 though... No cheating! \n");
      printf(" ============================================================ \n\n\n\n \n");
              printf("Press any key to continue... and try again...\n\n\n\n");
              getchar();
              menustructure();
      }
      }
      }

     
 void game(){
     printf("\n\n\n\n ============================================================ \n");
     printf("\nWelcome in your English Index Cards Game!\n Would you like to know the instructions or hop right in?\n \n");
     printf("Press: \n '1' to see instructions \n '2' to start the game \n '0' to exit..\n\n");
     printf(" ============================================================ \n\n\n\n \n");
     fflush(stdin);
     printf("\n I choose: ");
     char option_1;
     while (3) {
     scanf("%c", &option_1);
     
         switch (option_1) {
             case '1':
                howtoplay();
                 break;
             case '2':
                 printf("\n\n\n\n\n\n\n\n");
                 gamestartt();
                 break;
             case '0':
                 menustructure();
                 break;
             default:
                 printf("\n ============================================================ \n");
                 printf("\n Please insert number ranging from 1-2 though... No cheating! \n");
                 printf(" ============================================================ \n");
                 game();
 }
 }
 }

 typedef struct {
     int unit;
     char name[PLword+1];
     char name2[ENGword+1];
     char name3[pusty];
     
 } tlumaczenie_t;

 typedef struct {
     tlumaczenie_t *items;
     int numlines;
  
     
 } allitems_struct;

 allitems_struct *initialize_arraystructs(void);
 void print_arraystructs(allitems_struct *allitems);
 void read_insert_items(FILE *filestream, allitems_struct *allitems);
 void czekerpointera(void *ptr, const char *msg);
 void compare(allitems_struct *allitems);




 void optionss()
 {
     printf("\n As for now there are no options to configure! \n");
     submenuauthors();
 }
 int gamestartt(void) {
     

     
     allitems_struct *allitems;
     FILE *fp;

     fp = fopen("/Users/patrykpiwowarczyk/Desktop/STUDIA/FoCP/Kodowanie/TestProjektSemestralnyAngielski/TestProjektSemestralnyAngielski/Ffile", "r");
     if (fp == NULL) {
         fprintf(stderr, "%s\n", "Error reading file!\n");
         exit(EXIT_FAILURE);
     }

     allitems = initialize_arraystructs();

     read_insert_items(fp, allitems);

     print_arraystructs(allitems);

     compare(allitems);
     return 0;
 }

 void read_insert_items(FILE *filestream, allitems_struct *allitems) {
     int count = 0;
     char line[MAXSIZE];
     char *unit, *name2, *name;
     size_t numitems = INITSIZE;

     allitems->items = malloc(numitems * sizeof(tlumaczenie_t));
     czekerpointera(allitems->items, "Initial Allocation");

     while (fgets(line, MAXSIZE, filestream) != NULL) {
         unit = strtok(line, ".");
         name = strtok(NULL, ".");
         name2 = strtok(NULL, "\n");

         if (count == numitems) {
             numitems *= 2;
             allitems->items = realloc(allitems->items, numitems * sizeof(tlumaczenie_t));
             czekerpointera(allitems->items, "Reallocationn");

         }

         allitems->items[count].unit = atoi(unit);
        strcpy(allitems->items[count].name, name);
         strcpy(allitems->items[count].name2, name2);

         count++;
         allitems->numlines++;
     }
 }

 allitems_struct *initialize_arraystructs(void) {
     allitems_struct *allitems;

     allitems = malloc(sizeof(allitems_struct));
     czekerpointera(allitems, "Initial Allocation");

     allitems->items = NULL;
     allitems->numlines = 0;

     return allitems;
 }

 void print_arraystructs(allitems_struct *allitems) {
     int y;
     
       int
     lower = 1,
     upper = 30,
     count = 10;
       srand(time(0));
     
     int i;
        for (i = 0; i < count; i++) {
            int num = (rand() %
               (upper - lower + 1)) + lower;
          
         printf("%s %s\n",
                
                allitems->items[num].name,
                allitems->items[num].name3);
            
            char dummy[50];
                
       
                
               int result;
              poczatek:
                
                 printf("\n  ^\n / \\ \n  |     Try to translate this word \n");
                 printf("\n Your Answer: \n");
                 scanf("%s", &dummy[50]);
                 result = strcmp(&dummy[50], allitems->items[num].name2);
                 if (result == 0)
                 {
                     
               printf(" \n |Good job! Your answer was right!|\n");
                     printf("  ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n");
            }
                 else{
                     printf("\n |Unfortunately it's not a right answer. Try again...| \n");
                     printf("  ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n");
                     printf("\n Press 1 to continue or 0 to see the answer: \n");
                     char option_1;
                     while (3) {
                     scanf("%c", &option_1);
                     
                         switch (option_1) {
                             case '0':
                                 printf("\n the answer to this question is: \n");
                                 printf ("%s", allitems->items[num].name2);
                                 printf("\n Retype your mistake to continue.\n");
                                 scanf("%i",y);
                                 goto poczatek;
                                 break;
                             case '1':
                                 goto poczatek;

                                 break;
                                         
                 }
            }
            }
        }
 }

     
 

 void czekerpointera(void *ptr, const char *msg) {
     if (!ptr) {
         printf("zero pointers, error: %s\n", msg);
         exit(EXIT_FAILURE);
     }
 }

 void compare(allitems_struct *allitems){
     char dummy[50];
     
     int iter;
     
    int result;
  for (iter = 0; iter < allitems->numlines; iter++)
  {
     poczatek:
      printf("\n Try to translate word number %d \n", iter+1);
      printf("\n Your Answer: \n");
      scanf("%s", &dummy[50]);
      result = strcmp(&dummy[50], allitems->items[iter].name2);
      if (result == 0)
      {
          
    printf(" \n |Good job! Your answer was right!|\n");
          printf("  ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n");
 }
      else{
          printf("\n |Unfortunately it's not a right answer. Try again...| \n");
          printf("  ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n");
          goto poczatek;
         
      }
 }
 }

 void howtoplay(){
     printf("\n Worry not! It is very simple. You will be given a list of words (set up by default by me). Your goal is to guess the translation of each word \n");
     printf("\n There is only ONE simple but VERY important rule - the words you type must be written in CAPS (or the way you typed them in the file)\n");
     printf("\n Keep in mind that you can expand and edit the list of words in the game, just modify the file called FILE.txt included in the program. \n");
     submenuauthors();
 }


