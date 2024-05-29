def find(target, word_dict):
    for word in word_dict:
        if target == word:
            return True
    return False

def word_break(s, word_dict):
    if len(s) == 0:
        return True
    
    for i in range(1, len(s) + 1):
        test = s[0:i]  # Extracting the substring from index 0 to i
        if find(test, word_dict) and word_break(s[i:], word_dict):
            return True
    
    return False

word_dict1 = ["apple", "pen"]
str1 = "applepenapple"  # Fixed: str1 should be a string, not a list of characters
word_dict2 = ["cats", "dog", "sand", "and", "cat"]
str2 = "catsandog"      # Fixed: str2 should be a string, not a list of characters

print(word_break(str1, word_dict1))
print(word_break(str2, word_dict2))
