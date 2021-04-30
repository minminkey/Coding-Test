#include <string>
#include <iostream>
#include <vector>
#include <map>
 
using namespace std;
 
struct TRIE
{
    TRIE *Node[26];
    int Child_Cnt;
    bool Finish;
 
    void Insert(const char *Str);
    int Find(const char *Str);
};
 
int Idx = 0;
TRIE *Trie[10010], *R_Trie[10010];
TRIE Nodepool[1000010 * 2];
 
TRIE *Nodeset()
{
    TRIE *NewNode = &Nodepool[Idx++];
    NewNode->Child_Cnt = 0;
    NewNode->Finish = false;
    for (int i = 0; i < 26; i++) NewNode->Node[i] = NULL;
 
    return NewNode;
}
 
void TRIE::Insert(const char *Str)
{
    Child_Cnt++;
    if (*Str == NULL)
    {
        Finish = true;
        return;
    }
 
    int Cur = *Str - 'a';
    if (Node[Cur] == NULL) Node[Cur] = Nodeset();
    Node[Cur]->Insert(Str + 1);
}
 
int TRIE::Find(const char *Str)
{
    if (*Str == '?') return Child_Cnt;
 
    int Cur = *Str - 'a';
    if (Node[Cur] == NULL) return 0;
    return Node[Cur]->Find(Str + 1);
}
 
int Check_State(string S)
{
    if (S[0] == '?') return 0;
    if (S[S.length() - 1] == '?') return 1;
}
 
string Reverse(string S)
{
    string Temp = "";
    for(int i = S.length() - 1 ; i >= 0 ; i--)
    {
        Temp = Temp + S[i];
    }
    return Temp;
}
 
vector<int> solution(vector<string> words, vector<string> queries) 
{
    vector<int> answer;
    for (int i = 0; i < words.size(); i++)
    {
        string S = words[i];
        int Len = S.length();
        if (Trie[Len] == NULL) Trie[Len] = Nodeset();
        Trie[Len]->Insert(S.c_str());
 
        string Reverse_S = Reverse(S);
        if (R_Trie[Len] == NULL) R_Trie[Len] = Nodeset();
        R_Trie[Len]->Insert(Reverse_S.c_str());
    }
 
    map<string, int> MAP;
    for (int i = 0; i < queries.size(); i++)
    {
        string S = queries[i];
        if (MAP.count(S) == 0)
        {
            MAP[S] = i;
 
            int Len = S.length();
            int State = Check_State(S);
 
            if (State == 1)
            {
                if (Trie[Len] == NULL) answer.push_back(0);
                else answer.push_back(Trie[Len]->Find(S.c_str()));
            }
            else
            {
                string Reverse_S = Reverse(S);
                if (R_Trie[Len] == NULL) answer.push_back(0);
                else answer.push_back(R_Trie[Len]->Find(Reverse_S.c_str()));
            }
        }
        else answer.push_back(answer[MAP[S]]);
    }
    return answer;
}
