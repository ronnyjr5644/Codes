class BrowserHistory {
public:
    vector<string> URLsHistory;
    int currURL, lastURL;
    
    BrowserHistory(string homepage) {
        URLsHistory.push_back(homepage);
        currURL = 0;
        lastURL = 0;
    }
    
    void visit(string url) {
        currURL++;
        if (URLsHistory.size() > currURL) {
            URLsHistory[currURL] = url;
        }
        else {
            URLsHistory.push_back(url);
        }
        lastURL = currURL;
    }
    
    string back(int steps) {
        currURL = max(0, currURL - steps);
        return URLsHistory[currURL];
    }
    
    string forward(int steps) {
        currURL = min(lastURL, currURL + steps);
        return URLsHistory[currURL];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */