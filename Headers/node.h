//
// Created by mauro on 4/24/21.
//

#ifndef C_TEXT_EDITOR_NODE_H
#define C_TEXT_EDITOR_NODE_H



class node{
    int data;
    node* next;

    node();
    node(int number);

    void set_data(int info);

    void set_next(node* node);

    int get_data();

    node get_next();}

};

#endif //C_TEXT_EDITOR_NODE_H
