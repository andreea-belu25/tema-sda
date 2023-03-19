#include "header.h"

int main()
{
    int nr_op = 0;
    char op[256] = "\0", new_c = '\0';
    scanf("%d", &nr_op);
    for (int i = 0; i < nr_op; i++){
        scanf("%s", op);
        if((strcmp (op,"INSERT_LEFT") == 0) || (strcmp (op,"INSERT_RIGHT") == 0)) 
            scanf("%c", &new_c);
        if((strcmp (op,"MOVE_LEFT_CHAR") == 0) || (strcmp (op,"MOVE_RIGHT_CHAR") == 0))
            scanf("%c", &new_c);
        if((strcmp (op,"WRITE") == 0))
            scanf("%c", &new_c);
        if((strcmp (op,"UNDO") == 0) || (strcmp (op,"REDO") == 0)) {
            //adaug in coada
        } else {
            //adaug in stiva
        }       
    }
}
