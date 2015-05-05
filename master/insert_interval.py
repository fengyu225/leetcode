
# Definition for an interval.
class Interval:
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e
    def __repr__(self):
        return "start: {0}, end: {1}\n".format(self.start,self.end)

class Solution:
    # @param intervals, a list of Intervals
    # @param newInterval, a Interval
    # @return a list of Interval
    def insert(self, intervals, newInterval):
        i = 0
        while i<len(intervals) and intervals[i].end<newInterval.start:
            i+=1
        if i == len(intervals):
            intervals.append(newInterval)
            return intervals
        intervals.insert(i,newInterval)
        while i+1<len(intervals):
            if intervals[i].end<intervals[i+1].start:
                break
            intervals[i].start = min(intervals[i].start,intervals[i+1].start)
            intervals[i].end = max(intervals[i].end, intervals[i+1].end)
            intervals.pop(i+1)
        return intervals

if __name__ == "__main__":
    i0 = Interval(1,2)
    i1 = Interval(3,5)
    i2 = Interval(6,7)
    i3 = Interval(8,10)
    i4 = Interval(12,16)
    i5 = Interval(4,9)
    print Solution().insert([i0, i1, i2, i3, i4], i5)
