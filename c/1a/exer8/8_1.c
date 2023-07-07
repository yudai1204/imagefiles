#include "Kiso2A.h"

typedef struct Node
{
  int key;
  struct Node* next;
} Node;


//リストの先頭から末尾までを標準出力する関数
void list_print(Node* head)
{
  //TODO ここを編集
  printf("%d ",head->key);
  if(head->next == 0){
    return;
  }else{
    list_print(head->next);
  }
  printf("\n");
}


//新しいノードを末尾に追加する関数
void list_add(Node** head, int key)
{
  //new node
  Node* n = (Node*)malloc(sizeof(Node));
  n->key = key;
  n->next = 0;

  //headがnullならheadに追加 (注:二重ポインタが必要)
  if (*head == NULL)
  {
    *head = n;
    return;
  }

  //TODO ここを編集, Nodeを末尾に追加
  Node* p = *head;
  while(1){
    if(p->next == NULL){
      p->next = n;
      break;
    }
    p = p->next;
  }
}




int main(void)
{
  //load N ai
  int ai[1000];
  int N;
  load_ai(&N, ai);
  Node* head = NULL;

  for ( int i=0; i < N; ++i)
    list_add( &head, ai[i]);
  list_print(head);

  return 0;
}
