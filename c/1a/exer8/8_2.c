#include "Kiso2A.h"

typedef struct Node 
{
  int key;
  struct Node* next;
} Node;


void list_print(Node* head)
{
  //TODO ここを編集 (前の課題からコピーしてOK)
  printf("%d ",head->key);
  if(head->next == 0){
    printf("\n");
    return;
  }else{
    list_print(head->next);
  }
}


void list_add(Node** head, int key)
{
  //TODO ここを編集 (前の課題からコピーしてOK)
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
  Node* next = *head;
  while(1){
    if(next->next == NULL){
      next->next = n;
      break;
    }
    next = next->next;
  }
} 


// リストからq番目の要素を削除する
void list_delete(Node** head, int q)
{ 
  //TODO ここを編集
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


int main(void)
{
  //ai, bjの読み込み
  int ai[1000], bj[1000];
  int N, M;    
  load_ai_bj(&N, &M, ai, bj);

  Node* head = NULL;
  for (int i = 0; i < N; ++i)
    list_add(&head, ai[i]);

  //Step1 表示
  list_print(head);

  //Step2 削除
  for ( int j=0; j < M; ++j)
    list_delete(&head, bj[j]);
  
  //Step3 表示
  list_print(head);

  return 0;
}