#include "../include/head.h"
int main(){
    struct body_link {
        void *data;
        int type;
        struct body_link *next;
    };
    struct head_link {
        char *name;
        struct body_link *head;
        struct body_link **location;
        int offset;
        struct head_link *next;
    };
    return 0;
}

(struct head_link*)hcreate(){
    struct head_link *temp;
    temp = (struct head_link*)(malloc(sizeof(struct head_link)));
    temp->head = (struct body_link*)(malloc(sizeof(struct body_link)));
    temp->location = &(temp->head);
    temp->offset = 0;
    return temp;
}
int hadd(struct head_link *head_hl){
    struct head_link *temp;
    temp = (struct head_link*)(malloc(sizeof(struct head_link)));
    head_hl->next = temp;
    temp->head = head_hl->head;
    temp->location = (struct body_link*)(malloc(sizeof(struct body_link)));
    temp->offset = (head_hl->offset+1);
    return 0;
}
