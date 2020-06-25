#include <stdlib.h>
#include <stdio.h>
#include "Ex1.h"
void print_listInterne(List *list);

Date *create_date(int day, int month, int year){
    Date *d1 = (Date*) malloc(sizeof(Date));
    d1->day = day;
    d1->month = month;
    d1->year = year;
    return d1;
}

void print_date(Date *date){
    printf("%d/%d/%d", date->day, date->month, date->year);
    printf("\n");
}

int equal_date(Date *d1, Date *d2){
    if (d1->day == d2->day && d1->month == d2->month && d1->year == d2->year){
        return 1;
    }
    else{
        return 0;
    }

}

Date *copy_date(Date *d1){
    Date *d2 = (Date*) malloc(sizeof(Date));
    d2->day = d1->day;
    d2->month = d1->month;
    d2->year = d1->year;
}

List *create_list(Date *date, List *list){
    List *L = (List*) malloc(sizeof(List));
    L->date = date;
    L->next = list;
}

List* empty_List(){
    return NULL; //Pointeur NULL 
}

void print_list(List *list){
    printf("[");
    print_listInterne(list);
    printf("]");
}
void print_listInterne(List *list){
    if (list->next == NULL){
        printf("%d/%d/%d", list->date->day, list->date->month, list->date->year);

    }
    else{
        printf("%d/%d/%d", list->date->day, list->date->month, list->date->year);
        printf(", ");
        print_listInterne(list->next);
    }
}