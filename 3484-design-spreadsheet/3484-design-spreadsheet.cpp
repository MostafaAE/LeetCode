class Spreadsheet {
private:
    unordered_map<string, int> cellToValue;
public:
    Spreadsheet(int rows) 
    {
    }
    
    void setCell(string cell, int value) 
    {
        cellToValue[cell] = value;
    }
    
    void resetCell(string cell) 
    {
        cellToValue[cell] = 0;
    }
    
    int getValue(string formula) 
    {
        int idx = formula.find('+');

        string s1 = formula.substr(1, idx-1), s2 = formula.substr(idx + 1);

        int left = isdigit(s1[0]) ? stoi(s1) : cellToValue[s1];
        int right = isdigit(s2[0]) ? stoi(s2) : cellToValue[s2];

        return left + right;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */