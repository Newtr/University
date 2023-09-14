#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Transport{
    float Speed;
    float TicketCost;
    int Time;
    int MaxRange;
};

/* int Transport::Calculate(enum CRange){
    TicketCost = MaxRange * CRange;
    Time = MaxRange/Speed;
    return Time,TicketCost;
} */

enum TransportClass{
    CAR = 4,
    BUS = 90,
    MINIBUS = 20,
    TRAIN = 50,
    BIKE = 2,
    ONFOOT = 0,
};

enum CitiesRange{
    MINSK_BREST = 350,
    MINSK_GRODNO = 270,
    MINSK_VITEBSK = 310,
    MINSK_GOMEL = 320,
    MINSK_MOGILEV = 210,

    BREST_GRODNO = 240,
    BREST_VITEBSK = 614,
    BREST_GOMEL = 576,
    BREST_MOGILEV = 523,

    GRODNO_VITEBSK = 536,
    GRODNO_GOMEL = 594,
    GRODNO_MOGILEV = 478,

    VITEBSK_GOMEL = 331,
    VITEBSK_MOGILEV = 161,

    GOMEL_MOGILEV = 174
};

void Calculate(Transport& ex, CitiesRange cit, int spd, TransportClass tr){
    ex.MaxRange = cit;
    ex.Speed = spd;
    ex.Time = (ex.MaxRange/ex.Speed)*60;
    ex.TicketCost = ex.MaxRange/tr;
}

int TakeSpeed(Transport tr, int choose){
    ifstream IFile;
    string str, speed;
    static int NowSpeed;
    int count = 19, right=1;
    bool car = true;
    IFile.open("D:\\GitHub\\Second-Project\\TransportInformation.txt", ios::binary|ios::app);
    while (!IFile.eof() && car==true)
    {
        getline(IFile,str);
        if (str=="")
        {
            car=false;
            continue;
        }
        else if (right==choose)
        {
            switch (choose)
            {
            case 1:
                speed = str.substr(17,2);
                break;
            case 2:
                speed = str.substr(17,2);
                break;
            case 3:
                speed = str.substr(21,2);
                break;
            case 4:
                speed = str.substr(19,2);
                break;
            case 5:
                speed = str.substr(18,2);
                break;
            case 6:
                speed = str.substr(20,1);
                break;
            
            }
            car = false;
        }
        else if (right!=choose)
        {
            right++;
            continue;
        }
        
    }
    NowSpeed = stoi(speed);
    IFile.close();
    return NowSpeed;
}

void TakeIndex(string ff, int& Index){
    if (ff.substr(0)=="Minsk")
    {
        Index = 220000;
    }
    else if (ff.substr(0)=="Brest")
    {
        Index = 224000;
    }
    else if (ff.substr(0)=="Grodno")
    {
        Index = 230000;
    }
    else if (ff.substr(0)=="Vitebsk")
    {
        Index = 210000;
    }
    else if (ff.substr(0)=="Gomel")
    {
        Index = 246000;
    }
    else if (ff.substr(0)=="Mogilev")
    {
        Index = 212000;
    }
}

void FindCityRange(int Ind1, int Ind2, CitiesRange& Rg){
    string City1, City2, AllCity;
    switch (Ind1)
    {
    case 220000:    //Minsk
        switch (Ind2)
        {
        case 224000:
            Rg = MINSK_BREST;
            break;
        case 230000:
            Rg = MINSK_GRODNO;
            break;
        case 210000:
            Rg = MINSK_VITEBSK;
            break;
        case 246000:
            Rg = MINSK_GOMEL;
            break;
        case 212000:
            Rg = MINSK_MOGILEV;
            break;
        }
        break;
    case 224000:    //Brest
        switch (Ind2)
        {
        case 220000:
            Rg = MINSK_BREST;
            break;
        case 230000:
            Rg = BREST_GRODNO;
            break;
        case 210000:
            Rg = BREST_VITEBSK;
            break;
        case 246000:
            Rg = BREST_GOMEL;
            break;
        case 212000:
            Rg = BREST_MOGILEV;
            break;
        }
        break;
    case 230000:    //Grodno
        switch (Ind2)
        {
        case 220000:
            Rg = MINSK_GRODNO;
            break;
        case 224000:
            Rg = BREST_GRODNO;
            break;
        case 210000:
            Rg = GRODNO_VITEBSK;
            break;
        case 246000:
            Rg = GRODNO_GOMEL;
            break;
        case 212000:
            Rg = GRODNO_MOGILEV;
            break;
        }
        break;
    case 210000:    //Vitebsk
        switch (Ind2)
        {
        case 20000:
            Rg = MINSK_VITEBSK;
            break;
        case 224000:
            Rg = BREST_VITEBSK;
            break;
        case 230000:
            Rg = GRODNO_VITEBSK;
            break;
        case 246000:
            Rg = VITEBSK_GOMEL;
            break;
        case 212000:
            Rg = VITEBSK_MOGILEV;
            break;
        }
        break;
    case 246000:    //Gomel
        switch (Ind2)
        {
        case 20000:
            Rg = MINSK_GOMEL;
            break;
        case 224000:
            Rg = BREST_GOMEL;
            break;
        case 230000:
            Rg = GRODNO_GOMEL;
            break;
        case 246000:
            Rg = VITEBSK_GOMEL;
            break;
        case 212000:
            Rg = GOMEL_MOGILEV;
            break;
        }
        break;
    case 212000:    //Mogilev
        switch (Ind2)
        {
        case 220000:
            Rg = MINSK_MOGILEV;
            break;
        case 224000:
            Rg = BREST_MOGILEV;
            break;
        case 230000:
            Rg = GRODNO_MOGILEV;
            break;
        case 246000:
            Rg = VITEBSK_MOGILEV;
            break;
        case 212000:
            Rg = GOMEL_MOGILEV;
            break;
        }
        break;
    }
}

void FindMyTransp(TransportClass& Tr, int userchoose){
    switch (userchoose)
    {
    case 1:
        Tr = CAR;
        break;
    case 2:
        Tr = BUS;
        break;
    case 3:
        Tr = MINIBUS;
        break;
    case 4:
        Tr = TRAIN;
        break;
    case 5:
        Tr = BIKE;
        break;
    case 6:
        Tr = ONFOOT;
        break;
    }
}

int main(){
    int choose, CityIndex1=0, CityIndex2=0, speed;
    Transport MyTransport;
    string from, to;
    CitiesRange Range;
    TransportClass Transp;
    cout<<"Choose vehicle: 1) Car 2) Bus 3) Minibus 4) Train 5) Bike 6) On Foot"<<endl;
    cin>>choose;
    FindMyTransp(Transp, choose);
    speed = TakeSpeed(MyTransport,choose);
    cout<<"You going from : ";  cin>>from;
    cout<<"Going to : ";    cin>>to;
    TakeIndex(from,CityIndex1);
    TakeIndex(to,CityIndex2);
/*     cout<<"1 = "<<CityIndex1<<" 2 = "<<CityIndex2<<endl; */
    FindCityRange(CityIndex1,CityIndex2,Range);
/*     cout<<"Vot = "<<Range<<endl; */
    Calculate(MyTransport,Range,speed,Transp);
    cout<<"Примерное время составит: "<<MyTransport.Time<<" минут"<<endl;
    cout<<"Стоимость составит: "<<MyTransport.TicketCost<<"$"<<endl;
}