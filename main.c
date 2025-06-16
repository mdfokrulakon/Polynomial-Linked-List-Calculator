#include <stdio.h>
#include <stdlib.h>

struct node {
    int coefficient;
    int exponent;
    struct node *next;
};
int x ;
void insert_the_polynomial();
void display_the_polynomial();
void the_result_of_polynomial();

struct node *head = NULL, *tail = NULL;


int main() {
    int option, loop = 1;
    while (loop) {
        printf("Select your option:\n");
        printf("1. Insert the polynomial:\n");
        printf("2. Display the polynomial: \n");
        printf("3. The result of polynomial: \n");
        printf("0. Exit\n");

        scanf("%d", &option);

        switch (option) {
            case 1:
                insert_the_polynomial();
                break;
            case 2:
                display_the_polynomial();
                break;
            case 3:
                the_result_of_polynomial();
                break;


            case 0:
                loop = 0;
                break;

            default:
                printf("Invalid option\n");
                break;
        }
    }

    return 0;
}

void insert_the_polynomial() {
    int n, i;
    struct node *curr;

    printf("Input the number of terms? ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        curr = (struct node *)malloc(sizeof(struct node));
        printf("Input the coefficient of terms - %d: ",i);
        scanf("%d", &curr->coefficient);
        printf("Input the exponent of terms - %d : ",i);
        scanf("%d", &curr->exponent);
        curr->next = NULL;

        if (head == NULL) {
            head = curr;
            tail = curr;
        } else {
            tail->next = curr;
            tail = curr;
        }
    }
    printf("Input the value of x :\n");
    scanf("%d",&x);
    display_the_polynomial();
}

void display_the_polynomial() {
    struct node *temp;
    temp = head;
    printf("The polynomial is :\n");

    if(0<temp->coefficient){

    printf("%d", temp->coefficient);
    printf("x^");
    printf("%d", temp->exponent);
    temp = temp->next;
    }
    else {
        printf("%d", temp->coefficient);
    printf("x^");
    printf("%d", temp->exponent);
    temp = temp->next;

    }


    while (temp != NULL) {
        if(0<temp->coefficient){
        printf("+");
        }
        printf("%d", temp->coefficient);
        printf("x^");
        printf("%d", temp->exponent);
        temp = temp->next;
    }
    printf("\n");
}


void the_result_of_polynomial(){
  int sum = 0, x = 2, total_sum = 0,i;
  struct node *temp;
    temp = head;
   while (temp != NULL) {

        sum = sum + temp->coefficient * pow(x,temp->exponent);
        temp = temp->next;
    }
    printf("The result is : %d",sum);
     printf("\n");

}

