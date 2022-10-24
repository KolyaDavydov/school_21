#include "door_struct"
#include "list.h"

struct node *init(struct door *dr) {
    struct node *root;
    // выделение памяти для корня списка
    root = (struct node *) malloc(sizeof(struct node));
    root->dr = dr;    //  в поле передаем указатель струтуры
    root->ptr = NULL;     //  указатель на следующий элемент
    return(root);
}

struct node* add_door(struct node* elem, struct door *dr) {
    struct node *tmp;    //  создание узла списка
    // выделение памяти для корня списка
    tmp = (struct node *) malloc(sizeof(struct node));
    if (elem->ptr == NULL) {  //  если вставляем после последнего элемента
        elem->ptr = tmp;
        tmp->ptr = NULL;
    } else {            // если вставляем не в конец списка
        tmp->ptr = elem->ptr;
        elm->ptr = tmp;
    }
    tmp->dr = dr
    return(tmp);
}

struct node* find_door(int door_id, struct node *root) {
    struct node *temp;
    temp = root;
    while (temp->dr.id != door_id) {  // просматриваем список начиная с корня
    temp = temp->ptr;
    }
    return(temp);
}

struct node* remove_door(struct node *elem, struct node *root) {
    struct node *temp;
    temp = root;
    while (temp->ptr != elem) {  // просматриваем список начиная с корня
    temp = temp->ptr;
    }
    temp->ptr = node->ptr;  // переставляем указатель
    free(elem);  //  освобождаем память удаляемого узла
    return(temp);
}

void destroy(struct node *root) {
    do {
        del_root(root);
    } while (root != NULL)
    free(root);
}

struct node *del_root(struct node *root) {
    struct list *temp;
    temp = root->ptr;
    free(root);
    return(temp);
}
