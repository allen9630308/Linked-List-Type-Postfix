#include "ll_header.hpp"
int main() {
    struct Node* ll = NULL;
    ll = assign(5, ll);
    ll = push_back(ll, 10);
    ll = addfront(ll, 30);
    cout << getnum(ll, 3) << endl;
    cout << size(ll) << endl;
    struct Node* ll2 = copy(ll);
    ll2 = erase(2, ll2);
    mdf(1, 100, ll2);
    ll2 = rvs(ll2);
    ll2 = extend(3, ll2);
    cout << find(ll2, 0) << endl;
    printList(ll2);
}
