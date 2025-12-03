#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <climits>
#include "stack.h"
using namespace std;

int priority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

long long applyOp(long long a, long long b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0) {
                cout << "Error: Division by zero!" << endl;
                exit(1);
            }
            return a / b;
    }
    return 0;
}

long long evaluateExpression(const string& expr) {
    int n = expr.length();
    Stack<long long> values(n);
    Stack<char> ops(n);
    
    for (int i = 0; i < n; i++) {
        if (expr[i] == ' ') continue;
        
        else if (isdigit(expr[i])) {
            long long val = 0;
            
            while (i < n && isdigit(expr[i])) {
                val = val * 10 + (expr[i] - '0');
                i++;
            }
            i--;
            
            values.push(val);
        }
        
        else if (expr[i] == '(') {
            ops.push(expr[i]);
        }
        
        else if (expr[i] == ')') {
            while (!ops.isempty() && ops.peek() != '(') {
                long long val2 = values.pop();
                long long val1 = values.pop();
                char op = ops.pop();
                
                values.push(applyOp(val1, val2, op));
            }
            
            if (!ops.isempty()) ops.pop();
        }
        
        else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {

            while (!ops.isempty() && priority(ops.peek()) >= priority(expr[i])) {
                long long val2 = values.pop();
                long long val1 = values.pop();
                char op = ops.pop();
                
                values.push(applyOp(val1, val2, op));
            }
            
            ops.push(expr[i]);
        }
    }
    
    while (!ops.isempty()) {
        long long val2 = values.pop();
        long long val1 = values.pop();
        char op = ops.pop();
        
        values.push(applyOp(val1, val2, op));
    }
    
    return values.pop();
}
