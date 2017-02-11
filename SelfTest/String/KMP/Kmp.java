public class Main {

	public static void main(String[] args) {
		Solution s = new Solution();

		System.out.println(s.isSubsequence("abc", "ahbgdc"));
	}

}
// "abc"
// "ahbgdc"


class Solution {
    public boolean isSubsequence(String s, String t) {
        if (s.length() > t.length()) {
        	return false;
        }




        int[] next = new int[s.length()];

        getNext(s,next);



        return kmp(s,t,next) == -1 ? false : true;


    }

    void getNext(String s, int [] next) {

    	if (s.length() == 0) return;

    	int k = -1;

    	next[0] = -1;


    	for (int i = 1; i < s.length(); ++i) {
    		while (k >= 0 && s.charAt(k+1) != s.charAt(i)) k = next[k];
    		if (s.charAt(i) == s.charAt(k+1)) k++;
    		next[i] = k;
    	}

    }


    int kmp(String s, String t, int[] next) {
    	int k = -1;
    	if (s.length() == 0) return 0;


    	for (int i = 0; i < t.length(); ++i) {
    		while (k >= 0 && s.charAt(k+1) != t.charAt(i)) {
    			k = next[k];
    		}

    		if (s.charAt(k+1) == t.charAt(i)) k++;

    		if (k == s.length()-1) {
    			return i - (s.length() - 1);
    		}
    	}

    	return -1;
    }


}