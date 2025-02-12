// File: A1_T1_NULL_20230542
// Purpose: provide for text correction, prime number, domino chain validation, && word replacement in Arabic words.
// Author: Ahmed sheref sayed ahmed
// Section: None
// ID: 20230542
// TA: Mohamed Elramly
// Date: 10 Oct 2024


#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <map>
#include <locale>
#include <codecvt>
#include <sstream>
#include <fstream>
#include <cstring>
#include <cctype>
using namespace std;

//----------------------------------------------------
void setColor(const string &colorCode) 
{
    cout << "\033[" << colorCode << "m";
}
void resetColor()                
{
    cout << "\033[0m";
}
int validInput(int min, int max, string message);

//----------------------------------------------------
//----------------------------------------------------

string Correct_text (string text);                                 // task_1

//----------------------------------------------------

void Sieve(long long n);
void Print_Primes (long long n);                                  // task_4

//----------------------------------------------------

struct dominoT 
{
    int leftDots;
    int rightDots;
};
bool FormsDominoChain(vector<pair<dominoT, bool>>& dominos, vector<dominoT>& chain);        // task_7
//----------------------------------------------------

map<wstring, wstring> replacements = 
{
    {L"شرطة", L"أمن"},
    {L"الشرطة", L"الأمن"},
    {L"سياسي", L"مستشار"},
    {L"السياسي", L"المستشار"},
    {L"عقوبات", L"إجراءات"},
    {L"العقوبات", L"الإجراءات"},
    {L"قانون", L"لوائح"},
    {L"القانون", L"اللائحة"},
    {L"سجن", L"مركز احتجاز"},
    {L"السجن", L"مركز الاحتجاز"},
    {L"سلاح", L"أداة"},
    {L"السلاح", L"الأداة"},
    {L"ثورة", L"تغيير"},
    {L"الثورة", L"التغيير"},
    {L"شهيد", L"بطل"},
    {L"الشهيد", L"البطل"},
    {L"معارض", L"منتقد"},
    {L"المعارض", L"المنتقد"},
    {L"حظر", L"قيود"},
    {L"الحظر", L"القيود"},
    {L"احتلال", L"تواجد عسكري"},
    {L"الاحتلال", L"التواجد العسكري"},
    {L"استقلال", L"سيادة"},
    {L"الاستقلال", L"السيادة"},
    {L"حرب", L"نزاع"},
    {L"الحرب", L"النزاع"},
    {L"صراع", L"خلاف"},
    {L"الصراع", L"الخلاف"},
    {L"عدو", L"خصم"},
    {L"العدو", L"الخصم"},
    {L"قتل", L"إصابة"},
    {L"القتل", L"الإصابة"},
    {L"هجوم", L"عملية"},
    {L"الهجوم", L"العملية"},
    {L"مظاهرة", L"تجمع شعبي"},
    {L"المظاهرة", L"التجمع الشعبي"},
    {L"المظاهرات", L"التجمع الشعبي"},
    {L"فوضى", L"اضطراب"},
    {L"الفوضى", L"الاضطراب"},
    {L"سيطرة", L"نفوذ"},
    {L"السيطرة", L"النفوذ"},
    {L"نزاع", L"مسألة"},
    {L"النزاع", L"المسألة"},
    {L"معركة", L"مواجهة"},
    {L"المعركة", L"المواجهة"},
    {L"تهديد", L"تحذير"},
    {L"التهديد", L"التحذير"},
    {L"تدمير", L"إضرار"},
    {L"التدمير", L"الإضرار"},
    {L"مجاهد", L"مقاوم"},
    {L"المجاهد", L"المقاوم"},
    {L"قنبلة", L"جهاز"},
    {L"القنبلة", L"الجهاز"},
    {L"جيش", L"قوات"},
    {L"الجيش", L"القوات"},
    {L"مقاومة", L"صمود"},
    {L"المقاومة", L"الصمود"},
    {L"عدوان", L"اعتداء"},
    {L"العدوان", L"الاعتداء"},
    {L"ارهاب", L"تطرف"},
    {L"الإرهاب", L"التطرف"},
    {L"حصار", L"ضغط"},
    {L"الحصار", L"الضغط"},
    {L"هجرة", L"انتقال"},
    {L"الهجرة", L"الانتقال"},
    {L"تفرقة", L"اختلاف"},
    {L"التفرقة", L"الاختلاف"},
    {L"خسارة", L"تراجع"},
    {L"الخسارة", L"التراجع"},
    {L"انسحاب", L"تراجع تكتيكي"},
    {L"الانسحاب", L"التراجع التكتيكي"},
    {L"عنف", L"توتر"},
    {L"العنف", L"التوتر"},
    {L"مقاتل", L"محارب"},
    {L"المقاتل", L"المحارب"},
    {L"تهجير", L"ترحيل"},
    {L"التهجير", L"الترحيل"},
    {L"حظر", L"منع"},
    {L"الحظر", L"المنع"}
};

void Reblace_Words();                                               // task_10


//----------------------------------------------------

int main() 
{
    while (true)
    {
        setColor("1;30");
        cout << "---------------------------------------------------------------------------\n";
        cout << "                       Welcome to our Programme\n";
        cout << "---------------------------------------------------------------------------\n";
        cout << "✨ Choose Your Adventure! ✨\n";
        cout << "1️⃣  * Text Magician *\n";
        cout << "2️⃣  * Prime Hunter *\n";
        cout << "3️⃣  * Domain Detective *\n";
        cout << "4️⃣  * Article Sensei *\n";
        cout << "---------------------------------------------------------------------------\n";
        resetColor();
        
        int number = validInput(1, 4, "Please select one of the options (1-4): ");

        switch (number)
        {
            case 1:
            {
                string text_before_corrected;
                char ch;
                int limit = 100;
                cout << "Enter text (end with '.' or reach 100 characters):\n";
                while (cin.get(ch))
                {
                    if (ch == '.')
                    {
                        text_before_corrected += ch;
                        break;
                    }
                    if(text_before_corrected.size() >= limit)
                    {
                        text_before_corrected += ch;
                        break;
                    }
                    text_before_corrected += ch;
                }
                cout << Correct_text(text_before_corrected) << endl;
                break;
            }

            case 2:
            {
                long long num = validInput(1, 1000000000, "Enter the maximum number to find primes within (up to 1,000,000,000): ");
                Sieve(num);
                Print_Primes(num);
                // cout << "---------------------------------------------------------------------------\n";
                break;
            }

            case 3:
            {
                int siz;
                cout << "How many domino do you have? -> "; 
                siz = validInput(1,100," ");
                vector<pair<dominoT, bool>> vc_1(siz);
                vector<dominoT> chain1;
                for (int i = 0; i < siz; i++)
                {
                    vc_1[i].first.leftDots = validInput(0,6," ");
                    vc_1[i].first.rightDots = validInput(0,6," ");
                    vc_1[i].second = false;
                }
                if (FormsDominoChain(vc_1, chain1))
                {
                    cout << "A valid Possiple: ";
                    for (const auto& domino : chain1) 
                    {
                        cout << domino.leftDots << "|" << domino.rightDots << " ";
                    }
                    cout << endl;
                }
                else
                {
                    cout << "No valid Possiple." << endl;
                }
                break;
            }

            case 4:
            {
                Reblace_Words();
                break;
            }
        }
        int statue_of_programm;
        // cout << "1️.* Again\n* 2️.* End *;
        cout << "\n---------------------------------------------------------------------------\n\n";
        cout << "1. *Again*\n2. *End*\n-> ";
        cin.ignore();
        cin >> statue_of_programm;
        if (statue_of_programm == 1) continue;
        else break;
    }
}

//----------------------------------------------------
//----------------------------------------------------
//----------------------------------------------------


int validInput(int min, int max, string message)
{
    string input;
    int number = 0;
    bool valid = false;
    while (!valid) 
    {
        cout << message;
        cin >> input;
        try 
        {
            for (char c : input) 
            {
                if (!isdigit(c)) 
                {
                    throw "Please enter a valid number!";
                }
            }
            number = stoi(input);
            if (number < min || number > max) 
            {
                throw "Number out of valid range!";
            }
            valid = true;
        }
        catch (...) 
        {
            cout << "Unknown error occurred. Please try again.\n";
        }
    }
    return number;
}

//----------------------------------------------------
string Correct_text (string text)
{
    long long siz = text.size();
    string temp = "";
    bool check_after_space = false;
    long long start = 0;

    while (isspace(text[start]) || text[start] == ',') start++;
    
    for(long long i = start; i < siz; i++)
    {
        if (text[i] == '\n' && !isspace(temp.back())) 
        {
            temp.push_back(' ');
            continue;
        }

        if (text[i] != ',' && !isspace(text[i])) 
        {
            temp.push_back(isalpha(text[i]) ? tolower(text[i]) : text[i]);
        }
        else if (text[i] == ',')
        {
            while (temp.back() == ' ')
                temp.pop_back();

            if (temp.back() != ',') temp.push_back(',');

            while (i + 1 < siz && isspace(text[i + 1])) 
            {
                i++;
            }

            if (i + 1 < siz && text[i + 1] != ',')
                temp.push_back(' ');
        }
        else if (isspace(text[i]))
        {
            if (!isspace(temp.back()) && temp.back() != ',')
            {
                temp.push_back(' ');
            }
        }
    }

    if (temp.back() != '.') temp.push_back('.');
    while(isspace(*(temp.end() - 2)) || *(temp.end() - 2) == ',') temp.erase(temp.end() - 2);

    temp[0] = toupper(temp[0]);

    return temp;
}






//----------------------------------------------------
const int N = 1e7;

bool prime[N];

void Sieve(long long n)
{
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    for(long long p = 2; p * p <= n; p++)
    {
        if (prime[p])
        {
            for(long long i = p * p; i <= n; i += p)
            {
                prime[i] = false;
            }
        }
    }
}

void Print_Primes (long long n)
{
    cout << "Prime numbers up to " << n << ":\n";
    int count = 0;
    for (long long i = 0; i <= n; i++) 
    {
        if (prime[i]) 
        {
            cout << setw(4) << i << ' ';
            count++;
            if (count % 10 == 0) 
            {
                cout << endl;
            }
        }
    }
    if (n <= 1) cout << "None\n";
    cout << endl;
}



bool CanFormDominoChain(vector<pair<dominoT, bool>>& dominos, vector<dominoT>& chain, int matched_dots) 
{
    if (chain.size() == dominos.size()) 
    {
        return true;
    }
    for (int i = 0; i < dominos.size(); i++) 
    {
        if (dominos[i].second) 
        {
            continue;
        }
        if (dominos[i].first.leftDots == matched_dots) 
        {
            dominos[i].second = true;
            chain.push_back(dominos[i].first);
            if (CanFormDominoChain(dominos, chain, dominos[i].first.rightDots)) 
            {
                return true;
            }
            chain.pop_back();
            dominos[i].second = false;
        }
    }
    return false;
}

bool FormsDominoChain(vector<pair<dominoT, bool>>& dominos, vector<dominoT>& chain) 
{
    for (int i = 0; i < dominos.size(); i++) 
    {
        chain.clear();
        vector<pair<dominoT, bool>> dominos_copy = dominos;

        dominos_copy[i].second = true;
        chain.push_back(dominos_copy[i].first);

        if (CanFormDominoChain(dominos_copy, chain, dominos_copy[i].first.rightDots)) 
        {
            return true;
        }
    }

    return false;
}




//----------------------------------------------------

void Reblace_Words()
{
    wstring File_Name;
    wstring Consle_Out;
    cout << "File_Name: ";
    wcin >> File_Name;

    wfstream article(File_Name.c_str(), ios::in);
    article.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>)); 

    if (!article.is_open()) 
    {
        wcerr << L"Failed to open: " << File_Name << endl;
        return;
    }

    wfstream New_article(L"Output.txt", ios::out);
    New_article.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));

    if (!New_article.is_open()) 
    {
        wcerr << L"Failed to open" << endl;
        return;
    }

    wstring line;
    while (getline(article, line)) 
    {
        wstringstream wss(line);
        wstring word;
        wstring modified_line;

        while (wss >> word) 
        {
            if (replacements.find(word) != replacements.end()) 
            {
                modified_line += replacements[word] + L" ";
            } 
            else 
            {
                modified_line += word + L" ";
            }
        }

        New_article << modified_line << endl;
    }

    article.close();
    New_article.close();

    wcout << L"Processing completed. Modified content saved to 'Output.txt'." << endl;
}