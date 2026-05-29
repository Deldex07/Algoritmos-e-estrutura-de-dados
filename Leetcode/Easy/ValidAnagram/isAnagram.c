// 242. Valid Anagram

void merge(char arr[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    char L[n1], R[n2];

    for(int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for(int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2){
        if(L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while(i < n1)
        arr[k++] = L[i++];

    while(j < n2)
        arr[k++] = R[j++];
}

void mergeSort(char arr[], int left, int right){
    if(left < right){
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

bool isAnagram(char* s, char* t){
    int n1 = strlen(s);
    int n2 = strlen(t);

    if(n1 != n2)
        return false;

    mergeSort(s, 0, n1 - 1);
    mergeSort(t, 0, n2 - 1);

    return strcmp(s, t) == 0;
}
