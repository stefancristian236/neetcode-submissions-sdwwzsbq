class Solution {
public:

    string encode(vector<string>& strs) {
        std::string encoded_string = "";
        
        for (const auto st : strs){
            encoded_string += to_string(st.length()) + "#" + st;
        }
        
        return encoded_string;
    }

    vector<string> decode(string s) {
        std::vector<std::string> decoded_message;
        size_t i = 0;

        while (i < s.length()) {
            int delimiter_pos = s.find('#', i);
            int length = stoi(s.substr(i, delimiter_pos - i));
            std::string word = s.substr(delimiter_pos + 1, length);
            decoded_message.push_back(word);
            i = delimiter_pos + 1 + length;
        }

        return decoded_message;
    }
};
