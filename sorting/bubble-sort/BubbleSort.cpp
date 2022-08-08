void Swap(int& a, int& b) {
    int c(a);
    a = b;
    b = c;
}

void BubbleSort(int array[], int size) {
    for (int i = size; i >= 0; --i) {
        for (int j = 0; j < i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                Swap(array[j], array[j + 1]);
            }
        }
    }
}
