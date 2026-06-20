#include "text_editor.h"

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    Stack undoStack[MAX], redoStack[MAX];
    int undoTop = -1, redoTop = -1;

    int choice, lineNo;
    char str[100];
    char filename[50];
    char word[100];
    char old_word[100], new_word[100];
    char clipboard[100] = "";

    while(1)
{
    printf("\n");
    printf("=================================================\n");
    printf("                TEXT EDITOR MENU                 \n");
    printf("=================================================\n");
    printf(" 1.  Insert Line\n");
    printf(" 2.  Display Content\n");
    printf(" 3.  Delete Line\n");
    printf(" 4.  Save File\n");
    printf(" 5.  Open File\n");
    printf(" 6.  Search Text\n");
    printf(" 7.  Replace Text\n");
    printf(" 8.  Copy Line\n");
    printf(" 9.  Cut Line\n");
    printf("10.  Paste Line\n");
    printf("11.  Undo\n");
    printf("12.  Redo\n");
    printf("13.  Exit\n");
    printf("=================================================\n");
    printf("Enter your choice: ");

    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
        {
            printf("\nEnter text: ");
            scanf(" %[^\n]", str);

            insert_line(&head, &tail, str);

            push(undoStack, &undoTop, "insert", str);

            break;
        }

        case 2:
        {
            display(head);
            break;
        }

        case 3:
        {
            printf("\nEnter line number: ");
            scanf("%d", &lineNo);

            delete_line(&head, &tail, lineNo);

            break;
        }

        case 4:
        {
            printf("\nEnter filename: ");
            scanf("%s", filename);

            save_file(head, filename);

            break;
        }

        case 5:
        {
            printf("\nEnter filename: ");
            scanf("%s", filename);

            open_file(&head, &tail, filename);

            break;
        }

        case 6:
        {
            printf("\nEnter text to search: ");
            scanf(" %[^\n]", word);

            search_text(head, word);

            break;
        }

        case 7:
        {
            printf("\nEnter word to replace: ");
            scanf(" %[^\n]", old_word);

            printf("Enter new word: ");
            scanf(" %[^\n]", new_word);

            replace_text(head, old_word, new_word);

            break;
        }

        case 8:
        {
            printf("\nEnter line number to copy: ");
            scanf("%d", &lineNo);

            copy_line(head, lineNo, clipboard);

            break;
        }

        case 9:
        {
            printf("\nEnter line number to cut: ");
            scanf("%d", &lineNo);

            cut_line(&head, &tail, lineNo, clipboard);

            break;
        }

        case 10:
        {
            paste_line(&head, &tail, clipboard);

            break;
        }

        case 11:
        {
            undo(&head, &tail,
                 undoStack, &undoTop,
                 redoStack, &redoTop);

            break;
        }

        case 12:
        {
            redo(&head, &tail,
                 undoStack, &undoTop,
                 redoStack, &redoTop);

            break;
        }

        case 13:
        {
            free_list(&head, &tail);

            printf("\nExiting Text Editor...\n");

            return 0;
        }

        default:
        {
            printf("\nInvalid choice. Please try again.\n");
        }
    }

}
}