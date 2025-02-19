#include <iostream>
#include <fstream>
#include <string>
#include <TH1F.h>
#include <TCanvas.h>

using namespace std;

void zadanie1(const string& file = "wave_0.dat"){  
    
    ifstream input(file, ios::binary);  
    
    if (!input){

        cout << "File not open :<" << endl;
        return;

    }

    cout << "File with data is open" << endl;

    Int_t N = 0;
    Int_t n = 0;
    Float_t data;
    const Int_t window = 1024;  
    const Double_t adc2mV = 1/4.096; 

    gStyle->SetOptStat(0);
    
    TH1F *hist = new TH1F("Histogram", "Signal amplitude in time", window, 0, window);  
    TCanvas *c1 = new TCanvas("c1", "Signal amplitude in time", 1000, 600);
    TLegend *leg = new TLegend(0.7, 0.4, 0.9, 0.6);  
    
    hist->GetXaxis()->SetTitle("time [ns]");
    hist->GetYaxis()->SetTitle("voltage [mV]");  
    
    while (input.read(reinterpret_cast<char*>(&data), sizeof(data))) N++;

    input.clear();  
    input.seekg(0, ios::beg); 
    
    Int_t N_hist = N/window;

    Char_t Q;

    cout << "Number of events: " << N_hist << endl;

    cout << "Do you want to substract baseline y/n: " << endl;

    cin >> Q;

    while (n < N_hist){
        
        Int_t k = 0;
        Double_t sum = 0;

        while (input.read(reinterpret_cast<char*>(&data), sizeof(data)) && k+window*n < 50+window*n){

            sum = sum + data;
            k++;

        }

        Double_t base = sum*adc2mV/50.;
        
        input.clear();  
        input.seekg(n*window*4, ios::beg); 
 
        Int_t i = 0;
        while (input.read(reinterpret_cast<char*>(&data), sizeof(data)) && i+window*n < window*(n+1)) {

            data = data*adc2mV;

            if (Q == 'y' || Q == 'Y'){

                data = data-base;

            }

            hist->SetBinContent(i+1, data);

            i++;
        }
        
        char text[20];
        sprintf(text, "Event number %d", n+1);
        leg->AddEntry(hist, text, "1");
        char text2[50];   
        sprintf(text2, "BL = %.3f mV", base); 
        leg->AddEntry(hist, text2, "2");
        
        hist->Draw();
        leg->Draw();

        cout << "Base value of event number " << n+1 << " is " << base << " mV" << endl;        
        cout << "Click twice on histogram to show next one  " << endl;
        cout << N_hist-(n+1) << " events left" << endl;

        c1->WaitPrimitive();   
        c1->Clear();
        leg->Clear();
        hist->Reset();
        
        n++;
    }
    
    input.close();     
    
}