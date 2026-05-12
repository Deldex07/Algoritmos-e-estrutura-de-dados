// 1665. Minimum Initial Energy to Finish Tasks
int compare(const void* a, const void* b) {
    int* taskA = *(int**)a;
    int* taskB = *(int**)b;
    return (taskA[1] - taskA[0]) - (taskB[1] - taskB[0]);
}

int minimumEffort(int** tasks, int tasksSize, int* tasksColSize) {
    qsort(tasks, tasksSize, sizeof(int*), compare);
    int res = 0;
    for (int i = 0; i < tasksSize; i++) {
        int cost = tasks[i][0];
        int min = tasks[i][1];
        if (res + cost > min) {
            res = res + cost;
        } else {
            res = min;
        }
    }
    return res;
}