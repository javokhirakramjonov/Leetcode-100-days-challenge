class Solution {
public:
    vector<int> parents;

    int findPar(int n) {
        if (parents[n] == n)
            return n;
        return parents[n] = findPar(parents[n]);
    }

    void connect(int a, int b) {
        a = findPar(a);
        b = findPar(b);
        if (random() % 2)
            parents[a] = b;
        else
            parents[b] = a;
    }

    bool equationsPossible(vector<string> &equations) {
        srand(time(0));
        parents.resize(26);
        for (int i = 0; i < 26; ++i)
            parents[i] = i;
        for (string &x: equations) {
            if (x[1] == '=') {
                connect(x[0] - 'a', x[3] - 'a');
            }
        }
        for (string &x: equations) {
            if (x[1] == '!' && findPar(x[0] - 'a') == findPar(x[3] - 'a'))
                return false;
        }
        return true;
    }
};
