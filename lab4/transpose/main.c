#include <stdio.h>
# define SIZE 100
struct Queue{
int row;
int coloumn;
int element;
};
struct Queue queue[SIZE];
int front = -1, rear = -1;

int isFull() {
    if ((front == 0 && rear == SIZE - 1) || (rear == front - 1))
        return 1;
    return 0;
}

int isEmpty() {
    if (front == -1)
        return 1;
    return 0;
}

void enqueue(int i,int j,int item) {
    if (isFull()) {
        printf("Queue is full, cannot insert.\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear = (rear + 1) % SIZE;
    queue[rear].row = i;
    queue[rear].coloumn=j;
    queue[rear].element=item;
}

/*int dequeue() {
    int item;

    if (isEmpty()) {
        printf("Queue is empty, cannot dequeue.\n");
        return -1;
    }

    item = queue[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }

    return item;
}
*/
void display() {
    int i;

    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    for (i = front; i != rear; i = (i + 1) % SIZE)
        printf("\t%d \t\t %d\t\t %d\n ", queue[i].row,queue[i].coloumn,queue[i].element);
    printf("\t%d \t\t %d\t\t %d\n ", queue[i].row,queue[i].coloumn,queue[i].element);
}

void main()
{
    int a[10][10];
    int n,i,j;
    printf("enter the size of the square matrix");
    scanf("%d",&n);
    printf("enter the elements of the matrix");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]!=0)
            {
                enqueue(j,i,a[i][j]);
            }
        }

    }
printf(" the fast transpose of the sparse matrix is:\n row: \t coloumn:\t element:\n");
display();


}

