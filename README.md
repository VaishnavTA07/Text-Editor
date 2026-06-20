# 📝 Console-Based Text Editor in C

A menu-driven text editor developed in C that supports basic text editing operations such as insertion, deletion, search, replace, copy-paste, file save/load, and Undo/Redo functionality. The project demonstrates the use of linked lists, stacks, dynamic memory allocation, and file handling.

## 🚀 Features

- Insert text lines
- Delete specific lines
- Display complete text
- Search for words
- Replace words
- Copy and paste text
- Save content to a file
- Load content from a file
- Undo operations
- Redo operations

## 🛠 Technologies Used

- **Language:** C
- **Data Structures:** Linked Lists, Stacks
- **Concepts:** Dynamic Memory Allocation, File Handling, Modular Programming

## 📂 Project Structure

```
Text-Editor/
│
├── main.c
├── text_editor.c
├── text_editor.h
└── README.md
```

## 📖 Data Structures Used

### Linked List
Used to dynamically store text, where each node represents a line.

### Stack
Two stacks are maintained:
- Undo Stack – stores previous operations.
- Redo Stack – stores reverted operations.

## ⚙️ Compilation and Execution

### Linux/macOS

```bash
gcc main.c text_editor.c -o text_editor
./text_editor
```

### Windows (MinGW)

```bash
gcc main.c text_editor.c -o text_editor.exe
text_editor.exe
```

## 🎯 Key Challenges

- Designing an efficient Undo/Redo mechanism using stacks.
- Maintaining consistency between Undo and Redo operations.
- Managing dynamic memory and pointer manipulation.
- Handling file operations while preserving text structure.

## 📚 Key Learnings

- Practical implementation of Linked Lists and Stacks.
- Stack-based history management for Undo and Redo.
- Dynamic memory allocation and pointer handling.
- File handling in C.
- Modular programming and debugging techniques.

## 🔮 Future Enhancements

- Multiple clipboard support
- Auto-save functionality
- Syntax highlighting
- Keyboard shortcuts
- Pattern-based search
- Support for larger text files

## 👨‍💻 Author

**Vaishnav T A**  
Bachelor of Engineering in Electrical and Electronics Engineering  
VTU University

---

⭐ Feel free to fork this repository and contribute!
