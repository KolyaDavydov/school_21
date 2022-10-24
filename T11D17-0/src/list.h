#ifndef SRC_LIST_H_
#define SRC_LIST_H_

struct node* init(struct door *dr);
struct node* add_door(struct node *elem, struct door *dr);
struct node* find_door(int door_id, struct node *root);
struct node* remove_door(struct node *elem, struct node *root);
void destroy(struct node *root);

struct node {
    struct door *dr;  //  поле данных
    struct node *ptr;   // указатель на следующий элемент
};

#endif  // SRC_LIST_H_
