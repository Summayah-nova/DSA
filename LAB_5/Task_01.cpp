#include <iostream>
using namespace std;

template <typename T>
class AbstractStack {
public:
    virtual void push(T value) = 0;
    virtual T pop() = 0;
    virtual T top() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual ~AbstractStack() {}
};

template <typename T>
class myStack : public AbstractStack<T> {
private:
    T* arr;
    int capacity;
    int topIndex;

public:
    myStack(int size) {
        capacity = size;
        arr = new T[capacity];
        topIndex = -1;
    }

    void push(T value) override {
        if (isFull()) {
            cout << "Stack is full!\n";
            return;
        }

        arr[++topIndex] = value;
        cout << "Element pushed successfully.\n";
    }

    T pop() override {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return T();
        }

        return arr[topIndex--];
    }

    T top() const override {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return T();
        }

        return arr[topIndex];
    }

    bool isEmpty() const override {
        return topIndex == -1;
    }

    bool isFull() const override {
        return topIndex == capacity - 1;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }

        cout << "Stack (top to bottom): ";
        for (int i = topIndex; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~myStack() {
        delete[] arr;
    }
};

int main() {
    int size;
    cout << "Enter stack size: ";
    cin >> size;

    if (size <= 0) {
        cout << "Invalid stack size.\n";
        return 0;
    }

    myStack<int> s(size);
    int choice, value;

    do {
        cout << "\n--- BASIC STACK MENU ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Show Top\n";
        cout << "4. Check Empty\n";
        cout << "5. Check Full\n";
        cout << "6. Display\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            s.push(value);
            break;

        case 2:
            if (!s.isEmpty())
                cout << "Popped: " << s.pop() << endl;
            else
                cout << "Stack is empty!\n";
            break;

        case 3:
            if (!s.isEmpty())
                cout << "Top element: " << s.top() << endl;
            else
                cout << "Stack is empty!\n";
            break;

        case 4:
            cout << (s.isEmpty() ? "Stack is empty.\n"
                : "Stack is not empty.\n");
            break;

        case 5:
            cout << (s.isFull() ? "Stack is full.\n"
                : "Stack is not full.\n");
            break;

        case 6:
            s.display();
            break;

        case 7:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 7);

    return 0;
}