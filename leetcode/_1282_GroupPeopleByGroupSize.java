
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * @author Shahidul Islam
 * @date 1/30/2022
 **/
public class _1282_GroupPeopleByGroupSize {
    public List<List<Integer>> groupThePeople(int[] groupSizes) {
        List<List<Integer>> groupList = new ArrayList<>();
        Map<Integer, List<Integer>> groupMap = new HashMap<>();
        int n = groupSizes.length;
        for (int i = 0; i < n; i++) {
            int groupSize = groupSizes[i];
            List<Integer> group = groupMap.getOrDefault(groupSize, new ArrayList<>());
            groupMap.put(groupSize, group);
            group.add(i);
            if (group.size() == groupSize) {
                groupList.add(group);
                groupMap.remove(groupSize);
            }
        }

        return groupList;
    }
}
