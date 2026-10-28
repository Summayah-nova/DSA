#include <iostream>
#include <string>
using namespace std;

template <typename T>
class myStack {
private:
    T* arr;
    int capacity;
    int topIndex;

public:
    myStack(int size = 100) {
        capacity = size;
        arr = new T[capacity];
        topIndex = -1;
    }

    bool isEmpty() const {
        return topIndex == -1;
    }

    bool isFull() const {
        return topIndex == capacity - 1;
    }

    void push(T value) {
        if (isFull()) {
            cout << "Stack is full!\n";
            return;
        }

        arr[++topIndex] = value;
    }

    T pop() {
        if (isEmpty())
            return T();

        return arr[topIndex--];
    }

    void clear() {
        topIndex = -1;
    }

    ~myStack() {
        delete[] arr;
    }
};

int main() {
    string text = "";

    myStack<string> undoStack;
    myStack<string> redoStack;

    int choice;
    char ch;

    do {
        cout << "\n--- TEXT EDITOR MENU ---\n";
        cout << "Current text: " << text << endl;

        cout << "1. Type a character\n";
        cout << "2. Delete last character\n";
        cout << "3. Undo\n";
        cout << "4. Redo\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter character: ";
            cin >> ch;

            if (!undoStack.isFull()) {
                undoStack.push(text);
                text += ch;
                redoStack.clear();
                cout << "Character added.\n";
            }
            else {
                cout << "Undo history is full!\n";
            }
            break;

        case 2:
            if (text.empty()) {
                cout << "There is no text to delete.\n";
            }
            else if (!undoStack.isFull()) {
                undoStack.push(text);
                text.erase(text.length() - 1, 1);
                redoStack.clear();
                cout << "Last character deleted.\n";
            }
            else {
                cout << "Undo history is full!\n";
            }
            break;

        case 3:
            if (undoStack.isEmpty()) {
                cout << "Nothing to undo.\n";
            }
            else if (!redoStack.isFull()) {
                redoStack.push(text);
                text = undoStack.pop();
                cout << "Undo successful.\n";
            }
            else {
                cout << "Redo history is full!\n";
            }
            break;

        case 4:
            if (redoStack.isEmpty()) {
                cout << "Nothing to redo.\n";
            }
            else if (!undoStack.isFull()) {
                undoStack.push(text);
                text = redoStack.pop();
                cout << "Redo successful.\n";
            }
            else {
                cout << "Undo history is full!\n";
            }
            break;

        case 5:
            cout << "Text editor closed.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}