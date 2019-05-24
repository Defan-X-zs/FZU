//6-7 统计数字
class Solution {
	public:
		int count_digits(string a) {
			int i = 0, ret = 0;
			while (a[i] != '\0') {
				if (a[i]>='0'&&a[i]<='9') {
					ret++;
				}
				i++;
			}
		return ret;
		}
};
