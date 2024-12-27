class Solution {
public:
    vector<double> convertTemperature(double celsius) 
    {
        return {convertToKelvin(celsius), convertToFahrenheit(celsius)};
    }

    double convertToKelvin(double celsius)
    {
        return celsius + 273.15;
    }

    double convertToFahrenheit(double celsius)
    {
        return celsius * 1.80 + 32.00;
    }
};