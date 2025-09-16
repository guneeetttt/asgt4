#include <iostream>
using namespace std;

#define MAX 5

class CircularQueue
{
    int arr[MAX];
    int front, rear;

public:
    CircularQueue()
    {
        front = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        return (front == -1);
    }

    bool isFull()
    {
        return ((rear + 1) % MAX == front);
    }

    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "Queue is full\n";
        }
        else
        {
            if (front == -1)
                front = 0;
            rear = (rear + 1) % MAX;
            arr[rear] = x;
            cout << x << " inserted\n";
        }
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
        }
        else
        {
            cout << arr[front] << " deleted\n";
            if (front == rear)
            {
                front = rear = -1;
            }
            else
            {
                front = (front + 1) % MAX;
            }
        }
    }

    void peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
        }
        else
        {
            cout << "Front element: " << arr[front] << endl;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
        }
        else
        {
            cout << "Queue: ";
            int i = front;
            while (true)
            {
                cout << arr[i] << " ";
                if (i == rear)
                    break;
                i = (i + 1) % MAX;
            }
            cout << endl;
        }
    }
};

int main()
{
    CircularQueue q;
    int choice, value;

    do
    {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Check Empty\n6. Check Full\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.peek();
            break;
        case 4:
            q.display();
            break;
        case 5:
            if (q.isEmpty())
                cout << "Queue is empty\n";
            else
                cout << "Queue is not empty\n";
            break;
        case 6:
            if (q.isFull())
                cout << "Queue is full\n";
            else
                cout << "Queue is not full\n";
            break;
        case 7:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 7);

    return 0;
}
