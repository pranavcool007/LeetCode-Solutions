/* logic to convert the given longUrl to a unique no , for eg if 3 url are there like 
   "leetcode" = 1 , "google" = 2 "twitter" = 3.
   this can be easily done by mapping the long url to a no which is cal as size(enocdemap)+1
   short url will be baseurl + no
   we will map shorturl to longurl and longurl to shorturl in a map.
 */ 
class Solution {
public:
    unordered_map<string,string> encodeMap;
    unordered_map<string,string> decodeMap;
    string base = "http://tinyurl.com/";
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(encodeMap.find(longUrl) == encodeMap.end()){
            string shortURL = base + to_string(encodeMap.size() + 1);
            encodeMap[longUrl] = shortURL;
            decodeMap[shortURL] = longUrl;
        }
        return encodeMap[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return decodeMap[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));