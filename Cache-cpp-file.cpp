#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <utility>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <cassert>
#include <sstream>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef double db;
typedef string str;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

// Bhavesh Sood - 2019355
 
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
 
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL) 
#define cinarr(ar,n) for(int i=0;i<n;i++){cin>>ar[i];}
#define car(ar,n) for(int i =0;i<n;i++){cout<<ar[i]<<" ";}
#define forn(i,a,b) for (int i = (a); i < ll(b); ++i)
#define fo(i,a) forn(i,0,ll(a))
#define rforn(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define ro(i,a) rforn(i,0,a)
#define trav(a,x) for (auto& a: x)
 
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define rsz resize
#define ins insert
 
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define f first
#define s second
 
ll mod = 1000000007;
inline ll fast_expo(ll base,ll power,ll modulo=mod){
    base%=modulo;
    if (base<0) base+=modulo;
    ll x=base,cnt=power,ans=1;
    while(cnt){
        if (cnt&1) ans=(ans*x)%modulo;
        x=(x*x)%modulo;
        cnt>>=1;
    }
    return ans;
}
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
// Bhavesh Sood - 2019355

void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
const ll INF = 1e18;
//=========================CODE STARTS HERE=============================//
 string decToBinary(int n) 
{ 
     string s="";
    for (int i = 31; i >= 0; i--) { 
        int k = n >> i; 
        if (k & 1) 
            s+="1";
        else
            s+="0"; 
    }
    return s; 
} 
 int main(){
	cout<<"Cache Program"<<endl;
	cout<<"Enter the number of Cache Lines (CL) : ";
	int cl;
	cin>>cl;
	cout<<"Enter the block size (B) : ";
	int B;
	cin>>B;
	int offbits=0;
	while(pow(2,offbits)!=B){
		if(pow(2,offbits)>B){
		cout<<"Block Size is not in powers of two. Enter it again : ";
		cin>>B;
		offbits=0;
		}
	offbits++;
	}
	int indexs=0;
	while(pow(2,indexs)!=cl){
		if(pow(2,indexs)>cl){
		cout<<"No. of Cache lines are not in powers of two. Enter them again : ";
		cin>>cl;
		indexs=0;
		}
	indexs++;
	}
	int tagbits=32-offbits;
	cout<<"Cache Size : "<<cl*B<<" Bytes"<<endl;
	cout<<"Offset is of : "<<offbits<<" bits"<<endl;
	cout<<endl;
	cout<<"General Instructions: "<<endl;
	cout<<"To read the value at address x ,give command : read x \n";
	cout<<"To write value v at address x , give command : write x v "<<endl;
	cout<<"To print current status of  cache , give command : print "<<endl;
	cout<<"To go to previous menu , give command : exit"<<endl<<endl;
	mainmenu:
	cout<<"Please enter the type of cache ...."<<endl;
	cout<<"1. Direct Mapped Cache"<<endl;
	cout<<"2. Associative Cache"<<endl;
	cout<<"3. N-way Set Associative Cache"<<endl;
	int type;
	cin>>type;
	
	if (type==2){
					cout<<"Enter Command : ";
					string s;
					cin>>s;
					char ch=s[0];
					map <string,int [100000]> directmap;
					list<string> l;
					while(ch!='f'){
						if(ch=='r'){
								int x;
								cin>>x;
								string bs=decToBinary(x);
								cout<<"\t32 bit address to be read "<<bs<<endl;
								string tag=bs.substr(0,tagbits);
								string offset=bs.substr(tagbits);
								cout<<"\ttag :"<<tag<<"\toffset : "<<offset<<endl;
								 unsigned long long value = stoull(offset, 0, 2);
							 if(directmap.find(tag)!=directmap.end()){
								cout<<"\tThe value is "<<directmap[tag][value]<<endl;
								
									//~ list <string> :: iterator it; 
									//~ for(it = l.begin(); it != l.end(); ++it){
										//~ if(*it==tag){
										//~ cout<<"foundoutsaf"; l.erase(it);
										//~ }}
										//~ cout<<"<loop over0 0";
									auto ikt=find(l.begin(),l.end(),tag);
									if(ikt!=l.end()){
									//~ cout<<"\tfound it"<<endl;
									l.erase(ikt);
									}
									
										
									l.push_back(tag);
									}
								
							else {
								cout<<"\tCache miss ->> address not found in cache"<<endl;
								if(l.size()<cl){
									cout<<"\t Inserted into cache"<<endl;
									directmap[tag][value]=-1;
									l.push_back(tag);
									}
								else {
									cout<<"\tCache is full have to evict the least recently used block which has tag : ";
									cout<<l.front()<<endl;
									
									auto it=directmap.find(l.front());
									directmap.erase (it); 
									l.pop_front();
									l.push_back(tag);
									
									}
								
								}
								
							}
						else if(ch=='w'){
								int x;
								cin>>x;
								int v;
								cin>>v;
								string bs=decToBinary(x);
								cout<<"\t32 bit address is : "<<bs<<endl;
								string tag=bs.substr(0,tagbits);
								cout<<"\ttag : "<<tag;
								string offset=bs.substr(tagbits);
								cout<<"\toffset : "<<offset<<endl;
								unsigned long long value = stoull(offset, 0, 2);
								 if(directmap.find(tag)!=directmap.end()){
								cout<<"\tCache hit ";
								directmap[tag][value]=v;
								cout<< "\tvalue updated.."<<endl;
								
								}
								else {
									cout<<"\tCache miss, writing to it after bringing from lower memory"<<endl;
								 
								directmap[tag][value]=v; 
								if(l.size()<cl){
									cout<<"\tnow inserted into cache"<<endl;
									l.push_back(tag);
									}
								else {
									cout<<"\tCache is full have to evict the least recently used block which has tag : ";
									cout<<l.front()<<endl;
									
									auto it=directmap.find(l.front());
									directmap.erase (it);
									l.pop_front();
									l.push_back(tag);
									
									}
								
								}	
							}
						 else if(ch=='p'){
							 cout<<"\tPrinting Cache (Least recently used on top) : " <<endl;
								 for(auto i : l){
								  cout<<"\ttag : "<< i;
								  cout<<endl;
								 }
						 }
						 else if (ch=='e'){
							 cout<<endl;
							 directmap.clear();
						  goto mainmenu;
						 }
					cout<<"Enter Command : ";	 
					cin>>s;
					ch=s[0];
					}
		}
	if(type==1){
					cout<<"Enter Command : ";
					string s;
					cin>>s;
					char ch=s[0];
					map <string,int [100000]> directmap;
					string tagarray[cl+2];
					list<string> l;
					while(ch!='f'){
						if(ch=='r'){
								int x;
								cin>>x;
								string bs=decToBinary(x);
								cout<<"\t32 bit address is : "<<bs<<endl;
								string index=bs.substr(tagbits-indexs,indexs);
								string tag=bs.substr(0,tagbits-indexs);
								cout<<"\ttag : "<<tag;
								string offset=bs.substr(tagbits);
								cout<<"\tindex : "<<index;
								cout<<"\toffset : "<<offset<<endl;
								unsigned long long value = stoull(offset, 0, 2);
								unsigned long long indexv = stoull(index, 0, 2);
							 if(tagarray[indexv]==tag){
								cout<<"\tCache hit"<<endl<<"\tValue at address is : "<<directmap[tag][value]<<endl;
								}
							 
							else {
								cout<<"Cache miss ->> address not found in cache"<<endl;
								if(tagarray[indexv]==""){
									tagarray[indexv]=tag;
									directmap[tag][value]=-1;
									}
								else{
									cout<<"\tEvicting block at this index with tag : "<<tagarray[indexv]<<endl;
									auto it=directmap.find(tagarray[indexv]);
									directmap.erase (it);
									tagarray[indexv]=tag;
									directmap[tag][value]=-1;
									cout<<"\tblock inserted into cache"<<endl;
									}
								
								}
							}
						else if(ch=='w'){
								int x;
								cin>>x;
								int v;
								cin>>v;
								string bs=decToBinary(x);
								cout<<"\t32 bit address is : "<<bs<<endl;
								string index=bs.substr(tagbits-indexs,indexs);
								string tag=bs.substr(0,tagbits-indexs);
								cout<<"\ttag : "<<tag;
								string offset=bs.substr(tagbits);
								cout<<"\tindex : "<<index;
								cout<<"\toffset : "<<offset<<endl;
								unsigned long long value = stoull(offset, 0, 2);
								unsigned long long indexv = stoull(index, 0, 2);
								if(tagarray[indexv]==tag){
								 if(directmap.find(tag)!=directmap.end()){
								cout<<"Cache hit ";
								directmap[tag][value]=v;
								cout<< " ->> value updated.."<<endl;
								
									}
								}
								else {
								cout<<"\tCache miss writing to it after bringing from lower memory"<<endl;
								if(tagarray[indexv]!=""){
									cout<<"\tEvicting block at this index with tag : "<<tagarray[indexv]<<endl;
									auto it=directmap.find(tagarray[indexv]);
									directmap.erase (it);
									tagarray[indexv]=tag;
									directmap[tag][value]=v;
									cout<<"\tblock updated"<<endl;
									}
								else {
									tagarray[indexv]=tag;
									directmap[tag][value]=v;
									}
								}
							
							}
						 else if(ch=='p'){
							 cout<<"Printing Cache index wise (from 0) : " <<endl;
								 for(int i=0;i<cl;i++){
								  cout<<"tag : "<< tagarray[i];
								  cout<<endl;
								 }
						 }
						 else if (ch=='e'){
							 cout<<endl;
							 directmap.clear();
						  goto mainmenu;
						 }
					cout<<"Enter Command : ";	 
					cin>>s;
					ch=s[0];
					}
	
	}	
	if(type==3){
				cout<<"Enter N for a N-Way Set Associative Cache : ";
				int k;
				cin>>k;
				int kbits=0;
				while(pow(2,kbits)!=k){
					if(pow(2,kbits)>k){
						cout<<"N is not in power of two. Enter it again : ";
						cin>>k;
						kbits=0;
					}
					kbits++;
				
				}
				
				cout<<"Enter Command : ";
					string s;
					cin>>s;
					char ch=s[0];
					map <string,int [100000]> directmap;
					string tagarray[cl+2];
					list<string> l[1000];
					while(ch!='f'){
						if(ch=='r'){
								int x;
								cin>>x;
								string bs=decToBinary(x);
								cout<<"\t32 bit address is : "<<bs<<endl;
								string index=bs.substr(tagbits-indexs+kbits,indexs-kbits);
								string tag=bs.substr(0,tagbits-indexs+kbits);
								cout<<"\ttag : "<<tag;
								string offset=bs.substr(tagbits);
								cout<<"\tindex : "<<index;
								cout<<"\toffset : "<<offset<<endl;
								unsigned long long value = stoull(offset, 0, 2);
								unsigned long long indexv = stoull(index, 0, 2);
								int setind=k*indexv;
								bool hit=false;
								for(int i=setind;i<setind+k;i++){
									if(tagarray[i]==tag){
										hit=true;
										cout<<"\tCache Hit"<<endl<<"\tValue at address is : "<<directmap[tag][value]<<endl;
										auto ikt=find(l[setind].begin(),l[setind].end(),tag);
											if(ikt!=l[setind].end()){
											//~ cout<<" \tfound it"<<endl;
											l[setind].erase(ikt);
											l[setind].push_back(tag);
											}
										}
								}
								if(hit==false){
									cout<<"\tCache Miss..Bringing from lower memory"<<endl;
									if(l[setind].size()==k){
										string toremove=l[setind].front();
										for(int i=setind;i<setind+k;i++){
											if(tagarray[i]==toremove){
												cout<<"\tHave to evict block with tag : "<<toremove<<endl;
												auto it=directmap.find(tagarray[i]);
												directmap.erase(it);
												tagarray[i]=tag;
												directmap[tag][value]=-1;
												l[setind].pop_front();
												l[setind].push_back(tag);
											}
										}
									}
								  else{
									for(int i=setind;i<setind+k;i++){
										if(tagarray[i]==""){
												tagarray[i]=tag;
												directmap[tag][value]=-1;
												l[setind].push_back(tag);
												cout<<"\tblock inserted"<<endl;
												break;
										}
									
									
									}
								}
							}
								
						}
						else if(ch=='w'){
								int x;
								cin>>x;
								int v;
								cin>>v;
								string bs=decToBinary(x);
								cout<<"\t32 bit address is : "<<bs<<endl;
								string index=bs.substr(tagbits-indexs+kbits,indexs-kbits);
								string tag=bs.substr(0,tagbits-indexs+kbits);
								cout<<"\ttag : "<<tag;
								string offset=bs.substr(tagbits);
								cout<<"\tindex : "<<index;
								cout<<"\toffset : "<<offset<<endl;
								unsigned long long value = stoull(offset, 0, 2);
								unsigned long long indexv = stoull(index, 0, 2);
								int setind=k*indexv;
								bool hit=false;
								for(int i=setind;i<setind+k;i++){
									if(tagarray[i]==tag){
										hit=true;
										cout<<"\tCache Hit"<<endl;
										directmap[tag][value]=v;
										auto ikt=find(l[setind].begin(),l[setind].end(),tag);
											if(ikt!=l[setind].end()){
											//~ cout<<" \tfound it"<<endl;
											
											l[setind].erase(ikt);
											l[setind].push_back(tag);
											}
											
									}
								}
								if(hit==false){
									cout<<"\tCache miss writing to it after bringing from lower memory"<<endl;
									if(l[setind].size()==k){
										string toremove=l[setind].front();
										for(int i=setind;i<setind+k;i++){
											if(tagarray[i]==toremove){
												cout<<"\tHave to evict block with tag : "<<toremove<<endl;
												auto it=directmap.find(tagarray[i]);
												directmap.erase(it);
												tagarray[i]=tag;
												directmap[tag][value]=v;
												l[setind].pop_front();
												l[setind].push_back(tag);
											}
										}
									}
									else {
										for(int i=setind;i<setind+k;i++){
										if(tagarray[i]==""){
												tagarray[i]=tag;
												directmap[tag][value]=v;
												l[setind].push_back(tag);
												cout<<"\tblock inserted"<<endl;
												break;
											}
										}
									
									}
								
								}
							}
								
						 else if(ch=='p'){
							 cout<<"Printing Cache index wise (from 0) : " <<endl;
								 for(int i=0;i<cl;i++){
								  cout<<"tag : "<< tagarray[i];
								  cout<<endl;
								 }
						 }
						 else if (ch=='e'){
							 cout<<endl;
							 directmap.clear();
						  goto mainmenu;
						 }
					cout<<"Enter Command : ";	 
					cin>>s;
					ch=s[0];
					}
	
	}
	
	
	
	
	return 0;
}
 
 
