#include "Kiso2A.h"


//題意より双方向連結リストを選択（単純な配列でもとけるかも)
typedef struct Node
{
  int key;
  struct Node* next;
  struct Node* prev;
} Node;


Node* gen_node(int key)
{
  Node* n = (Node*)malloc(sizeof(Node));
  n->key = key;
  n->next = 0;
  n->prev = 0;
  return n;
}

//先頭から末尾に向かって表示
void list_print_front(Node* head)
{
  for (Node* p = head; p; p = p->next ) printf("%d ", p->key);
  printf("\n");
}

//末尾から先頭に向かって表示
void list_print_back(Node* tail)
{
  for (Node* p = tail; p; p = p->prev ) printf("%d ", p->key);
  printf("\n");
}


// 先頭に追加
void list_add_front(Node** head, Node** tail, int key)
{ 
  Node* n = gen_node(key);
  if (*head==NULL) 
  {
    *head = *tail = n;
    return;
  }
  n->next = *head; 
  *head = n;
  n->next->prev = n;
}

// 末尾に追加
void list_add_back(Node** head, Node** tail, int key)
{
  Node* n = gen_node(key);
  if (*head==NULL) 
  {
    *head = *tail = n;
    return;
  }
  n->prev = *tail;
  *tail = n;
  n->prev->next = n;
}



int main()
{
  int N;
  int ai[500];
  //load_ai(&N, ai);
  
  Node *head = NULL, *tail = NULL;
  //TODO ここを編集
  // 双方向連結リストは実装しておきました。これを活用して解いても良いです。
  int in,i,cnt;
  scanf("%d",&cnt);
  for(i=0; i<cnt; i++){
    scanf("%d",&in);
    if(i%2 == 0){
      list_add_back(&head,&tail,in);
    }else{
      list_add_front(&head,&tail,in);
    }
  }
  if(i%2 == 1){
    list_print_back(tail);
  }else{
    list_print_front(head);
  }
  return 0;
}



