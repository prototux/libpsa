#ifndef __VAN_H__
#define __VAN_H__

// VAN Buses
#define VAN_BUS_IS      0x01 // "Inter-Systemes" Bus
#define VAN_BUS_CONF    0x02 // "Confort" bus
#define VAN_BUS_CAR     0x04 // "Carrosserie" bus

// VAN ECUs
#define VAN_ECU_BSM      0x00 // Boitier de Servitude Moteur
#define VAN_ECU_EMF      0x02 // Ecran Multi-Fonction
#define VAN_ECU_RBCU     0x03 // Boitier Retournement/Taxi
#define VAN_ECU_RBG      0x04 // boitier aiRBaG centralise
#define VAN_ECU_DPP      0x05 // Detection Porte Passager
#define VAN_ECU_TAV      0x06 // Telecommande Au Volant
#define VAN_ECU_NAV      0x07 // NAVigation
#define VAN_ECU_HDC      0x08 // Haut De Colonne
#define VAN_ECU_MAE      0x09 // Module Auto-Ecole
#define VAN_ECU_RAD      0x0A // RADio
#define VAN_ECU_CDPL     0x0C // Capteur De Pluie et Luminosite
#define VAN_ECU_ALARM    0x0D // boitier ALARMe
#define VAN_ECU_CLIM     0x0E // CLIMatisation
#define VAN_ECU_ADDGO    0x10 // calculateur ADDitivation GazOle
#define VAN_ECU_BSI      0x12 // Boitier de Servitude Intelligent
#define VAN_ECU_BTO      0x13 // Boitier Temoin Odometre
#define VAN_ECU_AAS      0x14 // Aide Au Stationnement
#define VAN_ECU_CDC      0x16 // Changeur de Disque Compact
#define VAN_ECU_BDM      0x17 // Boitier De Memorisation siege conducteur
#define VAN_ECU_BTE      0x18 // Boitier de Toit Escamotable/ouvrant
#define VAN_ECU_MDPLC    0x19 // Module De Porte Laterale Coulissante
#define VAN_ECU_KML      0x1A // Kit Main Libre
#define VAN_ECU_EDP_C    0x1B // Electronique De Porte avant Conducteur
#define VAN_ECU_TO2      0x1C // Toit Ouvrant 2eme rangee
#define VAN_ECU_EDP_P    0x1D // Electronique De Porte avant Passager
#define VAN_ECU_CMB      0x1E // CoMBine
#define VAN_ECU_TO3      0x1F // Toit Ouvrant 3eme rangee

#endif /* __VAN__H__ */
