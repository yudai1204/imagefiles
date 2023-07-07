#include "Kiso2A.h"

typedef struct Node {
  int val;
  struct Node *next;
} Node;


//node生成関数 あると便利
Node* gen_node(int val)
{
  Node* p = (Node*)malloc(sizeof(Node));
  p->next = NULL;
  p->val = val;
  return p;    
}

//hash table の準備
//Nodeポインタの配列として hash tableを持つ
//※あまりお行儀は良くないが、ここではglobal変数を利用する 
Node* hash_table[10];

int hash(int x)
{
  return x % 10;
}

void hash_initialize() {
  for (int i = 0; i < 10; ++i)
    hash_table[i] = NULL;
}


void hash_add(int val)
{
  Node* n = gen_node(val);
  int h = hash(val);

  //TODO ここ以降を編集
  // hash_table[h] から始まるリストの末尾にnを追加する
  //headがnullならheadに加える
  if (hash_table[h] == NULL)
  {
    hash_table[h] = n;
    return;
  }

  Node* p = hash_table[h];
  while(1){
    if(p->next == NULL){
      p->next = n;
      break;
    }
    p = p->next;
  }
}


void hash_find(int val)
{
  // hashテーブルからvalを検索する
  // hash_table[hash(val)]から始まるリストに valがあるか探す
  Node *p = hash_table[hash(val)];

  if (p == NULL) //hash_table[hash(val)]がnullなら valはない
  {
    printf("2 0\n");
    return;
  }

  //TODO ここを編集
  //hash_table[hash(val)]から始まる連結リストから valを探す
  int i;
  for(i=1;p != NULL;i++){
    if(p->val == val){
      printf("1 %d\n",i);
      return;
    }
    p = p->next;
  }
  printf("2 %d\n",i-1);
}


int main()
{
  int N, M;
  int ai[500], bi[500];
  load_ai_bj(&N, &M, ai, bi);

  hash_initialize();

  //hashテーブルにaiをすべて追加
  for (int i = 0; i < N; ++i)
    hash_add(ai[i]);

  //biを検索
  for (int i = 0; i < M; ++i)
    hash_find(bi[i]);

  return 0;
}



