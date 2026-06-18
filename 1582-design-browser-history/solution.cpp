class Node {
public:
    string val;
    Node* next;
    Node* back;
    Node(string data) {
        this->val = data;
        next = NULL;
        back = NULL;
    }
};
class BrowserHistory {
    Node* curr;
public:
    BrowserHistory(string homepage) {
        curr=new Node(homepage);
    }
    
    void visit(string url) {
        Node* temp = curr->next;
        while (temp) {
            Node* nxt = temp->next;
            delete temp;
            temp = nxt;
        }
        Node* newN = new Node(url);
        newN->back = curr;
        curr->next = newN;
        curr = newN;
    }
    
    string back(int steps) {
        while(steps){
            if(curr->back) curr=curr->back;
            else break;
            steps--;
        }
        return curr->val;
    }
    
    string forward(int steps) {
        while (curr->next && steps) {
            curr = curr->next;
            steps--;
        }
        return curr->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
