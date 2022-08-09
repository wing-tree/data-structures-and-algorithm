void Merge(int array[], int sorted[], int begin, int middle, int end) {
    int i(begin), j(middle + 1), k(begin);

    while(i <= middle && j <= end) {
        if (array[i] <= array[j]) {
            sorted[k] = array[i];
            i++;
        } else {
            sorted[k] = array[j];
            j++;
        }

        k++;
    }

    while(i <= middle) {
        sorted[k] = array[i];
        i++;
        k++;
    }

    while(j <= end) {
        sorted[k] = array[j];
        j++;
        k++;
    }

    for (i = begin; i <= end; ++i) {
        array[i] = sorted[i];
    }
}

void MergeSort(int array[], int sorted[], int begin, int end) {
    if (begin < end) {
        int middle = (begin + end) / 2;

        MergeSort(array, sorted, begin, middle);
        MergeSort(array, sorted, middle + 1, end);
        Merge(array, sorted, begin, middle, end);
    }
}
