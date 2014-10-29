#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
#include "stdlib.h"
#include "stdio.h"
#include <memory.h>
#include <algorithm>

using namespace std;

float weight[1024][1024];
float lx [1024], ly [1024];
bool sx [1024], sy [1024];
int match [1024];

void set_customers(string customers, int* num_vowels, int* num_letters_customers){
    stringstream word_s(customers);
    string word;
    int curr = 0;
    while(getline(word_s, word, ',')){
        for(unsigned int i=0; i<word.length(); i++){
            if(word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u' || word[i] == 'y' || word[i] == 'A' || word[i] == 'E' || word[i] == 'I' || word[i] == 'O' || word[i] == 'U' || word[i] == 'Y')
                num_vowels[curr]++;
            if(word[i]<='Z' && word[i]>='A' || word[i]<='z' && word[i]>='a')
                num_letters_customers[curr]++;
        }
        curr++;
    }
}

void set_products(string products, int* num_letters_products){
    stringstream word_s(products);
    string word;
    int curr = 0;
    while(getline(word_s, word, ',')){
        for(unsigned int i=0; i<word.length(); i++){
            if(word[i]<='Z' && word[i]>='A' || word[i]<='z' && word[i]>='a')
                num_letters_products[curr]++;
        }
        curr++;
    }
}

void count_customers_products(string s, int& num_customers, int& num_products){
    num_customers = 0;
    num_products = 0;
    string customers = s.substr(0, s.find(';'));
    string products = s.substr(s.find(';'));
    for(unsigned int i=0; i<customers.length(); i++)
        if(customers[i] == ',')
            num_customers++;
    for(unsigned int i=0; i<products.length(); i++)
        if(products[i] == ',')
            num_products++;
    num_customers++;
    num_products++;
}

int gcd(int a, int b)
{
    int r;
    while(b)
    {
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

bool path(int u, int n){  
    sx [u] = true;  
    for (int v = 0; v < n; v ++)  
        if (!sy [v] && lx[u] + ly [v] == weight [u] [v]){  
            sy [v] = true;  
            if (match [v] == -1 || path (match [v], n)){  
                match [v] = u;  
                return true;
            }  
        }  
    return false;  
} 
 
float bestmatch (bool maxsum, int n){  
    int i, j;  
    if (!maxsum){  
        for (i = 0; i < n; i ++)  
            for (j = 0; j < n; j ++)  
                weight [i] [j] = -weight [i] [j];
    }  
    for (i = 0; i < n; i ++){  
        lx [i] = 1E-37;  
        ly [i] = 0;  
        for (j = 0; j < n; j ++)  
            if (lx [i] < weight [i] [j])  
                lx [i] = weight [i] [j];
    }  
    memset (match, -1, sizeof (match));  
    for (int u = 0; u < n; u ++)  
        while (1){  
            memset (sx, 0, sizeof (sx));  
            memset (sy, 0, sizeof (sy));  
            if (path(u, n))  
                break;  
            float dx = 1E+37;  
            for (i = 0; i < n; i ++)  
                if (sx [i])  
                    for (j = 0; j < n; j ++)  
                        if(!sy [j])  
                            dx = min (lx[i] + ly [j] - weight [i] [j], dx);  
            for (i = 0; i < n; i ++){  
                if (sx [i])  
                    lx [i] -= dx;  
                if (sy [i])  
                    ly [i] += dx;
            }
        }  
    float sum = 0;  
    for (i = 0; i < n; i ++)  
        sum += weight [match [i]] [i];  
    if (!maxsum){  
        sum = -sum;  
        for (i = 0; i < n; i ++)  
            for (j = 0; j < n; j ++)  
                weight [i] [j] = -weight [i] [j];
    }  
    return sum;  
}

int main(int argc, char** cmd){
    ifstream fin(cmd[1]);
    string line;
    while(getline(fin, line)){
        string customers, products;
        customers = line.substr(0, line.find(';'));
        products = line.substr(line.find(';')+1);
        int num_customers = 0;
        int num_products = 0;
        count_customers_products(line, num_customers, num_products);
        int num_vowels[num_customers];
        int num_letters_customers[num_customers];
        int num_letters_products[num_products];
        for(int i=0; i<num_customers; i++){
            num_vowels[i] = 0;
            num_letters_customers[i] = 0;
        }
        for(int i=0; i<num_products; i++)
            num_letters_products[i] = 0;
        set_customers(customers, num_vowels, num_letters_customers);
        set_products(products, num_letters_products);
        int num = num_customers>num_products?num_customers:num_products;
        for(int i=0; i<num; i++){
            for(int j=0; j<num; j++){
                if(i>=num_customers || j>=num_products){
                    weight[i][j] = 0;
                    continue;
                }
                if(num_letters_products[j] % 2 == 0){
                    weight[i][j] = 1.5*num_vowels[i];
                }
                else{
                    weight[i][j] = num_letters_customers[i]-num_vowels[i];
                }
                if(gcd(num_letters_customers[i], num_letters_products[j]) != 1)
                    weight[i][j] *= 1.5;
            }
        }
        float cost = bestmatch(true, num);
        printf("%.2f\n", cost);
    }
    return 0;
}

