// Potongan fungsi utama Orion 05.
// Modul sensor, katup, layar, dan angka kalibrasi tidak ada di repo ini.
// File ini tidak cukup untuk di-compile atau dipasang ke mesin.

void setup() {
    usbBegin();

    ioBusBegin();       // jalur bersama tombol panel
    panelBegin();       // knop burner, udara, drum, dan tombol
    thermoBegin();      // termokopel biji, ruang, motor
    sensorBoardBegin(); // papan tekanan gas dan sensor gas
    actuatorsBegin();   // servo katup, drum, blower, cooling
    safetyBegin();
    screenBegin();
    audioBegin();
    artisanBegin();     // laptop hanya meminta suhu
    settingsBegin();
}

void loop() {
    screenPoll();
    artisanPoll();
    sensorBoardPoll();
    drumSpeedTick();
    gasValveTick();     // servo maju sedikit menuju persen knop

    if (screen.startPressed()) {
        clearCurve();
        recording = true;   // timer dan kurva mulai
    }
    if (screen.stopPressed()) {
        recording = false;  // kurva diam; gas tidak ikut terbuka
    }
    if (screen.resetPressed()) {
        recording = false;
        elapsed = 0;
        clearCurve();
    }

    readTemperatures(bean, chamber, motor);
    rejectShortSpikes(bean, chamber, motor);

    readKnobs(airPct, burnerPct, drumPct);
    Safety safe = safetyUpdate(chamber, bean, motor, gasReading, pressure);
    applyOutputs(safe, drumPct, airPct, burnerPct);
    // tidak aman: katup gas ditutup, drum bisa berhenti

    if (oneSecondElapsed()) {
        updateRateOfRise(bean, chamber);
        if (recording) {
            elapsed++;
            drawCurvePoint(bean, chamber);
        }
        showNumbers(bean, chamber, elapsed, pressure);
    }

    audioTick(safe);
    sendTemperaturesIfLaptopAsks(bean, chamber, motor);
}
