#include "Kiso2A.h"


//このテンプレートでは連結リストで実装する
//配列で実装してもOK!

typedef struct Node
{
  int key;
  struct Node* next;
} Node;

// node生成関数（あると便利）
Node* gen_node(int key)
{
  Node* n = (Node*)malloc(sizeof(Node));
  n->key = key;
  n->next = 0;
  return n;
}


//stackに値keyを持つNodeをpushする
void stack_push(Node** head, int key)
{
  //TODO ここを編集する
  //new node
  Node* n = gen_node(key);

  //headがnullならheadに加える
  if (*head == NULL)
  {
    *head = n;
    return;
  }

  Node* next = *head;
  while(1){
    if(next->next == NULL){
      next->next = n;
      break;
    }
    next = next->next;
  }
}

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
int stack_pop(Node** head)
{
  //TODO ここを編集する (確保したメモリ領域のfreeはしなくてもOK)
  //list_print(*head);
  Node* p = *head;
  while(1){
    if(p->next == 0){
      *head = NULL;
      return p->key;
    }
    if(p->next->next == 0){
      int ret = p->next->key;
      p->next = 0;
      return ret;
    }
    p = p->next;
  }
}



int main()
{
  int N;
  scanf("%d", &N);
  Node* head = NULL;

  for (int i = 0; i < N; ++i)
  {
    int q, x;
    scanf("%d %d", &q, &x);
    
    if (q == 1) 
    {
      stack_push(&head, x);
    }
    else if (q == 2) 
    {
      if (head) stack_pop(&head);
    }
    else if (q == 3) 
    {
      if (head) printf("%d\n", stack_pop(&head));
      else printf("e\n");
    }
  }
  return 0; 
}
