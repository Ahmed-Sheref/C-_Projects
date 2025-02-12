#include <bits/stdc++.h>

#define ll long long int
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

istream& operator>> (istream &input, vector<ll> &vc_1)
{
    for3(vc_1);
    return input;
}

class Unique_Vector
{
public:
    static vector<string> Unique(vector<string>& vec)
    {
        sort(vec.begin(), vec.end());
        auto last = std::unique(vec.begin(), vec.end());
        vec.erase(last, vec.end());
        return vec;
    }
};

// Helper class to manage utility functions
class HelperFunction {
public:
    // Helper function to check if a character is alphabetic
    static bool Check_character(char ch)
    {
        return isalpha(ch);
    }

    // Helper function to check and open a file
    static void Check_File(string File_Name, fstream& Document)
    {
        Document.open(File_Name);
        while (!Document)
        {
            cout << "Please enter the name of the file again...(=>) ";
            cin >> File_Name;
            Document.open(File_Name);
        }
    }

    // Function to set Document (D) from a file
    static void Set_D(fstream& Document, vector<string>& D)
    {
        string word;
        char ch;
        while (Document.get(ch))
        {
            if (Check_character(ch)) 
                word.push_back(tolower(ch));
            else if (!word.empty())
            {
                D.push_back(word);
                word.clear();
            }
        }
        if (!word.empty()) 
            D.push_back(word);
        Document.close();
    }

    // Function to set Query (Q) from a text string
    static void Set_Q(string text, vector<string>& Q)
    {
        string word;
        for (char ch : text)
        {
            if (Check_character(ch)) 
                word.push_back(tolower(ch));
            else if (!word.empty())
            {
                Q.push_back(word);
                word.clear();
            }
        }
        if (!word.empty())
        {
            Q.push_back(word);
        }
    }
};


class StringSet
{
private:
    fstream Document;
    vector<string> D; // document set
    vector<string> Q; // query set
    bool Q_modified = false; // flag to track modifications in Q

    void Ensure_Unique(vector <string>& vec) 
    {
        Unique_Vector::Unique(vec);
        Q_modified = false;
    }

public:
    StringSet() {}
    
    void fromFile(string File_Name) 
    {
        HelperFunction::Check_File(File_Name, Document); 
        HelperFunction::Set_D(Document, D);
    }

    void fromText(string Text) 
    {
        HelperFunction::Set_Q(Text, Q);                  
        Q_modified = true;
    }

    void Add_Word(string new_word)
    {
        transform(new_word.begin(), new_word.end(), new_word.begin(), ::tolower);
        Q.emplace_back(new_word);
        Q_modified = true;
    }

    void Remove_Word(string text)
    {
        auto it = find(Q.begin(), Q.end(), text);
        if (it == Q.end()) 
            cout << "It's not found.\n";
        else {
            Q.erase(it);
            Q_modified = true;
        }
    }

    void Clear_Q() { Q.clear(); Q_modified = true; }

    int Get_size_Q () 
    {
        Ensure_Unique(Q);
        return Q.size();
    }

    void Display();

    StringSet operator+ (StringSet& s2)
    {
        StringSet s3;
        s3.Q.insert(s3.Q.end(), this->Q.begin(), this->Q.end());
        s3.Q.insert(s3.Q.end(), s2.Q.begin(), s2.Q.end());
        s3.Q_modified = true;
        s3.Ensure_Unique(Q);
        return s3;
    }

    StringSet operator* (StringSet& s2)
    {
        StringSet s3;
        for(auto& word : this->Q)
        {
            if (find(s2.Q.begin(), s2.Q.end(), word) != s2.Q.end())
                s3.Q.push_back(word);
        }
        s3.Q_modified = true;
        s3.Ensure_Unique(Q);
        return s3;
    }

    double Get_Computes()
    {
        Ensure_Unique(D);
        Ensure_Unique(Q);
        return Numerator() / (sqrt(Q.size()) * sqrt(D.size()));
    }

private:
    double Numerator()
    {
        ll count = 0;
        for(auto& word : this->D)
        {
            if (find(this->Q.begin(), this->Q.end(), word) != this->Q.end())
                count++;
        }
        return count;
    }

    friend class HelperFunction;
};


void StringSet::Display() 
{
    Ensure_Unique(Q);
    cout << "\nTable Format Representation:\n";
    cout << "+---------+------------+\n";
    cout << "| Index   | Word       |\n";
    cout << "+---------+------------+\n";
    for (size_t i = 0; i < Q.size(); ++i) 
    {
        cout << "| " << setw(7) << i << " | " << setw(10) << Q[i] << " |\n";
    }
    cout << "+---------+------------+\n\n";
}


void ahmedsheref2288()
{
    cout << "Creating StringSet from file...\n";
    StringSet s1;
    s1.fromFile("test.txt");
    s1.fromText("Hello world this is a test file This");
    cout << "Displaying contents of s1 (from file):\n";
    s1.Display();

    cout << "\nCreating StringSet from text...\n";
    StringSet s2;
    s2.fromText("hello world sample text");
    cout << "Displaying contents of s2 (from text):\n";
    s2.Display();

    cout << "\nAdding word 'additional' to s2's Q set:\n";
    s2.Add_Word("additional");
    s2.Display();

    cout << "\nRemoving word 'sample' from s2's Q set:\n";
    s2.Remove_Word("sample");
    s2.Display();

    cout << "\nUnion of s1 and s2:\n";
    StringSet unionSet = s1 + s2;
    unionSet.Display();

    cout << "\nIntersection of s1 and s2:\n";
    StringSet intersectionSet = s1 * s2;
    intersectionSet.Display();

    cout << "\nSize of Q in s1: " << s1.Get_size_Q() << nl;
    cout << "Size of Q in s2: " << s2.Get_size_Q() << nl;

    cout << "\nComputing similarity between s1 and s2:\n";
    cout << "Similarity: " << s1.Get_Computes() << nl;
}

int main()
{
    ahmedsheref2288();
    return 0;
}
