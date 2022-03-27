
import java.util.Arrays;
import java.util.Comparator;

/**
 * @author Shahidul Islam
 * @date 1/29/2022
 **/
public class _1828_PointsInsideCircle {
    public int[] countPoints(int[][] points, int[][] queries) {
        int n = points.length;
        Comparator<int[]> pointComparator = Comparator.comparingInt(o -> o[0]);
        Arrays.sort(points, pointComparator);
        int[] pointCount = new int[queries.length];
        Arrays.fill(pointCount, 0);
        int qn = 0;
        for (int[] circle : queries) {
            int cx = circle[0];
            int cy = circle[1];
            int r = circle[2];
            int lowerBoundIndex = lowerBound(points, cx - r);
            int upperBoundIndex = upperBound(points, cx + r);
            for (int i = lowerBoundIndex; i < upperBoundIndex; i++) {
                int[] point = points[i];
                double d = Math.sqrt(Math.pow(point[0] - cx, 2) + Math.pow(point[1] - cy, 2));
                if (d <= r) {
                    pointCount[qn] += 1;
                }
            }
            qn++;
        }
        return pointCount;
    }

    private int lowerBound(int[][] points, int targetX) {
        int low = 0;
        int high = points.length;
        while (low < high) {
            int mid = low + (high - low) / 2;
            int midX = points[mid][0];
            if (midX < targetX) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

    private int upperBound(int[][] points, int targetX) {
        int low = 0;
        int high = points.length;
        while (low < high) {
            int mid = low + (high - low) / 2;
            int midX = points[mid][0];
            if (midX > targetX) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
}
