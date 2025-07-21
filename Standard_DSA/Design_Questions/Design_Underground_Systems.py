class UndergroundSystem:

    def __init__(self):
        self.check_in_data={}
        self.travel_data={}

    def checkIn(self, id: int, stationName: str, t: int) -> None:
        self.check_in_data[id]=(stationName,t)


    def checkOut(self, id: int, stationName: str, t: int) -> None:
        startStation,startTime=self.check_in_data.pop(id)
        travelTime=t-startTime
        key=(startStation,stationName)

        if key in self.travel_data:
            self.travel_data[key][0]+=travelTime
            self.travel_data[key][1]+=1
        else:
            self.travel_data[key]=[travelTime,1]

    def getAverageTime(self, startStation: str, endStation: str) -> float:

        totalTime,count=self.travel_data[(startStation,endStation)]
        return totalTime/count


# Your UndergroundSystem object will be instantiated and called as such:
# obj = UndergroundSystem()
# obj.checkIn(id,stationName,t)
# obj.checkOut(id,stationName,t)
# param_3 = obj.getAverageTime(startStation,endStation)

######################################################################################################################################################################################################################################
