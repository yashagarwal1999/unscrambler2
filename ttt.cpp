#include <bits/stdc++.h>
using namespace std;

class dictionary
{
	string word,hash;
	int len;
public:
void getdata(string w,string h,int l)
{
word=w;
hash=h;
len=l;
}
bool operator <(dictionary &i)
{
	return i.len>len;
}

bool operator ==(int  i)
{
	return i==len;
}
int leng()
{
	return len;
}
string h()
{
	return hash;
}
void n()
{
	cout<<word<<endl;
}
};
int main()
{
	vector<dictionary>d;
	vector<dictionary>::iterator it;
	dictionary m;
	string input;
	d.reserve(84098);
	  fstream hash,dict,len;
	  hash.open("hash.txt",ios::in);
dict.open("dictionary.txt",ios::in);
len.open("length.txt",ios::in);
string w,h;
int l;

while(!dict.eof())
{
	dict>>w;
	len>>l;
	hash>>h;
	m.getdata(w,h,l);
	d.push_back(m);


}
dict.close();
len.close();
hash.close();
sort(d.begin(),d.end());
char c;
c='y';

while(c=='y' || c=='Y')
{
int flag=0;
cout<<"Enter the string"<<endl;
cin>>input;
 int arr[26]={0};
 for(int i=0;i<input.length();i++)
 {
 	arr[input[i]-'a']++;
 }
 string z="";
 for(int i=0;i<26;i++)
 {
z+=to_string(arr[i]);
 }
int ilen=input.length();



cout<<"The possible words are "<<endl;
for(int i=0;i<d.size();i++)
{
	if(d[i].leng()>ilen)
		{break;}
	else if(d[i].leng()==ilen)
	{
if(d[i].h()==z)
{
	d[i].n();
	flag=1;
}

	}
}
if(flag==0)
{
	cout<<"No words formed"<<endl;
}
cout<<"Do u want to enter another word(y/n)"<<endl;
cin>>c;
flag=0;
}
return 0;
}