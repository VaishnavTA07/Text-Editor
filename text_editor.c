#include "text_editor.h"

// Creating node
Node *create_node(char *str)
{
    Node *new = malloc(sizeof(Node));

    if(new == NULL)
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    strcpy(new->line, str);
    new->prev = NULL;
    new->next = NULL;

    return new;
}

void insert_line(Node **head, Node **tail, char *str)
{
    Node *new = create_node(str);

    if(new == NULL)
        return;

    if(*head == NULL)
    {
        *head = new;
        *tail = new;
    }
    else
    {
        (*tail)->next = new;
        new->prev = *tail;
        *tail = new;
    }
}

// Display contents
void display(Node *head)
{
    Node *temp = head;
    int line = 1;

    if(temp == NULL)
    {
        printf("\nNo content available.\n");
        return;
    }

    printf("\n=================================================\n");
    printf("                 DOCUMENT CONTENT                \n");
    printf("=================================================\n");

    while(temp)
    {
        printf("%2d. %s\n", line++, temp->line);
        temp = temp->next;
    }

    printf("=================================================\n");
}

void delete_line(Node **head, Node **tail, int lineNo)
{
    if(*head == NULL)
    {
        printf("No content available.\n");
        return;
    }

    Node *temp = *head;
    int count = 1;

    while(temp != NULL && count < lineNo)
    {
        temp = temp->next;
        count++;
    }

    if(temp == NULL)
    {
        printf("Invalid line number.\n");
        return;
    }

    if(temp == *head)
    {
        *head = temp->next;

        if(*head != NULL)
            (*head)->prev = NULL;
        else
            *tail = NULL;
    }
    else if(temp == *tail)
    {
        *tail = temp->prev;
        (*tail)->next = NULL;
    }
    else
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    free(temp);

    printf("Line deleted successfully.\n");
}

void save_file(Node *head, char *filename)
{
    FILE *fp = fopen(filename, "w");

    if(fp == NULL)
    {
        printf("Unable to open the file.\n");
        return;
    }

    Node *temp = head;

    if(temp == NULL)
    {
        printf("No content available to save.\n");
        fclose(fp);
        return;
    }

    while(temp != NULL)
    {
        fprintf(fp, "%s\n", temp->line);
        temp = temp->next;
    }

    fclose(fp);

    printf("File saved successfully.\n");
}

void open_file(Node **head, Node **tail, char *filename)
{
    FILE *fp = fopen(filename, "r");

    if(fp == NULL)
    {
        printf("Unable to open the file.\n");
        return;
    }

    free_list(head, tail);

    char str[100];

    while(fgets(str, sizeof(str), fp))
    {
        str[strcspn(str, "\n")] = '\0';

        insert_line(head, tail, str);
    }

    fclose(fp);

    printf("File loaded successfully.\n");
}

void search_text(Node *head, char *word)
{
    Node *temp = head;
    int lineNo = 1;
    int count = 0;

    while(temp != NULL)
    {
        if(strstr(temp->line, word) != NULL)
        {
            printf("Match found at line %d : %s\n", lineNo, temp->line);
            count++;
        }

        temp = temp->next;
        lineNo++;
    }

    if(count == 0)
        printf("Specified text not found.\n");
    else
        printf("Total occurrences found : %d\n", count);
}

void replace_text(Node *head, char *old_word, char *new_word)
{
    Node *temp = head;
    int found = 0;

    while(temp != NULL)
    {
        char *pos = strstr(temp->line, old_word);

        if(pos != NULL)
        {
            char buffer[200];

            int index = pos - temp->line;

            strncpy(buffer, temp->line, index);
            buffer[index] = '\0';

            strcat(buffer, new_word);
            strcat(buffer, pos + strlen(old_word));

            strcpy(temp->line, buffer);

            found = 1;
        }

        temp = temp->next;
    }

    if(found)
        printf("Text replacement completed successfully.\n");
    else
        printf("Specified text not found.\n");
}

void copy_line(Node *head, int lineNo, char *clipboard)
{
    Node *temp = head;
    int count = 1;

    if(temp == NULL)
    {
        printf("The document is empty.\n");
        return;
    }

    while(temp != NULL)
    {
        if(count == lineNo)
        {
            strcpy(clipboard, temp->line);
            printf("Line copied successfully.\n");
            return;
        }

        temp = temp->next;
        count++;
    }

    printf("Invalid line number.\n");
}

void cut_line(Node **head, Node **tail, int lineNo, char *clipboard)
{
    copy_line(*head, lineNo, clipboard);

    delete_line(head, tail, lineNo);

    printf("Line cut successfully.\n");
}

void paste_line(Node **head, Node **tail, char *clipboard)
{
    if(strlen(clipboard) == 0)
    {
        printf("The clipboard is empty.\n");
        return;
    }

    insert_line(head, tail, clipboard);

    printf("Line pasted successfully.\n");
}

void free_list(Node **head, Node **tail)
{
    Node *temp;

    while(*head != NULL)
    {
        temp = *head;

        *head = (*head)->next;

        free(temp);
    }

    *tail = NULL;

    printf("All contents have been cleared successfully.\n");
}