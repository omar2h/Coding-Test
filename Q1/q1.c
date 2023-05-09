#include <stdio.h>
#include <stdlib.h>

typedef enum TypeTag {
    ADD, SUB, MUL, FIBO
} TypeTag;

typedef struct Node{
    TypeTag typeTag;
    int data;
} Node;

typedef Node* (*FuncPtr)(const void*, const void*, int);

Node* createNode(TypeTag typeTag, int data){
    Node* node = (Node*)(malloc(sizeof(Node)));
    node->typeTag = typeTag;
    node->data = data;
    return node;
}

int fibo(int n){
    if(n == 0)
        return 0;
    int* dp = (int*)(calloc(n, sizeof(int)));
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2; i<n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    int res = dp[n-1];
    free(dp);
    return res;
}

void freeNode(Node* node){
    if(node != NULL)
        free(node);
}

Node* calculateFibonacci(int n){
    if(n < 0)
        n = -n;
    return createNode(FIBO, fibo(n));
}

Node* addFun(const void* a, const void* b, int isNode){
    if(isNode){
        Node* nodeA = (Node*)(a);
        Node* nodeB = (Node*)(b);
        if(nodeB == NULL){
            return calculateFibonacci(nodeA->data);
        }
        return createNode(ADD, nodeA->data + nodeB->data);
    }
    int a1 = *(int *)(&a);
    int b1 = *(int *)(&b);
    return createNode(ADD, a1+b1);
}

Node* mulFun(const void* a, const void* b, int isNode){
    if(isNode){
        Node* nodeA = (Node*)(a);
        Node* nodeB = (Node*)(b);
        if(nodeB == NULL){
            return calculateFibonacci(nodeA->data);
        }
        return createNode(MUL, nodeA->data * nodeB->data);
    }
    int a1 = *(int *)(&a);
    int b1 = *(int *)(&b);
    return createNode(MUL, a1 * b1);
}

Node* subFun(const void* a, const void* b, int isNode){
    if(isNode){
        Node* nodeA = (Node*)(a);
        Node* nodeB = (Node*)(b);
        if(nodeB == NULL){
            return calculateFibonacci(nodeA->data);
        }
        return createNode(SUB, nodeA->data - nodeB->data);
    }
    int a1 = *(int *)(&a);
    int b1 = *(int *)(&b);
    return createNode(SUB, a1 - b1);
}

FuncPtr makeFunc(TypeTag typeTag){
    switch (typeTag)
    {
        case ADD:
            return &addFun;
        
        case MUL:
            return &mulFun;
        
        case SUB:
            return &subFun;

        default:
            return NULL;
    }
}

void calc(Node* node){
    switch (node->typeTag)
    {
    case ADD:
        printf("%s", "add: ");
        printf("%d\n", node->data);
        break;
    case MUL:
        printf("%s", "mul: ");
        printf("%d\n", node->data);
        break;
    case SUB:
        printf("%s", "sub: ");
        printf("%d\n", node->data);
        break;
    case FIBO:
        printf("%s", "fibo: ");
        printf("%d\n", node->data);
        break;
    default:
        break;
    }
}

int main () {
    Node *add = makeFunc(ADD)(10, 6, 0);
    Node *mul = makeFunc(MUL)(5, 4, 0);
    Node *sub = makeFunc(SUB)(add, mul, 1);
    Node *fibo = makeFunc(SUB)(sub, NULL, 1);
    calc(add);
    calc(mul);
    calc(sub);
    calc(fibo);

    freeNode(add);
    freeNode(mul);
    freeNode(sub);
    freeNode(fibo);
    return 0;
}
