void Swap(int& a, int& b) {
    int c(a);
    a = b;
    b = c;
}

void OptimizedBubbleSort(int array[], int size) {
    for (int i = size; i >= 0; --i) {
        bool swapped(false);

        for (int j = 0; j < i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                Swap(array[j], array[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }
}
