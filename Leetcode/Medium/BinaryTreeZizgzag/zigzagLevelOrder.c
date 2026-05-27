// 103. Binary Tree Zigzag Level Order Traversal
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

typedef struct {
    struct TreeNode* data[2000];
    int front, rear;
} queue;

void initialize(queue *q){
    q->front = 0;
    q->rear = 0;
}

void enqueue(queue *q, struct TreeNode* node){
    q->data[q->rear++] = node;
}

struct TreeNode* dequeue(queue *q){
    return q->data[q->front++];
}

int isEmpty(queue *q){
    return q->front == q->rear;
}

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    queue q;
    initialize(&q);
    enqueue(&q, root);

    int** result = malloc(sizeof(int*) * 2000);
    *returnColumnSizes = malloc(sizeof(int) * 2000);

    int levels = 0;
    int leftToRight = 1;

    while (!isEmpty(&q)) {

        int levelSize = q.rear - q.front;
        int* level = malloc(sizeof(int) * levelSize);

        for (int i = 0; i < levelSize; i++) {

            struct TreeNode* node = dequeue(&q);

            int index;

            if (leftToRight){
                index = i;
            } else {
                index = levelSize - 1 - i;
            }
            level[index] = node->val;

            if (node->left) enqueue(&q, node->left);
            if (node->right) enqueue(&q, node->right);
        }

        result[levels] = level;
        (*returnColumnSizes)[levels] = levelSize;
        levels++;

        leftToRight = !leftToRight;
    }
    *returnSize = levels;
    return result;
}