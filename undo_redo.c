#include"text_editor.h"

void push(Stack undoStack[], int *undoTop, char *work, char *line)
{
    if(*undoTop == MAX-1)
    {
        printf("Stack Overflow\n");
        return;
    }

    (*undoTop)++;

    strcpy(undoStack[*undoTop].work, work);
    strcpy(undoStack[*undoTop].line, line);
}

void undo(Node **head, Node **tail, Stack undoStack[], int *undoTop, Stack redoStack[], int *redoTop)
{
    if(*undoTop == -1)
    {
        printf("Nothing to undo\n");
        return;
    }

    Stack temp = pop(undoStack, undoTop);   //collect recentle done operation and line

    if(strcmp(temp.work, "insert") == 0)         //if we done insert at last
    {
        delete_last_line(head, tail);          //when pressed undo delete

        push(redoStack, redoTop, temp.work, temp.line);  //store it to the redo stack
    }

    printf("Undo successful\n");
}

void delete_last_line(Node **head, Node **tail)
{
    if(*head == NULL)
    {
        printf("Empty file\n");
        return;
    }

    Node *temp = *tail;

    // Only one node
    if(*head == *tail)
    {
        *head = NULL;
        *tail = NULL;
    }
    else
    {
        *tail = temp->prev;
        (*tail)->next = NULL;
    }

    free(temp);

    printf("Last line deleted successfully\n");
}

Stack pop(Stack stack[], int *top)
{
    Stack temp;

    if(*top == -1)
    {
        strcpy(temp.work, "");
        strcpy(temp.line, "");

        return temp;
    }

    temp = stack[*top];

    (*top)--;

    return temp;
}

void redo(Node **head, Node **tail,  Stack undoStack[], int *undoTop, Stack redoStack[], int *redoTop)
{
    if(*redoTop == -1)
    {
        printf("Nothing to redo\n");
        return;
    }

    Stack temp = pop(redoStack, redoTop);

    if(strcmp(temp.work, "insert") == 0)
    {
        insert_line(head, tail, temp.line);

        push(undoStack, undoTop, temp.work, temp.line);
    }

    printf("Redo successful\n");
}