// 493. Reverse Pairs

int mergeAndCount(int* nums, int left, int mid, int right, int* temp) {
    int count = 0;
    int j = mid + 1;

    // 1. Passo do problema: Contar os pares válidos
    // Como as duas metades estão ordenadas, usamos dois ponteiros lineares
    for (int i = left; i <= mid; i++) {
        // Usamos long long para evitar estouro de memória (overflow) na multiplicação por 2
        while (j <= right && (long long)nums[i] > 2 * (long long)nums[j]) {
            j++;
        }
        // Se nums[i] é maior que 2*nums[j], ele também é maior para todos os elementos anteriores a j
        count += (j - (mid + 1));
    }

    // 2.Passo normal: Unir as duas metades ordenadas
    int i = left;
    j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            temp[k++] = nums[i++];
        } else {
            temp[k++] = nums[j++];
        }
    }

    // Copia os elementos restantes, se houver
    while (i <= mid)   temp[k++] = nums[i++];
    while (j <= right) temp[k++] = nums[j++];

    // Devolve os elementos ordenados do array temporário para o array original
    for (i = left; i <= right; i++) {
        nums[i] = temp[i];
    }

    return count;
}

// Função principal divisória do Merge Sort
int mergeSort(int* nums, int left, int right, int* temp) {
    if (left >= right) return 0;

    int mid = left + (right - left) / 2;
    int count = 0;

    // Divide e soma os pares encontrados na esquerda e na direita
    count += mergeSort(nums, left, mid, temp);
    count += mergeSort(nums, mid + 1, right, temp);
    count += mergeAndCount(nums, left, mid, right, temp);

    return count;
}

int reversePairs(int* nums, int numsSize) {
    if (numsSize < 2) return 0;

    // Aloca o array auxiliar uma única vez para evitar desperdício de memória
    int* temp = (int*)malloc(numsSize * sizeof(int));
    int result = mergeSort(nums, 0, numsSize - 1, temp);

    return result;
}