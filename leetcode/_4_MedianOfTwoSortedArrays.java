
/**
 * @author Shahidul Islam
 * @date 2/2/2022
 **/
public class _4_MedianOfTwoSortedArrays {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        if (nums1.length > nums2.length) {
            int[] tempArray = nums1;
            nums1 = nums2;
            nums2 = tempArray;
        }

        int m = nums1.length;
        int n = nums2.length;

        if (m == 0) {
            if (n % 2 == 1) {
                return nums2[n / 2];
            } else {
                return (nums2[n / 2 - 1] + nums2[n / 2]) / 2.0;
            }
        }

        int totalCount = m + n;
        int tlf = totalCount / 2;
        int low = 0;
        int high = m - 1;
        int midX = 0;
        int midY = 0;
        while (true) {
            midX = (int) Math.floor((low + high) / 2.0);

            midY = tlf - (midX + 1) - 1;
            //System.out.println(low + " " +high + " || " + midX + " " + midY);

            int xLeft = midX < 0 ? Integer.MIN_VALUE : nums1[midX];
            int xRight = midX + 1 >= m ? Integer.MAX_VALUE : nums1[midX + 1];

            int yLeft = midY < 0 ? Integer.MIN_VALUE : nums2[midY];
            int yRight = midY + 1 >= n ? Integer.MAX_VALUE : nums2[midY + 1];

            if (xLeft <= yRight && yLeft <= xRight) {
                if (totalCount % 2 == 1) {
                    return Math.min(xRight, yRight);
                } else {
                    return (Math.max(xLeft, yLeft) + Math.min(xRight, yRight)) / 2.0;
                }
            } else if (xLeft > yRight) {
                high = midX - 1;
            } else {
                low = midX + 1;
            }
        }

    }
}
