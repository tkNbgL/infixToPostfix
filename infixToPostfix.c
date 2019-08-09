#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LINKED_STACK_NODE_s *LINKED_STACK_NODE;
typedef struct LINKED_STACK_NODE_s{
	LINKED_STACK_NODE next;
	void *data;
} LINKED_STACK_NODE_t[1];

typedef struct LINKED_STACK_s{
	LINKED_STACK_NODE head;
} LINKED_STACK_t[1], *LINKED_STACK;

typedef struct LINKED_QUEUE_NODE_s *LINKED_QUEUE_NODE;
typedef struct LINKED_QUEUE_NODE_s{
    LINKED_QUEUE_NODE next;
    void *data;
}LINKED_QUEUE_NODE_t[1];

typedef struct LINKED_QUEUE_s *LINKED_QUEUE;
typedef struct LINKED_QUEUE_s{
    LINKED_QUEUE_NODE head;
    LINKED_QUEUE_NODE tail;
}LINKED_QUEUE_t[1];

typedef struct RATIONAL_S *RATIONAL;
typedef struct RATIONAL_s{//3 için
    signed long pay;
    signed long payda;
}RATIONAL_t[1];

LINKED_STACK linked_stack_init();
void linked_stack_free(LINKED_STACK stack);
void linked_stack_push(LINKED_STACK stack, void *data);
void *linked_stack_pop(LINKED_STACK stack);
void *linked_stack_top(LINKED_STACK stack);
int linked_stack_is_emtpy(LINKED_STACK stack);
LINKED_QUEUE linked_queue_init();
void linked_queue_free(LINKED_QUEUE queue);
int linked_queue_is_empty(LINKED_QUEUE queue);
int linked_queue_size(LINKED_QUEUE queue);
void linked_queue_enqueue(LINKED_QUEUE queue, void *data);
void *linked_queue_dequeue(LINKED_QUEUE queue);

int main()
{
    int asd;
    char *a="((((0-0)*(1-((21*1-2*6)*(7-8)+(9^2-3^2-6+8)*(9-0))/2)*7*(4-(2-4)^2+(2-7)*(1*0-3*6)+12)-((0-((21*1-2*6)*(7-8)+(9^2-3^2-6+8)*(9-0))/2+0)*1*7*(4-12)+2^2*8*35+11^2*22*3-7*4*(5*7+9*4*4)+(22-3-5)*(11-7*9+0*12))/2+2^2*8*35+11^2*22*3-7*4*(5*7+9*4*4)+(22-3-5)*(31-7*9+0*12))/10)^2-44)/(((((4-5)*(7-3)-(10+((5^2*7*8+9^2*0*3-3*5*(6*3+3*5)+(6-7)*(8*9-1*32)+(3*5*(2-4)+(5*7-8*9))*(2-7))/7)-4)*(5-7))/22))*(3-6-66-(1-2*32*13)/(((4-5)*(7-3)-(10-4)*(5-7))/34)^2)^2*2*11)";
    LINKED_STACK s;
    LINKED_STACK ss;
    LINKED_QUEUE s2;


    asd=check(ss,a);

    if(asd==2){
        printf("true");
    }
    if(asd==1){
        printf("false");
    }

    printf("\n\n");
    convert(s,s2,a);
    return 1;

}


int check(LINKED_STACK ss, char *a){
    char p = '(';
    ss = linked_stack_init();
     int i;
     for(i=0; a[i]!='\0'; i++){
        if(a[i]=='('){
                linked_stack_push(ss, &p);
           }
           else if( a[i]==')'){
                if(checkempty(ss)==0){
                    return 1;
                }
                else{
                     linked_stack_pop(ss);
                }
        }
     }
     if(checkempty(ss)==0){
        return 2;
     }
}


void convert(LINKED_STACK s,LINKED_QUEUE s2, char *a){
    char *topelement;
    char *data;
    s=linked_stack_init();
    s2=linked_queue_init();
    int i;
    char *adamsin;


    for(i=0; a[i]!='\0'; i++){
        if(a[i]!='+' && a[i]!='*' && a[i]!='(' && a[i]!=')' && a[i]!='/' && a[i]!='^' && a[i]!='-'){
            //linked_stack_push(s2,&a[i]);
            linked_queue_enqueue(s2,&a[i]);

        }
        else if(a[i]=='+' || a[i]=='*' || a[i]=='/' || a[i]=='^' || a[i]=='-'){




                            while(checkempty(s)!= 0 && priority(*topelement)>=priority(a[i]) && priority(*topelement)!=10)
                            {


                                data=linked_stack_pop(s);
                                topelement=linked_stack_top(s);
                                //linked_stack_push(s2,data);
                                linked_queue_enqueue(s2,data);



                            }
                            linked_stack_push(s,&a[i]);
                    topelement=linked_stack_top(s);
        }
        else if(a[i]=='('){
                    linked_stack_push(s,&a[i]);
                    topelement=linked_stack_top(s);

                }
                else if(a[i]==')'){
                     while(checkempty(s)!= 0 && priority(*topelement)!=10){

                        data=linked_stack_pop(s);
                         topelement=linked_stack_top(s);
                       // linked_stack_push(s2,data);
                       linked_queue_enqueue(s2,data);

                    }
                       linked_stack_pop(s);
                       topelement=linked_stack_top(s);

                }


    }
    while(checkempty(s)!= 0){
                    data=linked_stack_pop(s);
                    //linked_stack_push(s2,data);
                    linked_queue_enqueue(s2,data);
                }


  /* while(checkempty(s2)!= 0){
        adamsin=linked_stack_pop(s2);
        printf("%c",*adamsin);
    }*/

    while(linked_queue_is_emtpy(s2)!=0){
        adamsin=linked_queue_dequeue(s2);
        printf("%c",*adamsin);
    }

}

int linked_queue_is_emtpy(LINKED_QUEUE queue){
	if(queue->head==0 && queue->tail==0){
        return 0;
	}
	else{
        return 1;
	}
}

/*int evaluate(LINKED_QUEUE queue){//evaluate fonksyonunu yazdim ama calismiyor
    char *op2;
	char *op1;
	int *answer;
	int res;
	int i;

	s = linked_stack_init();
	for(i=0; a[i]!='\0'; i++){
        if(a[i]!='*' && a[i]!='+'){
            linked_stack_push(s,&a[i]);
        }
        else if(a[i]=='+' || a[i]=='*'){
            op2=linked_stack_pop(s);
            op1=linked_stack_pop(s);
            res=perform(a[i],op1,op2);
            linked_stack_push(s,res);
        }
	}
	answer=linked_stack_top(s);
	printf("%d",*answer);
}

int perform(char *s,char *op1, char *op2){
    int res;
    int a,b;
    a=op1-'0';
    b=op2-'0';
    if(s=='*'){
        res=a*b;
    }
    if(s=='+'){
        res=a+b;
    }
    return res;
}*/


void linked_stack_push(LINKED_STACK stack, void *data){
	LINKED_STACK_NODE node = (LINKED_STACK_NODE)malloc(sizeof(LINKED_STACK_NODE_t));
	if(node != NULL){
		node->data = data;
		node->next = stack->head;
		stack->head = node;
	}
	else{
		printf("Error @ linked_stack_push: Cannot allocate memory.\n");
	}
}

void *linked_stack_pop(LINKED_STACK stack){
	LINKED_STACK_NODE node;
	void *res = NULL;

	if(stack->head != NULL){
		node = stack->head;
		res = node->data;
		stack->head = node->next;
		free(node);
	}
	else{
		//printf("Error @ linked_stack_pop: Empty stack is popped.\n");
	}
	return res;
}

void *linked_stack_top(LINKED_STACK stack){
	void *res = NULL;

	if(stack->head != NULL){
		res = stack->head->data;
	}
	else{
		//printf("Error @ linked_stack_top: stack empty no top.\n");
	}
	return res;
}

int linked_stack_is_emtpy(LINKED_STACK stack){
	return stack->head == NULL;
}
int checkempty(LINKED_STACK stack){
    if(stack->head != NULL){
        return 1;
    }
    else
        return 0;
}

LINKED_STACK linked_stack_init(){
	LINKED_STACK new;

	new = (LINKED_STACK)malloc(sizeof(LINKED_STACK_t));
	if(new != NULL){
		new->head = NULL;
	}
	else{
		printf("Error @ linked_stack_init: Memory allocation.\n");
	}
	return new;
}

void linked_stack_free(LINKED_STACK stack){
	while(stack->head !=NULL){
		linked_stack_pop(stack);
	}
	free(stack);
}

int priority(char *ch){


    if(ch=='^'){
        return 7;
    }
    if(ch=='*' || ch=='/'){
        return 5;
    }
    if(ch=='+' || ch=='-'){
        return 1;
    }
    if(ch=='(' || ch==')'){
        return 10;
       }


     //return 0;
}

LINKED_QUEUE linked_queue_init(){
    LINKED_QUEUE newhead;

    newhead=(LINKED_QUEUE)malloc(sizeof(LINKED_QUEUE_t));
    if(newhead != NULL){
        newhead->head=NULL;
        newhead->tail=NULL;
    }
    else{
        printf("eroor");
    }
    return newhead;
}

void linked_queue_enqueue(LINKED_QUEUE queue, void *data){
    LINKED_QUEUE_NODE node=(LINKED_QUEUE_NODE)malloc(sizeof(LINKED_QUEUE_NODE_t));
    if(node != NULL){
        node->data=data;
        node->next=NULL;
        if(queue->head==NULL){
            queue->head=node;
        }
        else{
            queue->tail->next=node;
        }
        queue->tail=node;
    }
    else{
        printf("unable to allocate memory");
    }
}

void *linked_queue_dequeue(LINKED_QUEUE queue){
    LINKED_QUEUE_NODE node;
    void *res=NULL;
    node=queue->head;
    if(node != NULL){
        if(node == queue->tail){
            queue->head=NULL;
            queue->tail=NULL;
        }
        else{
            queue->head=node->next;
        }
        res=node->data;
        free(node);
    }
    else{
        printf("queue empty");
    }

    return res;
}
