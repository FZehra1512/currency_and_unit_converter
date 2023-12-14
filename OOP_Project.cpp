#include <iostream>
#include <iomanip>
using namespace std;

void Clear()
{
    cout << "\x1B[2J\x1B[H";
}

class Working{
public:
    virtual void get_convert_values() = 0;
    virtual void get_input_value() = 0;
    virtual void conversion() = 0;
};

class all_all{
    private:
        double pkr_usd = 0.004380;
        double pkr_euro = 0.004288;
        double pkr_sar = 0.016425;
        double pkr_cny = 0.029567;
        double cny_usd = 0.148132;
        double cny_euro = 0.145021;
        double cny_sar = 0.555497;
        double sar_usd = 0.266667;
        double sar_euro = 0.261065;
        double euro_usd = 1.021457;
    public:
        double rupeetodollars(double value){
            return value * pkr_usd;
        }
        double rupeetoeuro(double value){
            return value * pkr_euro;
        }
        double rupeetoriyal(double value){
            return value * pkr_sar;
        }
        double rupeetoyuan(double value){
            return value * pkr_cny;
        }
        double yuantodollars(double value){
            return value * cny_usd;
        }
        double yuantoeuro(double value){
            return value * cny_euro;
        }
        double yuantoriyal(double value){
            return value * cny_sar;
        }
        double yuantorupee(double value){
            return value * (1/pkr_cny);
        }
        double riyaltodollars(double value){
            return value * sar_usd;
        }
        double riyaltoeuro(double value){
            return value * sar_euro;
        }
        double riyaltoyuan(double value){
            return value * (1/cny_sar);
        }
        double riyaltorupee(double value){
            return value * (1/pkr_sar);
        }
        double eurotodollars(double value){
            return value * euro_usd;
        }
        double eurotoriyal(double value){
            return value * (1/sar_euro);
        }
        double eurotoyuan(double value){
            return value * (1/cny_euro);
        }
        double eurotorupee(double value){
            return value * (1/pkr_euro);
        }
        double dollarstoeuro(double value){
            return value * (1/euro_usd);
        }
        double dollarstoriyal(double value){
            return value * (1/sar_usd);
        }
        double dollarstoyuan(double value){
            return value * (1/cny_usd);
        }
        double dollarstorupee(double value){
            return value * (1/pkr_usd);
        }
};

class all_units{
private:
    double cm_inch = 0.393701;
    double ft_m = 0.3048;
    double mile_km = 1.609344;
    double lb_kg = 0.4535924;
    double mpers_kmperh = 3.6;
    double hp_kW = 0.7457;
    
public:
    double centitoinch(double value) {
        return value * cm_inch;
    }
    double inchtocenti(double value) {
        return value * (1 / cm_inch);
    }
    double feettometer(double value) {
        return value * ft_m;
    }
    double metertofeet(double value) {
        return value * (1/ft_m);
    }
    double miletokm(double value) {
        return value * mile_km;
    }
    double kmtomile(double value) {
        return value * (1/mile_km);
    }
    double kilotopound(double value) {
        return value * (1/lb_kg);
    }
    double poundtokilo(double value) {
        return value * lb_kg;
    }
    double mperstokmperh(double value) {
        return value * mpers_kmperh;
    }
    double kmperhtompers(double value) {
        return value * (1/mpers_kmperh);
    }
    double hptokW(double value) {
        return value * hp_kW;
    }
    double kWtohp(double value) {
        return value * (1/hp_kW);
    }
    double celsiustofahren(double value) {
        return (value * 1.8)+32;
    }
    double fahrentocelsius(double value) {
        return (value-32)/1.8;
    }
};

class Currency_Con: public Working, private all_all{
    private:
        int from_cur;
        int to_cur;
        double input_cur;
    public:
        void get_convert_values(){
            cout << "\nEnter numbers between (1-5) for conversion." << endl;
            cout << "\nSelect the currency you want to convert: ";
            cin >> from_cur;
            cout << "Select the currency you want to convert into:  ";
            cin >> to_cur;
            cout << endl;
        }
        void get_input_value(){
            cout << "Enter amount to be converted: ";
            cin >> input_cur;
        }
        void conversion(){
            cout << fixed << showpoint << setprecision(3);
            switch (from_cur)
            {
            case 1:
                switch(to_cur)
                {
                case 2:
                    cout << endl;
                    cout << input_cur << " Dollars = " << 
                    all_all::dollarstoeuro(input_cur) << " Euros" << endl; 
                    break;
                case 3:
                    cout << endl;
                    cout << input_cur << " Dollars = " << 
                    all_all::dollarstoriyal(input_cur) << " Riyal" << endl; 
                    break;
                case 4:
                    cout << endl;
                    cout << input_cur << " Dollars = " << 
                    all_all::dollarstoyuan(input_cur) << " Yuan" << endl;  
                    break;
                case 5:
                    cout << endl;
                    cout << input_cur << " Dollars = " << 
                    all_all::dollarstorupee(input_cur) << " Rupees" << endl;
                    break;
                default:
                    cout << endl;
                    cout << "\nINVALID SELECTION." << endl;
                    cout << "Try again please." << endl;
                }
                break;
            case 2:
                switch(to_cur)
                {
                case 1:
                    cout << endl;
                    cout << input_cur << " Euros = " << 
                    all_all::eurotodollars(input_cur) << " Dollars" << endl; 
                    break;
                case 3:
                    cout << endl;
                    cout << input_cur << " Euros = " << 
                    all_all::eurotoriyal(input_cur) << " Riyal" << endl; 
                    break;
                case 4:
                    cout << endl;
                    cout << input_cur << " Euros = " << 
                    all_all::eurotoyuan(input_cur) << " Yuan" << endl;  
                    break;
                case 5:
                    cout << endl;
                    cout << input_cur << " Euros = " << 
                    all_all::eurotorupee(input_cur) << " Rupees" << endl;
                    break;
                default:
                    cout << "\nINVALID SELECTION." << endl;
                    cout << "Try again please." << endl;
                }
                break;
            case 3:
                switch(to_cur)
                {
                case 1:
                    cout << endl;
                    cout << input_cur << " Riyal = " << 
                    all_all::riyaltodollars(input_cur) << " Dollars" << endl; 
                    break;
                case 2:
                    cout << endl;
                    cout << input_cur << " Riyal = " << 
                    all_all::riyaltoeuro(input_cur) << " Euros" << endl; 
                    break;
                case 4:
                    cout << endl;
                    cout << input_cur << " Riyal = " << 
                    all_all::riyaltoyuan(input_cur) << " Yuan" << endl;  
                    break;
                case 5:
                    cout << endl;
                    cout << input_cur << " Riyal = " << 
                    all_all::riyaltorupee(input_cur) << " Rupees" << endl;
                    break;
                default:
                    cout << "\nINVALID SELECTION." << endl;
                    cout << "Try again please." << endl;
                }
                break;
            case 4:
                switch(to_cur)
                {
                case 1:
                    cout << endl;
                    cout << input_cur << " Yuan = " << 
                    all_all::yuantodollars(input_cur) << " Dollars" << endl; 
                    break;
                case 2:
                    cout << endl;
                    cout << input_cur << " Yuan = " << 
                    all_all::yuantoeuro(input_cur) << " Euros" << endl; 
                    break;
                case 3:
                    cout << endl;
                    cout << input_cur << " Yuan = " << 
                    all_all::yuantoriyal(input_cur) << " Riyal" << endl;  
                    break;
                case 5:
                    cout << endl;
                    cout << input_cur << " Yuan = " << 
                    all_all::yuantorupee(input_cur) << " Rupees" << endl;
                    break;
                default:
                    cout << "\nINVALID SELECTION." << endl;
                    cout << "Try again please." << endl;
                }
                break;
            case 5:
                switch(to_cur)
                {
                case 1:
                    cout << endl;
                    cout << input_cur << " Rupees = " << 
                    all_all::rupeetodollars(input_cur) << " Dollars" << endl;
                    break;
                case 2:
                    cout << endl;
                    cout << input_cur << " Rupees = " << 
                    all_all::rupeetoeuro(input_cur) << " Euros" << endl; 
                    break;
                case 3:
                    cout << endl;
                    cout << input_cur << " Rupees = " << 
                    all_all::rupeetoriyal(input_cur) << " Riyal" << endl; 
                    break;
                case 4:
                    cout << endl;
                    cout << input_cur << " Rupees = " << 
                    all_all::rupeetoyuan(input_cur) << " Yuan" << endl;  
                    break;
                default:
                    cout << "\nINVALID SELECTION." << endl;
                    cout << "Try again please." << endl;
                }
                break;
            default:
                cout << "\nINVALID SELECTION." << endl;
                cout << "Try again Please." << endl; 
            }
        }
};

class Unit_Conversion : public Working, private all_units{
private:
    int convert_value;
    double input_value;

public:
    void get_convert_values() {
        cout << "\nEnter number between (1-10) for conversion." << endl;
        cout << "\nSelect the conversion: ";
        cin >> convert_value;
        cout << endl;
    }
    void get_input_value() {
        cout << "Enter value to be converted: ";
        cin >> input_value;
    }
    void conversion() {
        cout << fixed << showpoint << setprecision(3);
        switch (convert_value)
        {
        case 1:
            cout << endl;
            cout << input_value << " inches = " << 
            all_units::inchtocenti(input_value) << " centimeters" << endl; 
            break;
        case 2:
            cout << endl;
            cout << input_value << " centimeters = " << 
            all_units::centitoinch(input_value) << " inches" << endl; 
            break;
        case 3:
            cout << endl;
            cout << input_value << " feets = " << 
            all_units::feettometer(input_value) << " meters" << endl; 
            break;
        case 4:
            cout << endl;
            cout << input_value << " meters = " << 
            all_units::metertofeet(input_value) << " feets" << endl; 
            break;
        case 5:
            cout << endl;
            cout << input_value << " miles = " << 
            all_units::miletokm(input_value) << " kilometers" << endl; 
            break;
        case 6:
            cout << endl;
            cout << input_value << " kilometers = " << 
            all_units::kmtomile(input_value) << " miles" << endl; 
            break;
        case 7:
            cout << endl;
            cout << input_value << " pounds = " << 
            all_units::poundtokilo(input_value) << " kilograms" << endl; 
            break;
        case 8:
            cout << endl;
            cout << input_value << " kilograms = " << 
            all_units::kilotopound(input_value) << " pounds" << endl; 
            break;
        case 9:
            cout << endl;
            cout << input_value << " Centigrade = " << 
            all_units::celsiustofahren(input_value) << " Fahrenheit" << endl; 
            break;
        case 10:
            cout << endl;
            cout << input_value << " Fahrenheit = " << 
            all_units::fahrentocelsius(input_value) << " Centigrade" << endl; 
            break;
        case 11:
            cout << endl;
            cout << input_value << " Km/h = " << 
            all_units::kmperhtompers(input_value) << " m/s" << endl; 
            break;
        case 12:
            cout << endl;
            cout << input_value << " m/s = " << 
            all_units::mperstokmperh(input_value) << " Km/h" << endl; 
            break;
        case 13:
            cout << endl;
            cout << input_value << " hp = " << 
            all_units::hptokW(input_value) << " kW" << endl; 
            break;
        case 14:
            cout << endl;
            cout << input_value << " kW = " << 
            all_units::inchtocenti(input_value) << " hp" << endl; 
            break;
        default:
            cout << endl;
            cout << "\nINVALID SELECTION." << endl;
            cout << "Try again please." << endl;
        }
    }
};

int main(){
    int initial_state;

    do
    {
         cout << endl << "\t\t****WELCOME TO CURRENCY AND UNIT CONVERTOR****" << endl << endl;
        cout << "\n1. Currency Conversion.\n2. Unit Conversion." << endl << endl;
        cout << "Enter 1 or 2 for conversion or any number to exit" << endl << endl;
        cout << "Select the convertor:  ";
        cin >> initial_state;
        int final_state;
        if (initial_state == 1){
            Clear();
            cout << endl << "\t****WELCOME TO CURRENCY CONVERTOR****" << endl << endl;
            cout << "CURRENCIES" << endl << endl;
            cout << "1. USD -- United States Dollars" << endl;
            cout << "2. EUR -- Euro" << endl;
            cout << "3. SAR -- Saudi Arabian Riyal" << endl;
            cout << "4. CNY -- Chinese Yuan Renminbi" << endl;
            cout << "5. PKR -- Pakistani Rupee" << endl; 

            do
            {
                cout << "\n\n\nEnter 1 for conversion or any number to exit" << endl;
                cin >> final_state;
                if (final_state == 1){
                    Working* ptrCur = new Currency_Con();
                    ptrCur->get_convert_values();
                    ptrCur->get_input_value();
                    ptrCur->conversion();
                }
                else{
                    Clear();
                    cout << endl << "Please come again. THANK YOU :)" << endl; 
                }
            }while (final_state == 1);
        }
        else if (initial_state == 2){
            Clear();
            cout << endl << "\t****WELCOME TO UNIT CONVERTOR****" << endl << endl;
            cout << "UNITS" << endl << endl;
            cout << "1. inch --> centimeter" << endl;
            cout << "2. centimeter --> inch" << endl;
            cout << "3. feet --> meter" << endl;
            cout << "4. meter --> feet" << endl;
            cout << "5. mile --> kilometer" << endl;
            cout << "6. kilometer --> mile" << endl;
            cout << "7. lb --> kilogram" << endl;
            cout << "8. kilogram --> lb" << endl;
            cout << "9. Centigrade --> Fahrenheit" << endl;
            cout << "10. Fahrenheit --> Centigrade" << endl;
            cout << "11. Km/h --> m/s" << endl;
            cout << "12. m/s --> Km/h" << endl;
            cout << "13. hp --> KW" << endl;
            cout << "14. KW --> hp" << endl;
            do {
                cout << "\n\n\nEnter 1 for conversion or any number to exit" << endl;
                cin >> final_state;
                if (final_state == 1) {
                    Working* ptrunit = new Unit_Conversion();
                    ptrunit->get_convert_values();
                    ptrunit->get_input_value();
                    ptrunit->conversion();
                }
                else {
                    Clear();
                    cout << endl << "Please come again. THANK YOU :)" << endl;
                }
            } while (final_state == 1);
        }
        else{
            cout << endl;
            cout << "WE ARE HAPPY TO SERVE YOU... PLEASE COME AGAIN :)" << endl;
        }
    } while (initial_state == 1 || initial_state == 2);
    return 0;
}
