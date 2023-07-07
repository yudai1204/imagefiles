#include <stdlib.h>
#include "Kiso2A.h"


typedef struct Node
{
  int key;
  struct Node* next;
  struct Node* prev;
} Node;


// 連結リストを先頭から末尾、末尾から先頭へ表示する関数
// 先の課題で出した問題ですが参考までにコードを載せます。
void list_print(Node* head)
{
  if (head == NULL)
    return;

  Node* p = head;
  while (1)
  {
    printf("%d ", p->key);
    if (p->next == NULL) break;
    p = p->next;
  }

  while (p)
  {
    printf("%d ", p->key);
    p = p->prev;
  }
  printf("\n");
}

// 連結リストの末尾に新しい要素を追加する関数
// 先の課題で出した問題ですが参考までにコードを載せます。
void list_add(Node** head, int key)
{
  Node* n = (Node*)malloc(sizeof(Node));
  n->key = key;
  n->next = 0;
  n->prev = 0;

  if (*head == NULL)
  {
    *head = n; //headに追加する可能性があるので二重ポインタ引数が必要
    return;
  }

  Node* p = *head;
  while (p->next)
    p = p->next;
  n->prev = p;
  p->next = n;
}


//
// リストのci番目の要素の後ろに値diを持つ要素を挿入する
//
void list_insert(Node* head, int ci, int di)
{
  // generate new node
  Node* n = (Node*)malloc(sizeof(Node));
  n->key = di;
  n->next = 0;
  n->prev = 0;

  //head から ci回 nextをたどる (本当はここも課題にしたかったが...)
  Node* p = head;
  for (int i = 0; i < ci; ++i)
  {
    p = p->next;
    if (p == NULL) return; // 踏み越え
  }

  //TODO ここを編集 p->next にノードnをつなぐ（prevをつなぐのを忘れない）
  
  n->next = p->next;
  if(n->next != 0)
    n->next->prev = n;
  n->prev = p;
  p->next = n;
}




int main(void)
{
  // ai, bjの読み込み
  int ai[100], ci[100], di[100];
  int N, M;
  load_ai( &N, ai);
  load_ci_di( &M, ci, di);

  //aiをlistへ格納
  Node* head = NULL;
  for ( int i=0; i < N; ++i)
  {
    list_add( &head, ai[i]);
  }
  //挿入操作を行ってからprintする
  for (int i=0; i<M; ++i)
  {
    list_insert(head, ci[i], di[i]);
  }
  list_print(head);

  return 0;

}
