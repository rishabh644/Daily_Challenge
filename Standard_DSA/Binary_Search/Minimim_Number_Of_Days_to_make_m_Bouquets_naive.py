class Solution:
    def minDays(self, bloomDay: List[int], m: int, k: int) -> int:
        n=len(bloomDay)

        if n<m*k:
            return -1

        max_day=max(bloomDay)

        for day in range(1,max_day+1):

            bloomed=[bloomDay[i]<=day for i in range(n)]

            bouquets=0
            flowers=0

            for flower in bloomed:
                if flower:
                    flowers+=1

                    if flowers==k:
                        bouquets+=1
                        flowers=0
                else:
                    flowers=0
            if bouquets>=m:
                return day

        return -1
