#include <bits/stdc++.h>

#define ll long long int
// Removed #define NULL __null, as it's not needed
#define for1(x1) for(ll i = 0; i < x1; i++)
#define for2(x2) for(ll j = 0; j < x2; j++)
#define for3(vc_1) for(auto &it : vc_1) cin >> it;
#define so(x3) sort((x3).begin(), (x3).end())
#define rev(x3) reverse((x3).begin(), (x3).end())
#define nl endl
#define nb "\n"
#define fast_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(container) (container).begin(), (container).end()
using namespace std;

istream& operator>> (istream &input, vector <ll> &vc_1)
{
    for3(vc_1);
    return input;
}

const ll mod = 1e9 + 7;
const int N = 2e5 + 5;  

vector<int> adj[N];     
bool vis[N];      

ll gcd(ll a, ll b)
{
    if(b == 0) return a;
    return gcd(b, a%b);
}

ll mult(ll a, ll b)
{
    return (a%mod * b%mod)%mod;
}

ll add(ll a, ll b)
{
    return (a%mod + b%mod)%mod;
}

ll subtract(ll a, ll b)
{
    return (a%mod - b%mod + 2*mod)%mod;
}

char di[] = {'D', 'L', 'U', 'R'};
int dx[] = {1, 0, -1, 0, -1, -1, 1, 1};
int dy[] = {0, -1, 0, 1, -1, 1, -1, 1};

class HeapNode
{
public:
    HeapNode(char data , int freq);
    char data;
    int freq;
    HeapNode* right;
    HeapNode* left;
};

struct CompareNode
{
    bool operator()(HeapNode* h1, HeapNode* h2) 
    {
        return h1->freq > h2->freq; 
    }
};

class Huffman
{
public:
    Huffman(string message);
    unordered_map <char , int> freq;
    unordered_map <char , string> codes;
    priority_queue <HeapNode* , vector<HeapNode*>, CompareNode> min_heap;
    void Generate(HeapNode*, string);
};

HeapNode::HeapNode(char data , int freq)
{
    this->data = data;
    this->freq = freq;
    this->left = this->right = nullptr;
}

Huffman::Huffman(string message)
{
    for1(message.size())
    {
        if (freq.find(message[i]) == freq.end())
        {
            freq[message[i]] = 1;
        }
        else
        {
            freq[message[i]]++;
        }
    }

    for (auto item : freq)
    {
        HeapNode* h = new HeapNode(item.first , item.second);
        min_heap.push(h);
    }

    HeapNode *left, *right, *TOP;
    int new_freq = 0;
    while(min_heap.size() != 1)
    {
        left = min_heap.top(); min_heap.pop();
        right = min_heap.top(); min_heap.pop();
        new_freq = left->freq + right->freq;
        TOP = new HeapNode('\0', new_freq);  
        TOP->left = left;
        TOP->right = right;
        min_heap.push(TOP);
    }
    this->Generate(min_heap.top() , "");
}

void Huffman::Generate(HeapNode* h , string str)
{
    if (h == nullptr) return; 
    if (h->data != '\0') 
    {
        codes[h->data] = str;
    }
    Generate(h->left , str + '0');
    Generate(h->right , str + '1');
}

void ahmedsheref2288()
{
    Huffman huff("internet");
    for (auto const &[k, v] : huff.codes) 
    {
        cout << k << " " << v << endl;
    }
}

int main()
{
    fast_IO;
    ll test_case = 1;
    while(test_case--)
    {
        ahmedsheref2288();
    }
    return 0;
}
