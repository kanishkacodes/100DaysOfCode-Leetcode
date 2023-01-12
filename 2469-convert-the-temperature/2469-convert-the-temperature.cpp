class Solution {
public:
    vector<double> convertTemperature(double celsius) {

      vector<double>vec;
      double  kelvin = celsius+273.15;
      double   fh = (celsius*1.80)+32.00;
      vec.push_back(kelvin);
      vec.push_back(fh);
      
    return vec;


        
    }
};