#include <iostream>
#include <string>
using namespace std;
// 1. LINKED LIST: Transaction History
class TransactionNode {
public:
    string description;
    double amount;
    TransactionNode* next;

    TransactionNode(string desc, double amt) {
        description = desc;
        amount = amt;
        next = NULL;
    }
};

class TransactionHistory {
private:
    TransactionNode* head;
public:
    TransactionHistory() { head = NULL; }

    void addTransaction(string desc, double amt) {
        TransactionNode* newNode = new TransactionNode(desc, amt);
        newNode->next = head; // Naya kharcha sabse upar dikhega
        head = newNode;
        cout << "[SUCCESS] Transaction Added: " << desc << " (Rs. " << amt << ")\n";
    }

    void displayHistory() {
        if (head == NULL) {
            cout << "\nNo transactions found!\n";
            return;
        }
        cout << "\n--- Transaction History ---\n";
        TransactionNode* temp = head;
        while (temp != NULL) {
            cout << "- " << temp->description << ": Rs. " << temp->amount << "\n";
            temp = temp->next;
        }
    }
};
// 2. STACK: Undo System
class ActionNode {
public:
    string actionType;
    ActionNode* next;

    ActionNode(string type) {
        actionType = type;
        next = NULL;
    }
};

class UndoStack {
private:
    ActionNode* top;
public:
    UndoStack() {
        top = NULL;
        }

    void pushAction(string type) {
        ActionNode* newNode = new ActionNode(type);
        newNode->next = top;
        top = newNode;
    }

    string popAction() {
        if (top == NULL) return "";
        ActionNode* temp = top;
        string type = temp->actionType;
        top = top->next;
        delete temp;
        return type;
    }

    bool isEmpty() { 
        return top == NULL;
        }
};
// 3. BINARY SEARCH TREE (BST): Expense Search
class TreeNode {
public:
    double amount;
    TreeNode* left;
    TreeNode* right;

    TreeNode(double amt) {
        amount = amt;
        left = NULL;
        right = NULL;
    }
};

class ExpenseTree {
private:
    TreeNode* root;

    TreeNode* insertNode(TreeNode* node, double amt) {
        if (node == NULL) return new TreeNode(amt);
        if (amt < node->amount) 
            node->left = insertNode(node->left, amt);
        else 
            node->right = insertNode(node->right, amt);
        return node;
    }

    void inOrderTraversal(TreeNode* node) {
        if (node == NULL) return;
        inOrderTraversal(node->left);
        cout << "Rs. " << node->amount << " | ";
        inOrderTraversal(node->right);
    }

public:
    ExpenseTree() { 
        root = NULL;
        }

    void insert(double amt) { 
        root = insertNode(root, amt);
        }

    void displaySortedExpenses() {
        if (root == NULL) {
            cout << "\nNo data in tree!\n";
            return;
        }
        cout << "\nSorted Expenses (Low to High): ";
        inOrderTraversal(root);
        cout << "\n";
    }
};
// 4. QUEUE: Live Stock Order Processing
class OrderNode {
public:
    string stockName;
    string orderType; // Buy or Sell
    OrderNode* next;

    OrderNode(string name, string type) {
        stockName = name;
        orderType = type;
        next = NULL; 
    }
};

class StockOrderQueue {
private:
    OrderNode* front;
    OrderNode* rear;
public:
    StockOrderQueue() {
        front = rear = NULL; 
        
    }

    void enqueueOrder(string name, string type) {
        OrderNode* newNode = new OrderNode(name, type);
        if (rear == NULL) {
            front = rear = newNode;
            cout << "[QUEUE] Order placed in queue: " << type << " " << name << "\n";
            return;
        }
        rear->next = newNode;
        rear = newNode;  
        cout << "[QUEUE] Order placed in queue: " << type << " " << name << "\n";
    }

    void dequeueAndProcess() {
        if (front == NULL) {
            cout << "\nNo pending stock orders to process!\n";
            return;
        }
        OrderNode* temp = front;
        cout << "\n[PROCESSING] Executing " << temp->orderType << " order for stock: " << temp->stockName << "...\n";
        front = front->next;
        if (front == NULL) rear = NULL;
        delete temp;
        cout << "[SUCCESS] Order Executed!\n";
    }

    void displayQueue() {
        if (front == NULL) {
            cout << "\nNo pending orders in the queue.\n";
            return;
        }
        cout << "\n--- Pending Stock Orders ---\n";
        OrderNode* temp = front;
        while (temp != NULL) {
            cout << "[" << temp->orderType << "] -> " << temp->stockName << "\n";
            temp = temp->next;
        }
    }
};
// MAIN APP ENGINE

int main() {
    TransactionHistory history;
    UndoStack undo;
    ExpenseTree tree;
    StockOrderQueue orderQueue;

    int choice;
    do {
        cout << "\n====================================" << endl;
        cout << "      FinTrack: Personal Finance     " << endl;
        cout << "====================================" << endl;
        cout << "1. Add Expense/Income (Linked List)" << endl;
        cout << "2. View All Transactions (Linked List Display)" << endl;
        cout << "3. Undo Last Action (Stack)" << endl;
        cout << "4. View Sorted Expenses (Tree Traversal)" << endl;
        cout << "5. Place Stock Order (Queue Enqueue)" << endl;
        cout << "6. Process Next Stock Order (Queue Dequeue)" << endl;
        cout << "7. View Pending Stock Orders (Queue Display)" << endl;
        cout << "0. Exit Application" << endl;
        cout << "------------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string desc; double amt;
            cout << "Enter Description (e.g., Food, Salary): ";
            cin >> desc;
            cout << "Enter Amount: ";
            cin >> amt;
            history.addTransaction(desc, amt);
            tree.insert(amt);
            undo.pushAction("Added Transaction (" + desc + ")");
        }
        else if (choice == 2) {
            history.displayHistory();
        }
        else if (choice == 3) {
            string undoneAction = undo.popAction();
            if (undoneAction != "") {
                cout << "[UNDO] Reversed action: " << undoneAction << endl;
            } else {
                cout << "[ALERT] Nothing to undo!" << endl;
            }
        }
        else if (choice == 4) {
            tree.displaySortedExpenses();
        }
        else if (choice == 5) {
            string name, type;
            cout << "Enter Stock Ticker (e.g., AAPL, GOOG): ";
            cin >> name;
            cout << "Enter Order Type (Buy/Sell): ";
            cin >> type;
            orderQueue.enqueueOrder(name, type);
        }
        else if (choice == 6) {
            orderQueue.dequeueAndProcess();
        }
        else if (choice == 7) {
            orderQueue.displayQueue();
        }
    } while (choice != 0);

    cout << "\nThank you for using FinTrack Engine!\n";
    return 0;
}
