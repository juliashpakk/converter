// 8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int oper(char op) {
    if (op == '+')
        return 1;
    if (op == '*')
        return 2;
    return 0;
}

string infixToPostfix(string infix) {
    stack<char> s;
    string postfix;

    for (char c : infix) {
        if (isalnum(c))
            postfix += c;
        else {
            postfix += ' ';
            if (c == '(')
                s.push(c);
            else if (c == ')') {
                while (!s.empty() && s.top() != '(') {
                    postfix += s.top();
                    s.pop();
                }
                s.pop();
            }
            else {
                while (!s.empty() && oper(c) <= oper(s.top())) {
                    postfix += s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
    }

    while (!s.empty()) {
        postfix += ' ';
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    string infix = "ax*(bx+c)+c*d";
    string postfix = infixToPostfix(infix);
    cout << postfix << '\n';
    return 0;
}


//ax*(bx+c)+c*d  abc+c*d
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
