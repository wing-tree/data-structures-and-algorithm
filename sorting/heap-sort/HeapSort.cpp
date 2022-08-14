inline void Swap(int& a, int& b) {
    int c(a);
    a = b;
    b = c;
}

void Heapify(int array[], int i, int size) {
    int j, root(0);

    do {
        j = 2 * root + 1;

        if (array[j] < array[j + 1] && i - 1 > j) {
            j++;
        }

        if (array[j] > array[root] && i > j) {
            Swap(array[root], array[j]);
        }

        root = j;
    } while (i > j);
}

void HeapSort(int array[], int size) {
    for (int i(1); i < size; ++i) {
        int j(i);

        do {
            int root((j - 1) / 2);

            if (array[j] > array[root]) {
                Swap(array[j], array[root]);
            }

            j = root;
        } while (j > 0);
    }

    for (int i(size - 1); i >= 0; --i) {
        Swap(array[0], array[i]);
        Heapify(array, i, size);
    }
}
