//增量计算,计算间隔
void shellSort(int arr[], int length) {
    int gap = length / 3 + 1;
    while (gap > 0) {
        for (int i = gap; i < length; i++) {
            int tmp = arr[i];
            int j = i - gap;
            if (j >= 0 && arr[j] > tmp) {
                arr[j + gap] = arr[j];
                j -= gap;
            }
            arr[j + gap] = tmp;
        }
        if (gap == 1) { break; }
        gap = gap / 3 + 1;
    }
}