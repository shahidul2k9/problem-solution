
import java.util.*;

/**
 * @author Shahidul Islam
 * @date 1/23/2022
 **/
public class _743_NetworkDelayTime {
    static class Pair{
        public int v;
        public int w;
        Pair(int v, int w){
            this.v = v;
            this.w = w;
        }
    }
    public int networkDelayTime(int[][] times, int n, int k) {
        List<List<Pair>> g = new ArrayList<>();
        int[] d = new int[n + 1];
        for (int i = 0; i <= n; i++){
            g.add(new ArrayList<>());
            d[i] = Integer.MAX_VALUE;

        }


        for (int i = 0; i < times.length; i++){
            g.get(times[i][0]).add(new Pair(times[i][1], times[i][2]));
        }

        d[k] = 0;
        PriorityQueue<Pair> pq = new PriorityQueue<>(new Comparator<Pair>() {
            @Override
            public int compare(Pair o1, Pair o2) {
                return o1.w - o2.w;
            }
        });
        pq.add(new Pair(k, 0));
        while (!pq.isEmpty()){
            Pair front = pq.poll();
            int u = front.v;
            for (Pair vw : g.get(u)){
                int v = vw.v;
                if (d[v] > d[u] + vw.w){
                    d[v] = d[u] + vw.w;
                    pq.add(new Pair(v, d[v]));
                }
            }
        }

        int maxValue = Integer.MIN_VALUE;

        for (int i = 1; i <= n; i++ ){
           maxValue = Math.max(maxValue, d[i]);
        }
        if (maxValue == Integer.MAX_VALUE){
            return -1;
        }else {
            return maxValue;
        }
    }
}
