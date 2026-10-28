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
    T* minArr;
    int capacity;
    int topIndex;
    int minIndex;

public:
    myStack(int size) {
        capacity = size;
        arr = new T[capacity];
        minArr = new T[capacity];
        topIndex = -1;
        minIndex = -1;
    }

    void push(T value) override {
        if (isFull()) {
            cout << "Stack is full!\n";
            return;
        }

        arr[++topIndex] = value;

        if (minIndex == -1 || value <= minArr[minIndex]) {
            minArr[++minIndex] = value;
        }

        cout << "Element pushed successfully.\n";
    }

    T pop() override {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return T();
        }

        T value = arr[topIndex--];

        if (value == minArr[minIndex]) {
            minIndex--;
        }

        return value;
    }

    T top() const override {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return T();
        }

        return arr[topIndex];
    }

    T getMin() const {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return T();
        }

        return minArr[minIndex];
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
        delete[] minArr;
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
        cout << "\n--- MINIMUM STACK MENU ---\n";
        cout << "1. Push element\n";
        cout << "2. Pop element\n";
        cout << "3. Show top element\n";
        cout << "4. Check if empty\n";
        cout << "5. Check if full\n";
        cout << "6. Display stack\n";
        cout << "7. Show minimum element\n";
        cout << "8. Exit\n";
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
            if (!s.isEmpty())
                cout << "Minimum element: " << s.getMin() << endl;
            else
                cout << "Stack is empty!\n";
            break;

        case 8:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 8);

    return 0;
}