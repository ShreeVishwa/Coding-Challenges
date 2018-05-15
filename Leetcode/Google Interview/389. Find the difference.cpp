//Xor gives the fastest solution and it takes around 4ms to run the program

class Solution {
public:
    char findTheDifference(string s, string t) {
        long long int sum1 = 0;
        long long int sum2 = 0;
        for(int i=0;i<s.length();i++){
            sum1 ^= s[i];
            sum1 ^= t[i];
        }
        sum1 ^= t[t.length()-1];
        return sum1;
    }
};

// Another simple approach is to find the sum of all the characters and then finding the difference in the sum to get the resultant extra digit

class Solution {
public:
    char findTheDifference(string s, string t) {
        long long int sum1 = 0;
        long long int sum2 = 0;
        for(int i=0;i<s.length();i++){
            sum1 += s[i] - 'a';
        }
        for(int j=0;j<t.length();j++){
            sum2 += t[j] - 'a';
        }
        long long int diff = sum1 > sum2 ? sum1 - sum2 : sum2 - sum1;
        cout<<diff<<endl;
        return diff+'a';
    }
};

//Another solution one can think of is using a hash map which is also efficient as the above but would require and additional space to store
// the counts of the digits.

class Solution {
public:
    char findTheDifference(string s, string t) {
        int count[26];
        for(int i=0;i<26;i++) count[i] = 0;
        for(int i=0;i<s.length();i++){
            count[s[i]-'a']++;
            count[t[i]-'a']--;
        }
        count[t[t.length()-1]-'a']--;
        for(int i=0;i<26;i++){
            if(count[i] < 0) return i+'a';
        }
    }
};
