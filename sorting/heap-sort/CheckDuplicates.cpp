bool CheckDuplicates(int array[], int size) {
    HeapSort(array, size);
    
    for (int i(0); i < size; ++i) {
        if (array[i] == array[i + 1]) {
            return true;
        }
    }

    return false;
}
