#include<stdio.h>
#include<string.h>
#define NO_OF_CHARS 256


int getNextState(char *pat, int M, int state, int x)
{
    int ns, i;
      
    if (state < M && x == pat[state])
        return state+1;
     
         
    for (ns = state; ns > 0; ns--)
    {
        if(pat[ns-1] == x)
        {
          for(i = 0; i < ns-1; i++)
          {
              if (pat[i] != pat[state-ns+1+i])
                  break;
          }
          if (i == ns-1)
              return ns;
        }
    }
     
    return 0;
}
 

/* This function builds the TF table which represents Finite Automata for a
  given pattern */
void computeTF(char *pat, int M, int TF[][NO_OF_CHARS])
{
    int state, x;

    for (state = 0; state <= M; ++state)
        for (x = 0; x < NO_OF_CHARS; ++x)
            TF[state][x] = getNextState(pat, M, state, x);
}
 

/* Prints all occurrences of pat in txt */
void search(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int TF[M+1][NO_OF_CHARS];
    int i, state=0;

    computeTF(pat, M, TF);

    for (i = 0; i < N; i++)
    {
        state = TF[state][txt[i]];
        if (state == M)
        {
            printf ("\n\t--> Pattern found at index %d", i-M+1);
        }
    }
}
 
/* Main function which drives program to test above functions */
int main()
{
    char txt[256];
    char pat[256];

    printf("Enter the string:  ");
    scanf (" %s", txt);  
    printf("Enter the sub-string:  ");
    scanf (" %s", pat);

    search(pat, txt);
    printf("\n");

    return 0;
}
