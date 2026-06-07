class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_map<string,int>hash;
        for(int i = 0; i<emails.size(); i++){
            string currEmail = emails[i];
            string localName = "";
            string domainName = "";
            bool theRateFound = false;
            bool plusFound = false;
            for(int k = 0; k<currEmail.size(); k++){
                if(currEmail[k] == '+') plusFound = true;
                else if(currEmail[k] == '@') theRateFound = true;

                if(theRateFound) domainName+=currEmail[k];
                else{
                    if(currEmail[k] == '.')continue;
                    else if(!plusFound) localName+= currEmail[k];
                }
            }
            

            string emailAddress = localName+"@"+domainName;
            hash[emailAddress]++;
        }
        return hash.size();
    }
};