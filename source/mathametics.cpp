#include <string>
#include <iostream>
#include "ll_header.hpp"
using namespace std;

char num[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int main() {
    string s, ts;
    int flag = 0, cmp;
    cin >> s;
    s += ")";
    struct Node* opt = NULL;
    opt = push_back(opt, -5);
    struct Node* out = NULL;
    for (int k = 0; k < s.size(); k++) {
        flag = 0;
        for (int r = 0; r < 10; r++) {
            if (s[k] == num[r]) {
                ts += s[k];
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            continue;
        switch (s[k]) {
            case '(':
                opt = stack_push(opt, -5);
                break;
            case ')':
                if (ts != "") {
                    out = stack_push(out, stoi(ts));
                    ts = "";
                }
                while ((cmp = stack_top(opt)) != -5) {
                    out = stack_push(out, cmp);
                    opt = stack_pop(opt);
                }
                opt = stack_pop(opt);
                break;
            case '+':
                if (ts != "") {
                    out = stack_push(out, stoi(ts));
                    ts = "";
                }
                if (size(opt) > 0) {
                    while ((cmp = stack_top(opt)) > -5) {
                        out = stack_push(out, cmp);
                        opt = stack_pop(opt);
                        if (size(opt) == 0)
                            break;
                    }
                }
                opt = stack_push(opt, -3);
                break;
            case '-':
                if (ts != "") {
                    out = stack_push(out, stoi(ts));
                    ts = "";
                }
                if (size(opt) > 0) {
                    while ((cmp = stack_top(opt)) > -5) {
                        out = stack_push(out, cmp);
                        opt = stack_pop(opt);
                        if (size(opt) == 0)
                            break;
                    }
                }
                opt = stack_push(opt, -4);
                break;
            case '*':
                if (ts != "") {
                    out = stack_push(out, stoi(ts));
                    ts = "";
                }
                if (size(opt) > 0) {
                    while ((cmp = stack_top(opt)) > -3) {
                        out = stack_push(out, cmp);
                        opt = stack_pop(opt);
                        if (size(opt) == 0)
                            break;
                    }
                }
                opt = stack_push(opt, -1);
                break;
            case '/':
                if (ts != "") {
                    out = stack_push(out, stoi(ts));
                    ts = "";
                }
                if (size(opt) > 0) {
                    while ((cmp = stack_top(opt)) > -3) {
                        out = stack_push(out, cmp);
                        opt = stack_pop(opt);
                        if (size(opt) == 0)
                            break;
                    }
                }
                opt = stack_push(opt, -2);
                break;
            default:
                cout << "illegal input" << endl;
                break;
        }
    }
    while (size(opt) != 0) {
        cmp = stack_top(opt);
        out = stack_push(out, cmp);
        opt = stack_pop(opt);
    }
    while (out != NULL) {
        if (out->val < 0) {
            switch (out->val) {
                case -1:
                    cout << '*';
                    out = out->child;
                    break;
                case -2:
                    cout << '/';
                    out = out->child;
                    break;
                case -3:
                    cout << '+';
                    out = out->child;
                    break;
                case -4:
                    cout << '-';
                    out = out->child;
                    break;
            }
        } else {
            cout << out->val;
            out = out->child;
        }
    }
	cout << endl;
}
