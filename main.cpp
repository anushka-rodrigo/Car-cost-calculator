#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int totalMaintenanceCost(int, int);
int  totalOperationalCost(int, int, int);
int totalServiceCost(int, int);
int totalOtherCost(int, int, float);
int carDepreciation(int, float);
float totalmonthlycost = 0.00;
float ls = 0.00;

void final_result (int, int, int, int, int, int);

int main()
{
    string car;
    string gas;
    char transmission;
    int yr;
    float price;
    int n;
    int td;
    int td_month;
    int tmc,tsc,cd,totherc;
    int toc;

    cout<<"======================================================================"<<endl;
    cout<<"\t\tWelcome to the Car cost analysis system"<<endl;
    cout<<"\nPlease enter the following details"<<endl;
    cout<<"Enter car name: ";
    getline(cin, car);
    cout<<"Enter year of car model: ";
    cin>>yr;
    cout<<"Enter transmission type (Auto-A/Manual-M): ";
    cin>>transmission;
    cout<<"Enter gas type (Petrol-P/Diesel-D): ";
    cin>>gas;
    cout<<"Enter vehicle price: Rs.";
    cin>>price;

    cout<<"Number of years planing to use the vehicle: ";
    cin>>n;
    cout<<"Total distance travelled per month (KM): ";
    cin>>td_month;

    cout<<"\nCalculating...";
    cout<<"\n======================================================================"<<endl;

    td=td_month*12*n;
    td=td+1000; //additional travels added 1000 km

    tmc = totalMaintenanceCost(td, n);
   toc = totalOperationalCost(td, n, td_month);
    tsc = totalServiceCost(td, n);
    totherc = totalOtherCost(td, n, price);
    cd = carDepreciation(n, price);

    final_result(tmc, toc, tsc, totherc, cd, n);

    return 0;
}

int totalMaintenanceCost(int td, int n){
    int tmc=0;
    int ttc=0;
    int bp=0;
    int bl=0;
    int tbc=0;
    int ttf=0;
    int tcc=0;
    int tbr=0;

    cout<<"\t\tCalculating maintenance cost\n"<<endl;
    cout<<"Enter tyre change price: Rs.";
    cin>>ttc;
    cout<<"Enter price of brake pad and liner: Rs.";
    cin>>tbc;
    cout<<"Enter transmission fluid cost: Rs.";
    cin>>ttf;
    cout<<"Enter coolant replacement cost: Rs.";
    cin>>tcc;
    cout<<"Enter battery replacement cost: Rs.";
    cin>>tbr;
    cout<<endl;

    ttc=ttc*(td/30000);
    tbc = tbc*(td/35000);
    ttf=ttf*(td/30000);
    tcc=tcc*n;
    tbr=tbr*(n/3);

    tmc=ttc+tbc+ttf+tcc+tbr;

    cout<<"Total tyre change price for "<<n<<" years\t\t: Rs."<<fixed<<setprecision(2)<<(float)ttc<<endl;
    cout<<"Total brake pad and liner price for "<<n<<" years\t: Rs."<<fixed<<setprecision(2)<<(float)tbc<<endl;
    cout<<"Total transmission fluid price for "<<n<<" years\t: Rs."<<fixed<<setprecision(2)<<(float)ttf<<endl;
    cout<<"Total coolant replacement price for "<<n<<" years\t: Rs."<<fixed<<setprecision(2)<<(float)tcc<<endl;
    cout<<"Total battery replacement price for "<<n<<" years\t: Rs."<<fixed<<setprecision(2)<<(float)tbr<<endl;
    cout<<endl;

    cout<<"Your total maintenance cost "<<n<<" years\t: Rs."<<fixed<<setprecision(2)<<(float)tmc<<endl;
    cout<<"Your total maintenance cost per 1 year\t: Rs."<<fixed<<setprecision(2)<<(float)tmc/(n*12)<<endl;
    cout<<"\n======================================================================"<<endl;
    return tmc;
}


int  totalOperationalCost(int td, int n, int td_month){
    int toc=0;
    float fuel;
    float tfc;
    int tic;
    float distance;
    float percentage;

    cout<<"\t\tCalculating operational cost\n"<<endl;
    cout<<"Enter fuel price: Rs.";
    cin>>fuel;
    cout<<"Enter KM travelled per Liter: ";
    cin>>distance;
    cout<<"Enter car cost evaluated by insurance officer: Rs.";
    cin>>tic;
    cout<<"Enter insurance cost per year(%): ";
    cin>>percentage;
    cout<<endl;

    tfc=((float)td/distance)*fuel;
    tic=(tic*percentage/100)*n;

    toc=tfc+tic;

    cout<<"Total fuel cost for "<<n<<" years\t\t: Rs."<<fixed<<setprecision(2)<<(float)tfc<<endl;
    cout<<"Total insurance cost for "<<n<<" years\t: Rs."<<fixed<<setprecision(2)<<(float)tic<<endl;
    cout<<endl;

    cout<<"Your total operational cost per "<<n<<" years\t: Rs."<<fixed<<setprecision(2)<<(float)toc<<endl;
    cout<<"Your total operational cost per 1 year\t: Rs."<<fixed<<setprecision(2)<<(float)toc/(n*12)<<endl;
    cout<<"\n======================================================================"<<endl;

    totalmonthlycost = totalmonthlycost + (((float)td_month/distance)*fuel) + ((float)tic/(12.0*n));

    return toc;
}

int totalServiceCost(int td, int n){
    int tsc=0;
    int tet;
    float tfs;
    float tcw;
    float carwash;

    cout<<"\t\tCalculating service cost\n"<<endl;
    cout<<"Enter vehicle emission test cost: Rs.";
    cin>>tet;
    cout<<"Enter full service cost: Rs.";
    cin>>tfs;
    cout<<"Enter car wash cost: Rs.";
    cin>>carwash;
    cout<<endl;

    tet=tet*n;
    tfs=((float)td/5000)*tfs;
    tcw=((12*n)-((float)td/5000))*carwash;

    tsc=tet+tfs+tcw;

    cout<<"Total emission test cost for "<<n<<" years\t: Rs."<<fixed<<setprecision(2)<<(float)tet<<endl;
    cout<<"Total full service cost for "<<n<<" years\t: Rs."<<fixed<<setprecision(2)<<(float)tfs<<endl;
    cout<<"Total car wash cost for "<<n<<" years\t\t: Rs."<<fixed<<setprecision(2)<<(float)tcw<<endl;
    cout<<endl;

    cout<<"Your total service cost per "<<n<<" years\t: Rs."<<fixed<<setprecision(2)<<(float)tsc<<endl;
    cout<<"Your total service cost per 1 year\t: Rs."<<fixed<<setprecision(2)<<(float)tsc/(n*12)<<endl;
    cout<<"======================================================================"<<endl;

    totalmonthlycost = totalmonthlycost + (tfs/(12.0*n)) + carwash;

    return tsc;
}


int totalOtherCost(int td, int n, float price){
    int totherc=0;
    float sc;
    float lr;
    float r;
    float a;

    cout<<"\t\tCalculating other cost\n"<<endl;
    cout<<"Enter supplementary cost(%): ";
    cin>>sc;
    cout<<"Enter lease amount: Rs.";
    cin>>a;
    cout<<"Enter lease rate for "<<n<<" years: ";
    cin>>r;
    cout<<endl;

    sc=price*sc/100;
    sc=sc*0.25*n;
    lr=a*r/100;
    ls =ls + (a/(12*n));
    ls = ls + (lr*(1.0/(12*n)));

    totherc=sc+lr+a;

    cout<<"Total supplementary cost for "<<n<<" years\t: Rs."<<fixed<<setprecision(2)<<(float)sc<<endl;
    cout<<"Total lease rate for "<<n<<" years\t: Rs."<<fixed<<setprecision(2)<<(float)lr<<endl;
    cout<<"Total lease for "<<n<<" years\t\t\t: Rs."<<fixed<<setprecision(2)<<(float)a<<endl;
    cout<<endl;

    cout<<"Your total service cost per "<<n<<" years\t: Rs."<<fixed<<setprecision(2)<<(float)totherc<<endl;
    cout<<"Your total service cost per 1 year\t: Rs."<<fixed<<setprecision(2)<<(float)totherc/(n*12)<<endl;
    cout<<"\n======================================================================"<<endl;

    totalmonthlycost = totalmonthlycost + ls + (sc/3.0);

    return totherc;
}

int carDepreciation(int n, float price){
    int cd=price;
    int d[10] = {15,10,10,5,5,3,3,2,2,1};
    cout<<"\t\tCalculating car depreciation\n"<<endl;
    for (int i=0; i<n; i++){
        cd=cd-(cd*d[i]/100);
        cout<<"Depreciation for year "<<i+1<<": Rs."<<fixed<<setprecision(2)<<(float)cd<<endl;
    }
    cout<<"\n======================================================================"<<endl;
    return cd;
}

void final_result (int tmc, int toc, int tsc, int totherc, int cd, int n){
    cout<<"\t\tFinal cost\n"<<endl;
    int sum = tmc + toc + tsc + totherc;
    cout<<"Total cost for vehicle for "<<n<<" years\t\t: Rs."<<fixed<<setprecision(2)<<(float)sum<<endl;
    cout<<"Lease settlement for vehicle for 1 month\t: Rs."<<fixed<<setprecision(2)<<ls<<endl;
    cout<<"Total cost for vehicle for 1 month\t\t: Rs."<<fixed<<setprecision(2)<<totalmonthlycost<<endl;
    cout<<"Total Monthly cost without lease settlement\t: Rs."<<fixed<<setprecision(2)<<totalmonthlycost-ls<<endl;
    cout<<"\nCar value left after "<<n<<" years: Rs."<<fixed<<setprecision(2)<<(float)cd<<endl;
    cout<<"\nThank you for using our system!\nHave a nice day!";
    cout<<"\n======================================================================"<<endl;

}
