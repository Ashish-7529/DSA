class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> sk;

        for (string val : tokens) {

            if (val != "+" && val != "-" && val != "*" && val != "/") {
                sk.push(stoi(val));
            } else {
                int b = sk.top();
                sk.pop();

                int a = sk.top();
                sk.pop();

                switch (val[0]) {
                    case '+':
                        sk.push(a + b);
                        break;
                    case '-':
                        sk.push(a - b);
                        break;
                    case '*':
                        sk.push(a * b);
                        break;
                    case '/':
                        sk.push(a / b);
                        break;
                }
            }
        }

        return sk.top();
    }
};