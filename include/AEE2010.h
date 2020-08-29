#ifndef __AEE2010_H__
#define __AEE2010_H__

// AEE2010 buses
#define AEE2010_BUS_IS      0x01 // "Inter-Systemes" Bus
#define AEE2010_BUS_CONF    0x02 // "Confort" bus
#define AEE2010_BUS_CAR     0x04 // "Carrosserie" bus
#define AEE2010_BUS_LAS     0x08 // "Liaison Au Sol" bus
#define AEE2010_BUS_INFO    0x10 // "Information et Divertissement" bus


// AEE2010 ECUs
// High-Speed is the same as AEE2004
// Low-speed have these news ECUs (no IDs yet)
// LCE - Lecteur de Cle Electronique (ADML?)
// AVE - Antivol Electronique (already on AEE2004?!?)
// BML - Boitier Mains Libres (TKML?)
// BSG RQ - Boitier de Servitude Generique Remorque
// BSG OP - Boitier de Servitude Generique Option
// CIELO - Toit en verre Electro-Chrome
// SAM/MPD - Surveillance d'Angle Mort/Mesure de Place Disponible
// AFIL - Alerte de Franchissement Invonlontaire de Ligne (BSTL?)
// All the BDM* goes into one BDM
// FMUX - Facade MUltipleXee
// VISION AR/LAT - Vision Arriere/Laterale
// VISION NUIT - Vision nuit
// BTA - Boitier Telematique Autonome
// BSG TT - Boitier de Servitude Generique Transformation Telematique
// Assistance Feux Route

#endif /* __AEE2010_H__ */
