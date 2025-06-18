#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_EXPR_LEN 1000
#define MAX_VARS 26

void extract_vars(const char *expr, char *vars, int *var_count);
int compare_char(const void *a, const void *b);
void infix_to_postfix(const char *infix, char *postfix);
int get_priority(char op);
bool is_right_associative(char op);
int evaluate_postfix(const char *postfix, const int *assignment, const char *vars, int var_count);

int main() {
    char expr[MAX_EXPR_LEN];
    fgets(expr, MAX_EXPR_LEN, stdin);
    expr[strcspn(expr, "\n")] = '\0';

    char vars[MAX_VARS];
    int var_count = 0;
    extract_vars(expr, vars, &var_count);
    qsort(vars, var_count, sizeof(char), compare_char);

    char postfix[MAX_EXPR_LEN] = {0};
    infix_to_postfix(expr, postfix);
    for (int i = 0; i < var_count; i++) {
        printf("%c ", vars[i]);
    }
    printf("%s\n", expr); 
    int n = var_count;
    int total = 1 << n;
    for (int i = 0; i < total; i++) {
        int assignment[MAX_VARS];
        for (int j = 0; j < n; j++) {
            assignment[j] = (i >> (n-1 -j)) & 1;
        }
        int result = evaluate_postfix(postfix, assignment, vars, var_count);
        for (int j = 0; j < n; j++) {
            printf("%d ", assignment[j]);
        }
        printf("%d\n", result);
    }

    return 0;
}

void extract_vars(const char *expr, char *vars, int *var_count) {
    int index_map[26] = {0};
    int len = strlen(expr);
    for (int i = 0; i < len; i++) {
        char c = expr[i];
        if (islower(c) && index_map[c - 'a'] == 0) {
            vars[(*var_count)++] = c;
            index_map[c - 'a'] = 1;
        }
    }
    qsort(vars, *var_count, sizeof(char), compare_char);
}

int compare_char(const void *a, const void *b) {
    return (*(char*)a - *(char*)b);
}

void infix_to_postfix(const char *infix, char *postfix) {
    char stack[MAX_EXPR_LEN];
    int stack_top = -1;
    int postfix_len = 0;
    int len = strlen(infix);

    for (int i = 0; i < len; i++) {
        char c = infix[i];
        if (islower(c)) {
            postfix[postfix_len++] = c;
        } else if (c == '(') {
            stack[++stack_top] = c;
        } else if (c == ')') {
            while (stack_top >= 0 && stack[stack_top] != '(') {
                postfix[postfix_len++] = stack[stack_top--];
            }
            stack_top--;
        } else {
            while (stack_top >= 0 && stack[stack_top] != '(') {
                char top_op = stack[stack_top];
                int top_prio = get_priority(top_op);
                int curr_prio = get_priority(c);
                bool curr_right = is_right_associative(c);
                if ((!curr_right && curr_prio <= top_prio) ||
                    (curr_right && curr_prio < top_prio)) {
                    postfix[postfix_len++] = top_op;
                    stack_top--;
                } else {
                    break;
                }
            }
            stack[++stack_top] = c;
        }
    }
    while (stack_top >= 0) {
        postfix[postfix_len++] = stack[stack_top--];
    }
    postfix[postfix_len] = '\0';
}

int get_priority(char op) {
    switch (op) {
        case '!': return 5;
        case '&': return 4;
        case '|': return 3;
        case '>': return 2;
        case '-': return 1;
        case '(': return 0;
        default:  return -1;
    }
}

bool is_right_associative(char op) {
    return op == '!';
}

int evaluate_postfix(const char *postfix, const int *assignment, const char *vars, int var_count) {
    int stack[MAX_EXPR_LEN];
    int stack_top = -1;
    int len = strlen(postfix);

    for (int i = 0; i < len; i++) {
        char c = postfix[i];
        if (islower(c)) {
            for (int j = 0; j < var_count; j++) {
                if (vars[j] == c) {
                    stack[++stack_top] = assignment[j];
                    break;
                }
            }
        } else {
            if (c == '!') {
                int a = stack[stack_top--];
                stack[++stack_top] = !a;
            } else {
                int b = stack[stack_top--];
                int a = stack[stack_top--];
                int res;
                switch (c) {
                    case '&': res = a & b; break;
                    case '|': res = a | b; break;
                    case '>': res = !a | b; break;
                    case '-': res = (a == b); break;
                    default: exit(1);
                }
                stack[++stack_top] = res;
            }
        }
    }
    return stack[0];
}