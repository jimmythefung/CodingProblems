#include <iostream>
#include <unordered_map>

unordered_map<string, int>  buildFreq(const string &s){
    unordered_map<string, int> freq;
    for(string c:s){
        if (freq.count(c)==0){
            freq[c] = 1;
        }else{
            freq[c] += 1;
        }
    }
    return freq;
}

string longestPal(const string &s){
    unordered_map<string, int> freq = buildFreq(s);
    string L, M, R, c;
    M="";
    int count;
    
    for(auto it=freq.begin(); it!=freq.end(); it++){
        c = it->first;
        count = it->second;
        
        if(count>2){
            while(count>1){
                L=L+c;    // forward string
                R=c+R;    // reverse of L
                count=count-2;
            }
        }
        // either count is 1 to begin with or the left over is now 1
        if (count==1){
            M=c;
        }
    }
    
    return L+M+R;
}

void longPalTest(){
    string s = "gggaaa"
    cout << "Input s: " << s << endl;
    cout << "Longest Palindrome: " << longestPal(s) << endl;
}

int main(){
    longPalTest();
    return 0;
}
