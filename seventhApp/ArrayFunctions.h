void PrintDynamicArray(char* str) {
    for (int i = 0; i < strlen(str) + 1; i++) {
        cout << str[i] << endl;
    }
}

void PrintDynamicBooks(char** str, int amountOfBooks) {
    cout << "Books in library:\n";
    for (int i = 0; i < amountOfBooks; i++) {
        cout << i << ": " << str[i] << endl;
    }
}
void AddBook(char**& str, int& amountOfBooks) {
    char** newStr = new char* [amountOfBooks + 1];

    for (int i = 0; i < amountOfBooks; i++) {
        newStr[i] = str[i];
    }

    newStr[amountOfBooks] = new char[12];
    cout << "Enter a name of book: ";
    cin.getline(newStr[amountOfBooks], 12);

    delete[] str;
    str = newStr;
    amountOfBooks++;
}

void RenameBook(char** str, int amountOfBooks) {
    int index;
    cout << "Enter the index of the book to rename (0 to " << amountOfBooks - 1 << "): ";
    cin >> index;

    if (index >= 0 && index < amountOfBooks) {
        cout << "Enter the new name of book: ";
        cin.ignore();
        cin.getline(str[index], 12);
    }
    else {
        cout << "Invalid index\n";
    }
}

void DeleteBook(char**& str, int& amountOfBooks) {
    int index;
    cout << "Enter the index of the book to delete (0 to " << amountOfBooks - 1 << "): ";
    cin >> index;

    if (index >= 0 && index < amountOfBooks) {
        delete[] str[index];
        for (int i = index; i < amountOfBooks - 1; i++) {
            str[i] = str[i + 1];
        }
        amountOfBooks--;
    }
    else {
        cout << "Invalid index\n";
    }
}#pragma once
