
/**
 * @author Shahidul Islam
 * @date 1/24/2022
 **/
public class _190_ReverseBits {
    public int reverseBits(int n) {
        int r = 0;
        for (int i = 0; i < 32; i++) {
            r = (((n >> i) & 0x01) << (31 - i)) | r;
        }
        return r;
    }
}
