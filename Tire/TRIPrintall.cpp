#include<bits/stdc++.h>
using namespace std;
struct node
{
  int isEnd=0;
  node *next[26];
  node()
  {
    for(int i=0; i<26; i++)
    {
      isEnd=0;
      next[i]=NULL;
    }

  }
};

void insert(node * root, string str)
{

  node *cur = root;
  for(int i=0; i<str.size(); i++)
  {
    int idx = str[i]-'a';
    if(cur->next[idx]==NULL)
    {
        cur->next[idx]=new node();
        cur= cur->next[idx];
        //cur->isEnd = 1;
    }
  }
   cur->isEnd = 1;

}

int query(node *root, string str)
{
  node *cur = root;
  for(int i=0; i<str.size(); i++)
  {
     int idx = str[i]-'a';
     if(cur->next[idx]==NULL)
     {
       return 0;
     }
     cur = cur->next[idx];

  }
  return cur->isEnd;
}

void printall(node *cur, string str)
{


  if(cur==NULL) return ;
  if(cur->isEnd)
  {
    cout<<str<<" ";

  }
  for(int i=0; i<26; i++)
  {
    if(cur->next[i]!=NULL)
    {
      string tmp = str + (char)(i+'a');
      //cout<<"Str : "<<str<<endl;
      printall(cur->next[i], tmp);
    }
  }
}
int main()
{
  int i,j,m,n,a,b;
   node *root;
   root = new node();

   vector<string>word;
   word.push_back("  tazim");
   word.push_back(" rasel");
   word.push_back("sakil");
   for(i=0; i<word.size(); i++)
   {
     insert(root,word[i]);
   }
   a= query(root,"rasel");
   if(a==1)
   {
     cout<<"String is present"<<endl;
   }
   else cout<<"String is absent "<<endl;
   printall(root,"");
   return 0;
}
