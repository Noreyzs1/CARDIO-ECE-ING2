#include "rtc.hpp"

// Initalisation RTC
ThreeWire myWire(PIN_IO,PIN_CLK,PIN_CE);
RtcDS1302 <ThreeWire> Rtc(myWire);
RtcDateTime now;


// Variables de texte a afficher
static char textDate[11];
static char textHeure[9];

void texteDateHeure(){

    snprintf(textDate,sizeof(textDate),"%02u:%02u:%04u",
             (u16)now.Day(),
             (u16)now.Month(),
             (u16)now.Year());
    
    snprintf(textHeure,sizeof(textHeure),"%02u:%02u:%02u",
             (u8)now.Hour(),
             (u8)now.Minute(),
             (u8)now.Second());
}

bool TestValidite(){
    RtcDateTime DateCompil(__DATE__,__TIME__);
    if (now<DateCompil){
        return false;
        //A rajouter message d'erreur sur l'ecran oled peuèt etre // Ça se voit c'est MAxime qui a écrit ça
    }
    else if (now>=DateCompil){
        return true;
    }
}

void loopRtc(){
    static u16 derniereLecture = 0;
    u16 maintenant = (u16)millis();

    if ((u16)(maintenant-derniereLecture)>=1000){
        // Spammer l'affichage oled actualiser toutes les secondes
    }
}