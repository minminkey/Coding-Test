#define NULL 0

const int ALPA = 26;

int idx;

struct Trie{
   int cnt;
   bool finish;
   Trie *child[ALPA];
   void Insert(char *str);
   int find(char *str);
};

Trie *tri, Nodepool[1000000];

Trie *Nodeset(){
   Trie *New = &Nodepool[idx++];
   New->cnt = 0;
   New->finish = false;
   for(int i=0; i<ALPA; i++)  New->child[i] = NULL;
   return New;
}

void Trie::Insert(char *str){
   cnt++;
   if(*str==NULL){
      finish = true;
      return;
   }
   int next = *str - 'a';
   if(child[next] == NULL) child[next] = Nodeset();
   child[next]->Insert(str+1);
}

int Trie::find(char *str){
   if(*str == NULL)  return cnt;
   int next = *str - 'a';
   if(child[next] == NULL) return 0;
   return child[next]->find(str+1);
}


void init(void) {
   idx = 0;
   tri = Nodeset();
}

void insert(int buffer_size, char *buf) {
   tri->Insert(buf);
}

int query(int buffer_size, char *buf) {
   return tri->find(buf);
}