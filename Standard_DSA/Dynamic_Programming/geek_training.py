# Geek is going for n day training program.
# He can perform any one of these three activities Running,
# Fighting, and Learning Practice. Each activity has some point on each day.
# As Geek wants to improve all his skills, he can't do the same activity on two consecutive days.
#  Help Geek to maximize his merit points as you are given a 2D
# array of points points, corresponding to each day and activity.

class Solution:

    def maximumPoints(self, points, n):
        # Code here

        cur_row=[0 for _ in range(3)]

        if(n==1):
            return max(points[0])

        next_row=[points[n-1][j] for j in range(3)]

        for j in range(n-2,-1,-1):
            for h in range(3):
                cur_row[h]=points[j][h]
                for k in range(3):
                    if(h!=k):
                        cur_row[h]=max(cur_row[h],points[j][h]+next_row[k])
            next_row[:]=cur_row

        return max(cur_row[:])