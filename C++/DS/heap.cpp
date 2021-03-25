#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 10

struct Heap {
    int size = 0;
    int heap[MAX_HEAP_SIZE];

    int push(int value) {
        if(size == MAX_HEAP_SIZE) return -1;

        heap[size] = value;
        update(size);
        size++;
    }

    int pop() {
        if(size == 0) return -1;

        int res = heap[0];
        heap[0] = heap[--size];
        downdate(0);

        return res;
    }

    void update(int idx) {
        int c = idx;
        int p = (c - 1) / 2;

        while(c > 0 && heap[c] > heap[p]) {
            swap(c, p);
            c = p;
            p = (c - 1) / 2;
        }
    }

    void downdate(int idx) {
        int p = idx;
        int c = 1;

        while(c <= size) {
            if(c < size && heap[c] < heap[c + 1]) c++;
            if(heap[c] <= heap[p]) break;

            swap(c, p);
            p = c;
            c = c * 2 + 1;
        }
    }

    int getSize() {
        return size;
    }

    void swap(int a, int b) {
        int temp = heap[a];
        heap[a] = heap[b];
        heap[b] = temp;
    }
};

int main() {
    Heap* myHeap = new Heap();

    for(int i = 0 ; i < MAX_HEAP_SIZE ; ++i) {
        int value = rand() % 100;
        myHeap->push(value);
    }

    for(int i = 0 ; i < MAX_HEAP_SIZE ; ++i) {
        printf("%d번째 pop()의 결과는 %d\n", i, myHeap->pop());
    }
}
