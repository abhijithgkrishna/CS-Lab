int front = -1, rear = -1;
int size = 20;
int Q[20];
void enqueue(int item)
{
    if (rear == size - 1)
        return;
    rear = rear + 1;
    Q[rear] = item;
    if (front == -1)
        front = 0;
}
int dequeue()
{
    int item;
    if (front == -1)
        return;
    item = Q[front];
    front++;
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
}