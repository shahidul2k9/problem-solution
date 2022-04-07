
import java.util.TreeMap;

class _729_MyCalendarI {
    TreeMap<Integer, Integer> windowMap;

    public _729_MyCalendarI() {
        this.windowMap = new TreeMap<>();
    }

    public boolean book(int start, int end) {
        Integer floorKey = windowMap.floorKey(start);
        Integer ceilKey = windowMap.ceilingKey(start);
        if ((floorKey != null && windowMap.get(floorKey) > start) || (ceilKey != null && end > ceilKey)) {
            return false;
        } else {
            windowMap.put(start, end);
            return true;
        }
    }
}