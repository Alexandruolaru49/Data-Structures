#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LEN 256

typedef char Item;
#include "Stack.h"

int isBalanced(const char *str, int length){

  /* TODO: Cerinta 3
   * Implementation must use a stack.
   * Do NOT forget to deallocate the memory you use.
   */
    int ret = 0;
    Stack *stack = createStack();
    int i ;
    for(i = 0 ; i < length ; i++){
      if((str[i] == '{') || (str[i] == '[') || (str[i] == '(')){
        push(stack,str[i]);
      }
      else{
        if(((str[i] == '}') && (top(stack) == '{')) || ((str[i] == ']') && (top(stack) == '[')) || ((str[i] == ')') && (top(stack) == '('))) {
          if(isStackEmpty(stack) == 0)
          pop(stack);
          else{
            destroyStack(stack);
            return 0;
          }
        }
        else{
          destroyStack(stack);
          return 0;
        }
      }
    }
    if(isStackEmpty(stack) == 1){
      destroyStack(stack);
      return 1;
    }
    else {
      destroyStack(stack);
      return 0;   
}
}

int main(){
    int len;
    char buffer[MAX_INPUT_LEN];
    FILE* inputFile = fopen("input-parantheses.txt","r");
    if(inputFile == NULL) return 1;


    while(fgets(buffer, MAX_INPUT_LEN, inputFile) != NULL){
      buffer[strcspn(buffer, "\r\n")] = 0;
      len = strlen(buffer);
      if(len == 0) break;

      if(isBalanced(buffer, len))
        printf("%s ---> is balanced.\n", buffer);
      else
        printf("%s ---> not balanced.\n", buffer);
    }

    fclose(inputFile);

    return 0;
}
