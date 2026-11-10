class Solution:
    def maxScore(self, cardPoints: list[int], k: int) -> int:

        currSum = sum(cardPoints[:k])
        ans = currSum

        for i in range(1, k + 1):
            currSum -= cardPoints[k - i]
            currSum += cardPoints[-i]

            ans = max(ans, currSum)

        return ans