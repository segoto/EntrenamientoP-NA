#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key, size;
    struct Node *left, *right;
};

int size(struct Node *N){
    if (N == NULL)
        return 0;
    return N->size;
}

struct Node* newNode(int key){
    struct Node* node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    node->size = 1;
    return node;
}

struct Node* insert(struct Node* node, int key, int *result){
    if (node == NULL)
        return(newNode(key));

    if (key > node->key){
        node->right  = insert(node->right, key, result);
        *result = *result + size(node->left) + 1;
    }
    else
        node->left = insert(node->left, key, result);

    node->size = size(node->left) + size(node->right) + 1;

    return node;
}

int countInversions(int arr[], int n) {
  struct Node *root = NULL;
  int result = 0;

  for (int i=n-1; i>=0; i--)
     root = insert(root, arr[i], &result);

  return result;
}

int manhattanDistance(int arr[], int m, int n) {
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if (arr[i*n+j] == m*n) {
                return (m-i) + (j-n);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int arr [100000];
    int m, n;
    string input;
    while (scanf("%d %d", &m, &n) == 2) {
        for (int i = 0; i < n*m; i++)
			scanf("%d", &arr[i]);

        int result = countInversions(arr, m*n);
        result += manhattanDistance(arr, m, n);

        string ans = result%2==0 ? "Y" : "N";
        cout << ans << endl;
    }
    return 0;
}
