#include<bits/stdc++.h>
using namespace std;
struct trie
{
	struct trie*child[26];
	bool isleaf;
};
struct trie* getnode()
{
struct trie*ptr=(struct trie*)malloc(sizeof(struct trie));
int i=0;
for(i=0;i<26;i++)
ptr->child[i]=NULL;	
	ptr->isleaf=false;
	return ptr;
}
void insert(struct trie*root,string s)
{
	int length=s.length(),i;
	struct trie*pcrawl=root;
	for(i=0;i<length;i++)
	{
		pcrawl->child[s[i]-'a']=getnode();
			cout<<(s[i]);
		pcrawl=pcrawl->child[s[i]-'a'];
	}
	pcrawl->isleaf=true;
}
bool search(struct trie*root,string s)
{
	struct trie*pcrawl=root;
	int l=s.length(),i=0,f=0;
	while(i<l)
	{
		if(pcrawl->child[s[i]-'a']!=NULL)
		pcrawl=pcrawl->child[s[i]-'a'];
		else 
	{
		f=1;
		break;
	}
		i++;
	}
	if(f==1)
	return false;
	else
	{
		if(pcrawl->isleaf)
		return true;
		else
		false;
	}
	
}
main()
{int i,j;
struct trie*root=getnode(),*ptr;
string s[]={"aman","burtle","amae"};
	for(i=0;i<3;i++)
	{
		insert(root,s[i]);
		cout<<"done"<<endl;
	}
	if(root->child[0]!=NULL&&root->child[1]!=NULL&&root->child[2]!=NULL)
	cout<<"yes";
	for(i=0;i<3;i++)
	{
		ptr=root;
		for(j=0;j<s[i].length();j++)
		{
			if(ptr->child[s[i][j]-'a']!=NULL)
			cout<<(s[i][j]);
			if(ptr->isleaf)
			cout<<"end";
			if(!ptr->isleaf)
			ptr=ptr->child[s[i][j]-'a'];
		}
		cout<<endl;
	}
	cout<<"search result"<<endl;
cout<<search(root,"amae");
}
