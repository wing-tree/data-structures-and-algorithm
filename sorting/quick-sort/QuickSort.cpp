void Swap(int& a, int& b) {
    int c(a);
    a = b;
    b = c;
}

int Partition(int array[], int begin, int end) {
    int i(begin), j(end), pivot(begin);

    while(i < j) {
        while(array[i] <= array[pivot]) {
            i++;
        }

        while(array[j] > array[pivot]) {
            j--;
        }

        if (i < j) {
            Swap(array[i], array[j]);
        }
    }

    Swap(array[j], array[pivot]);

    return end;
}

void QuickSort(int array[], int begin, int end) {
    if (begin < end) {
        int pivot(Partition(array, begin, end));

        QuickSort(array, begin, pivot - 1);
        QuickSort(array, pivot + 1, end);
    }
}
