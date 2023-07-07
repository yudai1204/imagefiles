#include <stdlib.h>
#include "Kiso2A.h"

typedef struct Node
{
  int key;
  struct Node* next;
  struct Node* prev;
} Node;


//先頭から末尾まで出力し、末尾から先頭まで出力する関数
void list_print(Node* head)
{
  //TODOここを編集。prevポインタを使って逆方向へたどる
  Node* now = head;
  while(1){
    printf("%d ",now->key);
    if(now->next != 0){
      now = now->next;
    }else{
      break;
    }
  }
  while(1){
    printf("%d ",now->key);
    if(now->prev != 0){
      now = now->prev;
    }else{
      break;
    }
  }
  printf("\n");
}


//listの末尾に新しいノードを付け加える関数
void list_add(Node** head, int key)
{
  //new node
  Node* n = (Node*)malloc(sizeof(Node));
  n->key = key;
  n->next = 0;
  n->prev = 0;

  //headがnullならheadに加える
  if (*head == NULL)
  {
    *head = n;
    return;
  }

  //TODO ここを編集。末尾に加える（prevポインタもつなぐ）
  Node* next = *head;
  while(1){
    if(next->next == NULL){
      n->prev = next;
      next->next = n;
      break;
    }
    next = next->next;
  }
}


int main(void)
{
  // aiの読み込み
  int N;
  int ai[100000];
  load_ai(&N, ai);

  Node* head = NULL;
  for ( int i = 0; i < N; ++i) {
    list_add( &head, ai[i]);
  }
  list_print(head);

  return 0;
}
