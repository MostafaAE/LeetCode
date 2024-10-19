class Solution {
public:
    char findKthBit(int n, int k) 
    {
        string nthStr = constructStr(n);
    
        return nthStr[k-1];
    }
    
    string constructStr(int n)
    {
        if(n == 1)
            return "0";
        
        string prev = constructStr(n - 1);
        
        return prev + "1" + revInv(prev);
    }
    
    string revInv(string str)
    {
        for(int i = 0 ; i < str.size() ; ++i)
            str[i] = str[i] == '0' ? '1' : '0';
        
        reverse(str.begin(), str.end());
        return str;
    }
};