class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {

        int n = cars.size();

        vector<double> answer(n, -1.0);

        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty()) {

                int j = st.top();

                if (cars[i][1] <= cars[j][1]) {
                    st.pop();
                    continue;
                }

                double t = (double)(cars[j][0] - cars[i][0]) /
                           (cars[i][1] - cars[j][1]);
                if (answer[j] == -1 || t <= answer[j]) {
                    answer[i] = t;
                    break;
                }

                st.pop();
            }

            st.push(i);
        }

        return answer;
    }
};