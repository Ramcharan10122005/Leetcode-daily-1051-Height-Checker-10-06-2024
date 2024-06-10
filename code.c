int choosepivot(int a[], int l, int r) { return l; }
int partition(int a[], int l, int r) {
    int p = l;
    int i = l + 1;
    int j;
    for (j = l + 1; j <= r; j++) {
        if (a[j] < a[p]) {
            int temp;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i = i + 1;
        }
    }
    int temp1;
    temp1 = a[l];
    a[l] = a[i - 1];
    a[i - 1] = temp1;
    return i - 1;
}
void quicksort(int a[], int l, int r) {
    int p1, p;
    if (l < r) {
        p1 = choosepivot(a, l, r);
        p = partition(a, l, r);
        quicksort(a, l, p - 1);
        quicksort(a, p + 1, r);
    }
}
int heightChecker(int* h, int s) {
    int temp[s];
    for (int i = 0; i < s; i++) {
        temp[i] = h[i];
    }
    quicksort(temp, 0, s - 1);
    int count = 0;
    for (int i = 0; i < s; i++) {
        if (temp[i] != h[i])
            count++;
    }
    return count;
}
