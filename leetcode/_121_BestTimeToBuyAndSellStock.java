
class _121_BestTimeToBuyAndSellStock {
    public int maxProfit(int[] prices) {
        int minPrice, sellingPrice, localProfit, globalProfit;
        minPrice = prices[0];
        globalProfit = 0;
        for (int i = 1; i < prices.length;i++){
            globalProfit = Math.max(prices[i] - minPrice, globalProfit);
            minPrice = Math.min(minPrice, prices[i]);
        }
        return globalProfit;
        
    }
}