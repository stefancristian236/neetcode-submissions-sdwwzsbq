class Solution:
    def groupAnagrams(sel, strs: List[str]) -> List[List[str]]:
        anagram_map = defaultdict(list)
        for word in strs:
            sign = "".join(sorted(word))
            anagram_map[sign].append(word)
        return list(anagram_map.values())
