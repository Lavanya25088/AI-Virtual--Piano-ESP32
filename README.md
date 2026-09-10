# 🎹 AI Virtual Piano using ESP32

An AI-based virtual piano that combines **Computer Vision, Hand Tracking,
Python audio processing, and ESP32 hardware**.

The system uses a webcam to track the user's hand using **MediaPipe**.
The position of the index finger is used to interact with eight virtual
piano keys displayed on the screen.

When a key is selected, the corresponding musical note can be played
through the **laptop, ESP32 buzzer, or both simultaneously**. LEDs connected
to the ESP32 provide visual feedback for the selected key.

---

## ✨ Features

- 🎹 8 virtual piano keys
- ✋ Real-time hand tracking using MediaPipe
- 👆 Index-finger based key detection
- 🎵 Real-time piano note generation
- 🔊 Laptop audio output
- 🔔 ESP32 buzzer output
- 💡 LED indication for selected piano keys
- 🔌 Serial communication between Python and ESP32
- 🎛️ Three sound modes
- 🔄 Automatic ESP32 serial-port detection
- 💻 Works with a standard computer webcam

---

## 🧠 How It Works

```text
                  Webcam
                     │
                     ▼
            OpenCV Video Capture
                     │
                     ▼
             MediaPipe Hands
                     │
                     ▼
          Index Finger Detection
                     │
                     ▼
        Virtual Piano Key Detection
                     │
                     ▼
               Python Program
                /           \
               /             \
              ▼               ▼
       Laptop Audio         Serial
                              │
                              ▼
                            ESP32
                           /     \
                          /       \

                         ▼         ▼
                      Buzzer      LEDs
The webcam captures the user's hand.

MediaPipe detects the hand landmarks and identifies the position of the
index finger.

The Python program determines which virtual piano key the finger is
pointing at.

The selected note is then:

played through the laptop,
sent to the ESP32 buzzer,
or played through both.

The corresponding LED connected to the ESP32 is also activated.

🎹 Virtual Piano

The project contains eight virtual piano keys:

Key	Note	Frequency
1	C	262 Hz
2	D	294 Hz
3	E	330 Hz
4	F	349 Hz
5	G	392 Hz
6	A	440 Hz
7	B	494 Hz
8	C2	523 Hz

The Python program generates piano-style audio for these notes and can
also send the selected note information to the ESP32.

# 🔌 Hardware Connections

The ESP32 controls four LEDs based on commands received from the Python
program through serial communication.

## ESP32 Pin Configuration

| Component | ESP32 GPIO | Function |
|-----------|------------|----------|
| LED 1 | GPIO 25 | Piano Key Group 1 |
| LED 2 | GPIO 26 | Piano Key Group 2 |
| LED 3 | GPIO 27 | Piano Key Group 3 |
| LED 4 | GPIO 32 | Piano Key Group 4 |

## LED Wiring

Each LED should be connected with a current-limiting resistor
(typically 220Ω–330Ω).

```text
ESP32 GPIO 25 ── 220Ω ──► LED 1 ──► GND
ESP32 GPIO 26 ── 220Ω ──► LED 2 ──► GND
ESP32 GPIO 27 ── 220Ω ──► LED 3 ──► GND
ESP32 GPIO 32 ── 220Ω ──► LED 4 ──► GND

The eight piano notes are divided across four LEDs, with each LED
representing two adjacent piano notes.

LED 1 → C / D
LED 2 → E / F
LED 3 → G / A
LED 4 → B / C2
💻 Software & Technologies
Programming
Python
C/C++ for ESP32
Computer Vision
OpenCV
MediaPipe
Audio
Pygame
Python WAV generation
Communication
PySerial
Serial communication
Hardware Development
ESP32
Arduino IDE
📡 Python → ESP32 Communication

The Python program communicates with the ESP32 through serial communication
at 9600 baud.

The ESP32 expects commands in the following format:

NOTE:X,LED:Y

For example:

NOTE:0,LED:0

This represents the first piano note and the first LED.

Another example:

NOTE:4,LED:2

represents the fifth piano note and the third LED.

The ESP32 reads the incoming serial command, extracts the note and LED
numbers, activates the corresponding LED and plays the selected frequency
through the buzzer.

🎛️ Sound Modes

The Python application supports three sound modes:

1 → Laptop
2 → Buzzer
3 → Both
💻 Laptop Mode

The selected piano note is played through the computer using Pygame.

The ESP32 is not required for laptop-only sound.

🔔 Buzzer Mode

The selected note is sent to the ESP32 through serial communication.

The ESP32 generates the corresponding frequency using the buzzer.

🔊 Both Mode

The note is played simultaneously through:

Laptop
   +
ESP32 Buzzer

The corresponding ESP32 LED is also activated.

📁 Project Structure
AI-Virtual-Piano-ESP32/
│
├── Arduino/
│   └── esp32_piano_led.ino
│
├── Python/
│   └── virtual_piano_with_leds.py
│
├── Media/
│   └── piano_setup.jpg
│
├── README.md
├── requirements.txt
└── .gitignore
⚙️ Installation
1. Clone the Repository
git clone https://github.com/Lavanya25088/AI-Virtual-Piano-ESP32.git

Move into the project directory:

cd AI-Virtual-Piano-ESP32
2. Install Python Dependencies

Install all required Python libraries using:

pip install -r requirements.txt

The project requires:

opencv-python
mediapipe
numpy
pygame
pyserial
🚀 Running the Project
Step 1 — Upload the ESP32 Program

Open:

Arduino/esp32_piano_led.ino

using Arduino IDE.

Select:

ESP32 board
Correct USB serial port

Then upload the program to the ESP32.

Step 2 — Connect the Hardware

Connect the ESP32 to the computer using USB.

Connect:

Buzzer → GPIO 5

LED 1 → GPIO 12
LED 2 → GPIO 13
LED 3 → GPIO 14
LED 4 → GPIO 15

Make sure the LEDs have appropriate current-limiting resistors.

Step 3 — Run the Python Program

From the project root directory:

python Python/virtual_piano_with_leds.py

The program will open the webcam and display the virtual piano.

Step 4 — Play the Piano 🎹

Point your index finger toward one of the virtual piano keys.

The program detects the finger position and determines which key has been
selected.

The corresponding note is then played according to the selected sound mode.

🎮 Controls

The Python application provides the following controls:

Key	Function
1	Laptop sound mode
2	ESP32 buzzer mode
3	Both laptop + ESP32
ESC	Exit application

The main interaction with the piano is performed using the index finger.

👁️ Hand Tracking

The project uses MediaPipe Hands to detect hand landmarks in real time.

The index finger landmark is used to determine the position of the user's
finger.

        Hand
         │
         ▼
   MediaPipe Hands
         │
         ▼
   Hand Landmarks
         │
         ▼
   Index Finger
         │
         ▼
 Virtual Piano Key

This allows the user to interact with the piano without a physical
keyboard or touchscreen.

🎵 Audio Generation

The Python program generates WAV audio files for the piano notes.

The generated notes correspond to:

C   → 261.63 Hz
D   → 293.66 Hz
E   → 329.63 Hz
F   → 349.23 Hz
G   → 392.00 Hz
A   → 440.00 Hz
B   → 493.88 Hz
C2  → 523.25 Hz

The audio is then loaded and played using Pygame.

The generated note_*.wav files are ignored by Git using .gitignore.

🔄 System Workflow
1. Start Python program
          ↓
2. Webcam captures video
          ↓
3. MediaPipe detects hand
          ↓
4. Index finger position is calculated
          ↓
5. Finger position is mapped to piano key
          ↓
6. Piano note is selected
          ↓
7. Laptop sound is played
          ↓
8. Serial command is sent to ESP32
          ↓
9. ESP32 activates LED
          ↓
10. ESP32 buzzer plays corresponding note
📸 Project

🧩 Key Concepts Demonstrated

This project combines several important concepts:

Computer Vision

Using OpenCV and MediaPipe for real-time hand tracking.

Human-Computer Interaction

Using hand gestures and finger position as a natural input method.

Audio Processing

Generating and playing musical notes using Python.

Serial Communication

Sending commands between a computer and ESP32.

Embedded Systems

Using ESP32 GPIOs to control LEDs and a buzzer.

Hardware-Software Integration

Combining a computer vision application with physical embedded hardware.

🔮 Future Improvements

Possible future improvements include:

🎹 Add black piano keys
🎼 Add multiple octaves
🎵 Improve piano sound synthesis
🎤 Add microphone-based interaction
🎚️ Add volume control
💾 Add song recording and playback
🎶 Add MIDI output
📡 Add wireless ESP32 communication
⌨️ Add physical keyboard support
🎹 Add chord detection
🎼 Add predefined songs and automatic playback
📚 Learning Outcomes

Through this project, the following concepts were explored:

Real-time computer vision
Hand landmark detection
Gesture-based interaction
Python programming
OpenCV
MediaPipe
NumPy
Pygame
Serial communication
ESP32 GPIO control
Buzzer frequency generation
LED control
Hardware-software integration
👨‍💻 Author
Lavanya Raj Singh

Electronics and Communication Engineering Student

Interests

Embedded Systems | VLSI | Computer Vision

⭐ If you find this project interesting, consider giving the repository a star!


### One important thing

Because your README currently has `Media/piano_setup.jpg` in it, **only keep that image line if you actually upload an image with exactly that path**.

So your final repo should be:

```text
AI-Virtual-Piano-ESP32/
├── Arduino/
│   └── esp32_piano_led.ino
├── Python/
│   └── virtual_piano_with_leds.py
├── Media/
│   └── piano_setup.jpg
├── README.md
├── requirements.txt
└── .gitignore

