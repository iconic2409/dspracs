1.	To implement Stack using arrays
#include <stdio.h>

int stack[100];
int top = -1;
int n;

void push();
void pop();
void peek();

int main()
{
    printf("Enter the number of elements in the stack: ");
    scanf("%d", &n);

    printf("****Stack operations using array****\n\n");

    int choice = 0;

    while (choice != 4)
    {
        printf("Choose one from the below options...\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            printf("Exiting\n");
            break;
        default:
            printf("Please enter a valid choice.\n");
        }
    }

    return 0;
}

void push()
{
    int val;
    if (top == n - 1)
    {
        printf("Overflow\n");
    }
    else
    {
        printf("Enter the value: ");
        scanf("%d", &val);
        top = top + 1;
        stack[top] = val;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Underflow\n");
    }
    else
    {
        top = top - 1;
    }
}

void peek()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

3.	To implement Circular Queue using arrays

#include <stdio.h>

#define max 6
int queue[max];
int front = -1;
int rear = -1;

void enqueue(int element) {
    if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
        queue[rear] = element;
    } else if ((rear + 1) % max == front) {
        printf("Queue is overflow.\n");
    } else {
        rear = (rear + 1) % max;
        queue[rear] = element;
    }
}

int dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue is underflow.\n");
        return -1; // Indicate underflow
    } else if (front == rear) {
        int dequeuedElement = queue[front];
        printf("The dequeued element is %d\n", dequeuedElement);
        front = -1;
        rear = -1;
        return dequeuedElement;
    } else {
        int dequeuedElement = queue[front];
        printf("The dequeued element is %d\n", dequeuedElement);
        front = (front + 1) % max;
        return dequeuedElement;
    }
}

void display() {
    int i = front;
    if (front == -1 && rear == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Elements in the Queue are: ");
        while (i != rear) {
            printf("%d, ", queue[i]);
            i = (i + 1) % max;
        }
        printf("%d\n", queue[rear]);
    }
}

int main() {
    int choice = 1;
    int x;

    while (choice != 0) {
        printf("\nPress 1: Insert an element\n");
        printf("Press 2: Delete an element\n");
        printf("Press 3: Display the elements\n");
        printf("Press 0: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &x);
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Please enter a valid choice.\n");
                break;
        }
    }

    return 0;
}



4.	To Implement Single Linked List and insert a node at the front

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL; 

void beginsert(int item) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("OVERFLOW\n");
    } else {
        ptr->data = item;
        ptr->next = head;
        head = ptr;
        printf("Node inserted\n");
    }
}

int main() {
    int choice, item;
    do {
        printf("Enter the item which you want to insert: ");
        scanf("%d", &item);
        beginsert(item);
        printf("Press 0 to insert more: ");
        scanf("%d", &choice);
    } while (choice == 0);

    return 0;
}


5.	To Implement Single Linked List and insert a node at the end

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void lastinsert(int item) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *temp;
    if (ptr == NULL) {
        printf("OVERFLOW\n");
    } else {
        ptr->data = item;
        ptr->next = NULL;
        if (head == NULL) {
            head = ptr;
            printf("Node inserted\n");
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = ptr;
            printf("Node inserted\n");
        }
    }
}

int main() {
    int choice, item;
    do {
        printf("Enter the item which you want to insert: ");
        scanf("%d", &item);
        lastinsert(item);
        printf("Press 0 to insert more: ");
        scanf("%d", &choice);
    } while (choice == 0);
    return 0;
}

6.	To Implement Single Linked List and delete a node from the front

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void create(int item) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("OVERFLOW\n");
    } else {
        ptr->data = item;
        ptr->next = head;
        head = ptr;
        printf("Node inserted\n");
    }
}

void begdelete() {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        struct node *ptr = head;
        head = ptr->next;
        free(ptr);
        printf("Node deleted from the beginning\n");
    }
}

int main() {
    int choice, item;
    do {
        printf("\n1. Append List\n2. Delete node\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the item: ");
                scanf("%d", &item);
                create(item);
                break;
            case 2:
                begdelete();
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Please enter a valid choice\n");
        }
    } while (choice != 3);
    return 0;
}


7.	To Implement Single Linked List and delete a node from the end


#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void create(int item) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("OVERFLOW\n");
    } else {
        ptr->data = item;
        ptr->next = head;
        head = ptr;
        printf("Node inserted\n");
    }
}

void end_delete() {
    if (head == NULL) {
        printf("List is empty\n");
    } else if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Only node of the list deleted\n");
    } else {
        struct node *ptr = head;
        struct node *ptr1 = NULL;
        while (ptr->next != NULL) {
            ptr1 = ptr;
            ptr = ptr->next;
        }
        ptr1->next = NULL;
        free(ptr);
        printf("Deleted Node from the last\n");
    }
}

int main() {
    int choice, item;
    do {
        printf("\n1. Append List\n2. Delete node\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the item: ");
                scanf("%d", &item);
                create(item);
                break;
            case 2:
                end_delete();
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Please enter a valid choice\n");
        }
    } while (choice != 3);
    return 0;
}


8.	To Implement Stack using Linked List for push operation

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int item) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Stack overflow: Unable to push the element\n");
        return;
    }
    newNode->data = item;
    newNode->next = top;
    top = newNode;
    printf("Pushed: %d\n", item);
}

int pop() {
    if (top == NULL) {
        printf("Stack underflow: The stack is empty\n");
        return -1; // Return an invalid value to indicate an error
    }
    int item = top->data;
    struct Node *temp = top;
    top = top->next;
    free(temp);
    return item;
}

int isEmpty() {
    return top == NULL;
}

void display() {
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        struct Node *current = top;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    int choice, item;
    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                if (!isEmpty()) {
                    item = pop();
                    printf("Popped: %d\n", item);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}



9.	To Implement Stack using Linked List for pop operation


#include <stdio.h>
#include <stdlib.h>

void push();
void pop();
void display();

struct node {
    int val;
    struct node *next;
};

struct node *head = NULL;

void main() {
    int choice = 0;
    printf("\n*********Stack operations using linked list*********\n");
    printf("\n\n");

    while (choice != 4) {
        printf("\n\nChoose one from the below options...\n");
        printf("\n1.Push\n2.Pop\n3.Show\n4.Exit");
        printf("\n Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting\n");
                break;
            default:
                printf("Please Enter a valid choice\n");
        }
    }
}

void push() {
    int val;
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Not able to push the element\n");
    } else {
        printf("Enter the value: ");
        scanf("%d", &val);
        ptr->val = val;
        ptr->next = head;
        head = ptr;
        printf("Item pushed\n");
    }
}

void pop() {
    struct node *ptr;
    if (head == NULL) {
        printf("Underflow\n");
    } else {
        int item = head->val;
        ptr = head;
        head = head->next;
        free(ptr);
        printf("Item popped: %d\n", item);
    }
}

void display() {
    struct node *ptr = head;
    if (ptr == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Printing Stack elements\n");
        while (ptr != NULL) {
            printf("%d\n", ptr->val);
            ptr = ptr->next;
        }
    }
}



10.	To implement Queue using Linked List


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void menu();
void display(struct Node *start);
struct Node *insert_at_beginning(struct Node *, int);
struct Node *insert_after(struct Node *, int, int);
struct Node *insert_at_end(struct Node *, int);
struct Node *delete_from_beginning(struct Node *);
struct Node *delete_after(struct Node *, int);
struct Node *delete_from_end(struct Node *);
int search(struct Node *, int);

int main() {
    struct Node *start = NULL;
    int user_choice, element, after;
    menu();

    do {
        printf(">>> ");
        scanf("%d", &user_choice);
        switch (user_choice) {
            case 0:
                break;
            case 1:
                printf("Enter Data To Insert: ");
                scanf("%d", &element);
                start = insert_at_beginning(start, element);
                break;
            case 2:
                printf("Enter The Value to Insert: ");
                scanf("%d", &element);
                printf("After What Value: ");
                scanf("%d", &after);
                start = insert_after(start, element, after);
                break;
            case 3:
                printf("Enter The Value to Insert: ");
                scanf("%d", &element);
                start = insert_at_end(start, element);
                break;
            case 4:
                start = delete_from_beginning(start);
                break;
            case 5:
                printf("Delete After What Value: ");
                scanf("%d", &after);
                start = delete_after(start, after);
                break;
            case 6:
                start = delete_from_end(start);
                break;
            case 7:
                printf("What Value to Search For: ");
                scanf("%d", &element);
                if (search(start, element))
                    printf("The Given Value %d is Present in the Linked List...\n", element);
                else
                    printf("The Given Value %d is Not Present in the Linked List...\n", element);
                break;
            case 8:
                display(start);
                break;
            case 99:
                menu();
                break;
            default:
                printf("Invalid Choice...\n");
                menu();
                break;
        }
    } while (user_choice);

    return 0;
}

void menu() {
    printf("0. Exit\n\
1. Insert At Beginning\n\
2. Insert After a Value\n\
3. Insert At End\n\
4. Delete From Beginning\n\
5. Delete After a Value\n\
6. Delete From End\n\
7. Search Element\n\
8. Display Elements\n\
99. Display This Menu Again\n");
}

void display(struct Node *start) {
    struct Node *ptr = start;
    if (ptr == NULL) {
        printf("Linked List Is Empty...\n");
        return;
    }

    do {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != start);

    printf("\n");
}

struct Node *insert_at_beginning(struct Node *start, int data) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

    if (ptr == NULL) {
        printf("Overflow...\n");
        return NULL;
    }

    if (start == NULL) {
        ptr->data = data;
        ptr->next = ptr;
        return ptr;
    }

    struct Node *head = start;
    ptr->data = data;
    ptr->next = start;

    while (head->next != start) {
        head = head->next;
    }

    head->next = ptr;
    start = ptr;
    return start;
}

struct Node *insert_after(struct Node *start, int data, int after) {
    struct Node *head = start;

    if (head == NULL) {
        printf("Cannot Insert Element after Given Value, Linked List is Empty...\n");
        return start;
    }

    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

    if (ptr == NULL) {
        printf("Overflow...\n");
        return NULL;
    }

    while (head->data != after) {
        head = head->next;
        if (head == start) {
            printf("Value Not Found!\n");
            return start;
        }
    }

    ptr->data = data;
    ptr->next = head->next;
    head->next = ptr;
    return start;
}

struct Node *insert_at_end(struct Node *start, int data) {
    struct Node *head = start;

    if (head == NULL) {
        start = insert_at_beginning(start, data);
        return start;
    }

    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

    if (ptr == NULL) {
        printf("Overflow...\n");
        return NULL;
    }

    while (head->next != start) {
        head = head->next;
    }

    ptr->data = data;
    ptr->next = start;
    head->next = ptr;
    return start;
}

struct Node *delete_from_beginning(struct Node *start) {
    struct Node *head = start;

    if (head == NULL) {
        printf("Underflow...\n");
        return NULL;
    }

    if (head->next == start) {
        free(head);
        return NULL;
    }

    struct Node *ptr = start;

    while (ptr->next != start) {
        ptr = ptr->next;
    }

    start = start->next;
    ptr->next = start;
    free(head);
    return start;
}

struct Node *delete_after(struct Node *start, int after) {
    struct Node *head = start;

    if (head == NULL) {
        printf("Underflow...\n");
        return NULL;
    }

    while (head->data != after) {
        head = head->next;
        if (head == start) {
            printf("Value Not Found!...\n");
            return start;
        }
    }

    if (head->next == start) {
        start = delete_from_beginning(start);
        return start;
    }

    struct Node *del = head->next;
    head->next = del->next;
    free(del);
    return start;
}

struct Node *delete_from_end(struct Node *start) {
    struct Node *ptr = start;
    struct Node *preptr = ptr;

    if (ptr == NULL) {
        printf("Underflow...\n");
        return NULL;
    }

    if (ptr->next == start) {
        start = delete_from_beginning(start);
        return start;
    }

    while (ptr->next != start) {
        preptr = ptr;
        ptr = ptr->next;
    }

    preptr->next = ptr->next;
    free(ptr);
    return start;
}

int search(struct Node *start, int data) {
    struct Node *head = start;

    if (start == NULL) {
        return 0;
    }

    do {
        if (head->data == data) {
            return 1;
        }
        head = head->next;
    } while (head != start);

    return 0;
}

