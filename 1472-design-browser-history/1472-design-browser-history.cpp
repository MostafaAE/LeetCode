class BrowserHistory {
vector<string> history;
int idx{};
int actualSize{};
public:
    BrowserHistory(string homepage) 
    {
        history.push_back(homepage);
        idx = 0;
        actualSize = 1;
    }
    
    void visit(string url) 
    {
        if(idx == history.size() - 1)
        {
            ++idx;
            history.push_back(url);
        }
        else
        {
            ++idx;
            history[idx] = url;
        }
            
        actualSize = idx + 1;
    }
    
    string back(int steps) 
    {
        idx = max(0, idx - steps);

        return history[idx];
    }
    
    string forward(int steps) 
    {
        idx = min(actualSize - 1, idx + steps);

        return history[idx];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */