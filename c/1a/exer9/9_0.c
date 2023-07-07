#include "Kiso2A.h"

typedef struct Node
{
  int key;
  struct Node* next;
} Node;


Node* gen_node(int key)
{
  Node* n = (Node*)malloc(sizeof(Node));
  n->key = key;
  n->next = 0;
  return n;
}


void list_print(Node* head)
{
  //TODO ここを編集 （先週の課題に類題あり）
  printf("%d ",head->key);
  if(head->next == 0){
    printf("\n");
    return;
  }else{
    list_print(head->next);
  }
}


void list_add_front(Node** head, int key)
{
  //TODO ここを編集 （先週の課題に類題あり）
  //new node
  Node* n = gen_node(key);

  //headがnullならheadに加える
  if (*head == NULL)
  {
    *head = n;
    return;
  }

  n->next = *head;
  *head = n;
}


void list_add_back(Node** head, int key)
{
  //後ろまでたどって末尾に追加（この関数は作成済み）
  Node* n = gen_node(key);

  if (*head == NULL)
  {
    *head = n;
    return;
  }

  Node* p = *head;
  while (p->next) p = p->next;
  p->next = n;
}


// リストからq番目を削除
void list_delete(Node** head, int q)
{
  //TODO ここを編集（先週の課題に類題あり）
  Node* current = *head;
  //qが0だったとき
  if(q == 0){
    *head = (*head)->next;
  }else{
    //qが1以上だった時
    for(int i=0; i<q-1; i++){
      //見る場所を進める
      current = current->next;
    }
  }
  //削除する
  current->next = current->next->next;
}




int main()
{
  int N;
  scanf("%d", &N);
  Node* head = NULL;

  for ( int i = 0; i < N; ++i)
  {
    //クエリiの処理をする
    int q, x;
    scanf("%d %d", &q, &x);

    if     (q == 1) list_add_back(&head,x);
    else if(q == 2) list_add_front(&head,x);
    else if(q == 3) list_delete   (&head, x);
    else if(q == 4) list_print    ( head   );
  }
  return 0;
}



