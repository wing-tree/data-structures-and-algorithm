void Swap(int& a, int& b) {
    int c(a);
    a = b;
    b = c;
}

void SelectionSort(int array[], int size) {
    int k;

    for (int i = 0; i < size; ++i) {
        k = i;

        for (int j = i + 1; j < size; ++j) {
            if (array[j] < array[k]) {
                k = j;
            }
        }

        Swap(array[i], array[k]);
    }
}
