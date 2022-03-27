
/**
 * @author Shahidul Islam
 * @date 1/28/2022
 **/
public class _1518_WaterBottles {
    public int numWaterBottles(int numBottles, int numExchange) {
        int drankBottleCount, emptyBottleCount;
        drankBottleCount = numBottles;
        emptyBottleCount = numBottles;
        while (emptyBottleCount >= numExchange){
            int newBottleCount = emptyBottleCount / numExchange;
            emptyBottleCount = emptyBottleCount % numExchange + newBottleCount;
            drankBottleCount += newBottleCount;
        }
        return drankBottleCount;
    }
}
