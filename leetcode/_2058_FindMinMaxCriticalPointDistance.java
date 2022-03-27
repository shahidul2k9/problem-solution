
import java.util.ArrayList;
import java.util.List;

/**
 * @author Shahidul Islam
 * @date 2/20/2022
 **/
public class _2058_FindMinMaxCriticalPointDistance {
    public int[] nodesBetweenCriticalPoints(ListNode head) {
        int[] noCriticalDistance = new int[]{-1, -1};
        if (head == null || head.next == null || head.next.next == null) {
            return noCriticalDistance;
        }
        ListNode a = head;
        ListNode b = a.next;
        ListNode c = b.next;
        List<Integer> positionList = new ArrayList<>();
        int pos = 0;
        while (c != null) {
            if ((a.val > b.val && b.val < c.val) || (a.val < b.val && b.val > c.val)) {
                positionList.add(pos);
            }
            pos++;
            a = a.next;
            b = b.next;
            c = c.next;
        }

        int size = positionList.size();
        if (size > 1) {
            int minD = Integer.MAX_VALUE;
            int maxD = positionList.get(size - 1) - positionList.get(0);
            for (int i = 0; i < size - 1; i++) {
                minD = Math.min(positionList.get(i + 1) - positionList.get(i), minD);
            }
            return new int[]{minD, maxD};
        }
        return noCriticalDistance;
    }
}
