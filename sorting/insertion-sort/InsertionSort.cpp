void InsersionSort(int array[], int size) {
    int i, j, k;

    for (i = 1; i < size; ++i) {
        j = i;
        k = array[i];

        while(array[j - 1] > k && j >= 0) {
            array[j] = array[j - 1];
            j--;
        }

        array[j] = k;
    }
}
