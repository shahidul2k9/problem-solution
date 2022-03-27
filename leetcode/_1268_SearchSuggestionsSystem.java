
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * @author Shahidul Islam
 * @date 2/26/2022
 **/
public class _1268_SearchSuggestionsSystem {
    public List<List<String>> suggestedProducts(String[] products, String searchWord) {
        List<List<String>> suggestionCollection = new ArrayList<>();
        Arrays.sort(products);
        int low = 0;
        int high = products.length - 1;
        StringBuilder prefix = new StringBuilder();
        for (char ch : searchWord.toCharArray()) {
            prefix.append(ch);
            List<String> newSuggestionList = new ArrayList<>();
            int lb = lowerBound(low, high, prefix.toString(), products);
            for (int i = lb; i < lb + 3 && i < products.length; i++) {
                if (products[i].startsWith(prefix.toString())) {
                    newSuggestionList.add(products[i]);
                }
            }
            suggestionCollection.add(newSuggestionList);
            low = lb;
        }
        return suggestionCollection;

    }

    private int lowerBound(int low, int high, String val, String[] products) {
        while (low <= high) {
            int mid = (low + high) / 2;
            int cmpVal = products[mid].compareTo(val);
            if (cmpVal < 0) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
}
