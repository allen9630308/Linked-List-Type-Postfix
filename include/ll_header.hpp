struct Node {
    int val;
    int layer;
    Node* child;
};

struct Node* push_back(Node* nodes, int value);

struct Node* addfront(Node* nodes, int value);

int find(Node* nodes, int target);

int size(Node* nodes);

int getnum(Node* nodes, int checkid);

void printList(Node* nodes);

struct Node* assign(int num, Node* nodes);

struct Node* copy(Node* nodes);

struct Node* erase(int num, Node* nodes);

bool empty(Node* nodes);

struct Node* rvs(Node* nodes);

void mdf(int id, int newv, Node* nodes);

struct Node* insert(Node* nodes, int pos, int newv);

struct Node* extend(int count, Node* nodes);

struct Node* pop_back(struct Node* nodes);

struct Node* clear(Node* nodes);

struct Node* stack_push(struct Node* nodes, int newv);

struct Node* stack_pop(struct Node* nodes);

int stack_top(struct Node* nodes);

bool stack_isempty(struct Node* nodes);

bool queue_isempty(struct Node* nodes);

int queue_peakrear(struct Node* nodes);

int queue_peak(struct Node* nodes);

int queue_size(struct Node* nodes);

bool queue_isfull(struct Node* nodes, int length);

struct Node* queue_enqueue(struct Node* nodes, int newv);

struct Node* queue_dequeue(struct Node* nodes);
