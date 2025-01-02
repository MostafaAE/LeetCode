class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) 
    {
        int travels = travel.size(), houses = garbage.size(), result{};
        vector<int> travelPrefix(travels+1, 0);

        for(int i = 0 ; i < travels ; ++i)
            travelPrefix[i+1] = travel[i] + travelPrefix[i];
        
        int metalIndex{}, paperIndex{}, glassIndex{};

        for(int i = 0 ; i < houses ; ++i)
        {
            vector<int> garbageCount = countGarbage(garbage[i]);
            result += garbageCount[0] + garbageCount[1] + garbageCount[2];

            if(garbageCount[0]) // metal
                result += travelPrefix[i] - travelPrefix[metalIndex++], metalIndex = i;
            
            if(garbageCount[1]) // paper
                result += travelPrefix[i] - travelPrefix[paperIndex++], paperIndex = i;
            
            if(garbageCount[2]) // glass
                result += travelPrefix[i] - travelPrefix[glassIndex], glassIndex = i;
        }

        return result;
    }

    vector<int> countGarbage(const string& garbage)
    {
        vector<int> result(3, 0);
        for(char c :  garbage)
        {
            if(c == 'M')
                ++result[0];
            else if(c == 'P')
                ++result[1];
            else
                ++result[2];
        }

        return result;
    }
};