//思路：首先统计utf8字符超出1字节的字节数目，然后对于后续的多字节，统计其字节数目之和是否和前者一样。注意避开不符合规范的情况(对应val>>7 == ob1的情况)
//utf8编码规范详见：http://www.ruanyifeng.com/blog/2007/10/ascii_unicode_and_utf-8.html
class Solution {
public:
    bool validUtf8(vector<int> &data) {
        int count = 0;
        for (auto val:data) {
            if (count == 0) {
                if (val >> 5 == 0b110)
                    count = 1;
                else if (val >> 4 == 0b1110)
                    count = 2;
                else if (val >> 3 == 0b11110)
                    count = 3;
                else if (val >> 7 == 0b1)
                    return false;
            } else {
                if (val >> 6 != 0b10)
                    return false;
                --count;
            }
        }
        return count == 0;
    }
};