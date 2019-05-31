#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *hanged[] = {"  ______\n |      |\n        |\n        |\n        |\n       / \\\n", "  ______\n |      |\n O      |\n        |\n        |\n       / \\\n",
"  ______\n |      |\n O      |\n |      |\n        |\n       / \\\n", "  ______\n |      |\n O      |\n |/     |\n        |\n       / \\\n",
"   ______\n  |      |\n  O      |\n \\|/     |\n         |\n        / \\\n", "   ______\n  |      |\n  O      |\n \\|/     |\n  |      |\n        / \\\n",
"   ______\n  |      |\n  O      |\n \\|/     |\n  |      |\n   \\    / \\\n", "   ______\n  |      |\n  O      |\n \\|/     |\n  |      |\n / \\    / \\\n"};



int avaible(int len, int j, char word[50], char ch[50])
{
  int i= 0, win = 0, k = 0, repeat = 0, rep;
  rep = 1;

  for(i; i < len; i++)
  {
    repeat = 0;
    for(k = 0; k <= j; k++)
    {
      if(ch[k] == word[i])
      {
        repeat++;
      }
      if(repeat > rep)
      {
        rep = repeat;
      }
    }
  }

  if(rep == 1)
    return 1;
  else
    return 2;
}

int main()
{
  char word[50];
  int i = 0, len, j = 0, chance = 7, true, win = 0, choose = 0, pos = 0, end = 0, k = 0, counter = 0;
  char ch[50]; // this variable is the character the user will enter to check if it's avaible in word or not
  char pch[50]; /* this variable is for the character chosen right*/

  /*this for loop is to assign the asterix to the variable pch*/
  for(i = 0; i < 50; i++)
  {
    pch[i] = '*';
  }
  /*this will get the word from the user*/
  printf("enter your word: ");
  scanf("%s", word);

  len = strlen(word);
  printf("\n");
  /*this loop will print the asterix according to the len of the string*/
  for(i = 0; i < len; i++)
    printf("%c ", pch[i]);

  printf("\n");
  /*this loop will keep going until the user have <= 0 chances or wen he wins*/
  do
  {

    printf("\nenter your character: ");
    scanf("%s", &ch[j]); // it'll get thge first character from the user

    for(i = 0; i < len; i++)
    {
      if(ch[j] == word[i])
      /* if the character chosen by the user is equal to a character that is in the word entered,
         i will be assigned to pos, pos will give the position of the right chosen character */
        pos = i;
    }
    /*this for loop will check if the character entered is present in the word*/
    for(i = 0; i < len; i++)
    {
      if(ch[j] == word[i])
        {
          true = 1; //if the character entered by the user is avaible in word, true will be = 1
          break;    /*the for loop will break, cz for example ch[j] == to word[0] but != to word[1]
                      if it continues it will return to the else value   */
        }
      else          //if the character entered by the user is not avaible in word, true will be = 0
        true = 0;
    }

    if(true == 1) // if the character is avaible in word[] :
    {
      pch[pos] = ch[j]; //pch[pos] (pos was assigned in line 63), will be equal to the character entered in line 56

      for(i = 0; i < len; i++)
      {
        printf("%c", pch[i]); //this line will print the components of pch[],(including * and the characters chosen)
      }

      if(avaible(len, j, word, ch) == 1)
        win++; // this line will increase win by 1 when win reaches the lenghts of word[] the loop will break
      else
        if(avaible(len, j, word, ch) == 2)
          printf("\nyou have already enteredd that value\n");
    }
    else // if the character is not avaible in word[] :
    {
      choose++; /*this will determine what picture to choose from hanged[]
                  (everytime the user ipout a character not avaible in word it will increase by one)*/
      chance--; //chance will be decreased by one
    }
    printf("\n\nyou still have %d chance\n", chance); //this will determine how many chances the user still have
    j++; //this will increase j  by one, j is used to determine where we are inputting the character in ch[]

    printf("%s", hanged[choose]); //this will print the picture of the hanged man
    if(win == len)
    {
      break;
    }

    for(i = 0; i < len; i++)
    {
      counter = 0;
      for(k = 0; k <= j; k++)
      {
        if(ch[k] == word[i])
          {
            counter++;
            if(counter >= 2)
              printf("\nyou have already entered this value\n");
          }
      }
    }


    end = 0;
    for(i = 0; i <= j; i++)
    {
      if(pch[i] != '*')
        end++;
    }
    if(end == len)
      break;

  }while(chance > 0);

  if(end == len)
    printf("\nyou won !!\n");
  else
    printf("\nyou lost!!\n");
}
