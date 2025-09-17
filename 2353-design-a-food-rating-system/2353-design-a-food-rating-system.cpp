class FoodRatings {
private:
    unordered_map<string, pair<int, string>> foodToRatingAndCuisine;
    unordered_map<string, map<int, set<string>>> cuisineToRatingAndFoods;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) 
    {
        int n = foods.size();
        for(int i = 0 ; i < n ; ++i)
        {
            foodToRatingAndCuisine[foods[i]] = {ratings[i], cuisines[i]};
            cuisineToRatingAndFoods[cuisines[i]][ratings[i]].insert(foods[i]);
        }
    }
    
    void changeRating(string food, int newRating) 
    {
        auto [oldRating, cuisine] = foodToRatingAndCuisine[food];
        foodToRatingAndCuisine[food].first = newRating;
        cuisineToRatingAndFoods[cuisine][oldRating].erase(food);

        if(cuisineToRatingAndFoods[cuisine][oldRating].empty())
            cuisineToRatingAndFoods[cuisine].erase(oldRating);
            
        cuisineToRatingAndFoods[cuisine][newRating].insert(food);
    }
    
    string highestRated(string cuisine) 
    {
        auto& ratingAndFoods = cuisineToRatingAndFoods[cuisine];
        auto ritr = ratingAndFoods.rbegin();
        return *(ritr->second.begin());
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */