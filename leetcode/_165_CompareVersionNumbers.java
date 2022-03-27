
/**
 * @author Shahidul Islam
 * @date 2/21/2022
 **/
public class _165_CompareVersionNumbers {
    public int compareVersion(String version1, String version2) {
        String[] v1List = version1.split("\\.");
        String[] v2List = version2.split("\\.");

        int v1n = v1List.length;
        int v2n = v2List.length;

        for (int i = 0; i < Math.max(v1n, v2n); i++) {
            int v1 = i < v1n ? Integer.parseInt(v1List[i].trim()) : 0;
            int v2 = i < v2n ? Integer.parseInt(v2List[i].trim()) : 0;
            if (v1 < v2) {
                return -1;
            } else if (v2 < v1) {
                return 1;
            }
        }
        return 0;
    }
}
