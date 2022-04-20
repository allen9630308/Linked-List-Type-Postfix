#include <unistd.h>
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int val;
    int layer;
    Node* child;
};

struct Node* push_back(Node* nodes, int value) {
    struct Node* h = nodes;
    if (nodes == NULL) {
        struct Node* head = new Node;
        head->val = value;
        head->layer = 0;
        head->child = NULL;

        return head;
    }
    while (nodes->child != NULL) {
        nodes = nodes->child;
    }
    struct Node* last = new Node;
    last->val = value;
    last->layer = nodes->layer + 1;
    last->child = NULL;
    nodes->child = last;

    return h;
}

struct Node* addfront(Node* nodes, int value) {
    struct Node* nhead = new Node;
    nhead->layer = 0;
    nhead->val = value;
    nhead->child = nodes;
    while (nodes != NULL) {
        nodes->layer++;
        nodes = nodes->child;
    }
    return nhead;
}

int find(Node* nodes, int target) {
    while (nodes != NULL) {
        if (nodes->val == target)
            return nodes->layer;
        else
            nodes = nodes->child;
    }
    cout << "target not found" << endl;
    return -1;
}

int size(Node* nodes) {
    if (nodes == NULL)
        return 0;
    else {
        while (nodes->child != NULL)
            nodes = nodes->child;
        return nodes->layer + 1;
    }
}

int getnum(Node* nodes, int checkid) {
    while (nodes->layer < checkid) {
        if (nodes->child == NULL) {
            cout << "invalid requirement" << endl;
            return -1;
        }
        nodes = nodes->child;
    }
    return nodes->val;
}

void printList(Node* nodes) {
    if (nodes == NULL) {
        cout << "NULL" << endl;
    }
    while (nodes) {
        cout << nodes->layer << " " << nodes->val << endl;
        nodes = nodes->child;
    }
}

struct Node* assign(int num, Node* nodes) {
    struct Node* head;

    if (nodes != NULL)
        return NULL;
    else {
        for (int k = 0; k < num; k++) {
            struct Node* tail = new Node;
            tail->val = 0;
            tail->layer = k;
            tail->child = NULL;

            if (nodes == NULL) {
                nodes = tail;
                head = nodes;
            } else {
                nodes->child = tail;
                nodes = nodes->child;
            }
        }
    }
    return head;
}

struct Node* copy(Node* nodes) {
    struct Node* shead = NULL;
    struct Node* keep = NULL;
    while (nodes != NULL) {
        if (nodes->layer == 0) {
            shead = new Node;
            shead->layer = 0;
            shead->val = nodes->val;
            shead->child = NULL;
            keep = shead;
            nodes = nodes->child;
        } else {
            struct Node* last = new Node;
            last->layer = nodes->layer;
            last->val = nodes->val;
            last->child = NULL;
            shead->child = last;
            shead = shead->child;
            nodes = nodes->child;
        }
    }
    return keep;
}

struct Node* erase(int num, Node* nodes) {
    struct Node* head;
    head = nodes;

    if (num == 0 && nodes->child == NULL) {
        head = NULL;
    }

    for (int k = 0; k < num; k++) {
        if (nodes->child == NULL) {
            cout << "layer not found" << endl;
            break;
        }
        if (nodes->child->layer == num) {
            nodes->child = nodes->child->child;
            while (nodes->child != NULL) {
                nodes->child->layer -= 1;
                nodes = nodes->child;
            }
            break;
        }
        nodes = nodes->child;
    }
    return head;
}

bool empty(Node* nodes) {
    if (nodes == NULL)
        return true;
    else
        return false;
}

struct Node* rvs(Node* nodes) {
    int sum = size(nodes) - 1;
    struct Node* ant = nodes;
    struct Node* keep = nodes;
    for (int k = 0; k <= sum / 2; k++) {
        while (ant->layer < (sum - k))
            ant = ant->child;
        int tmp = nodes->val;
        nodes->val = ant->val;
        ant->val = tmp;
        ant = nodes;
        nodes = nodes->child;
    }
    return keep;
}

void mdf(int id, int newv, Node* nodes) {
    if (nodes == NULL) {
        cout << "layer not found" << endl;
        return;
    }
    for (int k = 0; k <= id; k++) {
        if (nodes->layer == id) {
            nodes->val = newv;
            return;
        }
        if (nodes->child == NULL) {
            cout << "layer not found" << endl;
            break;
        }
        nodes = nodes->child;
    }
    return;
}

struct Node* insert(Node* nodes, int pos, int newv) {
    struct Node* head = nodes;
    while (nodes->layer < pos - 1) {
        nodes = nodes->child;
    }
    if (nodes->layer == pos - 1) {
        struct Node* tmp = nodes->child;
        struct Node* mid = new Node;
        mid->layer = nodes->layer;
        mid->val = newv;
        mid->child = tmp;
        nodes->child = mid;
        while (mid != NULL) {
            mid->layer++;
            mid = mid->child;
        }
        return head;
    } else {
        cout << "wrong instruction" << endl;
        return NULL;
    }
}

struct Node* extend(int count, Node* nodes) {
    struct Node* keep = nodes;
    while (nodes->child != NULL) {
        nodes = nodes->child;
    }
    while (count != 0) {
        struct Node* last = new Node;
        last->val = 0;
        last->child = NULL;
        last->layer = nodes->layer + 1;
        nodes->child = last;
        nodes = nodes->child;
        count--;
    }
    return keep;
}

struct Node* pop_back(struct Node* nodes) {
    return erase(size(nodes) - 1, nodes);
}

struct Node* clear(Node* nodes) {
    while (nodes != NULL)
        nodes = pop_back(nodes);
    return nodes;
}

//////////////////////////

struct Node* stack_push(struct Node* nodes, int newv) {
    return push_back(nodes, newv);
}

struct Node* stack_pop(struct Node* nodes) {
    return pop_back(nodes);
}

int stack_top(struct Node* nodes) {
    return getnum(nodes, size(nodes) - 1);
}

bool stack_isempty(struct Node* nodes) {
    return empty(nodes);
}

//////////////////////////

bool queue_isempty(struct Node* nodes) {
    return empty(nodes);
}

int queue_peakrear(struct Node* nodes) {
    return getnum(nodes, size(nodes) - 1);
}

int queue_peak(struct Node* nodes) {
    if (nodes != NULL)
        return nodes->val;
    else
        return -1;
}

int queue_size(struct Node* nodes) {
    return size(nodes);
}

bool queue_isfull(struct Node* nodes, int length) {
    if (size(nodes) < length)
        return false;
    else
        return true;
}

struct Node* queue_enqueue(struct Node* nodes, int newv) {
    return push_back(nodes, newv);
}

struct Node* queue_dequeue(struct Node* nodes) {
    return erase(0, nodes);
}
