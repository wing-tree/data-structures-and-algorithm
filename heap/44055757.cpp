// https://www.acmicpc.net/problem/11279

#include <cstdio>
#include <cstdlib>

using namespace std;

struct BinaryMaxHeap {
    int *array;
    int capacity;
    int count;
};

inline void Swap(int &a, int &b) {
    int c = a;
    a = b;
    b = c;
}

BinaryMaxHeap *CreateBinaryMaxHeap(int capacity) {
    BinaryMaxHeap *binary_max_heap = (BinaryMaxHeap*) malloc(sizeof(BinaryMaxHeap));

    binary_max_heap->capacity = capacity;
    binary_max_heap->count = 0;
    binary_max_heap->array = (int*) malloc(sizeof(int) * binary_max_heap->capacity);
    
    return binary_max_heap;
}

int Parent(BinaryMaxHeap *binary_max_heap, int i) {
    if (i <= 0 || binary_max_heap->count <= i) {
        return -1;
    }

    return (i - 1) / 2;
}

int LeftChild(BinaryMaxHeap *binary_max_heap, int i) {
    int left_child = 2 * i + 1;

    if (binary_max_heap->count <= left_child) {
        return -1;
    }

    return left_child;
}

int RightChild(BinaryMaxHeap *binary_max_heap, int i) {
    int right_child = 2 * i + 2;

    if (binary_max_heap->count <= right_child) {
        return -1;
    }

    return right_child;
}

int GetMax(BinaryMaxHeap *binary_max_heap) {
    if (binary_max_heap->count == 0) {
        return -1;
    }

    return binary_max_heap->array[0];
}

void PercolateDown(BinaryMaxHeap *binary_max_heap, int i) {
    int max = i;
    int left_child = LeftChild(binary_max_heap, i);
    int right_child = RightChild(binary_max_heap, i);

    if (left_child != -1 && binary_max_heap->array[i] < binary_max_heap->array[left_child]) {
        max = left_child;
    }

    if (right_child != -1 && binary_max_heap->array[max] < binary_max_heap->array[right_child]) {
        max = right_child;
    }

    if (max != i) {
        Swap(binary_max_heap->array[i], binary_max_heap->array[max]);
        PercolateDown(binary_max_heap, max);
    }
}

int DeleteMax(BinaryMaxHeap *binary_max_heap) {
    if (binary_max_heap->count == 0) {
        return -1;
    }

    int max = binary_max_heap->array[0];

    binary_max_heap->array[0] = binary_max_heap->array[binary_max_heap->count - 1];
    binary_max_heap->count--;

    PercolateDown(binary_max_heap, 0);

    return max;
}

void Resize(BinaryMaxHeap *binary_max_heap) {
    int *array = binary_max_heap->array;
    binary_max_heap->array = (int*) malloc(sizeof(int) * binary_max_heap->capacity * 2);

    for (int i = 0; i < binary_max_heap->capacity; ++i) {
        binary_max_heap->array[i] = array[i];
    }

    binary_max_heap->capacity *= 2;
    free(array);
}

void Insert(BinaryMaxHeap *binary_max_heap, int x) {
    if (binary_max_heap->capacity == binary_max_heap->count) {
        Resize(binary_max_heap);
    }

    int i = binary_max_heap->count++;
    
    while(i > 0 && x > binary_max_heap->array[(i - 1) / 2]) {
        Swap(binary_max_heap->array[i], binary_max_heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }

    binary_max_heap->array[i] = x;
}

void DestroyBinaryMaxHeap(BinaryMaxHeap *bianry_max_heap) {
    free(bianry_max_heap->array);
    free(bianry_max_heap);
    bianry_max_heap = NULL;
}

int main(void) {
    int N, x;

    scanf("%d", &N);

    BinaryMaxHeap *binary_max_heap = CreateBinaryMaxHeap(N);

    for (int i = 0; i < N; ++i) {
        scanf("%d", &x);

        if (x == 0) {
            int max = DeleteMax(binary_max_heap);

            if (max == -1) {
                printf("0\n");
            } else {
                printf("%d\n", max);
            }
        } else {
            Insert(binary_max_heap, x);
        }
    }

    DestroyBinaryMaxHeap(binary_max_heap);

    return 0;
}
