#include <stdio.h>
#include <stdlib.h>

typedef struct yzel{ 
    int znachenie; 
    struct yzel *next; 
}yzel;
yzel *stack_init(int znachenie){    
    yzel *buf = (yzel*)malloc(sizeof(yzel)); 
    if (buf == NULL)
        printf("Не дали память ");
    buf->znachenie = znachenie;
    buf->next = NULL;
    return buf;
}

yzel  *push(yzel *st, int znachenie){ 
    yzel *buf = (yzel*)malloc(sizeof(yzel));
    if (buf == NULL)
        printf("Не дали память ");
    buf->znachenie = znachenie;
    buf->next = st; 
    return buf;
}

int pop(yzel *st){  
    if (st == NULL)
        printf("Стек пустой");
    int val_buf = st->znachenie; 
    st = st->next;
    return val_buf;
}

void stack_print(yzel *st){
    printf("Текущее состояние: ");
    while (st){ 
        printf("%d ", st->znachenie); 
        st = st->next;
    }
    printf("\n");
}
 
int stack_size(yzel *st){ 
    int schetchik = 0;
    while (st){
        schetchik ++; 
        st = st->next;
    }
    return schetchik;
}


int main(){
    yzel *st1, *st2, *st3 = NULL;     
    int a,b,c;
        scanf("%d%d%d", &a, &b, &c);    
        st1 = stack_init(a); 
        st2 = push(st1, b);    
        st3 = push(st2, c);        
    printf("Верхний элемент: %d\n", pop(st1));  
    printf("Верхний элемент: %d\n", pop(st2));
    printf("Верхний элемент: %d\n", pop(st3)); ;
    getchar();
}