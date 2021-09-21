// Kth permutation sequence (distinct elements)
// won;t work for duplicate elements

void find(string& s, int k, int n, string& ans) {
	if (n == 0) return;
	int rightChars = n - 1;
	// abc acb bac bca cab cba
	// total n! = 3! permutations, each one has (n-1)! = 2! groupSize
	// 0,1 => 0 || 2,3 => 1 || 4,5 => 2
	int groupSize = fact(rightChars);
	// index, where current character lies, i.e group number
	int index = k / groupSize;
	// new k to search for
	int newK = k % groupSize;
	// add to answer
	ans += s[index];
	// remove this character from the string
	s.erase(s.begin() + index);
	find(s, newK, n - 1, ans);
}

string kthPermutation(string s, int k) {
	sort(s.begin(), s.end());
	int n = s.size();
	string ans;
	find(s, k - 1, n, ans); // k-1 for 0-based indexing
	return ans;
}

// next permutation

string nextpermutation(string s) {
	int n = s.size();
	int indSmaller = -1;
	for (int i = n - 2; i >= 0; --i) {
		if (s[i] < s[i + 1]) {
			indSmaller = i;
			for (int i = n - 1; i > indSmaller; --i) {
				if (s[i] > s[indSmaller]) {
					int indGreater = i;
					swap(s[indSmaller], s[indGreater]);
					goto here;
				}
			}
		}
	}
here:;
	reverse(s.begin() + indSmaller + 1, s.end());
	return s;
}

// Rank of word

int findRank(string s) {
	int n = s.size();
	vector<int> cnt(26);
	for (char c : s)
		cnt[c - 'a']++;
	int ans = 0;
	int rightChars = n - 1;
	for (int i = 0; i < n; ++i) {
        // number of Lexicographically Smaller Chars For This Position
		int smallerChars = 0;
		for (char c = 'a'; c < s[i]; ++c)
			smallerChars += cnt[c - 'a'];
		int den = 1;
		for (int i = 0; i < 26; ++i)
			den *= fact(cnt[i]);
		int num = fact(rightChars);
		ans += smallerChars * num / den;
        // now we're done with this character, move to next index
		--rightChars;
		--cnt[s[i] - 'a'];
	}
	return ans;
}
