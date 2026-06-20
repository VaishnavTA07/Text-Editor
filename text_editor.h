#ifndef TEXT_EDITOR_H
#define TEXT_EDITOR_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//for undo operation
#define MAX 100

typedef struct
{
    char work[10];
    char line[100];
}Stack;


//normal operations
typedef struct Node
{
    char line[100];
    struct Node *prev;
    struct Node *next;
}Node;

Node *create_node(char *str);
void insert_line(Node **head, Node **tail, char *str);
void display(Node *head);
void delete_line(Node **head, Node **tail, int lineNo);
void save_file(Node *head, char *filename);
void free_list(Node **head, Node **tail);
void open_file(Node **head, Node **tail, char *filename);
void search_text(Node *head, char *word);
void replace_text(Node *head, char *old_word, char *new_word);
void copy_line(Node *head, int lineNo, char *clipboard);
void cut_line(Node **head, Node **tail, int lineNo, char *clipboard);
void paste_line(Node **head, Node **tail, char *clipboard);

//undo redo functions
void push(Stack stack[], int *top, char *work, char *line);
Stack pop(Stack stack[], int *top);
void undo(Node **head, Node **tail,Stack undoStack[], int *undoTop,  Stack redoStack[], int *redoTop);
void redo(Node **head, Node **tail, Stack undoStack[], int *undoTop, Stack redoStack[], int *redoTop);
void delete_last_line(Node **head, Node **tail);
#endif