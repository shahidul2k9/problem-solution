
class _125_Palindrome {
    public boolean isPalindrome(int x) {
        if (x < 0) {
            return false;
        } else {
            return new StringBuilder().append(x).reverse().toString().equals(String.valueOf(x));
        }
    }
}