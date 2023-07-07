#include <stdlib.h>
#include "Kiso2A.h"

// 採点対象外


typedef struct Node
{
  int key;
  struct Node* left;
  struct Node* right;
} Node;

//ノード生成関数．作っておくと便利。
Node* gen_node(int key)
{
  Node *p = (Node*)malloc(sizeof(Node));
  p->key   = key;
  p->right = 0;
  p->left  = 0;
}


void print_tree(Node* p, int depth)
{
  //TODO ここを編集 (前の課題からコピーOK)
}


//
//root以下の2分岐にノード追加
//
void tree_add(Node** root, int k, int val)
{
  Node* node = gen_node(val);

  //0番目はルートに追加し終了
  if (k == 0)
  {
    (*root) = node;
    return;
  }

  //TODO ここを編集
  //前課題の方法でパスを取得し、そこに追加

}



int main(void)
{
  int N;
  int ai[1000];
  load_ai(&N, ai);

  Node* root = 0;
  for (int i=0; i < N; ++i)
    tree_add(&root, i, ai[i]);
  print_tree(root, 0);

  return 0;
}
