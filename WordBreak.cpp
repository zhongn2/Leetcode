//word break
// string s = "leetcode"
// dict = {"leet", "code"}, return true when the string s can be segmented by the dict

bool wordBreak(string s, unordered_set<string> &dict){
	if（s == NULL) return false;
	if(dict.empty()) return false;
	int n = s.length();
	bool dp[n];
	dp[0] = false;
	for(int i = 1; i < n; i++){
		if(dict.count(s.substr(0, i)) > 0){
			dp[i] = true;
			continue;
		}
	}// init dp[]
	
	
	


}