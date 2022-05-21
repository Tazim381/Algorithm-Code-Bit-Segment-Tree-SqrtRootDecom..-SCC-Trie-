

#include <bits/stdc++.h>

using namespace std;
struct Trie{

  int isEnd;
  Trie *child[26];
  Trie()
  {
      isEnd=0;
      for(int i=0; i<26; i++)
      {
          child[i]=NULL;
      }
  }


};

void insert(Trie *root, string str)
{
    Trie *tmp = root;
    for(int i=0; i<str.size(); i++)
    {
        int idx = str[i]-'a';
        if(tmp->child[idx]==NULL)
        {
            tmp->child[idx]= new Trie();
        }
        tmp = tmp->child[idx];
    }
    tmp->isEnd = 1;
}

int query(Trie *root, string str)
{

    Trie *tmp = root;
    for(int i=0; i<str.size(); i++)
    {
        int idx = str[i]-'a';
        if(tmp->child[idx]==NULL)
        {
            return 0;
        }
        tmp = tmp->child[idx];
    }
    return tmp->isEnd;
}
int main()
{
    string str = "Common, applications: of tries include storing a predictive text";
    for(int i=0; i<str.size(); i++)
    {
        int flg=0;
        if(str[i]>='A'&&str[i]<='Z')
        {
            str[i]=str[i]-'A'+'a';
            flg=1;
        }
        if(str[i]>='a'&&str[i]<='z')
        {
            flg=1;
        }
        if(flg==0)
        {
            str[i]=' ';
        }


    }

    istringstream os(str);
    string token;
    vector<string>word;
    while(os>>token)
    {
        word.push_back(token);
    }

    Trie * root = new Trie();
    for(int i=0; i<word.size(); i++)
    {
        insert(root,word[i]);
    }

    int a =query(root,"tries");
    if(a==1)
    {
        cout<<"This string is present "<<endl;
    }
    else
    {
        cout<<"This string is absent "<<endl;
    }
}

