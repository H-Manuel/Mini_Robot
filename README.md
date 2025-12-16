# FLAM – Modulare Mobile Roboterplattform

**Projektstatus:** 🚧 *Prototyp (Version 1) – In Weiterentwicklung*  \
**Kurs:** Elektronische Produktentwicklung (MCI Bachelor Mechatronik)

📄 **Dokumentation:** Vollständigen Projektbericht ansehen (PDF)

---

## 👥 Autoren

**Gruppe BA-MECH-23-AED:**

- Manuel Hofer  
- Alexander Oberhofer  
- Leo Maier  
- Fabian Augschöll

Dieses Projekt entstand im Rahmen des Bachelor-Studiengangs **Mechatronik**.

---

## 📖 Über das Projekt

Ziel dieses Projekts ist die Entwicklung einer autonomen, modularen Roboterplattform zur Veranschaulichung von **Sensorfusion** im Zusammenhang mit **Indoor-Positionsbestimmung**. Die Plattform **FLAM** dient als Basis für Algorithmen zur autonomen Navigation und nutzt das **Marvelmind Indoor-GPS System**.

Das System ist für den **Akkubetrieb** ausgelegt und basiert auf **Micro-ROS**, was eine flexible Einbindung in ROS-basierte Host-Systeme (z. B. Raspberry Pi oder PC) ermöglicht.

> ℹ️ **Hinweis:** Der QR-Code auf der Unterseite der Platine verlinkt direkt zu diesem Repository.

---

## ✨ Features

- **Modularität:** Erweiterbar um Sensoren wie LiDAR, Kameras oder Näherungssensoren  
- **Konnektivität:** Native Micro-ROS Unterstützung via WiFi (ESP32-S3)  
- **Antrieb:** DC-Antrieb mit Encodern für Odometrie  
- **Lokalisierung:** Vorbereitet für Marvelmind Super-Beacons (±2 cm Genauigkeit)  
- **Mechanik:** Vollständig 3D-gedrucktes Gehäuse (PLA) und spezielle Soft-Reifen (TPU) für optimalen Grip auf glatten Oberflächen

---

## 🔧 Hardware Spezifikationen

### Elektronik & PCB

Das Herzstück ist eine eigens entwickelte **2-Layer-Platine**. Die Design-Dateien befinden sich im Ordner `/hardware/pcb`.

- **Mikrocontroller:** ESP32-S3-WROOM-2-N32R16V (USB-C Programmierung & WiFi)

### Spannungsversorgung

- **Akku:** 3,7 V 2000 mAh LiPo  
- **Lademanagement:** MCP73831T-2ACI/OT  
- **Spannungsregler:**  
  - TLV767DRVR (LDO 3.3 V)  
  - TPS63070RNMT (Buck/Boost 3.3 V)

- **Motor-Treiber:** DRV8835DSSR Dual H-Brücke

- **Schnittstellen:** I2C (2×), UART, GPIOs, USB-C

---

### Sensoren

- **Abstand:** VL53L3CX Time-of-Flight (25–3000 mm)  
- **Farbe/Linien:** Gravity TCS34725 RGB Sensor  
- **Position:** Marvelmind Starter Set Super-MP-3D

---

### Mechanik

- **Chassis:** Modularer Aufbau, Baseplate mit Führungselementen für PCB  
  → 3D-Modelle (STL/STEP) unter `/mechanical`
- **Reifen:** Luftloses Design, gedruckt aus TPU A70

---

## 🚀 Inbetriebnahme (Getting Started)

### Voraussetzungen

#### Software

- ESP-IDF **oder** Arduino IDE (mit ESP32 Board Support)
- Micro-ROS Agent auf dem Host-Computer

#### Hardware

- USB-C Kabel (datenfähig)
- LiPo Akku (für mobilen Betrieb)

---

### Flashen des ESP32

Das Board verfügt über dedizierte **BOOT**- und **RST**-Taster.

1. Board via USB-C verbinden
2. **BOOT** gedrückt halten
3. **RST** kurz drücken
4. **BOOT** loslassen → Download-Modus aktiv
5. Firmware hochladen
6. **RST** drücken zum Starten

---

### Jumper Konfiguration (V1)

| Jumper | Funktion       | Beschreibung |
|------:|----------------|--------------|
| J2    | USB Power      | Verbindet 5 V USB mit dem LDO (Betrieb ohne Akku) |
| J3    | 3.3 V Link     | Verbindet die 3.3 V Schienen von USB und Batterie |
| J10   | Batterie       | Hauptanschluss für den LiPo-Akku |
| J11   | ON / OFF       | Anschluss für den Hauptschalter |

Eine detaillierte Beschreibung aller Jumper findest du im Projektbericht unter **Punkt 3.4.1**.

---

## ⚠️ Bekannte Probleme (Version 1) & Workaround

Diese Version ist ein funktioneller Prototyp, weist jedoch folgende bekannte Mängel auf:

- **Boost-Converter (TPS61088):** Thermisches Problem durch fehlende Masseflächen-Anbindung → Überhitzung bei Last
- **Motor-Treiber (DRV8835):** Sehr kleine Bauform → Fertigungsschwierigkeiten und Kurzschlussgefahr beim Handlöten
- **PCB-Beschriftung:** PWM A und PWM B Pins im Schaltplan vertauscht

---

### 🛠 Aktueller Workaround

Zur kurzfristigen Umgehung der Fehler von Version 1 wurde ein **externes Motortreiber-Development-Board** bestellt. Damit wird ein temporär funktionierender Prototyp aufgebaut, um den Testbetrieb fortzuführen, während **Version 2** entwickelt wird.

---

## 📅 Roadmap (Version 2)

Die nächste Iteration konzentriert sich auf **Fehlerbehebung**, **Miniaturisierung** und **erweiterte Funktionalität**.

### Hardware Redesign (PCB)

[ ] Thermisches Management: Optimierung der Ground-Planes für den Boost-Converter  
[ ] Motortreiber: Layout-Überarbeitung oder Bauteilwechsel für einfachere Bestückung  
[ ] Induktives Laden: Integration der Hardware für kabelloses Laden  
[ ] Batteriemonitoring: Überwachungsschaltung zur direkten Ladezustandsmessung  
[ ] Debug-Features: User-LED auf dem PCB  
[ ] Display-Interface: Vorbereitung für ein I2C-Display (Speed, Akku, Modus)

### Mechanik & Design

[ ] Miniaturisierung: Reduktion auf „Zigarettenschachtel-Größe“ durch optimiertes Routing und kompaktes Gehäuse  
[ ] Reifen-Upgrade: Weicheres TPU (Shore < 95A) für maximalen Grip auf Glasoberflächen


