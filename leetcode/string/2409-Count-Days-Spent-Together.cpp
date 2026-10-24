
class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        vector<int> arr = {31, 28, 31, 30, 31, 30,
                           31, 31, 30, 31, 30, 31};

        vector<int> pre(12);
        pre[0] = arr[0];

        for (int i = 1; i < 12; i++) {
            pre[i] = pre[i - 1] + arr[i];
        }

        int x1, x2, y1, y2;
        string a, b;
        int m;

        a = arriveAlice.substr(0, 2);
        b = arriveAlice.substr(3, 2);
        m = stoi(a);
        x1 = (m == 1 ? 0 : pre[m - 2]);
        m = stoi(b);
        x1 += m;

        a = leaveAlice.substr(0, 2);
        b = leaveAlice.substr(3, 2);
        m = stoi(a);
        x2 = (m == 1 ? 0 : pre[m - 2]);
        m = stoi(b);
        x2 += m;

        a = arriveBob.substr(0, 2);
        b = arriveBob.substr(3, 2);
        m = stoi(a);
        y1 = (m == 1 ? 0 : pre[m - 2]);
        m = stoi(b);
        y1 += m;

        a = leaveBob.substr(0, 2);
        b = leaveBob.substr(3, 2);
        m = stoi(a);
        y2 = (m == 1 ? 0 : pre[m - 2]);
        m = stoi(b);
        y2 += m;

        int start = max(x1, y1);
        int end = min(x2, y2);

        int ans = end - start + 1;

        return max(0, ans);
    }
};
