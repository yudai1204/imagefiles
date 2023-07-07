#include "Kiso2A.h"


typedef struct Node {
  int key;
  struct Node* next;
} Node;

//node生成関数 (作っておくと便利)
Node* gen_node(int key)
{
  Node* p = (Node*)malloc(sizeof(Node));
  p->next = NULL;
  p->key = key;
  return p;
}

//自分より大きな値をもつノードの手前に挿入する
//(小さい順に並んだリストを作る)
void list_insert(Node** head, int x)
{
  //TODO ここを編集（過去にやった挿入を活用できる）
  //new node
  Node* n = gen_node(x);

  //headがnullならheadに加える
  if (*head == NULL)
  {
    *head = n;
    return;
  }
  Node* p = *head;
  if(p->key > x){
    n->next = p;
    *head = n;
    return;
  }
  //p->next->keyが自分より小さい限り繰り返す
  while(p->next != 0 && p->next->key < x){
    p = p->next;
  }
  n->next = p->next;
  p->next = n;
}



//リストが小さい順に並んでいるので、小さい方からq番目を削除すればOK
void list_delete(Node** head, int q)
{ 
  //q = 0 なら先頭を削除 
  if (q == 0)
  {
    *head = (*head)->next;
    return;
  }

  //TODO ここを編集 (q-1回ノードをたどって、その一個先のノードを削除すればOK)
  Node* p = *head;
  for(int i = 0; i <q-1; i++){
    p = p->next;
  }
  p->next = p->next->next;
}



void list_print(Node* head)
{
  for (Node* p = head; p != NULL; p = p->next)
    printf("%d ", p->key);
  printf("\n");
}



int main()
{
  int N;
  scanf("%d", &N);

  Node *head = NULL;

  for (int i = 0; i < N; ++i)
  {
    int q, x;
    scanf("%d %d", &q, &x);

    if (q == 1) 
      list_insert(&head, x); //昇順に並べて挿入
    else if (q == 2)
      list_delete(&head, x); //x番目を削除
    else if (q == 3)
      list_print(head);
  }
  return 0;
}

