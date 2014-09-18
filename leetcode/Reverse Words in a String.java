import java.util.ArrayList;

public class Solution {
    public String reverseWords(String s) {
   
    
    	
    	ArrayList<String> list = new ArrayList<>(); 
    	int len = s.length();
    	for(int i = 0; i < len; i++)
    		if(s.charAt(i) != ' '){
    			StringBuilder b = new StringBuilder();
    			int j;
    			for(j = i; j < len && s.charAt(j) != ' ';j++)
    				b.append(s.charAt(j));
    			list.add(b.toString());
    			i = j;
    		}
    	
    	StringBuilder builder = new StringBuilder();
    	
    	if(list.size()>0) builder.append(list.get(list.size()-1));
    	
    	for(int i = list.size()-2; i >= 0; i--){
    		builder.append(" ");
    		builder.append(list.get(i));
    	}
        
    	return builder.toString();
    }
    public static void main(String args[]){
    	System.out.println(new Solution().reverseWords(" 1"));
    	System.out.println(new Solution().reverseWords("the sky is blue"));
    }
}