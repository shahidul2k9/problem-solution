class Solution:
    def kthGrammar(self, n: int, k: int) -> int:
        def find_kth_bit(current_n : int, current_k : int, is_flip:bool)-> int:
            if current_n == 1:
                if is_flip:
                    return 1
                else:
                    return 0
            else:
                prev_row_bit_count = 1 << (current_n - 2)
                if prev_row_bit_count >= current_k:
                    return find_kth_bit(current_n - 1, current_k, is_flip)
                else:
                    return find_kth_bit(current_n - 1, current_k - prev_row_bit_count, not is_flip)
        return find_kth_bit(n, k, False)