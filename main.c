/*_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_- 
* Luna's First Sorting Algorithm Visualizer in C
* 
* 2021/09/11 - LuF-SAVIC V0.0.5 Pre-Alpha
*
* Bugs may be present
*
* Author -- Logan (Luna) N. Willis
* Special thanks to Charlie Ferme for Grate sort.
*_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-*/





#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>

void callStoogeRecurse(int i, int j, int toSort[], int userDelay, int size);
void stooge(int i, int j, int toSort[], int userDelay, int size);
int bubbleSort(int i, int j, int listToSort[], int size, int userDelay);
int sandPaperSort(int i, int j, int listToSort[], int size, int userDelay);
int reverseSandPaperSort(int i, int j, int listToSort[], int size, int userDelay);
int oddEvenSort(int i, int j, int listToSort[], int size, int userDelay);
int cocktailSort(int i, int j, int listToSort[], int size, int userDelay);
int combSort(int i, int j, int listToSort[], int size, int userDelay);
int grateSort(int i, int j, int listToSort[], int size, int userDelay);
void gnomeSort(int i, int j, int listToSort[], int size, int userDelay);
  void delay(int number_of_seconds) {
  // Converting time into milli_seconds
  int milli_seconds = 1000 * number_of_seconds;
  // Storing start time
  clock_t start_time = clock();
  // looping till required time is not achieved
  while (clock() < start_time + milli_seconds) ; }


int main(void) {
  
  printf("\n\nLuF-SAVIC V0.0.5PreAlpha (This is the PreAlpha version so bugs may be present. Very early in Developement.");
  int userInput;
  int a;
  int shuffleType;
  int userDelay;
  printf("\n\nInput your wanted delay in miliseconds -- ");
  scanf("%d", &userDelay);

  printf("\n\nInput list size\n\n");
  scanf("%d", &userInput);

  int mainList[userInput];
  int n = 0;

    while(n < userInput)
  {
    mainList[n] = n;
    n += 1;
  }
  
  n = 0;
  
  printf("\n[%d]", mainList[n]);
  
  n += 1;

  while(n < userInput)
  {
    printf(", [%d]", mainList[n]);
    n += 1;
  }

  printf("  |List Generated|\n");

  printf("\n\nInput the Shuffle you want.\nNormal -- 0  Reversed -- 1\nUnshuffled -- 2  Half sorted -- 3\nLess Shuffled -- 4\n\n");
  scanf("%d", &shuffleType);



  n = 0;
  int i = 0;
  int j = 0;
  int k = userInput - 1;

  if(shuffleType == 0) {
    while(n < userInput - 1)
    {
      i = rand() % (k - n);
      i = i + n + 1;
      j = mainList[i];
      mainList[i] = mainList[n];
      mainList[n] = j;
      n += 1;
    }
  } else if(shuffleType == 1) {
    while(n < ((userInput + 1) / 2) - 1)
    {
      i = userInput - n - 1;
      j = mainList[i];
      mainList[i] = mainList[n];
      mainList[n] = j;
      n += 1;
    }
  } else if(shuffleType == 3) {
    while(n < userInput / 2 - 1)
    {
      i = rand() % (k / 2 - n);
      i = i + n + 1;
      j = mainList[i];
      mainList[i] = mainList[n];
      mainList[n] = j;
      n += 1;
    }
  } else if(shuffleType == 4) {
    while(n < userInput - 1)
    {
      i = rand() % (k - n);
      i = i + n + 1;
      if (rand() % 10 == 1) {
        j = mainList[i];
        mainList[i] = mainList[n];
        mainList[n] = j;
      }
      n += 1;
    }
  }
  n = 0;
  
  printf("\n[%d]", mainList[n]);
  
  n += 1;

  while(n < userInput)
  {
    printf(", [%d]", mainList[n]);
    n += 1;
  }

  printf("  |List Shuffled|\n");

  int sortChosen;

  printf("\nChoose your sort\n\n  0 -- Bubble Sort  1 -- Cocktail Sort  2 -- Comb Sort  3 -- Gnome Sort  4 -- Odd Even Sort  5 -- Grate Sort  6 -- Sandpaper Sort  7 -- Stooge Sort  8 -- Reverse Sandpaper Sort\n\n");
  scanf("%d", &sortChosen);

  if(sortChosen == 0) {
    bubbleSort(i, j, mainList, userInput, userDelay);
  } else if(sortChosen == 1) {
    cocktailSort(i, j, mainList, userInput, userDelay);
  } else if(sortChosen == 2) {
    combSort(i, j, mainList, userInput, userDelay);
  } else if(sortChosen == 3) {
    gnomeSort(i, j, mainList, userInput, userDelay);
  } else if(sortChosen == 4) {
    oddEvenSort(i, j, mainList, userInput, userDelay);
  } else if(sortChosen == 5) {
    grateSort(i, j, mainList, userInput, userDelay);
  } else if(sortChosen == 6) {
    sandPaperSort(i, j, mainList, userInput, userDelay);
  } else if(sortChosen == 7) {
    callStoogeRecurse(0, userInput, mainList, userDelay, userInput);
  } else if(sortChosen == 8) {
    reverseSandPaperSort(i, j, mainList, userInput, userDelay);
  } 
  return 0;
}

int combSort(int i, int j, int listToSort[], int size, int userDelay) {

  printf("    Comb sort\n\n======================\n");
  
  int comps = 0;
  int swaps = 0;
  int done = 0;
  int a = 0;
  int passes = 0;
  int scalar = 1;
  int n = 0;
  

  while(done == 0 || j > i + 1) 
  {
    scalar *= 2;
    i = 0;
    j = size / scalar + 1;
    passes += 1;
    done = 1;

    while(j < size)
    {
      if(listToSort[j] < listToSort[i]) {
        a = listToSort[j];
        listToSort[j] = listToSort[i];
        listToSort[i] = a;
        done = 0;
        swaps += 1;
      }
      i += 1;
      j += 1;
      comps += 1;
      n = 0;

      printf("\n\n[%d]", listToSort[n]);
  
      n += 1;

      while(n < size)
      {
        if(n == i - 1 || n == j - 1){
          printf(", >%d<", listToSort[n]);
          n += 1;
        } else {
          printf(", [%d]", listToSort[n]);
          n += 1;
        }
      }
      delay(userDelay);

    }
    /*n = 0;

    printf("\n[%d]", listToSort[n]);
  
    n += 1;

    while(n < size)
    {
      printf(", [%d]", listToSort[n]);
      n += 1;
    }
    printf("  |Pass %d|, |%d comps|, |%d swaps|", passes, comps, swaps);
    
    */
  }

  n = 0;
  
  printf("\n[%d]", listToSort[n]);
  
  n += 1;

  while(n < size)
  {
    printf(", [%d]", listToSort[n]);
    n += 1;
  }

  printf("  |List Sorted in %d comparisons and %d swaps after %d passes|\n======================\n", comps, swaps, passes);

  return done;
}

int cocktailSort(int i, int j, int listToSort[], int size, int userDelay) {

  printf("    Cocktail sort\n\n======================\n");
  
  int comps = 0;
  int swaps = 0;
  int done = 0;
  int a = 0;
  int passes = 0;
  
  int n = 0;

  while(done == 0) 
  {
    i = 0;
    j = 1;
    passes += 1;
    done = 1;

    while(j < size - 1)
    {
      if(listToSort[j] < listToSort[i]) {
        a = listToSort[j];
        listToSort[j] = listToSort[i];
        listToSort[i] = a;
        done = 0;
        swaps += 1;
      }
      i += 1;
      j += 1;
      comps += 1;
      n = 0;
      if(n == i - 1 || n == j - 1){
          printf("\n\n>%d<", listToSort[n]);
          n += 1;
      } else {
          printf("\n\n[%d]", listToSort[n]);
          n += 1;
      }
      
  
      n += 1;

      while(n < size)
      {
        if(n == i - 1 || n == j - 1){
          printf(", >%d<", listToSort[n]);
          n += 1;
        } else {
          printf(", [%d]", listToSort[n]);
          n += 1;
        }
      }
      delay(userDelay);

    }
    while(i > 0)
    {
      if(listToSort[j] < listToSort[i]) {
        a = listToSort[j];
        listToSort[j] = listToSort[i];
        listToSort[i] = a;
        done = 0;
        swaps += 1;
      }
      i += -1;
      j += -1;
      comps += 1;
      n = 0;

      if(n == i - 1 || n == j - 1){
          printf("\n\n>%d<", listToSort[n]);
          n += 1;
        } else {
          printf("\n\n[%d]", listToSort[n]);
          n += 1;
        }
  
      n += 1;

      while(n < size)
      {
        if(n == i - 1 || n == j - 1){
          printf(", >%d<", listToSort[n]);
          n += 1;
        } else {
          printf(", [%d]", listToSort[n]);
          n += 1;
        }
      }
      delay(userDelay);

    }
   /* n = 0;
  
    printf("\n[%d]", listToSort[n]);
  
    n += 1;

    while(n < size)
    {
      printf(", [%d]", listToSort[n]);
      n += 1;
    }
    printf("  |Pass %d|, |%d comps|, |%d swaps|", passes, comps, swaps); */
  }

  n = 0;
  
  printf("\n\n[%d]", listToSort[n]);
  
  n += 1;

  while(n < size)
  {
    printf(", [%d]", listToSort[n]);
    n += 1;
  }

  printf("  |List Sorted in %d comparisons and %d swaps after %d passes|\n======================\n", comps, swaps, passes);

  return done;
}

void gnomeSort(int i, int j, int listToSort[], int size, int userDelay) {

  printf("    Gnome sort\n\n======================\n");
  
  int comps = 0;
  int swaps = 0;
  int done = 0;
  int a = 0;
  int passes = 0;
  
  int n = 0;

  while(done == 0) 
  {
    i = 0;
    j = 1;
    passes += 1;
    done = 1;

    while(j < size)
    {
      if (listToSort[j] < listToSort[i]) {
        a = listToSort[j];
        listToSort[j] = listToSort[i];
        listToSort[i] = a;
        done = 0;
        swaps += 1;
        if(i > 0) {
        i -= 1;
        j -= 1;
        }
      comps += 1;
      n = 0;
      } else {
      i += 1;
      j += 1;
      comps += 1;
      n = 0;
      }
      delay(userDelay);
      if(n == i - 1 || n == j - 1){
          printf("\n\n>%d<", listToSort[n]);
          n += 1;
      } else {
          printf("\n\n[%d]", listToSort[n]);
          n += 1;
      }
  
      n += 1;

      while(n < size)
      {
       if(n == i - 1 || n == j - 1){
          printf(", >%d<", listToSort[n]);
          n += 1;
        } else {
          printf(", [%d]", listToSort[n]);
          n += 1;
        }
      }
      /**/
    }   done = 1;
  }

  n = 0;
  
  printf("\n\n[%d]", listToSort[n]);
  
  n += 1;

  while(n < size)
  {
    printf(", [%d]", listToSort[n]);
    n += 1;
  }

  printf("  |List Sorted in %d comparisons and %d swaps after %d passes|\n======================\n", comps, swaps, passes);

  return;
}

int bubbleSort(int i, int j, int listToSort[], int size, int userDelay) {

  printf("    Bubble sort\n\n======================\n");
  
  int comps = 0;
  int swaps = 0;
  int done = 0;
  int a = 0;
  int passes = 0;
  
  int n = 0;

  while(done == 0) 
  {
    i = 0;
    j = 1;
    passes += 1;
    done = 1;

    while(j < size)
    {
      if(listToSort[j] < listToSort[i]) {
        a = listToSort[j];
        listToSort[j] = listToSort[i];
        listToSort[i] = a;
        done = 0;
        swaps += 1;
      }
      i += 1;
      j += 1;
      comps += 1;
      n = 0;

      if(n == i - 1 || n == j - 1){
          printf("\n\n>%d<", listToSort[n]);
          n += 1;
      } else {
          printf("\n\n[%d]", listToSort[n]);
          n += 1;
      }
  
      n += 1;

      while(n < size)
      {
        if(n == i - 1 || n == j - 1){
          printf(", >%d<", listToSort[n]);
          n += 1;
        } else {
          printf(", [%d]", listToSort[n]);
          n += 1;
        }
      }
      delay(userDelay);

    }
   // n = 0;
  
   // printf("\n[%d]", listToSort[n]);
  
   // n += 1;

   // while(n < size)
   // {
    //  printf(", [%d]", listToSort[n]);
    //  n += 1;
    //}
    //printf("  |Pass %d|, |%d comps|, |%d swaps|", passes, comps, swaps);
  }

  n = 0;
  
  printf("\n[%d]", listToSort[n]);
  
  n += 1;

  while(n < size)
  {
    printf(", [%d]", listToSort[n]);
    n += 1;
  }

  printf("  |List Sorted in %d comparisons and %d swaps after %d passes|\n======================\n", comps, swaps, passes);

  return done;
}

int oddEvenSort(int i, int j, int listToSort[], int size, int userDelay) {

  printf("    Odd Even sort\n\n======================\n");
  
  int comps = 0;
  int swaps = 0;
  int done = 0;
  int a = 0;
  int passes = 0;
  
  int n = 0;

  while(done == 0) 
  {
    i = 0;
    j = 1;
    passes += 1;
    done = 1;

    while(j < size)
    {
      if(listToSort[j] < listToSort[i]) {
        a = listToSort[j];
        listToSort[j] = listToSort[i];
        listToSort[i] = a;
        done = 0;
        swaps += 1;
      }
      i += 2;
      j += 2;
      comps += 1;
      n = 0;

      if(n == i - 1 || n == j - 1){
          printf("\n\n>%d<", listToSort[n]);
          n += 1;
      } else {
          printf("\n\n[%d]", listToSort[n]);
          n += 1;
      }
  
      n += 1;

      while(n < size)
      {
        if(n == i - 1 || n == j - 1){
          printf(", >%d<", listToSort[n]);
          n += 1;
        } else {
          printf(", [%d]", listToSort[n]);
          n += 1;
        }
      }
      delay(userDelay);

    }
    i = 1;
    j = 2;
    passes += 1;
    
    while(j < size)
    {
      if(listToSort[j] < listToSort[i]) {
        a = listToSort[j];
        listToSort[j] = listToSort[i];
        listToSort[i] = a;
        done = 0;
        swaps += 1;
      }
      i += 2;
      j += 2;
      comps += 1;
      n = 0;

      if(n == i - 1 || n == j - 1){
          printf("\n\n>%d<", listToSort[n]);
          n += 1;
      } else {
          printf("\n\n[%d]", listToSort[n]);
          n += 1;
      }
  
      n += 1;

      while(n < size)
      {
        if(n == i - 1 || n == j - 1){
          printf(", >%d<", listToSort[n]);
          n += 1;
        } else {
          printf(", [%d]", listToSort[n]);
          n += 1;
        }
      }
      delay(userDelay);

    }
   // n = 0;
  
   // printf("\n[%d]", listToSort[n]);
  
   // n += 1;

   // while(n < size)
   // {
    //  printf(", [%d]", listToSort[n]);
    //  n += 1;
    //}
    //printf("  |Pass %d|, |%d comps|, |%d swaps|", passes, comps, swaps);
  }

  n = 0;
  
  printf("\n[%d]", listToSort[n]);
  
  n += 1;

  while(n < size)
  {
    printf(", [%d]", listToSort[n]);
    n += 1;
  }

  printf("  |List Sorted in %d comparisons and %d swaps after %d passes|\n======================\n", comps, swaps, passes);

  return done;
}

int grateSort(int i, int j, int listToSort[], int size, int userDelay) {

  printf("    Grate sort\n\n======================\n");
  
  int comps = 0;
  int swaps = 0;
  int done = 0;
  int a = 0;
  int passes = 0;
  
  int n = 0;

  while(done == 0) 
  {
    i = -1;
    passes += 1;
    done = 1;
    j = size - 1;
    while (i < size - 1) 
    {
    i += 1;
    j = size - 1;
    
    while(j > i && listToSort[i] < listToSort[j])
      {
        j -= 1;
        
        
        comps += 1;
        n = 0;

        if(n == i || n == j - 1){
          printf("\n\n>%d<", listToSort[n]);
          n += 1;
      } else {
          printf("\n\n[%d]", listToSort[n]);
          n += 1;
      }
  
        n += 1;

        while(n < size)
        {
          if(n == i - 1 || n == j - 1){
            printf(", >%d<", listToSort[n]);
           n += 1;
           } else {
            printf(", [%d]", listToSort[n]);
            n += 1;
          }
        }
        delay(userDelay);

      }
      if (listToSort[j] < listToSort[i]){
        a = listToSort[j];
          listToSort[j] = listToSort[i];
          listToSort[i] = a;
          done = 0;
          swaps += 1;
      }
    }
  }

  n = 0;
  
  printf("\n[%d]", listToSort[n]);
  
  n += 1;

  while(n < size)
  {
    printf(", [%d]", listToSort[n]);
    n += 1;
  }

  printf("  |List Sorted in %d comparisons and %d swaps after %d passes|\n======================\n", comps, swaps, passes);

  return done;
}

int sandPaperSort(int i, int j, int listToSort[], int size, int userDelay) {

  printf("    Sandpaper sort\n\n======================\n");
  
  int comps = 0;
  int swaps = 0;
  int done = 0;
  int a = 0;
  int passes = 0;
  
  int n = 0;

  while(done == 0) 
  {
    i = -1;
    passes += 1;
    done = 1;
    j = size - 1;
    while (i < size - 1) 
    {
    i += 1;
    j = size - 1;
    
    while(j > i )
      {
        if (listToSort[j] < listToSort[i]){
        a = listToSort[j];
          listToSort[j] = listToSort[i];
          listToSort[i] = a;
          swaps += 1;
        }
        j -= 1;
        
        
        comps += 1;
        n = 0;

        if(n == i|| n == j + 1){
          printf("\n\n>%d<", listToSort[n]);
          n += 1;
      } else {
          printf("\n\n[%d]", listToSort[n]);
          n += 1;
      }
  
        n += 1;

        while(n < size)
        {
          if(n == i || n == j + 1){
            printf(", >%d<", listToSort[n]);
           n += 1;
           } else {
            printf(", [%d]", listToSort[n]);
            n += 1;
          }
        }
        delay(userDelay);

      
      
      }
    }
  }

  n = 0;
  
  printf("\n[%d]", listToSort[n]);
  
  n += 1;

  while(n < size)
  {
    printf(", [%d]", listToSort[n]);
    n += 1;
  }

  printf("  |List Sorted in %d comparisons and %d swaps after %d passes|\n======================\n", comps, swaps, passes);

  return done;
}

void callStoogeRecurse(int i, int j, int toSort[], int userDelay, int size){
  int n;
  n = 0;

    if(n == i || n == j){
          printf("\n\n>%d<", toSort[n]);
          n += 1;
      } else {
          printf("\n\n[%d]", toSort[n]);
          n += 1;
      }
  
    n += 1;

    while(n < size)
    {
      if(n == (i) || n == (j - 1)){
        printf(", >%d<", toSort[n]);
        n += 1;
        } else {
        printf(", [%d]", toSort[n]);
        n += 1;
      }
    }
    delay(userDelay);
  stooge(i, j - 1, toSort, userDelay, size);
  return;
}
void stooge(int i, int j, int toSort[], int userDelay, int size){
  int k;
  int n;
  if (j > i) {
    if (toSort[j] < toSort[i]) {
      k = toSort[j];
      toSort[j] = toSort[i];
      toSort[i] = k;
    }
    n = 0;

    if(n == i || n == j){
          printf("\n\n>%d<", toSort[n]);
          n += 1;
      } else {
          printf("\n\n[%d]", toSort[n]);
          n += 1;
      }
  
    n += 1;

    while(n < size)
    {
      if(n == (i) || n == (j)){
        printf(", >%d<", toSort[n]);
        n += 1;
        } else {
        printf(", [%d]", toSort[n]);
        n += 1;
      }
    }
    delay(userDelay);
    if (j - i + 1 > 2) {
      int t = (j - i + 1) / 3;
      stooge(i, j - t, toSort, userDelay, size);
      stooge(i + t, j, toSort, userDelay, size);
      stooge(i, j - t, toSort, userDelay, size);
    }
  }
  return;
}

int reverseSandPaperSort(int i, int j, int listToSort[], int size, int userDelay) {

  printf("    Reverse Sandpaper sort\n\n======================\n");
  
  int comps = 0;
  int swaps = 0;
  int done = 0;
  int a = 0;
  int passes = 0;
  
  int n = 0;

  while(done == 0) 
  {
    i = -1;
    passes += 1;
    done = 1;
    j = i;
    while (i < size - 1) 
    {
    i += 1;
    j = i + 1;
    
    while(j < size )
      {
        if (listToSort[j] < listToSort[i]){
        a = listToSort[j];
          listToSort[j] = listToSort[i];
          listToSort[i] = a;
          swaps += 1;
        }
        j += 1;
        
        
        comps += 1;
        n = 0;

        if(n == i|| n == j + 1){
          printf("\n\n>%d<", listToSort[n]);
          n += 1;
      } else {
          printf("\n\n[%d]", listToSort[n]);
          n += 1;
      }
  
        n += 1;

        while(n < size)
        {
          if(n == i || n == j + 1){
            printf(", >%d<", listToSort[n]);
           n += 1;
           } else {
            printf(", [%d]", listToSort[n]);
            n += 1;
          }
        }
        delay(userDelay);

      
      
      }
    }
  }

  n = 0;
  
  printf("\n[%d]", listToSort[n]);
  
  n += 1;

  while(n < size)
  {
    printf(", [%d]", listToSort[n]);
    n += 1;
  }

  printf("  |List Sorted in %d comparisons and %d swaps after %d passes|\n======================\n", comps, swaps, passes);

  return done;
}