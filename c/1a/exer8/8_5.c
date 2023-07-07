#include <stdlib.h>
#include "Kiso2A.h"


typedef struct Node
{
  int key;
  struct Node* left ;
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


// print tree関数
// pは着目ノード, depthはpの深さ
void print_tree(Node* p, int depth)
{

  //TODO ここを編集 
  //ヒント: 再帰で書くと良いです。右 --> 自分 --> 左の順番に書き出す。
  if(p->right != 0){
    print_tree(p->right, depth+1);
  }
  for(int i = 0; i < depth; i++){
    printf("..");
  }
  printf("+ %d\n",p->key);
  if(p->left != 0){
    print_tree(p->left, depth+1);
  }
}



int main(void)
{
  //create tree
  Node* n1 = gen_node(3); //root
  Node* n2 = gen_node(4);
  Node* n3 = gen_node(1);
  Node* n4 = gen_node(5);
  Node* n5 = gen_node(2);
  Node* n6 = gen_node(10);
  Node* n7 = gen_node(12);
  n1->left  = n2;
  n1->right = n3;
  n2->left  = n4;
  n2->right = n5;
  n3->left  = n6;
  n3->right = n7;

  Node* root = n1;
  print_tree(root, 0);

  return 0;
}
