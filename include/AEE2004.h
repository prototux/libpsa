#ifndef __AEE2004_H__
#define __AEE2004_H__

// AEE2004 Definitions (buses, ECUs, etc)

// CAN Buses
#define AEE2004_BUS_IS      0x01 // "Inter-Systemes" Bus
#define AEE2004_BUS_CONF    0x02 // "Confort" bus
#define AEE2004_BUS_CAR     0x04 // "Carrosserie" bus

// High Speed ECUs
#define AEE2004_ECU_HS_ADF        0x01 // Amplificateur de freinage
#define AEE2004_ECU_HS_AR2S       0x02 // Alternateur Reversible Stop&Start
#define AEE2004_ECU_HS_CC2S       0x03 // Controle Central Stop&Start
#define AEE2004_ECU_HS_BVMP       0x04 // Boite de Vitesse Manuelle Pilotee
#define AEE2004_ECU_HS_CAV        0x05 // Capteur d'Angle Volant de direction
#define AEE2004_ECU_HS_CMAD       0x06 // Calculateur Machine Alterno-Demarreur
#define AEE2004_ECU_HS_CMM        0x08 // Calculateur Multifonction Moteur
#define AEE2004_ECU_HS_BVA        0x09 // Boite de Vitesse Automatique
#define AEE2004_ECU_HS_COMELEC    0x0A // levier de vitesse a COMmande ELECtronique
#define AEE2004_ECU_HS_CCS        0x0B // Controle Commande Soupape
#define AEE2004_ECU_HS_CGPL       0x0C // Calculateur Injection GPL
#define AEE2004_ECU_HS_ABS        0x0D // ABS/ESP
#define AEE2004_ECU_HS_DSG        0x0F // Detection de Sous Gonflage
#define AEE2004_ECU_HS_CSS        0x10 // Calculateur Systeme Suspension
#define AEE2004_ECU_HS_BHI        0x11 // Boitier Hydraulique Intelligent
#define AEE2004_ECU_HS_BSI        0x12 // Boitier de Servitude Intelligent
#define AEE2004_ECU_HS_FSE        0x13 // Frein de Stationement Electrique/Frein SEcondaire
#define AEE2004_ECU_HS_MSB        0x14 // Module de Surveillance Batterie
#define AEE2004_ECU_HS_DAE        0x15 // Direction Assistee Electrique
#define AEE2004_ECU_HS_ACC        0x16 // Boitier Regulation Vitesse/Adaptive Cruise Control
#define AEE2004_ECU_HS_BCP        0x17 // Boitier Correcteur de Projecteurs
#define AEE2004_ECU_HS_CAAR       0x18 // Correcteur d'Assiette ARriere
#define AEE2004_ECU_HS_CAF        0x19 // CApteur Frein
#define AEE2004_ECU_HS_CHAR       0x1A // CHARgeur
#define AEE2004_ECU_HS_TEST       0x1C // TESTeur debarque
#define AEE2004_ECU_HS_CDP        0x1F // Correcteur Dynamique de phares

// Low Speed ECUs
#define AEE2004_ECU_LS_ADML       0x01 // Acces et Demarrage Main Libres
#define AEE2004_ECU_LS_HDC        0x02 // Haut De colonne
#define AEE2004_ECU_LS_RBG        0x04 // boitier aiRBaG centralise
#define AEE2004_ECU_LS_COV_P      0x05 // Classification Occupant Vehicule Passager
#define AEE2004_ECU_LS_COV_C      0x06 // Classification Occupant Vehicule Conducteur
#define AEE2004_ECU_LS_BSM        0x07 // Boitier de Servitude Moteur
#define AEE2004_ECU_LS_BSC        0x08 // Boitier de Servitude Coffre
#define AEE2004_ECU_LS_BDCP       0x09 // Boitier de Detection Choc Pieton
#define AEE2004_ECU_LS_CDPL       0x0A // Capteur De Pluie et Luminosite
#define AEE2004_ECU_LS_EDP_C      0x0B // Electronique De Porte Conducteur
#define AEE2004_ECU_LS_EDP_P      0x0C // Electronique De Porte Passager
#define AEE2004_ECU_LS_EDP_ARG    0x0D // Electronique De Porte ARriere Gauche
#define AEE2004_ECU_LS_EDP_ARD    0x0E // Electronique De Porte ARriere Droite
#define AEE2004_ECU_LS_AVE        0x0F // Anti-Vol Electrique
#define AEE2004_ECU_LS_PDSC       0x10 // Platine De Siege Conducteur
#define AEE2004_ECU_LS_PDSP       0x11 // Platine De Siege Passager
#define AEE2004_ECU_LS_BSI        0x12 // Boitier de Servitude Intelligent
#define AEE2004_ECU_LS_TKML       0x14 // Telephone Kit Main Libre
#define AEE2004_ECU_LS_MDPLC      0x15 // Module De Porte Laterale Coulissante
#define AEE2004_ECU_LS_BDM_A      0x17 // Boitier De Memorisation Arriere
#define AEE2004_ECU_LS_BDS_ARD    0x18 // Boitier De Siege ARriere Droit
#define AEE2004_ECU_LS_BDS_ARG    0x19 // Boitier De Siege ARriere Gauche
#define AEE2004_ECU_LS_SAM        0x1B // Surveillance Angle Mort
#define AEE2004_ECU_LS_ALARM      0x1C // ALARMe
#define AEE2004_ECU_LS_AAS        0x1D // Aide Au Stationnement
#define AEE2004_ECU_LS_MAE        0x1E // Module Auto-Ecole
#define AEE2004_ECU_LS_CMB        0x1F // CoMBine
#define AEE2004_ECU_LS_RAD        0x20 // RADio
#define AEE2004_ECU_LS_AAD        0x21 // Surveillance d'Angle Mort
#define AEE2004_ECU_LS_BSTL       0x22 // Boitier Surveillance Trajectoire Laterale
#define AEE2004_ECU_LS_RT3        0x24 // Radio-Telephone 3eme generation
#define AEE2004_ECU_LS_EMF        0x25 // Ecran Multi-Fonction
#define AEE2004_ECU_LS_BCD_AD     0x26 // Boitier Combine Deporte / Afficheur Deporte
#define AEE2004_ECU_LS_BTE        0x27 // Boitier de Toit Escamotable
#define AEE2004_ECU_LS_SCU        0x28 // Sun-roof Control Unit / Toit Ouvrant 1ere rangee
#define AEE2004_ECU_LS_TO2        0x29 // Toit Ouvrant 2eme rangee
#define AEE2004_ECU_LS_TO3        0x2A // Toit Ouvrant 3eme rangee
#define AEE2004_ECU_LS_BCM        0x2B // Botier de Coffre Motorise
#define AEE2004_ECU_LS_BSR        0x2C // Boitier de Servitude Remorque
#define AEE2004_ECU_LS_CLIM       0x2D // CLIMatisation avant
#define AEE2004_ECU_LS_BDM_C      0x2E // Boitier De Memorisation Conducteur
#define AEE2004_ECU_LS_BDM_P      0x2F // Boitier De Memorisation Passager
#define AEE2004_ECU_LS_VTH        0x30 // Vision Tete Haute
#define AEE2004_ECU_LS_CDC        0x31 // Changeur de Disque Compact
#define AEE2004_ECU_LS_NAV        0x32 // NAVigation
#define AEE2004_ECU_LS_KML        0x33 // Kit Main Libre
#define AEE2004_ECU_LS_DEF        0x34 // DEFlecteur mobile volet arriere
#define AEE2004_ECU_LS_ADDGO      0x35 // calculateur ADDitivation GazOle
#define AEE2004_ECU_LS_CRT        0x37 // Commande Radio Telephone
#define AEE2004_ECU_LS_CLIM_AR    0x38 // CLIMatisation ARriere
#define AEE2004_ECU_LS_ESV        0x39 // moteur ESsuie Vitres avant
#define AEE2004_ECU_LS_BNB_C      0x3C // Boitier de Non Bouclage ceinture
#define AEE2004_ECU_LS_AMPLI      0x3D // AMPLIficateur audio separe

#endif /* __AEE2004_H__ */
