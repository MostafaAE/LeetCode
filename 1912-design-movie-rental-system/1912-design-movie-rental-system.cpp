class MovieRentingSystem {
private:
    map<int, set<pair<int,int>>> availableMovies;   // movie -> available (price, shop)
    map<pair<int,int>, int> moviePrice;             // (movie, shop) -> price
    set<tuple<int,int,int>> rentedSet;              // rented movies: (price, shop, movie)

public:
    MovieRentingSystem(int n, vector<vector<int>>& inventory) 
    {
        // Load initial inventory into data structures
        for (auto &entry : inventory) 
        {
            int shop = entry[0], movie = entry[1], price = entry[2];
            availableMovies[movie].insert({price, shop});  // add to available
            moviePrice[{movie, shop}] = price;            // store price
        }
    }

    vector<int> search(int movie) 
    {
        // Return up to 5 cheapest shops that have the movie available
        vector<int> topShops;
        if (availableMovies.find(movie) == availableMovies.end()) 
            return topShops;

        for (auto &[price, shop] : availableMovies[movie]) 
        {
            topShops.push_back(shop);
            if (topShops.size() == 5) 
                break;   // only top 5 shops
        }
        return topShops;
    }

    void rent(int shop, int movie) 
    {
        // Move movie from available -> rented
        int price = moviePrice[{movie, shop}];
        rentedSet.insert({price, shop, movie});         // add to rented
        availableMovies[movie].erase({price, shop});    // remove from available
    }

    void drop(int shop, int movie) 
    {
        // Move movie from rented -> available
        int price = moviePrice[{movie, shop}];
        rentedSet.erase({price, shop, movie});          // remove from rented
        availableMovies[movie].insert({price, shop});   // add back to available
    }

    vector<vector<int>> report() 
    {
        // Return up to 5 cheapest rented movies
        vector<vector<int>> topRented;
        for (auto &[price, shop, movie] : rentedSet) 
        {
            topRented.push_back({shop, movie});
            if (topRented.size() == 5)
                break;           // only top 5
        }

        return topRented;
    }
};